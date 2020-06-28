#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
const int N = 3;
char S[4] = {'W','T','L'};
int findMax(double A[]){
    int max = 0;
    for(int i = 0 ; i < N ; ++i){
        if(A[i]>A[max]){
            max = i;
        }
    }
    return max;
}
int main(){
    double input[3];
    int max;
    int i=0;
    double sum=1;
    while (i<N){
        scanf("%lf %lf %lf",&input[0],&input[1],&input[2]);
        max = findMax(input);
        sum*=input[max];
        printf("%c ",S[max]);
        ++i;
    }
    printf("%.2lf",(sum*0.65-1)*2);
}


