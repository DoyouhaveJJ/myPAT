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

bool judge(string a){

    if(a.length() == 0){
        return false;
    }
    //去除后面的0

    //找小数点1
    if(a[0] == '-'){
        a.erase(a.begin());
    }
    int countdot = 0,len=a.length();
    int dotindex=len;


    for(int i =0;i < len ;++i){
        if(a[i] == '.'){
            countdot++;
            dotindex =i;
            continue;
        }
        if(!isdigit(a[i]))
            return false;

    }
    if(countdot > 1){
        return false;
    }
    int last = dotindex;
    //找小数点最后以为非0
    if(countdot == 1){

        for(int i = dotindex+1 ; i < len ; ++i){
            if(a[i] != '0'){
                last = i;
            }
        }
        if(last - dotindex > 2){
            return false;
        }
    }
    if(last > 5){
        return false;
    }

    return abs(stoi(a)) <= 1000;
}
int main()
{
    int N;
    cin >> N;
    string S[101];
    bool res[101]={false};
    for(int i = 0 ; i < N; ++i){
        cin >> S[i];
        res[i] = judge(S[i]);
    }
    int counter = 0;
    double sum=0;
    for(int i = 0 ; i < N; ++i){
        if(res[i]){
            sum += stod(S[i]);
            counter++;
        }else{
            cout << "ERROR: "<<S[i]<<" is not a legal number"<<endl;
        }
    }
    if(counter == 0){
        cout << "The average of 0 numbers is Undefined";
    }else if(counter==1){
        printf("The average of 1 number is %.2lf",sum);
    }else{
        printf("The average of %d numbers is %.2lf",counter,sum/counter);
    }



}