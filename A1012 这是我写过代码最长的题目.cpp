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
struct Score{
    int C,M,E,A;
    int id;
}scores[1000000];
struct Rank{
    int rankC;
    int rankM;
    int rankE;
    int rankA;
}ranks[1000000];

int getPri(char A){
    if(A=='A'){
        return 5;
    }
    if(A=='C'){
        return 4;
    }
    if(A=='M'){
        return 3;
    }
    if(A=='E'){
        return 2;
    }
}
struct Result {
    char A;
    int rank;
    Result(char a, int arank) {
        A = a;
        rank = arank;
    }
};
bool cmp(Result &a,Result &b){
    if(a.rank != b.rank){
        return a.rank < b.rank;
    }else{
        return getPri(a.A) > getPri(b.A);
    }
}

using namespace std;
bool cmpC(Score &a,Score &b){
    if(a.C != b.C){
        return a.C > b.C;
    }else{
        return a.id < b.id;
    }
}
bool cmpM(Score &a,Score &b){
    if(a.M != b.M){
        return a.M > b.M;
    }else{
        return a.id < b.id;
    }
}
bool cmpE(Score &a,Score &b){
    if(a.E != b.E){
        return a.E > b.E;
    }else{
        return a.id < b.id;
    }
}
bool cmpA(Score &a,Score &b){
    if(a.A != b.A){
        return a.A > b.A;
    }else{
        return a.id < b.id;
    }
}

bool isVaild[1000010]={false};




int main(){
    int N,M;
    cin >> N >> M;


    int id,c,m,e,a;
    for(int i = 0 ; i < N ; ++i){
        cin >> id >> c >> m >> e;
        a= (c+m+e)/3;
        scores[i].C=c;
        scores[i].M=m;
        scores[i].A=a;
        scores[i].E=e;
        scores[i].id = id;
        isVaild[id]=true;
    }

    sort(scores,scores+N,cmpC);
    ranks[scores[0].id].rankC = 1;
    for(int i = 1 ; i < N ; ++i){

        if(scores[i].C == scores[i-1].C){
            ranks[scores[i].id].rankC = ranks[scores[i-1].id].rankC;
        }else{
            ranks[scores[i].id].rankC = i+1;
        }
    }
    sort(scores,scores+N,cmpM);
    ranks[scores[0].id].rankM = 1;
    for(int i = 1 ; i < N ; ++i){
        if(scores[i].M == scores[i-1].M){
            ranks[scores[i].id].rankM = ranks[scores[i-1].id].rankM;
        }else{
            ranks[scores[i].id].rankM = i+1;
        }
    }
    sort(scores,scores+N,cmpE);
    ranks[scores[0].id].rankE = 1;
    for(int i = 1 ; i < N ; ++i){
        if(scores[i].E == scores[i-1].E){
            ranks[scores[i].id].rankE = ranks[scores[i-1].id].rankE;
        }else{
            ranks[scores[i].id].rankE = i+1;
        }
    }
    sort(scores,scores+N,cmpA);
    ranks[scores[0].id].rankA = 1;
    for(int i = 1 ; i < N ; ++i){
        if(scores[i].A == scores[i-1].A){
            ranks[scores[i].id].rankA = ranks[scores[i-1].id].rankA;
        }else{
            ranks[scores[i].id].rankA = i+1;
        }
    }

    for(int i = 0 ; i < M ; ++i){
        int queryID;
        cin >> queryID;
        vector<Result> res;
        if(isVaild[queryID]){
            res.push_back(Result{'A',ranks[queryID].rankA});
            res.push_back(Result{'M',ranks[queryID].rankM});
            res.push_back(Result{'E',ranks[queryID].rankE});
            res.push_back(Result{'C',ranks[queryID].rankC});

            sort(res.begin(),res.end(),cmp);
            printf("%d %c\n",res[0].rank,res[0].A);

        }else{
            printf("N/A\n");
        }
    }

}