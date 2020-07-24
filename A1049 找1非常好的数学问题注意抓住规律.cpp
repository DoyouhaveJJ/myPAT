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
    //主要思路，枚举每一位， 计算该位可能出现1的个数
    //抓住规律。当枚举到某一位时，判断该位的值。
    //要保证所有讨论的数均不超过这个数
    //如果该位为0，那么left 只能当left取遍 0~n-1(共n个) right就可以能取遍0～99..999 共a个。 那么当枚举到这位时
    //就能取 left * a 个

    //如果该位为1，那么left 只取到 0 ~ n-1 同理。 特别的，当left=n时，需要额外加上+1（自己本身） 再加上right
    //即 30715 当枚举到第四位1时 是什么个情况呢 left:0~306同上，当left=307时， 只能有30710,30711...只能有30715
    //即为 left * a + right + 1

    //如果该位大于1 那么left可以取遍 0~307 因为该位定死位1了，那就可以全部取而不会超过最大值。
    //即为 (left+1) * a
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
