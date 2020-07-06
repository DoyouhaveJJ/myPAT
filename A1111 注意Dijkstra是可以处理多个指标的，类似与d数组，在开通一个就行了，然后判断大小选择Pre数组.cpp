
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
#define INF 1e9


using namespace std;

vector<int> Adj[510];

int Gtime[510][510];
int Glength[510][510];
//用DFS遍历会超时
/*
bool vis[510] = {false};
vector<int> short_optPath,short_tempPath;
int optTime=INF,optDis=INF;
void DFS_Short(int now ,int target, int time , int distence){
    short_tempPath.push_back(now);
    vis[now] = true;
    if(now == target){
        if(distence < optDis ){
            optDis = distence;
            optTime = time;
            short_optPath = short_tempPath;
        }else if(distence == optDis){
            if(time < optTime){
                optTime = time;

                short_optPath = short_tempPath;
            }
        }
        vis[now] = false;
        short_tempPath.pop_back();
        return;
    }

    for(int i = 0 ; i < Adj[now].size();++i){
        int v = Adj[now][i];

        if(!vis[v]){
            DFS_Short(v,target,time+Gtime[now][v],distence+Glength[now][v]);
        }
    }
    vis[now] = false;
    short_tempPath.pop_back();
}



vector<int> fast_optPath,fast_tempPath;
int optTimef=INF,optInsersection=INF;
void DFS_Fast(int now ,int target, int time,int intersections){
    fast_tempPath.push_back(now);
    vis[now] = true;
    if(now == target){
        if(time < optTimef ){
            optTimef = time;
            optInsersection = intersections;
            fast_optPath = fast_tempPath;
        }else if(time == optTimef){
            if(intersections < optInsersection){
                optInsersection = intersections;
                fast_optPath = fast_tempPath;
            }
        }
        vis[now] = false;
        fast_tempPath.pop_back();
        return;
    }

    for(int i = 0 ; i < Adj[now].size();++i){
        int v = Adj[now][i];
        if(!vis[v]){
            DFS_Fast(v,target,time+Gtime[now][v],intersections+1);
        }
    }
    vis[now] = false;
    fast_tempPath.pop_back();
}

*/
bool vis[510];


int N,M;
int t[510];
int nodes[510];

int preTime[510];
void Dijkstra_Time(int root){
    fill(t,t+N,INF);
    fill(nodes,nodes+N,INF);
    for(int i = 0 ; i < N ; ++i){
        preTime[i] = i;
    }
    t[root] = 0;
    nodes[root] = 1;
    for(int i = 0 ; i < N ; ++i){
        int u=-1,min=INF;
        for(int j = 0 ; j < N ; ++j){
            if(!vis[j] && t[j] < min){
                min = t[j];
                u = j;
            }
        }
        if(u==-1) return;
        vis[u] = true;
        for(int k = 0 ; k < Adj[u].size();++k){
            int v = Adj[u][k];
            //找一个最块且点最少的路
            if(!vis[v] && Gtime[u][v] < INF){
                if(t[u] + Gtime[u][v] < t[v]){
                    t[v] = t[u] + Gtime[u][v];
                    nodes[v] = nodes[u]+1;
                    preTime[v]=u;
                }else if(t[u] + Gtime[u][v] == t[v] && nodes[v] > nodes[u]+1){
                    nodes[v] = nodes[u]+1;
                    preTime[v]=u;
                }
            }
        }
    }
}



int d[510];
int times[510];
int preDis[510];

void Dijkstra_Dis(int root){
    fill(d,d+N,INF);
    fill(times,times+N,INF);
    d[root] = 0;
    times[root] = 0;
    for(int i = 0 ; i < N ; ++i){
        preDis[i] = i;
    }
    for(int i = 0 ; i < N ; ++i){
        int u=-1,min=INF;
        for(int j = 0 ; j < N ; ++j){
            if(!vis[j] && d[j] < min){
                min = d[j];
                u = j;
            }
        }
        if(u==-1) return;
        vis[u] = true;
        for(int k = 0 ; k < Adj[u].size();++k){
            int v = Adj[u][k];
            //找一个最短且时间最少
            if(!vis[v] && Glength[u][v] < INF){
                if(d[u] + Glength[u][v] < d[v]){
                    d[v] = d[u] + Glength[u][v];
                    times[v] = times[u]+Gtime[u][v];
                    preDis[v]=u;
                }else if(d[u] + Glength[u][v] == d[v] && times[v] > times[u]+Gtime[u][v]){
                    times[v] = times[u]+Gtime[u][v];
                    preDis[v]=u;
                }
            }
        }
    }
}
int s,e;
vector<int> dispath, Timepath, temppath;
void dfsdispath(int v) {
    dispath.push_back(v);
    if(v == s) return ;
    dfsdispath(preDis[v]);
}
void dfsTimepath(int v) {
    Timepath.push_back(v);
    if(v == s) return ;
    dfsTimepath(preTime[v]);
}


int main(){

    cin >> N >> M;
    fill(Gtime[0],Gtime[0]+510*510,INF);
    fill(Glength[0],Glength[0]+510*510,INF);
    for(int i = 0 ; i < M ; ++i){
        int a1,a2,a3,a4,a5;

        cin >> a1 >> a2 >> a3 >> a4 >>a5;
        if(a3==0){
            Adj[a1].push_back(a2);
            Adj[a2].push_back(a1);
            Glength[a1][a2] =Glength[a2][a1] = a4;
            Gtime[a1][a2] = Gtime[a2][a1] = a5;
        }else{
            Adj[a1].push_back(a2);
            Glength[a1][a2] = a4;
            Gtime[a1][a2] = a5;
        }
    }

    cin >> s >> e;
    vector<int> optTime,optDis;
    Dijkstra_Dis(s);
    memset(vis,false, sizeof(vis));
    Dijkstra_Time(s);
    dfsdispath(e);
    dfsTimepath(e);

    if(dispath != Timepath){
        cout <<"Distance = " << d[e] <<": ";
        for(int k = dispath.size()-1 ; k >= 0;--k){
            cout <<  dispath[k];
            if(k >0){
                cout <<" -> ";
            }
        }
        cout << endl;
        cout <<"Time = " << t[e] <<": ";
        for(int k = Timepath.size()-1 ; k >= 0;--k){
            cout <<  Timepath[k];
            if(k > 0){
                cout <<" -> ";
            }
        }
    }else{
        cout <<"Distance = " << d[e];
        cout <<"; Time = " << t[e]<<": ";
        for(int k = dispath.size()-1 ; k >= 0;--k){
            cout <<  dispath[k];
            if(k > 0){
                cout <<" -> ";
            }
        }
    }

}