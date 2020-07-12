#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;


// 递归 n中的质因子p的总个数 = n/p +  cal(n/p,p)
// n!中p的倍数的个数(相当于切分),且下一个(n/p)!中p倍数的个数 直到n<p没有为止。
int cal1(int n,int p){
    if(n < p){
        return 0;
    }
    return (n/p) + cal1(n/p,p);
}

//非递归
int cal2(int n, int p){
    int ans = 0;
    while (n){
        ans += n/p;
        n = n/p;
    }
    return ans;
}
//C(n,m) = n!/(m!(n-m)!)
long int C(long int n,long int m){
    long int ans = 1;
    for(long int i =  1; i <= m ; i++){
        ans =(ans * (n - m + i) ) / i;
    }
    return ans;
}

//C(n,m) = C(n-1,m-1) +C(n-1,m)


int main(){
    printf("%ld",C(4,2));
}