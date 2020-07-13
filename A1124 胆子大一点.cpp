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

unordered_map<string,bool> mp;
string list[1010];
int main(){
    int M,N,S;
    cin >> M >> N >> S;
    for(int i = 1 ; i <= M ; ++i){
        cin >> list[i];
        mp[list[i]] = true;
    }
    int counter = 0;
    for(int i = S ; i <= M ;){
        if(mp[list[i]]){
            cout << list[i] << endl;
            mp[list[i]] = false;
            i+=N;
            counter++;
        }else{
            i++;
        }
    }
    if(counter==0){
        cout << "Keep going..."<<endl;
    }
}