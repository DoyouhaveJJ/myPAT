#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#include <iostream>
#include<unordered_map>
#define INF 0x3fffffff
typedef long long LL;
using namespace std;

struct Record{
    int flag;
    string plate;
    int time;
};
bool cmp(Record a,Record b){
    if(a.plate!=b.plate){
        return a.plate < b.plate;
    }else{
        return a.time < b.time;
    }
}
int main(){
    int N,M;
    string plate,type;
    Record records[10010];
    int hh,mm,ss;
    int op[86400]={0},res[86400]={0};
    unordered_map<string,int> cartime;
    cin >> N >> M;
    for(int i = 0 ; i < N ; ++i){
        cin >> plate;
        scanf("%d:%d:%d",&hh,&mm,&ss);
        cin >> type;
        records[i].plate=plate;
        records[i].time=3600*hh + 60*mm + ss;
        records[i].flag = type=="in"?1:-1;
    }
    sort(records,records+N,cmp);
    int max=0;
    set<string> maxcar;
    for(int i = 0 ; i < N ; i++){
        if(records[i].plate == records[i+1].plate && records[i].flag==1 && records[i+1].flag==-1){
            op[records[i+1].time] += -1;
            op[records[i].time] += 1;
            if(cartime.find(records[i].plate)==cartime.end()){
                cartime[records[i].plate] = records[i+1].time - records[i].time;
            }else{
                cartime[records[i].plate] += records[i+1].time - records[i].time;
            }
            if(cartime[records[i].plate]>max){
                maxcar.clear();
                max = cartime[records[i].plate];
                maxcar.insert(records[i].plate);
            }else if(cartime[records[i].plate]==max){
                maxcar.insert(records[i].plate);
            }
        }
    }
    res[0]=op[0];
    for(int i = 1 ; i < 86400 ; ++i){
        res[i] =  res[i-1] + op[i];
    }

    for(int i = 0 ; i < M ; ++i){
        scanf("%d:%d:%d",&hh,&mm,&ss);
        cout << res[3600*hh+60*mm+ss] << endl;
    }

    for(auto it = maxcar.begin() ; it!=maxcar.end();++it){
        cout << *it << " ";
    }
    printf("%02d:%02d:%02d",max/3600,(max%3600)/60,(max%3600)%60);




}
