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
const int maxN = 50;
set<int> st[maxN];
void compare(int a,int b){
    int totalNum = st[b].size() , sameNum = 0;
    for(set<int>::iterator it = st[a].begin();it!=st[a].end();++it){
        //找到了
        if(st[b].find(*it) != st[b].end()){
            sameNum ++;
        }else{
            totalNum++;
        }
    }
    printf("%.1lf%%\n",sameNum*100.0/totalNum);
}


int main(){

    int N,n,num,K,st1,st2;
    scanf("%d",&N);
    for(int i = 0 ; i < N ; ++i){
        scanf("%d",&n);
        for(int j = 0 ; j < n ; ++j){
            scanf("%d",&num);
            st[i].insert(num);
        }
    }
    scanf("%d",&K);
    for(int i = 0 ; i < K ; ++ i){
        scanf("%d %d",&st1,&st2);
        compare(st1-1,st2-1);
    }
}