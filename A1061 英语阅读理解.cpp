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

bool test1(char c){
    if(c >= 'A' && c <= 'N'){
        return true;
    }
    return c >= '0' && c <= '9';


}
bool test2(char c){
    int asc = (int)c;
    if(asc < 65 || asc > 78){
        return false;
    }
    return true;
}

bool test3(char c){
    int asc = (int)c;
    if(asc >= 65 && asc <= 90){
        return true;
    }
    if(asc >= 97 && asc <= 122){
        return true;
    }
    return false;
}

int c2i(char c){
    if(c >= 'A' && c <='N'){
        return c-'A'+10;
    }else{
        return c-'0';
    }


}

string week[8]={"","MON","TUE","WED","THU","FRI","SAT","SUN"};
int main(){
    string s1,s2,s3,s4;
    cin >> s1 >> s2 >> s3 >> s4;
    int len1=s1.length(),len2=s2.length(),len3=s3.length(),len4=s4.length();
    int counter = 0;
    int time1,time2,time3;
    for(int i= 0 ; i < len1 && i < len2 ; ++i){
        if(s1[i]==s2[i] && test2(s1[i]) && counter==0){
            time1=s1[i]-'A'+1;
            counter++;
            continue;
        }
        if(s1[i]==s2[i] && test1(s1[i]) && counter==1){
            time2=c2i(s1[i]);
            break;
        }
    }

    for(int i= 0 ; i < len3 && i < len4 ; ++i){
        if(s3[i]==s4[i] && test3(s3[i])){
            time3=i;
            break;
        }
    }
    cout << week[time1] << " ";
    printf("%02d:%02d",time2,time3);

}
