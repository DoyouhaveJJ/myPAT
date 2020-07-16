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

int main2(){
    int N;
    LL A,B,C;
    cin >> N;
    for(int i = 1 ; i <= N ; ++i){
        printf("Case #%d: ",i);
        scanf("%lld %lld %lld",&A,&B,&C);
        LL res = A+B;
        //只有两个正数相加才有可能正溢出，溢出则必然大于C
        if(res < 0 && A > 0 && B > 0){
            printf("true\n");
        }
        //只有两个负数相加才有可能负溢出，溢出必然小于C
        if(res > 0 && A < 0 && B < 0){
            printf("false\n");
        }
        //其他情况直接判断
        if(A + B - C > 0) {
            printf("true\n");
        }else{
            printf("false\n");
        }

    }
}

int main(){

    int N;
    long double A,B,C;
    cin >> N;

    for(int i = 1 ; i <= N ; ++i){
        printf("Case #%d: ",i);
        scanf("%Lf %Lf %Lf",&A,&B,&C);
        if(A + B - C > 0) {
            printf("true\n");
        }else{
            printf("false\n");
        }

    }
}




