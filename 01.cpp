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

string low[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13] = {"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
int findlowindex(string s){
    for(int i = 0 ; i < 13 ; ++i){
        if(s==low[i]){
            return i;
        }
    }
    return 0;
}
int findhighindex(string s){
    for(int i = 0 ; i < 13 ; ++i){
        if(s==high[i]){
            return i;
        }
    }
    return 0;
}
void trans(string word,string &res){
    if(isdigit(word[0])){
        int num = stoi(word);
        int lownum = num % 13;
        int highnum = num / 13;
        res ="";
        res += high[highnum];
        if(highnum!=0){
            res += " ";
        }
        res +=low[lownum];
        cout<<res << endl;

    }else{
        int findspace = word.find(' '),len=word.length();
        int len1 = findspace;
        int len2 = len - findspace-1;
        string word1 = word.substr(0,len1);
        string word2 = word.substr(findspace+1,len2);
        int highnum = findhighindex(word1);
        int lownum = findlowindex(word2);
        cout << highnum*13+lownum << endl;

    }
}

int main(){
    int N;
    cin >> N;
    string word;
    getchar();
    string res;
    for(int i = 0 ; i < N ; ++i){
        getline(cin,word);
        trans(word,res);
    }
}