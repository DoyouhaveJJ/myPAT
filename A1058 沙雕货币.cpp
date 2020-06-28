#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
struct H{
    int G;
    int S;
    int K;
}A,B,Result;
int main(){
   scanf("%d.%d.%d %d.%d.%d",&A.G,&A.S,&A.K,&B.G,&B.S,&B.K);
   int carry = 0;
   Result.K = (A.K + B.K)%29;
   carry = (A.K + B.K)/29;
   Result.S = (A.S + B.S + carry)%17;
   carry = (A.S + B.S + carry)/17;
   Result.G = (A.G + B.G + carry);
   printf("%d.%d.%d",Result.G,Result.S,Result.K);
}