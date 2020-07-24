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


int counter(int n,int target){
    int ans = 0;
    int a = 1;
    while (n/a!=0){
        int left = n / (10*a);
        int mid = n / a % 10;
        int right = n % a;

        if(mid < target){
            ans += left * a;
        }else if(mid == target){
            ans += left * a + 1 + right;
        }else{
            ans += (left + 1) * a;
        }
        a*=10;
    }
    return ans;
}

int main(){
    cout << counter(999999,3);
}