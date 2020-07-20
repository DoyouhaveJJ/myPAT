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
const int maxN = 1e8;


int main(){
    int N;
    cin >> N;
    unordered_map<string,bool> amap;
    string id;
    string old_a;
    int oldest=99999999;
    for(int i = 0 ; i < N ; ++i){
        cin >> id;
        int age = stoi(id.substr(6,8));
        if(age < oldest){
            oldest = age;
            old_a = id;
        }
        amap[id]=true;
    }
    cin >> N;
    string old_c;
    oldest=99999999;
    int counter = 0;
    for(int i = 0 ; i < N ; ++i){
        cin >> id;
        int age = stoi(id.substr(6,8));
        if(age < oldest){
            oldest = age;
            old_c = id;
        }
        if(amap[id]){
            counter++;
        }
    }
    printf("%d\n",counter);
    if(counter==0){
        cout << old_c;
    }else{
        cout << old_a;
    }

}
