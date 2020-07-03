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


int main(){
    //动态规划
    //dp记录最优状态 // 最大值？最小值等
    int dp[1000];
    int num[1000];
    //最大连续子序列和  -2 11 -4 13 -5 -2 找一个连续序列 i~j 使得值最大

    //找状态方程。 如果令i为某一值。那么 在1~i-1中共有 i-1中方法
    //记录以i为结尾的最大值，那么在计算i+1时，就直接可以用i的结果了

    //状态方程为 dp[i+1] = max (num[i+1] , dp[i]+ num[i+1] ) 如果不加前面的最大值，加了最大值更大呢？

    //求解状态dp
    //dp的第一个只能为num[0]
    dp[0] = num[0];
    //动态规划需要重叠子问题（这里是连续字串是重叠的， 第i个子问题是i+1的重复部分，因此可以写出状态转移方程）
    //动态规划注重每一个子问题的最优结果，作为上一层子问题的可行解。
    for(int i = 1 ; i < 1000 ; ++i){
        dp[i] = max(num[i] , dp[i-1]+ num[i]);
    }



    //最长不下降非连续子序列问题

    //{1,2,3,-1,-2,7,9}
    //总问题： 找一个序列（可以非连续）让他不下降且最长。
    //分解：第i个位置作为结尾时的最长？那么在求i+1时
    //如果1~i(非连续)的某一个v比他小，那么就可以把i+1接在v后面，长度为dp[v]+1
    //dp记录长度
    dp[0]=1;
    for(int i = 1 ; i < 1000;++i){
        //讨论第i个点的dp
        for(int j = 0 ; j < i ; j ++){
            // dp[j]+1 > dp[i] 相当于在1~i中找最大的那个。num[j] <= num[i]是题意
            // 因为dp已被分解成1~i个最优了，可以作为第i+1个的可行解之一。
            if(dp[j]+1 > dp[i] && num[j] <= num[i]){
                dp[i] = dp[j]+1;
            }

        }
    }


    //最长公共子序列
    //sadstory
    //adminsorry
    //得到 adsory
    //总问题，找一个可以非连续序列最长的公共序列
    //分解，A的第i个字符 和 B的第j个字符 的最长公共子序列长度dp[i][j]
    //转移方程 dp[i+1][j+1] =
    // 如果 A[i+1] == B[j+1] ，则dp[i+1][j+1] = dp[i][j] + 1
    // 如果 A[i+1] != B[j+1] ，则继承dp[i+1][j]和dp[i][j+1] 中较大的那个一个
    int lenA = 1,lenB=2;
    char A[1],B[2];
    int dp2[lenA][lenB];

    //边界dp2[0~lenA][0] = 0;
    //边界dp2[0][0~lenB] = 0;
    for(int i = 1 ; i < lenA ; ++i){
        for(int j = 1 ; j < lenB ; ++j){
            if(A[i] == B[j]){
                dp2[i][j] = dp2[i-1][j-1] +1;
            }else{
                dp2[i][j] = max(dp2[i][j-1],dp2[i-1][j]);
            }
        }
    }


    //最长回文串
    //
    //1 1 1 1 1 1 3 5 7 9 dp
    //0 1 2 3 4 5 6 7 8 9
    //P A T Z J U J Z T A C C B C C
    //  A T Z J U J Z T A <-最长回文串
    //总问题：找一个最长的串，使其长度最长
    //子问题，第i个位置的前1~i字串的最长回文串长度dp[i] 目测复杂度为O(n^2)
    //状态转移 dp[i+1] = dp[i]+1 如果加入i+1后仍然是回文串 ，否则为0
    //一维有时行不通，可以试试二维
    //dp[i][j]表示i~j字串是否是回文串
    //当A[i] == A[j] 时： dp[i][j] = dp[i+1][j-1] 当左右两个相同，看内部，如果内部也是回文串，那么就是了。
    //当A[i-1] != A[j+1] 时： dp[i][j] = 0;
    //边界： i==j时 肯定是回文串






}