
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


using namespace std;
const int maxN=105;
int G[maxN][maxN];
int N,M;
bool visit[maxN]={false};
int main(){
    fill(G[0],G[0]+maxN*maxN,INF);
    cin >> N >> M;
    for(int i = 0 ; i < M ; ++i){
        int x,y,z;
        cin >> x >> y >> z;
        G[x][y]=z;
        G[y][x]=z;
    }
    int K,x,n;
    cin >> K;
    int minl = INF,id=0;
    for(int k = 1 ; k <= K ; ++k){
        cin >> n;
        vector<int> path;
        memset(visit,false, sizeof(visit));
        for(int i = 0 ; i < n ; ++i){
            cin >> x;
            path.push_back(x);
        }
        //检测
        int length = 0;
        visit[path[0]] = true;
        bool isSimple = true;
        bool isTC = true;
        bool isRoute = true;
        int viscount = 0;
        for(int i = 0 ; i < n-1 ; ++i){
            //存在路
            if(G[path[i]][path[i+1]] < INF){
                //如果下一个就是终点也是起点
                if(path[i+1]==path[0] && i+1 == n-1){
                    length += G[path[i]][path[i+1]];
                    viscount++;
                    break;
                }else{
                    if(!visit[path[i+1]]){
                        viscount++;
                        visit[path[i+1]] = true;
                    }else{
                        isSimple = false;
                    }
                }
                length += G[path[i]][path[i+1]];
            }else{
                isRoute = false;
                break;
            }
        }
        if(*path.begin() != *(path.end()-1) || viscount < N){
            isTC = false;
        }
        if(isTC){
            if(length < minl){
                minl = length;
                id = k;
            }
            if(isSimple){
                printf("Path %d: %d (TS simple cycle)",k,length);
            }else{
                printf("Path %d: %d (TS cycle)",k,length);
            }
        }else{
            if(!isRoute){
                printf("Path %d: N/A (Not a TS cycle)",k);
            }else{
                printf("Path %d: %d (Not a TS cycle)",k,length);
            }
        }
        printf("\n");
    }
    printf("Shortest Dist(%d) = %d",id,minl);
}