
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

const int maxN = 10010;
const int maxM = 105;
const int maxID = 100000;
unordered_map<int,bool> gMap;
bool vis[maxID] = {false};
int main(){

    int N,M;
    cin >> N>>M;

    for(int i = 0; i < N ; ++i){
        int x,y;
        cin >>x >>y;
        vis[x] = true;
        vis[y] = true;
        gMap[maxID * x + y] = true;
        gMap[maxID * y + x] = true;
    }
    for(int i = 0; i < M ; ++i){
        vector<int> pack;
        int n = 0;
        cin >> n;
        for(int j = 0 ;j<n;++j){
            int id;
            cin >> id;
            pack.push_back(id);
        }
        bool flag=false;
        for(int j = 0 ;j<n;++j){
            if(!vis[pack[j]]){
                continue;
            }
            if(flag)
                break;
            for(int k = j+1 ;k<n;++k){
                if(!vis[pack[k]]){
                    continue;
                }
                if(gMap[pack[j]*maxID + pack[k]]){
                    flag = true;
                    break;
                }
            }
        }
        if(!flag){
            cout << "Yes" << endl;

        }else{
            cout << "No" << endl;
        }
    }
}
