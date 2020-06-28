#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

int main() {
    int N,i=1,sum=0,s,e,di;
    int dis[100010];
    scanf("%d",&N);
    dis[1] = 0;
    while(i<=N){
        //i到i+1的距离为di
        scanf("%d",&di);
        sum += di;
        //从1号点到i号点的顺时针距离
        dis[i+1] = sum;
        i++;
    }
    //逆时针的距离便是 sum-dis
    scanf("%d",&N);
    while (N--){
        scanf("%d %d",&s,&e);
        if(s>e){
            i=e;
            e=s;
            s=i;
        }
        di = dis[e] - dis[s];
        printf("%d\n",di>=(sum-di)?(sum-di):di);
    }


}