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


vector<vector<int>> edges;

bool check(vector<int> color){
    for(int i = 0 ; i < edges.size();++i){
        if(color[edges[i][0]] == color[edges[i][1]]){
            return false;
        }
    }
    return true;
}

int main(){
    int N,M,K;
    cin >> N >> M;

    for(int i = 0 ; i < M ; ++i){
        int x,y;
        cin >> x >> y ;
        vector<int> edge(2);
        edge[0]=x;
        edge[1]=y;
        edges.push_back(edge);
    }
    cin >> K;
    for(int k = 0 ; k < K ; ++k){
        vector<int> color(N);
        set<int> type;
        for(int i = 0 ; i < N ; ++i){
            cin >> color[i];
            type.insert(color[i]);
        }
        if(check(color)){
            printf("%lu-coloring\n",type.size());
        }else{
            printf("No\n");
        }
    }

}