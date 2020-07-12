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

int calc(string n){
    int res = 0;
    for(auto it = n.begin() ; it!=n.end();++it){
        res += *it-'0';
    }
    return res;
}
int counter[10000]={0};
int main(){
    int N;
    set<int> ids;
    cin >> N;
    for(int i  = 0 ; i < N ; ++i){
        string num;
        cin >> num;
        int res = calc(num);
        ids.insert(res);
    }
    printf("%lu\n",ids.size());
    int i = 0;
    int len =ids.size();
    for(auto it = ids.begin();it!=ids.end();++it){
        printf("%d",*it);
        if(i<len-1){
            printf(" ");
        }
        i++;
    }

}
