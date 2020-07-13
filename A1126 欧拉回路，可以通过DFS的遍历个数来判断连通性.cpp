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
//欧拉回路 经过所有边（所有点偶数度）
//欧拉路，经过所有边（只有两个奇数度）
int degree[520];
int G[520][520]={0};
bool vis[520] = {false};
vector<int> path;
void DFS(int v){
    vis[v] = true;
    path.push_back(v);
    for(int i = 1 ; i <= 520 ; ++i){
        if(G[v][i]==1 && !vis[i]){
            DFS(i);
        }
    }
}
//是否连通
int main(){
    int N,M;
    cin >> N >> M;
    for(int i = 1 ; i <=M ;++i){
        int x,y;
        cin >> x >>y;
        //不计算重复边
        if(G[x][y]==0 ||G[y][x]==0 ){
            G[x][y]=G[y][x] = 1;
            degree[x]++;
            degree[y]++;
        }


    }
    int even=0;
    int type = 0;
    for(int i = 1 ; i <=N ;++i){
        printf("%d",degree[i]);
        if(i<=N-1){
            printf(" ");
        }
        if(degree[i] % 2 == 0){
            even++;
        }
    }

    DFS(1);


    if(N==even && N!=0 && path.size()==N){
        type=2;
    }else if(N-even == 2 && N!=0 && path.size()==N){
        type=1;
    }
    if(type==0){
        printf("\nNon-Eulerian");
    }else if(type == 1){
        printf("\nSemi-Eulerian");
    }else{
        printf("\nEulerian");
    }
}