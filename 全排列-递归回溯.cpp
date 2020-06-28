#include <iostream>
#include <cstring>
#include <algorithm>

#define MaxN 11
int n,P[MaxN],flag[MaxN]={false};
int count = 0;
//对剩余 index～n 进行排列 假设前 1～index-1 已经排列好了
void gP(int index){
    //到了边界 已经排列完了 输出P
    if(index > n){
        //判断是否合法
        count++;
        return;
    }
    //排列
    for(int i = 1 ; i <= n ; i++){
        if(flag[i] == false){

            bool ok = true;

            //检查，如果不满足，就回溯剪枝
            for(int j = 1 ; j < index ; j++){
                if(abs(j-index) == abs(P[j]-i)) {
                    ok = false;
                    break;
                }
            }
            //不可以return
            if(ok){
                P[index] = i;
                flag[i] = true;
                //加入前检查
                gP(index+1);
                flag[i] = false;
            }
        }
    }
}
int main() {
    n=8;
    gP(1);
    printf("%d",count);
}