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

struct node{
    int deep{0};
    vector<int> next;
}G[1001];
bool vis[1001] = {false};
int K;


int BFS(int root){
    queue<int> Q;
    Q.push(root);
    G[root].deep =0;
    int res=0;
    vis[root] = true;
    while (!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(auto it = G[now].next.begin();it!=G[now].next.end();it++){
            if(!vis[*it]){
                G[*it].deep = G[now].deep+1;
                if(!vis[*it] && G[*it].deep <= K){
                    vis[*it] = true;
                    Q.push(*it);
                    res++;
                }
            }



        }
    }
    return res;
}

int main() {

    int N;
    int n,k;
    cin >> N >> K;
    for(int i = 1 ;i <= N ; i++){

        cin >> n ;
        for(int j = 1 ; j <= n ; ++j){
            cin >>k;
            G[k].next.push_back(i);
        }
    }

    //建立完成
    int res=0;
    cin>>n;
    for(int i = 0 ; i < n ; ++i){
        memset(vis, false, sizeof(vis));
        cin >> k;
        res = BFS(k);
        cout << res <<endl;
    }


}




