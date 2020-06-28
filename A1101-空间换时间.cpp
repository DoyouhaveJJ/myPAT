#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#define MAX 1e9;
int main(){
    int N,i=0,A[100010],count=0;
    int leftMax[100010],rightMin[100010],result[100010];
    scanf("%d",&N);
    while (i<N){
        scanf("%d",&A[i++]);
    }
    int Max=-1;
    leftMax[0]=-1;
    for(i=1;i<N;i++){
        if(A[i-1]>Max){
            Max = A[i-1];
        }
        leftMax[i] = Max;
    }
    int Min = MAX;
    rightMin[N-1]=MAX;
    for(i = N-2 ; i >= 0; i--){
        if(A[i+1]<Min){
            Min = A[i+1];
        }
        rightMin[i] = Min;
    }
    for(i=0;i<N;i++){
        if(!(A[i]>leftMax[i] && A[i]<rightMin[i])){
            continue;
        }
        result[count++] = A[i];
    }
    if(count == 0){
        printf("%d\n",count);

        printf("\n");
        return 0;
    }
    printf("%d\n%d",count,result[0]);
    for(i = 1 ; i < count ; i++){
        printf(" %d",result[i]);
    }

    printf("\n");
    return 0;

}