#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#include <iostream>
using namespace std;

const int INF = 1e9;
const int maxN = 1000;

//邻接表
int n , G[maxN][maxN];
//到集合S的距离
int distence[maxN];
//相当于集合S
bool vis[maxN]={false};

int Prime(int start){
    //n为顶点个数
    fill(distence,distence + n ,INF);

    distence[start] = 0;

    //最小生成树的边权之和
    int ans = 0;

    for(int i = 0 ; i < n ; ++i){
        int u = -1 , min=INF;
        //找最小
        for(int j = 0; j < n ; ++j){
            if(!vis[j] && distence[j]<min){
                min = G[i][j];
                u=j;
            }
        }
        if(u == -1)
            return -1;
        vis[u] = true;
        ans += distence[u];
        for(int v = 0 ; v < n ; ++v){

            //不同于Dijkstar的 G[u][v]+distence[u] < distence[v]
            //prime是u点加入到后，更新 点j到集合S的最短距离，只要判断v到S的距离是否可以更新即可
            //每加入一个u，只需要判断u对其他边的影响即可，不用判断别的点对v的影响
            //因为distence存的是v点到S的最短距离。若新加入了u点，使得u-v更近，那么就更新
            if(!vis[v] && G[u][v] < INF && G[u][v]< distence[v]){
                distence[v] = G[u][v];
            }

        }
    }

    return ans;



}
int main(){

}