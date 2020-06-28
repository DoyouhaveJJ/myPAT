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
bool check(char a){
    if(a >= 'A' && a<= 'Z') return true;
    if(a >= 'a' && a<= 'z') return true;
    if(a >= '0' && a<= '9') return true;
    return false;
}
int main(){
    map<string,int> count;
    string str;
    getline(cin,str);
    int i = 0;
    while (i < str.length()){
        string word;
        //只保留数字和单词
        while(i < str.length() && check(str[i])){
            //大写变小写
            if(str[i] >='A' && str[i] <='Z'){
                str[i]+=32;
            }
            word += str[i];
            i++;
        }
        //如果这个单词是空的，那么意味着下面可能会有空的
        if(word!=""){
            if(count.find(word)==count.end()){
                count[word] = 1;
            }else{
                count[word] ++;
            }
            while (i < str.length() && !check(str[i])){
                i++; //跳过非单词部分
            }
        }
    }
    int max;
    string maxW;
    for(auto it = count.begin();it!=count.end();++it){
        if(it->second>max){
            max = it->second;
            maxW = it->first;
        }else if(it->second == max){
            if(maxW > it->first){
                max = it->second;
                maxW = it->first;
            }
        }
    }
    cout << maxW << " "<<max<<endl;
}