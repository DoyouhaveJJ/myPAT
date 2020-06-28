#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>
#include <iostream>

const int maxCoin = 100010;
int Coins[maxCoin];
using namespace std;




int main(){
    int N,M,a,b;
    bool flag=false;
    int index;
    scanf("%d %d",&N,&M);
    for(int i=0 ;i<N;++i){
        scanf("%d",&index);
        Coins[index]++;
    }
    for(int i = 0 ; i <= M/2;++i){
        if(flag){
            break;
        }
        if(Coins[i] && Coins[M-i]){
            if(i != M-i){
                a = i;
                b = M - i;
                flag = true;
            }else if(Coins[i]>1){
                a = i;
                b = M - i;
                flag = true;
            }
        }
    }
    if(flag){
        printf("%d %d",a,b);
    }else{
        printf("No Solution");
    }


}