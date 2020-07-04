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
const int maxN = 220;
int N,K;
vector<int> G[maxN*maxN];
int Cost[maxN][maxN];
map<string,int> sMap;
map<int,string> iMap;
int End=0;
int Happy[maxN];

int d[maxN];
bool visit[maxN] = {false};
vector<int> Pre[maxN];
void Dijkstra(int root){
    fill(d,d+N,INF);
    d[root] = 0;
    for(int i = 0 ; i < N ; ++i){
        int min = INF,u=-1;
        for(int j = 0 ; j < N ; ++j){
            if(!visit[j] && d[j] < min){
                min = d[j];
                u =j;
            }
        }
        if(u==-1) return;
        visit[u] = true;
        for(int j = 0 ; j < G[u].size();++j){
            int v = G[u][j];
            if(!visit[v] && d[u] + Cost[u][v] < d[v]){
                d[v] = d[u] + Cost[u][v];
                Pre[v].clear();
                Pre[v].push_back(u);
            }else if(!visit[v] && d[u] + Cost[u][v] == d[v]){
                Pre[v].push_back(u);
            }
        }

    }
}


vector<int> tempPath,optPath;

int num = 0;
int maxHappy=0;
int maxAvg=0;
void DFS(int Target,int AllHappy,int Nodes){
    if(Target ==End){

        tempPath.push_back(Target);
        num++;
        if(AllHappy > maxHappy){
            maxHappy = AllHappy;
            optPath = tempPath;
            maxAvg = AllHappy/Nodes;
        }else if(AllHappy == maxHappy){
            if((AllHappy/Nodes) > maxAvg){
                maxAvg = (AllHappy)/Nodes;
                optPath = tempPath;
            }
        }


        tempPath.pop_back();
        return;
    }

    tempPath.push_back(Target);
    for(int i = 0 ; i < Pre[Target].size();++i){
        int next = Pre[Target][i];
        DFS(next,AllHappy + Happy[next],Nodes+1);
    }
    tempPath.pop_back();



}



int main(){

    string Start;
    cin >> N >> K >> Start;

    sMap[Start] = 0;
    iMap[0] = Start;
    Happy[0] = 0;
    for(int i = 1 ; i <= N-1 ; ++i){
        string city;
        int happy;
        cin >> city >> happy;
        sMap[city] = i;
        iMap[i] = city;
        Happy[i] = happy;
    }

    for(int i = 0 ; i < K ; ++i){
        string city1,city2;
        int cost;
        cin >> city1 >> city2 >> cost;
        int c1=sMap[city1],c2=sMap[city2];
        G[c1].push_back(c2);
        G[c2].push_back(c1);
        Cost[c1][c2]= cost;
        Cost[c2][c1]= cost;
    }

    Dijkstra(0);

    int Target = sMap["ROM"];

    DFS(Target,Happy[Target],0);
    End = sMap[Start];
    cout <<num <<" "<< d[Target] <<" "<< maxHappy;
    printf(" %.0f\n",floor(maxAvg));

    for(int i = optPath.size()-1 ;i>=0 ; --i){
        cout << iMap[optPath[i]] ;
        if(i > 0){
            cout << "->";
        }
    }
}
