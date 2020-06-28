#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
using  namespace std;

typedef long long LL;
LL gcd(LL a, LL b)
{
    return b == 0 ? abs(a) : gcd(b, a % b);
}

void show(LL a,LL b){
    if(b==0){
        printf("Inf");
        return;
    }
    LL gcdab = gcd(a,b);
    a/=gcdab;
    b/=gcdab;
    if(b<0){
        a=-a;
        b=-b;
    }
    LL i = a/b;
    a = a%b;
    if(a<0 || i < 0){
        printf("(");
        if(i==0&&a==0){
            printf("0");
        }
        else if(i==0){
            printf("%lld/%lld",a,b);
        }else if(a==0){
            printf("%lld",i);
        }else{
            printf("%lld %lld/%lld",i,abs(a),abs(b));
        }
        printf(")");
    }
    else{
        if(i==0&&a==0){
            printf("0");
        }
        else if(i==0){
            printf("%lld/%lld",a,b);
        }else if(a==0){
            printf("%lld",i);
        }else{
            printf("%lld %lld/%lld",i,a,b);
        }
    }



}


int main() {
   LL a1,a2,b1,b2;
   scanf("%lld/%lld %lld/%lld",&a1,&a2,&b1,&b2);
   LL res1,res2;
   LL gcdab = gcd(a2,b2);
   res1 = (b2/gcdab)*a1 + (a2/gcdab)*b1;
    res2 = (b2/gcdab)*a2;
    show(a1,a2);
    printf(" + ");
    show(b1,b2);
    printf(" = ");
    show(res1,res2);
    printf("\n");

    res1 = (b2/gcdab)*a1 - (a2/gcdab)*b1;
    res2 = (b2/gcdab)*a2;
    show(a1,a2);
    printf(" - ");
    show(b1,b2);
    printf(" = ");
    show(res1,res2);
    printf("\n");

    res1 = a1*b1;
    res2 = a2*b2;
    show(a1,a2);
    printf(" * ");
    show(b1,b2);
    printf(" = ");
    show(res1,res2);
    printf("\n");

    res1 = a1*b2;
    res2 = a2*b1;
    show(a1,a2);
    printf(" / ");
    show(b1,b2);
    printf(" = ");
    show(res1,res2);
    printf("\n");
}