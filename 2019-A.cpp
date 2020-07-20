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
#define INF 1000000000
typedef long long LL;
using namespace std;
const int maxN = 1e8;

bool isPrim(int n){
    if(n<0)
        n=-n;
    if(n==1){
        return false;
    }
    for(int i = 2 ; i*i<=n;++i){
        if(n % i ==0){
            return false;
        }
    }
    return true;

}

bool isSexy(int n){
    return (isPrim(n) && isPrim(n - 6)) || (isPrim(n)&&isPrim(n + 6));
}
int main(){
    int N;
    cin >> N;
    if(isSexy(N)){
        printf("Yes\n");
        if(isPrim(N-6)){
            printf("%d",N-6);
        }else if(isPrim(N+6)){
            printf("%d",N+6);
        }
    }else{
        printf("No\n");
        for(int i = N+1 ; i <=maxN ; ++i ){
            if(isSexy(i)){
                printf("%d",i);
                break;
            }
        }
    }


}