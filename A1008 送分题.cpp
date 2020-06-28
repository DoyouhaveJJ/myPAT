#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>

int main(){
    int N,next;
    scanf("%d",&N);
    int now = 0;
    int time=0;
    for(int i = 0 ; i<N;++i){
        scanf("%d",&next);
        if(next > now){
            time += (next-now)*6;
        }else{
            time += (now-next)*4;
        }
        now = next;
    }
    time += 5*N;
    printf("%d",time);
}
