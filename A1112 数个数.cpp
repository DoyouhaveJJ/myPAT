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
bool flag[10000]={false};
bool flag2[10000]={false};
int main(){
    string origin;
    int K;
    cin >> K >> origin;
    int len = origin.length();
    vector<char> list;
    for(int i = 0 ; i < len ; ++i){
        if(!flag[origin[i]]){
            list.push_back(origin[i]);
            flag[origin[i]] = true;
        }
    }
    for(auto it = list.begin();it!=list.end();++it){
        int counter = 0;
        for(int i = 0 ; i < len ; ++i){
            if(origin[i] == *it){
                counter++;
            }else if(counter!=0){
                if(counter % K !=0){
                    flag2[*it] = true;
                }
                counter = 0;
            }
        }
        //处理最后
        if(counter!=0){
            if(counter % K !=0){
                flag2[*it] = true;
            }
        }
    }

    for(auto it = list.begin();it!=list.end();++it){
        if(!flag2[*it]){
            printf("%c",*it);
        }
    }
    printf("\n");
    string ans;

    for(int i = 0 ; i < len ; ++i){
        if(!flag2[origin[i]]){
            i+=(K-1);
        }
        ans += origin[i];
    }
    cout << ans<<endl;
}
