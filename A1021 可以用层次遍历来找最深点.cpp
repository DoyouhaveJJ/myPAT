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

const int maxN = 10010;
//图
vector<int> G[maxN];
int deep[maxN];
bool visited[maxN] = {false};

struct findNode{
    int ID;
    int deep;

}nodes[maxN];

int BFS(int root){
    if(visited[root]){
        return -1;
    }else{
        queue<int> Q;
        deep[root] = 1;
        Q.push(root);
        int now=root;
        while(!Q.empty()){
            now = Q.front();
            visited[now] = true;//访问
            Q.pop();
            for(auto it = G[now].begin();it!=G[now].end(); ++it){
                deep[*it]=deep[now]+1;
                if(!visited[*it]){
                    Q.push(*it);
                }
            }
        }
        return deep[now];

    }




}


bool cmp(findNode a,findNode b){
    if(a.deep != b.deep){
        return a.deep>b.deep;
    }else{
        return a.ID<b.ID;
    }
}
int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N-1; ++i){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    //连通子图个数
    //利用广度遍历
    int components = 0;

    for(int i = 1 ; i <= N ; ++i){
        if(!visited[i]){
            int res = BFS(i);
            components++;
        }
    }
    if(components > 1){
        cout << "Error: "<< components <<" components";
    }else{
        int resdeep;
        for(int i = 1 ; i <= N ; ++i){
            memset(visited,false,sizeof(visited));
            resdeep = BFS(i);
            nodes[i].ID=i;
            nodes[i].deep = resdeep;
        }

        sort(nodes+1,nodes+N+1,cmp);
        int max = nodes[1].deep;
        for(int i = 1 ; i <= N ; ++i){
            if(max > nodes[i].deep){
                break;
            }
            cout << nodes[i].ID<<endl;
        }
    }




}