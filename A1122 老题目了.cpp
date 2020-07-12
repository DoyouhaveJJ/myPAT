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
int G[201][201];
int main(){
    int N,M;
    cin >> N >> M;
    for(int i = 0 ; i < M ; ++i){
        int x,y;
        cin >>x >>y;
        G[x][y] = G[y][x] = 1;
    }
    int Q;
    cin >> Q;
    for(int q = 0 ; q< Q; ++q){
        int n;
        cin >>n;
        vector<int> query(n);
        set<int> v;
        for(int i = 0 ; i < n ; ++i){
            cin >> query[i];
            v.insert(query[i]);
        }

        if(n != N+1 || *query.begin() != *(query.end()-1)||v.size()!=N ){

            printf("NO\n");
        }else{
            int c=1;
            for(c = 1 ; c < n ; ++c){
                if(G[query[c]][query[c-1]] == 0){
                    break;
                }
            }
            if(c != n){
                printf("NO\n");
            }else{
                printf("YES\n");
            }
        }
    }
}
