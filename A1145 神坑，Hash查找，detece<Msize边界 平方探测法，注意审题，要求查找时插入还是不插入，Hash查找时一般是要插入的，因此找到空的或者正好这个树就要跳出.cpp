
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
const int maxN = 10010;

//是 非质数
bool pre[maxN] = {false};

void init(){
    for(int i = 2 ; i < maxN ; ++i){
        if(!pre[i]){
            for(int j = 2*i ; j < maxN ; j+=i){
                pre[j] = true;
            }
        }
    }
}

int find(int s){
    if(!pre[s]){
        return s;
    }else{
        for(int i = s+1 ; i < maxN;++i){
            if(!pre[i]){
                return i;
            }
        }
    }
    return s;
}

int HashTable[maxN];
bool flag[maxN]={false};

int findNum(int num,int MSize){
    int detect = 0;
    int counter = 1;
    int index = num % MSize;
    while(detect < MSize){
        if(!flag[index] || HashTable[index]==num){
            break;
        }else{
            detect++;
            index = (num + detect*detect) % MSize;

        }
        counter++;
    }
    return counter;
}


bool insert(int num,int MSize){
    int detect = 0;
    int index = num % MSize;
    while(detect < MSize){
        if(!flag[index]){
            HashTable[index] = num;
            flag[index] = true;
            return true;
        }else{
            detect++;
            index = (num + detect*detect)%MSize;

        }
    }
    return false;
}
int main(){
    init();

    int MSize,N,M;
    cin >> MSize >> N >> M;

    MSize = find(MSize);
    int num;
    for(int i = 0 ; i < N ; ++i){
        cin >> num;
        if(!insert(num,MSize)){
            printf("%d cannot be inserted.\n",num);
        }
    }
    int counter = 0;
    for(int i = 0 ; i < M ; ++i){
        cin >> num;
        counter += findNum(num,MSize);
    }
    printf("%.1lf\n",(1.0*counter)/M);

}