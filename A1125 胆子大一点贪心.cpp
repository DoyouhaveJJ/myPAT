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
double list[10010];
int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        cin >> list[i];
    }
    sort(list,list+N);
    for(int i = 1 ; i < N ; ++i){
        list[i] = (list[i]+list[i-1])/2;
    }

    int last = floor(list[N-1]);
    printf("%d",last);
}