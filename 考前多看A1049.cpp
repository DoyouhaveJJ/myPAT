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
#define INF 1000000000
typedef long long LL;
using namespace std;

//主要思路，枚举每一位， 计算该位可能出现1的个数
//抓住规律。当枚举到某一位时，判断该位的值。
//要保证所有讨论的数均不超过这个数
//如果该位为0，那么left 只能当left取遍 0~n-1(共n个) right就可以能取遍0～99..999 共a个。 那么当枚举到这位时
//就能取 left * a 个

//如果该位为1，那么left 只取到 0 ~ n-1 同理。 特别的，当left=n时，需要额外加上+1（自己本身） 再加上right
//即 30715 当枚举到第四位1时 是什么个情况呢 left:0~306同上，当left=307时， 只能有30710,30711...只能有30715
//即为 left * a + right + 1

//如果该位大于1 那么left可以取遍 0~307 因为该位定死位1了，那就可以全部取而不会超过最大值。
int counter(int n,int target){
    int ans = 0;
    int a = 1;
    while (n/a!=0){
        int left = n / (10*a);
        int mid = n / a % 10;
        int right = n % a;

        if(mid < target){
            ans += left * a;
        }else if(mid == target){
            ans += left * a + 1 + right;
        }else{
            ans += (left + 1) * a;
        }
        a*=10;
    }
    return ans;
}

int main(){
    cout << counter(999999,3);
}