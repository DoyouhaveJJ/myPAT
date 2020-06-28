#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>

int main(){
    long long N;
    scanf("%ld",&N);
    double value=0,res = 0;
    for(long long i = 1 ; i <= N;++i){
        scanf("%lf",&value);
        res += (N-i+1)*i*value;
    }
    printf("%.2lf",res);
    return 0;
}
