#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#define INF 1e9
#include <iostream>
using namespace std;
const int maxN = 1000;

struct Node{
    //为了方便起见的结构体，用于vector
    int v; //从i开始v为目标顶点id
    int dis; //从i开始以v为目标顶点的边权
};

//顶点到其余各点的距离
int d[maxN];
int N;

//用于记录路径
int pre[maxN];


//邻接表
vector<Node> G[maxN];

//记录是否访问
bool vis[maxN]={false};

void Dijkstra(int start){

    fill(d,d+N,INF);//初始化
    d[start] = 0;//初始化
    //初始化，令前驱是自己
    for(int i = 0 ; i < N ; ++i){
        pre[i] = i;
    }

    //一共要做N次
    for(int i  = 0 ; i < N ; ++i){

        int min=INF;
        int selectNode=-1;

        //找剩下中没有被访问过且可以到达的点
        for(int j= 0 ; j < N ; ++j){
            if(d[j]<INF&&!vis[j]){
                if(min > d[j]){
                    min = d[j];
                    selectNode = j;
                }
            }
        }

        //将selectNode点加入，并更新
        vis[selectNode] = true; //表示更新

        if(selectNode == -1){
            return;
        }else{
            //找到新加入的点的所有连接的点
            for(int k = 0; k<G[selectNode].size() ; ++k){
                int v = G[selectNode][k].v;
                //如果加入select点后，比原来的要小，且新加入的点没有被访问过！
                if(!vis[v] &&  d[selectNode] + G[selectNode][v].dis < dis[v]){
                    d[v] = d[selectNode] + G[selectNode][v].dis;//  优化

                    //令v的前驱为selectNode
                    pre[v] = selectNode;
                }
            }
        }


    }

}

int main() {



}




