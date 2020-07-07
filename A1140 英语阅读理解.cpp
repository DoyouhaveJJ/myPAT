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


int main(){
    string s;
    int N;
    cin >> s >> N;
    string next = s;
    for(int i = 0 ; i < N-1; ++i){
        int len = next.length();
        string temp = "";
        int count = 1;
        char now = next[0];
        for(int j = 1 ; j < len ; ++j){
            if(next[j] != now){
                temp += now;
                temp += ( '0' + count);
                count = 1;
                now = next[j];
            }else{
                count ++;
            }
        }
        temp += now;
        temp += ( '0' + count);
        next = temp;
    }
    cout << next;
}