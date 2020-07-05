
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



const int maxN = 10001;
const int maxM = 101;

int w[maxN],dp[maxM] = {0}; //w[i]为钱币价值 //dp为剩余m空间时能获得的最大价值
bool choice[maxN][maxM] ,flag[maxN]; //

bool cmp(int a,int b){
    return a>b;
}

int main(){
    int N,M;


    //需要记录选择的硬币
    cin >> N >> M;
    for(int i = 1 ; i <= N ; ++i){
        cin >> w[i];
    }
    //倒着排序
    sort(w+1,w+N+1,cmp);
    //枚举，枚举第一个前

    //状态转移方程 dp[m] 剩余m容量时能获得的最大利益。
    for(int i = 1 ; i <= N ; ++i){
        //这里钱币的价值和重量是相当于共享的
        //枚举容量
        for(int m = M; m >= w[i];m--){
            if(dp[m] <= dp[m-w[i]] + w[i]){
                dp[m] = dp[m-w[i]] + w[i];
                choice[i][m] = true; //
            }else{
                choice[i][m] = false;
            }
        }
    }

    if(dp[M]!=M){
        printf("No Solution");

    }else{
        int k = N , num = 0 , v =M;
        while (k>=0){
            if(choice[k][v]==1){
                flag[k] = true;
                v-=w[k];
                num++;
            }else
                flag[k] =  false;
            k--;
        }

        for(int i = N ; i>=1 ; --i){
            if(flag[i]){
                printf("%d",w[i]);
                num--;
                if(num > 0){
                    printf(" ");
                }
            }
        }
    }




}