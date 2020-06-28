#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>
#include <iostream>
#include <queue>

using namespace std;
const int maxN = 10010;
const int maxC = 10;

bool cmp(string a,string b){
    //这里体现了贪心的思想，局部使得字符串最小
    return a+b < b+a;
}

int main(){
    int N;
    string str[maxN];
    scanf("%d",&N);
    for(int i=0;i<N;++i){
        cin >> str[i];
    }
    sort(str,str + N,cmp);
    string ans;
    for(int i=0;i<N;++i){
       ans += str[i];
    }
    //去掉0
    while (!ans.empty() && ans[0]=='0'){
        ans.erase(ans.begin());
    }
    if(ans.empty()) printf("0");
    else
        cout << ans;


}
