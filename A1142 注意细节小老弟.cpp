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

int edge[210][210] = {0};
int Nv , Ne;
bool judge(vector<int> query){
    for(auto it = query.begin();it!=query.end();++it){
        for(auto jt = query.begin();jt!=query.end();++jt){
            if(*it == *jt){
                continue;
            }else{
                if(edge[*it][*jt] == 0){
                    return false;
                }
            }
        }
    }
    return true;
}
bool isNow[210] = {false};
bool isMax(vector<int> query){

    for(int i = 1 ; i <= Nv ; ++i){
        if(isNow[i]){
            continue;
        }
        bool flag = true;
        for(auto it = query.begin();it!=query.end();++it){
            if(edge[i][*it]==0){
                flag = false;
            }
        }

        if(flag){
            return false;
        }
    }
    return true;

}

int main(){

    cin >> Nv >> Ne;
    for(int i = 0 ; i < Ne ; ++i){
        int x,y;
        cin >> x >> y;
        edge[x][y] = 1;
        edge[y][x] = 1;
    }

    int Q;
    cin >> Q;
    for(int i = 0 ; i < Q; ++i){
        int n,k;
        cin >> n;
        vector<int> query;
        memset(isNow,false, sizeof(isNow));
        for(int j = 0 ; j < n ; ++j){
            cin >> k;
            isNow[k] = true;
            query.push_back(k);
        }
        bool flag1 = judge(query),flag2 = isMax(query);
        if(flag1){
            if(flag2){
                cout << "Yes" << endl;
                continue;
            }else{
                cout << "Not Maximal" << endl;
            }
        }else{
            cout << "Not a Clique" << endl;
        }
    }
}