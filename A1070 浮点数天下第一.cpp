#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>
#include <iostream>

using namespace std;


const int maxN = 1010;
struct MoonCake{
    double inventroy;
    double price;
    double single;
}moonCakes[maxN];

bool cmp(MoonCake a,MoonCake b){
    return a.single>b.single;
}

int main(){
    int N;
    double ans=0,amount = 0;
    scanf("%d %lf",&N,&amount);
    for(int i=0;i<N;++i){
        scanf("%lf",&moonCakes[i].inventroy);
    }
    for(int i=0;i<N;++i){
        scanf("%lf",&moonCakes[i].price);
        moonCakes[i].single = moonCakes[i].price/moonCakes[i].inventroy;
    }
    sort(moonCakes,moonCakes+N,cmp);
    for(int i=0;i<N;++i){
        if(moonCakes[i].inventroy > amount){
            ans += moonCakes[i].single* amount;
            break;
        }else{
            ans += moonCakes[i].single * moonCakes[i].inventroy;
            amount -=  moonCakes[i].inventroy;
        }

    }
    printf("%.2lf",ans);

}