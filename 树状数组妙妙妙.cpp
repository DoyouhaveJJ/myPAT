
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
#define INF 1e9


using namespace std;

//树状数组，
//lastmin相当于找最右边的 一个1和后面的连续0
//例如 12 : 1100 -> 1[100] -> [100]  因为-12 12是补码存储的，负的相当于取反末尾+1。
//+1必然会进位或者不进位，如果进位了，那么会导致0->1 1->0 相当于又取反了。 反反就相当于没反
//那就得了，反正自己算去吧 憨批
//性质就是 这个数一定是2的幂，且是最大的，能被x整除的幂次。
//于是就为了树状数字提供了条件
//例如数组 A[] (1~1000) 必须是1开始编号
//树状数组用于计算前n个和
//树状数组用于计算前n个和
//树状数组用于计算前n个和
//树状数组用于计算前n个和

//新建一个数组C(1~1000) 保存的是 k的前lownum(k)项和

//例如C[12] ， 里面存的是 A[9] A[10] A[11] A[12] 的和！ (lownum(12) = 4)
//那么要计算   前12个数字的和？ 可以C[12] + C[8] + C[0] 因为C[12] = A[9] A[10] A[11] A[12]
//                                                     C[8] = A[8] ~ A[1]
//                                                     C[0]  = 0
//如何找12 8 0? 只需要x - lowcase(x) 即可

//其实就是减去了 最右边的1，使得 12 ->( 1100 - 100 ) -> 1000 = 8
// 100 + 1000 = 12 于是就覆盖到了所有的前12

int C[1000],A[1000];
int lownum(int x){
    return (x) & (-x);
}
int getSum(int x){
    int res = 0;
    for(int i = x ; i > 0  ; i = i - lownum(i) ){
        res += C[i];
    }
    return res;
}

//当A 的数字变化时，C中也要变化，那么如何找到A[i]影响了哪些C?
//可以知道， 如果要被A[i] 影响，那么C[j] 的lownum[j]一定要大于lownum[i] 否则无法包含
//又因为要保证lownum[j] > lownum[i] 在二进制来看，j的最右1000要大于i的最右100
//且要遍历到所有的j，因此 i的增量要尽可能小！ 因此增量只能选 100 ，能够保证进位，100 + 100 = 1000
//使得原来的范围变大，因此 增量就可以选自己的lownum(i)，必然能增大范围。
//更新12号数字
// 12 : 1100 += 100 -> 10000(16) (C[16]是包含A[12]的)
// 16 : 100000 + 10000 ->100000(32) (C[32]也是包含A[12]的) 同样要更新（因为C[32]包含C[16]）
//开始套娃

void update(int loc , int addnum){
    for(int i = loc ; i <= 1000  ; i = i + lownum(i) ){
        C[i] += addnum;
    }
}


int main(){
   cout << lownum(12);


}