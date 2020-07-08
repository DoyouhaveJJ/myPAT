
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
const int maxN = 1005;
int inP[maxN]={0};
vector<int> Adj[maxN];
void copyS(int a[],int b[]){
    for(int i = 0 ; i < maxN ; ++i){
        b[i] = a[i];
    }

}


int main(){
    int N,M;
    cin >>N >> M;
    for(int i = 0 ; i < M ; ++i){
        int x,y;
        cin >> x >>y;
        //入度
        Adj[x].push_back(y);
        inP[y]++;
    }

    int Q;
    cin >>Q;
    vector<int> res;

    int temp[maxN];
    for(int q = 0 ; q < Q ; ++q){

        copyS(inP,temp);
        vector<int> query;
        int now,num = N;
        for(int i = 0 ; i < N ; ++i){
            cin >> now;
            query.push_back(now);
        }


        for(int i = 0 ; i < query.size() ; ++i){
            now = query[i];
            if(temp[now] == 0 ){
                num--;
                for(int j = 0 ; j < Adj[now].size();++j){
                    temp[Adj[now][j]]--;
                }
            }else{
                break;
            }
        }
        if(num > 0){
            res.push_back(q);
        }


    }

    for(int i = 0 ; i < res.size(); ++i){
        cout << res[i];
        if(i <res.size()-1)
            cout << " ";
    }


}