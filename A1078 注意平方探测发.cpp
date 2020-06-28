#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
using  namespace std;

const int maxN = 10010;

bool flag[maxN]{false};
bool visited[maxN]={false};

void init(){
    flag[1] = true;
    for(int i = 2;i<maxN;++i){
        if(!flag[i]){
            for(int j = 2*i; j < maxN ; j+=i){
                flag[j] = true;//true = 不是素数
            }
        }
    }
}
int findMax(int i){
    int j = 0;
    for(j = i ; j < maxN ; ++j){
        if(!flag[j]){
            break;
        }
    }
    return j;
}

int main(){
    init();
    int M,N,num[maxN];
    scanf("%d %d",&M,&N);
    M = findMax(M);
    for(int i  = 0 ; i < N ; ++i){
        scanf("%d",&num[i]);
    }
    for(int i  = 0 ; i < N ; ++i){
        if(!visited[num[i]%M]){
            printf("%d",num[i]%M);
            visited[num[i]%M]=true;
        }else{
            //发生冲突
            int step = 1;
            for(step = 1 ; step < M ; step++){
                if(!visited[(step*step+num[i])%M]) {
                    printf("%d", (step*step+num[i])%M);
                    visited[(step*step+num[i])%M] = true;
                    break;
                }
            }
            if(step == M){
                printf("-");
            }

        }
        if(i != N -1){
            printf(" ");
        }
    }
}