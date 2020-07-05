
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
const int maxN = 10010;
vector<int> G[maxN];

int main(){
    int N,M,Q;
    cin >>N >> M;
    for(int i = 0 ; i < M ; ++i){
        int x,y;
        cin >> x>>y;
        G[x].push_back(i);
        G[y].push_back(i);
    }

    bool Map[maxN]={false};
    cin >> Q;
    for(int i = 0 ; i < Q ; ++i){
        int n,z,js=0;
        cin >> n;
        memset(Map,false, sizeof(Map));
        for(int j = 0; j< n ; ++j ){
            cin >> z;
            for(int k = 0 ; k < G[z].size();++k){
                if(!Map[G[z][k]]){
                    js++;
                    Map[G[z][k]] = true;
                }
            }

        }
        if(js < M){
            cout <<"No"<<endl;
        }else{
            cout <<"Yes"<<endl;
        }
    }


}
