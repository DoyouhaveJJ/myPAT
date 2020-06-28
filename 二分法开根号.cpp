#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
//精度
const double eps = 1e-5;

double f(double a){
    return a*a;
    //其实f函数就是方程，用二分查找的思想求根，要指明精度即可
}
double calcSqrt(double num){
    double left = 0,right = num,mid;
    while (right - left > eps){
        mid = (right + left)/2;
        if(f(mid) > num){
            right = mid;
        }else{
            left = mid;
        }
    }
    return (right + left)/2;

}



int main() {
    double N ;
    scanf("%lf",&N);
    printf("%.2lf",calcSqrt(N));

}



#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
//精度
int A[3]={10,24,15};
int f(int a){
    int sum = 0;
    for(int i : A){
        sum += i/a;
    }
    return sum;
}
int calcSqrt(int num){
    int left = 1,right = 9999,mid;
    while (left < right){
        mid = (right + left)/2;
        if(f(mid) < num){
            right = mid;
        }else{
            left = mid+1;
        }
    }
    return mid;

}



int main() {

    int K;
    scanf("%d",&K);
    printf("%d",calcSqrt(K));

}