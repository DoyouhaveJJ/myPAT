#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <string>

#include <iostream>

using namespace std;

struct Result{
    int id;
    int rank;
    int resultRank;
}result[1001];

bool cmp(Result a, Result b){
    return a.rank>b.rank;
}

int main() {
    int Np,Ng,Mice[1000],id,Rank[1000]={0};
    scanf("%d %d",&Np,&Ng);
    for(int i = 0 ; i < Np ; ++i){
        scanf("%d",&Mice[i]);
    }
    queue<int> Q;
    for(int i = 0 ; i < Np ; ++i){
        scanf("%d",&id);
        Q.push(id);
    }

    int Ranknow= 0;
    while (Q.size()>1){
        int size = Q.size();
        int truns = (size/Ng) + (size%Ng==0?0:1);

        for(int i = 0 ; i < truns && !Q.empty(); ++i){
            int max=-1,winner=0;
            for(int j = 0 ; j < Ng && !Q.empty() && Ranknow == Rank[Q.front()]; ++j){
                if(Mice[Q.front()] > max){
                    max = Mice[Q.front()];
                    winner = Q.front();
                }
                Q.pop();
            }
            Rank[winner]++;
            Q.push(winner);
        }
        Ranknow++;
    }

    for(int i = 0 ; i < Np ; ++i){
        result[i].id = i;
        result[i].rank = Rank[i];
    }

    sort(result,result+Np,cmp);
    result[0].resultRank = 1;
    Rank[result[0].id]=1;
    for(int i = 1 ; i < Np ; ++i){
        if(result[i].rank == result[i-1].rank){
            result[i].resultRank = result[i-1].resultRank;
        }else{
            result[i].resultRank = i+1;
        }
        Rank[result[i].id]=result[i].resultRank;
    }
    for(int i = 0 ; i < Np ; ++i){

        printf("%d",Rank[i]);
        if(i != Np-1){
            printf(" ");
        }
    }





}