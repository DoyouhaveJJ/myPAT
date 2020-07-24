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


const int maxN = 100010;
const int sqrN = 316;

int block[sqrN];//第N块所有元素的个数 //第i块存储 [ i*316 , (i+1)*316 - 1 ] 号元素
int table[maxN];//第i个数字的个数
//找第K大的元素
int peekMid(int K){
    //枚举所有块
    int sum = 0,idB=0,inNum=0;
    while (sum + block[idB] < K){
        //当数量超过K时，表示要找的那个数在当前加的块中。
        sum += block[idB++];
    }
    inNum = idB * sqrN; //当前块负责的元素的起始元素。（其实这里的元素是作为下标来使用的）
    while (sum + table[inNum] < K){
        //当数量超过K时，表示要找的那个数就是这个数，因为table保存的是元素个数。
        sum += table[inNum++];
    }
    return inNum;
}
//插入x元素 处理block和table即可
void push(int x){
    //找到当前元素所在的块 为 x/sqrN;
    block[x/sqrN] ++;
    table[x] ++;
}

void pop(int x){
    block[x/sqrN] --;
    table[x] --;
}
