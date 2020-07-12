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

int rides[100010];
unordered_map<int,int> mp;
int main() {
    int N;
    cin >> N;
    int counter = 0;
    for(int i = 1 ; i <= N ; ++i){
        scanf("%d",&rides[i]);
        if(mp.find(rides[i])==mp.end()){
            mp[rides[i]] = 1;
        }else{
            mp[rides[i]]++;
        }
        if(rides[i]> N){
            counter++;
        }
    }
    int dp[100010];
    dp[N] = counter;
    for(int i = N ; i > 0 ; --i){
        dp[i-1] = dp[i] + mp[i];
    }
    bool flag =false;
    for(int i = N ; i > 0 ; --i){
        if(dp[i] >= i){
            printf("%d",i);
            flag = true;
            break;
        }
    }
    if(!flag){
        printf("0");
    }
}