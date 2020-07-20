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
#define INF 1000000000
typedef long long LL;
using namespace std;
const int maxN = 1005;
int G[maxN][maxN] = {0};
//找连通子图
int K,N,M;
bool vis[maxN] = {false};
vector<int> suspects;
vector<int> gang;
bool issus[maxN] = {false};
void BFS(int p){
    queue<int> Q;
    Q.push(p);
    while (!Q.empty()){
        int now = Q.front();
        vis[now]=true;
        gang.push_back(now);
        Q.pop();
        for(int i = 1 ; i <= N ; ++i){
            if(G[now][i]!=0 && G[i][now]!=0 && issus[i] && !vis[i]){
                Q.push(i);
            }
        }
    }
}




int main(){
    int x,y,d;
    cin >> K >> N >> M;
    for(int i = 1 ;i <= M; ++i){
        cin >> x >> y >>d;
        G[x][y] += d;
    }
    for(int i = 1 ; i <= N ; ++i){
        //找到所有的骗子
        int shortcalls = 0,callbacks=0;
        for(int j = 1 ; j <= N ; ++j){
            if(G[i][j]!= 0){
                if(G[i][j] <= 5){
                    shortcalls++;
                    if(G[j][i]!=0){
                        callbacks++;
                    }
                }
            }
        }
        if(shortcalls > K && (1.0*callbacks/shortcalls)<=0.2){
            suspects.push_back(i);
            issus[i]=true;
        }
    }
    if(suspects.empty()){
        cout <<"None"<<endl;
        return 0;
    }
    for(int i = 0 ; i < suspects.size();++i){
        gang.clear();
        if(!vis[suspects[i]]){
            BFS(suspects[i]);
            sort(gang.begin(),gang.end());
            for(int j = 0 ; j < gang.size();++j){
                cout << gang[j] ;
                if(j < gang.size()-1){
                    cout <<" " ;
                }
            }
            cout << endl;
        }
    }
    return 0;
}
