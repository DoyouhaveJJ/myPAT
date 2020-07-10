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
#define INF 0x3fffffff

typedef long long LL;

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    long double value=0,res = 0;
    for(int i = 1 ; i <= N;++i){
        cin >> value;
        res += value*i*(N-i+1) ;
    }
    printf("%.2Lf\n",res);
    return 0;
}
