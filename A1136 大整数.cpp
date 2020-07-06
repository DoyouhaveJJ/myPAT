
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
struct bign{
    int num[2000];
    int len;
};

bign add(){

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
            long long  aa = stoi(a);
            long long  bb = stoi(b);
            a = to_string(aa+bb);
            cout << " = " << a << endl;
        }

    }
    if(i < 10){
        cout << a << " is a palindromic number.";
    } else{
        cout <<"Not found in 10 iterations.";
    }



}