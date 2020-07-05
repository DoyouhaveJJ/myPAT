
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



const int maxN = 1010;

int main(){
    string Str;
    getline(cin,Str);
    int len = Str.length();
    int dp[maxN][maxN]={0};

    //边界 //尽可能在初始化边界是 多多弄
    for(int i = 0 ;i < len ; ++i){
        //自己和自己是回文串
        dp[i][i] = 1;
        if(i < len -1 && Str[i] == Str[i+1]){
            dp[i][i+1] = 1;
        }

    }

    //动态规划  第 i~j是否是回文串 dp[i][j] i~j串是否是回文串
    //枚举方式是 从长度3开始枚举 因为1和2已经枚举过了
    int MaxLen = 1;

    //枚举所有长度
    for(int L = 3 ; L <= len ; ++L){
        //枚举长度内所有起点
        for(int i = 0 ; i + L - 1 < len ; ++i){
            int j = i + L - 1; //字串右端点， 要保证右端点不超过len
            //如果左右相等，且内部dp[i-1][j-1]也为1的话，证明这个字串是回文串
            if(Str[j] == Str[i] && dp[i+1][j-1]==1){
                dp[i][j]= 1;
                MaxLen = L;
            }
        }
    }

    cout<<MaxLen;



}