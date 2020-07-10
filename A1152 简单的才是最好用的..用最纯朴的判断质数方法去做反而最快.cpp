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


//不是质数
using namespace std;
bool isPrime(LL a){
    if(a==1){
        return true;
    }
    if(a==2){
        return true;
    }
    for(LL i = 2 ; i*i < a;++i){
        if(a%i==0){
            return false;
        }
    }
    return true;
}
int main(){
    int N,M;
    bool flag = false;
    string num;
    cin >> N >> M;
    cin >> num;
    for(int i = 0 ; i < N-M+1 ; ++i){
        string temp = (num.substr(i,M));
        int number = stoi(temp);
        if(isPrime(number)){
            flag = true;
            cout << temp;
            break;
        }
    }
    if(!flag){
        cout <<"404";
    }
}