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
const int maxN = 10010;



int main(){
    int K;
    int num[maxN],dp[maxN];

    cin >> K;
    for(int i = 0 ; i < K ; ++i){
        scanf("%d",&num[i]);
    }
    //由于i~j 枚举j，i不会超过i，因此有1～i-1中字串，因此需要找到其中的最大值。
    //总问题 求以j为底子串的最大值
    //由于i相对于j是可以变的，因此关注j，j的最大值影响j+1的最大值
    //子问题，求以j为结束的字串的最大值，、 dp[j]为以j为结束的字串的最大值
    //状态方程 dp[j+1] = max( dp[j]+num[j+1] , num[i])
    //动态规划思想，保留每一次的最佳状态，直接省略了其他非最佳状态的计算，极大降低计算量。
    //需要有边界（边检通常只需要一次计算即可得出最佳状态），之后的计算都根据上一次的最佳状态来计算当前的最佳状态（即状态转移方程）
    //这道题是计算字串最大值了，因此第j个的最佳值需要通过前面1~j-1次计算才能得出。但可以基本划分成：保留1~j-1中最大的字串，不保留，或，只取第j个
    //边界
    dp[0] = num[0];
    for(int i = 1; i < K ; ++i){
        dp[i] = max(dp[i-1]+num[i],num[i]);
    }

    int max = -99999999;

    int index = -1;
    for(int i = 0 ; i < K ;++i){
       if(max < dp[i]){
           max = dp[i];
           index = i;
       }
    }


    if(max >= 0){
        int temp= max;
        int j;
        for(j= index ; j >=0 ; --j){
            temp -= num[j];
            if(temp == 0){
                break;
            }

        }
        printf("%d %d %d",max ,num[j] ,num[index]);
    }else{
        printf("0 %d %d",num[0],num[K-1]);
    }


}
