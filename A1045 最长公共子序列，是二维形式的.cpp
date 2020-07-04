#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#include <iostream>
#define INF 1e9

using namespace std;
const int maxC = 210;
const int maxN = 10010;

int A[maxC],B[maxN];
int dp[maxC][maxN]={0};

int main(){
    int n,N,M;

    cin >> n;
    cin >> N;
    //注意 这里是从1开始，是为了方便边界点判断
    for(int i = 1 ; i <= N ; ++i){
        cin >> A[i];
    }
    cin >> M;
    for(int i = 1 ; i <= M ; ++i){
        cin >> B[i];
    }


    //A是目的， B是全部
    //最长公共子序列
    //dp[i][j] A中第0~i串 和 B的0~j串最长的子序列
    //dp[i+1][j+1] = 若A[i+1]==B[j+1] => +1 若不等于 则为max( dp[i][j+1] , dp[i+1][j] )

    //边界
    for(int i = 0 ; i <= N ; ++i){
        dp[i][0] = 0;
    }
    for(int i = 0 ; i <= M ; ++i){
        dp[0][i] = 0;
    }

    for(int i = 1 ; i <= N ; ++i){
        for(int j = 1 ; j <= M ; ++j){
            //因为这里是可以重复的，因此不必要dp[i-1][j-1] + 1; 这样会导致只保留非重复的
            int Max = max(dp[i-1][j],dp[i][j-1]);
            if(A[i]==B[j]){
                dp[i][j] = Max + 1;
            }else{
                dp[i][j] = Max;
            }
        }
    }

    cout << dp[N][M];




}
