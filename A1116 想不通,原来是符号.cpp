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
const int maxN = 10010;
bool flag[maxN] = {false};
bool check[maxN] = {false};
int ranks[maxN] = {0};

int main(){
    bool pre[maxN]={false};
    for(int i = 2 ; i < maxN ; ++i){
        if(!pre[i]){
            for(int j = 2*i ; j < maxN ; j+=i){
                pre[j] = true;
            }
        }
    }
    int N;
    cin >> N;
    for(int i = 1 ; i <= N ; ++i){
        int x;
        cin >> x;
        flag[x] = true;
        check[x] = true;
        ranks[x] = i;
    }

    int M;
    cin >> M;
    for(int i = 1 ; i <= M ; ++i){
        int q;
        cin >> q;
        printf("%04d: ",q);
        if(flag[q]){
            if(check[q]){
                check[q] = false;
                if(ranks[q] == 1){
                    cout <<"Mystery Award"<<endl;
                }else if(!pre[ranks[q]]){
                    cout <<"Minion"<<endl;
                }else{
                    cout <<"Chocolate"<<endl;
                }
            }else{
                cout <<"Checked"<<endl;
            }
        }else{
            cout <<"Are you kidding?"<<endl;
        }
    }
}