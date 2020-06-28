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
    int N,num[maxN],loc[maxN];
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        scanf("%d",&num[i]);
        loc[num[i]] = i;
    }
    int ans = 0;
    int temp = 0;
    //总是用数字最小的去交换
    //只交换0!!
    //检查每一个元素的位置
    for(int i = 0 ; i < N ;++i){
        if(loc[i]==i){
            continue;
        }else{
            temp = loc[loc[i]];
            loc[loc[i]] = loc[0];
            loc[0] = temp;
            ans++;
        }
        while (loc[0] != 0){
            temp = loc[loc[0]];
            loc[loc[0]] = loc[0];
            loc[0] = temp;
            ans++;
        }
    }
    printf("%d",ans);

}
