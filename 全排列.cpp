#include <iostream>
#include <cstring>
#include <algorithm>

#define MaxN 11
int n,P[MaxN],flag[MaxN]={false};
int count = 0;
//对剩余 index～n 进行排列
void gP(int index){
    //到了边界 已经排列完了 输出P
    if(index > n){
        //判断是否合法
        bool ok = true;
        for(int j = 1 ; j <= n ; j ++){
            for(int k = j + 1 ; k < n ; k ++){
                if(j*P[j] == k*P[k]){
                    ok = false;
                }
            }
        }
        if(ok)
            count++;
        return;
    }
    //排列
    for(int i = 1 ; i <= n ; i++){
        if(flag[i] == false){
            flag[i] = true;
            P[index] = i;
            gP(index+1);
            flag[i] = false;
        }
    }
}
int main() {
    n=3;
    gP(1);
}