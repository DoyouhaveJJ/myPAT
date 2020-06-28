#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
using  namespace std;

long long lc(int a,int n){
    long long res = a;
    for(int i = 1 ; i <= n ; ++i){
        res *=(a+i);
    }
    return res;
}

int main(){
    long long N;
    scanf("%lld",&N);
    auto up = (long long)sqrt(N);
    int maxLen = 0;
    int start = 0;
    if(N==2){
        printf("1\n2");
        return 0;
    }

    for(int i = 2 ; i <= up+1 ; ++i){
        int j = 1;//j为长度
        for( j = 0 ; j <= up+1 ; ++j){
            long long v = lc(i,j);
            if((N % v) != 0 || v>N)
                break;

        }
        if(maxLen < j){
            maxLen = j;
            start = i;
        }
    }
    if(maxLen == 0){
        printf("%d\n%lld",1,N);
    }else{
        printf("%d\n",maxLen);
        for(int i = 0 ; i < maxLen;++i){
            printf("%d",start+i);
            if(i < maxLen-1){
                printf("*");
            }
        }
    }



}