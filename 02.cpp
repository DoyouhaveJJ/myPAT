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
const int maxN = 100010;

int main(){
    int N;
    int num[maxN],leftmin[maxN],rightmax[maxN];
    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        cin >> num[i];
    }
    leftmin[0]=0;
    rightmax[N-1]=INF;
    for(int i = 1 ; i < N ;++i){
        leftmin[i] = max(leftmin[i-1],num[i-1]);
    }
    for(int i = N-2 ; i >= 0 ;--i){
        rightmax[i] = min(rightmax[i+1],num[i+1]);
    }
    vector<int> res;
    for(int i = 0 ; i < N ; ++i){
        if(i == 0 && rightmax[i] > num[i]){
            res.push_back(num[i]);
        }else if(i == N-1 && leftmin[i] < num[i]){
            res.push_back(num[i]);
        }else if(num[i] > leftmin[i] && num[i] < rightmax[i]){
            res.push_back(num[i]);
        }
    }
    printf("%lu\n",res.size());
    if(!res.empty()){
        sort(res.begin(),res.end());
        for(int i = 0 ; i < res.size();++i){
            printf("%d",res[i]);
            if(i < res.size()-1){
                printf(" ");
            }
        }
    }
    printf("\n");
    return 0;

}