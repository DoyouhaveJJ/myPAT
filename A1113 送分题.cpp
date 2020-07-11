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
    int seq[100010];
    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        scanf("%d",&seq[i]);
    }
    sort(seq,seq+N);
    int mid = N/2;
    int s1=0,s2=0;
    for(int i = 0 ; i < mid ; ++i){
        s1+=seq[i];
        s2+=seq[mid+i];
    }
    if(N%2==1){
        s2+=seq[N-1];
    }
    printf("%d %d",(N-mid*2),s2-s1);
}