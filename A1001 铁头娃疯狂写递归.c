#include <stdio.h>
void getnext(long,int);
int main() {
    long i = 0;
    long j = 0;
    scanf("%ld %ld",&i,&j);
    long res = i + j;
    //printf("%ld",res);
    if(res == 0){
        printf("0");

        return 0;
    }
    if(res<0) {
        res = -res;
        printf("-");
    }
    getnext(res,1);
    return 0;
}

void getnext(long n,int count){
    if(n == 0){
        return;
    }
    getnext(n/10,count+1);
    if(count%3 == 0 && n >= 10)
        printf(",");
    printf("%ld",(n%10));


}