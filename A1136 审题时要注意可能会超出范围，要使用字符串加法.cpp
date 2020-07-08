
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
string add(string s1,string s2){
    int carry = 0;
    string res;
    for(int i = s1.length()-1 ; i>=0;--i){

        int num = ( (s1[i]-'0') + ((s2[i]-'0')) + carry) % 10;
        carry =((s1[i]-'0') + ((s2[i]-'0')) + carry)/10;
        res = to_string(num) + res;
    }
    if(carry != 0){
        res = "1" + res;
    }
    return res;
}


bool judge(string a){
    string b = a;
    reverse(b.begin(),b.end());
    return a==b;
}


int main(){
    string N;
    cin >> N;
    judge(N);
    string a = N;
    int i = 0;
    for(; i < 10 ; ++i){
        if(judge(a)){
            break;
        }
        else{
            string b = a;
            reverse(a.begin(),a.end());

            cout << b << " + " << a ;
            a = (add(a,b));
            cout << " = " << a << endl;
        }

    }
    if(i < 10){
        cout << a << " is a palindromic number.";
    } else{
        cout <<"Not found in 10 iterations.";
    }



}