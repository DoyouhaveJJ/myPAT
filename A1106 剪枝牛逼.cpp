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

vector<int> child[100010];

int N;
double P,r;
int counter= 1;
int minDeep = INF;
void DFS(int now,int deep){
    if(child[now].empty()){
        //
        if(deep < minDeep){
            minDeep = deep;
            counter= 1;
        }else if(deep == minDeep){
            counter ++;
        }
        return;
    }
    for(int i = 0 ; i < child[now].size();++i){
        int next = child[now][i];
        if(deep+1 > minDeep){
            continue;
        }
        DFS(next,deep+1);
    }
}

int main(){

    cin >> N >> P >> r;
    for(int i = 0 ; i < N ; ++i){
        int n;
        cin >> n;
        for(int j = 0 ; j < n ; ++j){
            int x;
            cin >> x;
            child[i].push_back(x);
        }
    }

    DFS(0,0);
    double ans = P;
    for(int i=0 ; i < minDeep ; ++i){
        ans *= (100.00+r)/100;
    }
    ans = ( ans /10000 )*10000;
    printf("%.4lf %d",ans,counter);



}
