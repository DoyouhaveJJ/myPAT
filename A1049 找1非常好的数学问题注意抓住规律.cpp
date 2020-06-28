#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
using  namespace std;

//数1
//计算1～10的1的个数



int main(){
    int N,a=1,ans=0;
    int left,now,right;
    scanf("%d",&N);
    int count = 1;
    while (N/a != 0){
        //将数字分成三部分
        left = N / (10*a);
        now = N / a % 10;
        right = N % a;

        //当前数字为0，能出现1的是左边全部 乘以 （每一种都是1）右边的所有情况
        if(now == 0){
            ans += left * a;
        }
        //当前数字为1，还要加上自己的情况
        else if(now == 1){
            ans += left * a + right + 1;
        }
        //当前大于1 ， 那么低位right可以取遍 0000 ～ 9999
        else{
            ans += (left + 1) * a;
        }



        a*=10;

    }
    printf("%d",ans);

}
