#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <string>

#include <iostream>

using  namespace std;

string low[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
map<string,int> lowMap;
map<string,int> highMap;
void trans(string a){
    //是数字，变为数字
    if(a[0] >='0' && a[0]<='9'){
        int num = 0;
        for(string::iterator it = a.begin() ; it!=a.end();it++){
            num = num*10 + ((*it)-'0');
        }
        if(num == 0 ){
            printf("tret");
            return;
        }
        cout << high[num / 13] << ((num / 13==0 || num%13 == 0)?"":" ") << ((num%13 == 0)?"":low[num%13])<<endl;
    }else{
        int loc = a.find(' ');
        if(loc == -1){
            cout << 13*highMap[a]+lowMap[a]<<endl;
        }else{
            string as =a.substr(0,loc);
            string as2 = a.substr(loc+1,a.size());
            cout << 13*highMap[as]+lowMap[as2]<<endl;
        }


    }
}


int main(){
    int N;
    string num;

    scanf("%d",&N);
    for(int i = 0 ; i < 13;++i){
        lowMap[low[i]] = i;
        highMap[high[i]] = i;
    }
    getchar();
    for(int i = 0 ; i < N ; ++i){
        getline(cin,num);
        trans(num);
    }
}