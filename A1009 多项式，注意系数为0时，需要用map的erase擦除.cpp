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

int main(){
    map<LL,double> Amap,Bmap,Cmap;
    LL x;
    double y;
    int Ka;
    cin >> Ka;
    for(int i = 1 ; i <= Ka ; ++i){
        cin >> x >>y;
        if(Amap.find(x)==Amap.end()){
            Amap[x]=y;
        }else{
            Amap[x]+=y;
        }
    }
    int Kb;
    cin >> Kb;
    for(int i = 1 ; i <= Kb ; ++i){
        cin >> x >>y;
        if(Bmap.find(x)==Bmap.end()){
            Bmap[x]=y;
        }else{
            Bmap[x]+=y;
        }
    }

    for(auto itA = Amap.begin();itA!=Amap.end();++itA){
        for(auto itB = Bmap.begin();itB!=Bmap.end();++itB){
            double Cc = itA->second * itB->second;
            LL Cexp = itA->first + itB->first;
            if(Cmap.find(Cexp) == Cmap.end()){
                Cmap[Cexp] = Cc;
            }else{
                Cmap[Cexp] += Cc;
            }
            if(Cmap[Cexp]==0){
                Cmap.erase(Cexp);
            }
        }
    }

    printf("%lu",Cmap.size());
    for(auto it = Cmap.rbegin();it!=Cmap.rend();++it){
        printf(" %lld %.1lf",it->first,it->second);
    }


}