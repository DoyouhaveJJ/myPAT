#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#include <iostream>
#define INF 1e9

using namespace std;
const int maxN = 1020;

int N,M,K,Ds;
int G[maxN][maxN];

int d[maxN];
bool visit[maxN] = {false};
void Dijkstra(int root){
    memset(visit,false, sizeof(visit));
    fill(d,d+maxN,INF);
    d[root] = 0;
    for(int i = 0 ; i< N + M;++i){
        int u = -1,min = INF;
        for(int j = 1 ; j <= N+M;++j){
            if(!visit[j] && d[j] < min){
                u = j;
                min = d[j];
            }

        }

        if(u == -1)
            return;
        visit[u] = true;
        visit[u] = true;
        for(int v = 1 ; v <= N+M;++v){
            if(!visit[v] && G[u][v] !=INF){
                if(d[u] + G[u][v] < d[v]){
                    d[v] = G[u][v]+d[u];
                }
            }

        }
    }
}
//获取编号
int getID(char str[]){
    int i = 0 ,len = strlen(str),ID= 0;
    while (i<len){
        if(str[i]!='G'){
            ID = ID * 10 + (str[i]-'0');
        }
        ++i;
    }
    if(str[0]=='G')
        return N+ID;
    else
        return ID;
}


int main(){

    scanf("%d %d %d %d",&N,&M,&K,&Ds);
    int u,v,w;
    char city1[5],city2[5];
    //初始化图
    fill(G[0],G[0]+maxN*maxN,INF);
    for(int i = 0 ; i < K ; ++i){
        scanf("%s %s %d",city1,city2,&w);
        u = getID(city1);
        v = getID(city2);
        G[u][v] = G[v][u] = w;
    }

    double ansDis = -1 , ansAvg = INF;
    int ansID = -1;
    //枚举所有的待建点
    for(int i = N + 1 ; i <= N+M;i++){
        double minDis = INF , avg = 0;
        Dijkstra(i);
        //根据DJ算法出来的距离时我们要的东西
        for(int j = 1 ; j <= N ; ++j){
            if(d[j] > Ds){
                //有一个不通就不可以
                minDis = -1;
                break;
            }
            if(d[j] < minDis)
                minDis = d[j];//最短的
            avg+=1.0*d[j]/N; //平均
        }
        if(minDis == -1)
            continue;
        if(minDis > ansDis){
            ansDis = minDis;
            ansID = i;
            ansAvg = avg;
        }else if(minDis == ansDis && avg < ansAvg){
            ansID = i;
            ansAvg = avg;
        }
    }
    if(ansID == -1)
        printf("No Solution\n");
    else{
        printf("G%d\n",ansID - N);
        printf("%.1f %.1f",ansDis,ansAvg);
    }

}
