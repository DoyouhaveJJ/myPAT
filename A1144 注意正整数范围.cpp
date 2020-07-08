
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
#define INF 1e9


using namespace std;

const int maxN = 0x3ffffff;

unordered_map<int,bool> mp;
bool num[maxN]={false};
int main(){
    int N,n;
    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        cin >> n;
        if(n >= 0){
            mp[n] = true;
        }
    }

    for(int i = 1 ; i < maxN ; ++i){
        if(!mp[i]){
            cout << i ;
            break;
        }
    }

}