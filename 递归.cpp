#include <string>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>
#include <iostream>


using namespace std;

const int maxn =30;
int maxN,maxW,maxV;
int W[maxn],V[maxn];
//没有剪枝的//相当于遍历所有的情况
void DFS(int index,int sumW , int sumV){
    //到了死胡同
    if(index == maxN){
        //如果当前分配最优，那么就更新
        if(sumW <= maxW && sumV > maxV){
            maxV = sumV;
        }
        return;
    }else{
        //岔路1：加入index物品
        DFS(index+1,sumW+W[index],sumV+V[index]);
        //岔路2：不加入index物品
        DFS(index+1,sumW,sumV);
    }
}
//上述缺点，只有在所有物品都判断完后才更新最大价值。

//剪枝 在进入岔路前要判断，保证容量必然足够
void Cut_DFS(int index,int sumW , int sumV){
    //到了死胡同
    if(index == maxN){
        //到底了 完成
        return;
    }else{
        //岔路2：不加入index物品
        DFS(index+1,sumW,sumV);
        //剪枝判断,如果这次加入不会超重，就加入这个物品
        if(sumW+W[index] <= maxW){
            //加入后价值变大，立即更新价值
            if(sumV + V[index] > maxV){
                maxV = sumV+V[index];
            }
            DFS(index+1,sumW+W[index],sumV+V[index]);
        }
    }
}
int main(){


}