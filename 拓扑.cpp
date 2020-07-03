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
vector<int> Adj[maxN];
int inDgree[maxN] = {0};
int n;
bool topoSort(){
    int num = 0;
    queue<int> Q;

    //入度为0的入队
    for(int i = 0 ; i < n ; ++i){
        if(inDgree[i] ==0){
            Q.push(i);
        }
    }

    while (!Q.empty()){
        int now = Q.front();
        Q.pop();
        num++;
        for(int i = 0 ; i < Adj[now].size();++i){
            int v = Adj[now][i];
            //删除边，相当于减入度
            inDgree[v]--;
            if(inDgree[v]==0){
                Q.push(v);
            }
        }
        //同时也清除now点的所有边
        //也可以不用
        Adj[now].clear();
    }
    if(num == n){
        return true;
    }
    return false;
}

int main(){

}