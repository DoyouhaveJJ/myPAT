#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>
#include <iostream>
#include <queue>

using namespace std;
const int maxN = 100010;
int main(){
   long long p,N,num[maxN];
   scanf("%ld %ld",&N,&p);
   for(int i=0;i<N;++i){
       scanf("%ld",&num[i]);
   }
   sort(num,num+N);
   int res=1;
   //用二分查找减少时间复杂度
   for(int i = 0 ; i < N ; ++i){
       //upper_bound 二分查找，返回的是数组指针位置
      int j = upper_bound(num+i+1,num+N,num[i]*p) - num;
      res = max(res,j-i);
   }
   printf("%d",res);

}
