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
const int maxN = 500;
int N,M,S,D;
struct Node{
    int dis;
    int cost;
    int v;
};
Node newNode(int dis,int cost,int v){
    Node a{};
    a.dis = dis;
    a.cost = cost;
    a.v = v;//结点编号
    return a;
}
vector<Node> Adj[maxN];
//所有前驱
vector<int> pre[maxN];
//是否访问过了
bool vis[maxN];
//到各个点的距离
int cost[maxN][maxN];
int dis[maxN][maxN];
//记录从start开始的到其他各个点最短的
int distence[maxN];
vector<int> optPath,tempPath;
int lowCost = INF;



void DFS(int now,int tempCost,int tempDis){
    //到了起点了！
    if(now == S){
        if(tempDis == distence[D]){
            if(tempCost < lowCost){
                lowCost = tempCost;
                optPath = tempPath;
            }
        }
        return;
    }

    //将当前点加入路径
    //并且计算价格

    tempPath.push_back(now);
    for(int i = 0 ; i < pre[now].size();++i){
        int next = pre[now][i];
        DFS(next,tempCost + cost[now][next],tempDis+dis[now][next]);
    }
    //将当前点移除路径，因为已经遍历完一轮他的爸爸们了
    //他就没用了，同时也跳出了递归，回到了下一轮的循环
    tempPath.pop_back();

}



//找所有路径
void Dijkstra(int start){
    fill(distence,distence+N,INF);
    distence[start] = 0;
    //一共要做N次
    for(int k = 0 ; k < N ;k++){
        int min = INF,u=-1;
        //找到一个最近可到达点 未访问的 最短的,
        for(int i = 0 ; i < N ; ++i){
            if(!vis[i] && distence[i]<INF){
                if(min > distence[i]){
                    min = distence[i];
                    u = i;
                }
            }
        }
        //访问这个点（相当于加入）
        vis[u] = true;

        if(u==-1){
            return;
        }

        for(int j = 0 ; j < Adj[u].size();++j){
            int v = Adj[u][j].v;
            if(!vis[v] && dis[u][v] + distence[u] < distence[v]){
                distence[v] = dis[u][v] + distence[u];
                pre[v].clear();
                pre[v].push_back(u);
            }else if(!vis[v] && dis[u][v] + distence[u] == distence[v]){
                pre[v].push_back(u);
            }

        }

    }
}


int main(){

    cin >> N >> M>> S>>D;

    for(int i = 0 ; i < M ; ++i){
        int c1,c2,d,c;
        cin >> c1 >> c2 >> d >> c;
        Adj[c1].push_back(newNode(d,c,c2));
        Adj[c2].push_back(newNode(d,c,c1));
        cost[c1][c2] = c;
        cost[c2][c1] = c;
        dis[c1][c2]=d;
        dis[c2][c1]=d;
    }

    Dijkstra(S);
    DFS(D,0,0);
    cout << S << " ";
    for(int i = optPath.size()-1 ; i >=0;--i){
        cout << optPath[i] << " ";
    }

    cout << distence[D]<<" "  << lowCost;
}