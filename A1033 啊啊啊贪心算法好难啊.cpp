#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>
#include <iostream>

using namespace std;
const int max_num = 510;
struct Station{
    double price;
    double dis;
}stations[max_num];

bool cmp(Station a,Station b){
    return a.dis < b.dis;
}

int main(){
    double max_cap,cap_now=0,distence,p_dis,ans=0,dis_now;
    bool ok = true;
    int station_num;
    scanf("%lf %lf %lf %d",&max_cap,&distence,&p_dis,&station_num);
    double max_dis = max_cap * p_dis;
    for(int i=0;i<station_num;++i){
        scanf("%lf %lf",&stations[i].price,&stations[i].dis);
    }
    stations[station_num].dis = distence;
    stations[station_num++].price = 0;
    sort(stations,stations+station_num,cmp);
    if(stations[0].dis !=0){
        printf("The maximum travel distance = 0");
        return 0;
    }
    int i = 0;
    while (dis_now < distence){
        int j = i+1;
        int min_station = j;
        bool flag = false,founded=false;
        //这个从这个站点出发后，可能能到哪些站,找价格最短的
        //如果找到第一个第一个第一个第一个第一个第一个第一个第一个第一个第一个第一个第一个第一个第一个第一个最短的，那就去(贪心重要思想)
        while (((stations[j].dis -  stations[i].dis)<= max_dis) && j < station_num){
            flag = true;
            if(stations[j].price < stations[i].price){
                founded= true;
                min_station = j;
                break;
            }
            j++;
        }
        if(!founded){
            j = i + 1;
            while (((stations[j].dis -  stations[i].dis)<= max_dis) && j < station_num){
                flag = true;
                if(stations[j].price < stations[min_station].price){
                    min_station = j;
                }
                j++;
            }
        }
        //找到了这个站点min_staion
        //计算到这个站点的距离，加刚好的油
        if(flag){
            //下一站是终点
            if(min_station == station_num-1){
                //油不够
                if(p_dis * cap_now < (stations[min_station].dis - stations[i].dis)){
                    ans += (((stations[min_station].dis - stations[i].dis) - p_dis * cap_now)/p_dis)*stations[i].price;
                }
                break;
            }
            //现在的便宜，还是先加满油吧
            if(stations[i].price < stations[min_station].price){
                ans += (max_cap - cap_now)*stations[i].price;
                cap_now = max_cap;
            }else{
                //油不够，先加油到刚好到为止
                if(p_dis * cap_now < (stations[min_station].dis - stations[i].dis)){
                    //还缺多少油
                    ans += (((stations[min_station].dis - stations[i].dis) - p_dis * cap_now)/p_dis)*stations[i].price;
                    cap_now += ((stations[min_station].dis - stations[i].dis) - p_dis * cap_now)/p_dis;
                }
                //油够的，那就啥事也不做

            }
            //开往下一站,消耗油
            cap_now -= (stations[min_station].dis - stations[i].dis)/p_dis;
            i = min_station;
            dis_now = stations[min_station].dis;
        }
        else{
            //没找到，计算最远距离
            ok = false;
            break;
        }

    }
    if(ok){
        printf("%.2lf",ans);
    }else{
        printf("The maximum travel distance = %.2lf",stations[i].dis+max_dis);
    }



}