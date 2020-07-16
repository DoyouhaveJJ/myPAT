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
    string num;
    cin >> num;
    bool positive = num[0] == '+';
    num.erase(num.begin());
    int indexE=0,indexP=0,len=num.length();
    for(int i = 0 ; i < len ; ++i ){
        if(num[i]=='.'){
            indexP=i;
        }
        if(num[i]=='E'){
            indexE=i;
        }
    }
    int exp = stoi(num.substr(indexE+1,len-indexE));
    num = num.substr(0,indexE);
    num.erase(num.begin()+indexP);
    string res;
    if(exp < 0){
        string temp = "0.";
        for(int i = 1 ; i < -exp ; ++i){
            temp+="0";
        }
        res = temp + num;
    }else{
        len = num.length();
        int more = exp-len+1;
        if(more < 0){
            res = num.substr(0,exp+1)+"."+num.substr(exp+1,len);
        }
        else{
            for(int i = 0 ; i < more ; ++i){
                res+="0";
            }
            res = num+res;
        }

    }
    if(!positive){
        cout <<"-";
    }
    cout << res;
    return 0;

}
