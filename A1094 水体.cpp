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
typedef long long LL;
using namespace std;
const int maxN=200;
int deep[maxN];
int counter[maxN];
vector<int> childrens[maxN];
int maxg=0,maxdeep=0;
void BFS(int root){
    deep[root] = 1;
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        counter[deep[now]]++;
        if(counter[deep[now]] > maxg){
            maxg=counter[deep[now]];
            maxdeep=deep[now];
        }
        for(int i = 0 ; i < childrens[now].size();++i){
            int next = childrens[now][i];
            deep[next] = deep[now] + 1;
            Q.push(next);
        }
    }
}

int main(){
    int N,M,x,n;
    cin >> N >> M;
    for(int i = 1 ; i <= M ; ++i){
        cin >> x >> n;
        for(int j = 1 ; j <= n ; ++j){
            int y;
            cin >> y;
            childrens[x].push_back(y);
        }
    }
    BFS(1);
    printf("%d %d",maxg,maxdeep);


}

