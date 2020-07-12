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
bool havecp[100005]={false};
int cp[100005];
bool present[100005];

bool cmp(int a,int b){
    return a<b;
}
int main(){
    int N;
    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        int x,y;
        cin >> x >>y;
        cp[x]=y;
        cp[y]=x;
        havecp[x] = true;
        havecp[y] = true;
    }
    int M;
    cin >> M;
    vector<int> all(M),dsg;
    for(int i = 0 ; i < M ; ++i){
        cin >> all[i];
        present[all[i]]=true;
    }

    for(auto it = all.begin();it != all.end();++it){
        if(havecp[*it]){
            if(!present[cp[*it]]){
                dsg.push_back(*it);
            }
        }else{
            dsg.push_back(*it);
        }
    }
    sort(dsg.begin(),dsg.end(),cmp);
    printf("%d\n",dsg.size());
    for(int i = 0 ; i < dsg.size();++i){
        printf("%05d",dsg[i]);
        if(i < dsg.size()-1){
            printf(" ");
        }
    }

}
