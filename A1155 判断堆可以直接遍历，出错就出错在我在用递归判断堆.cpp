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


using namespace std;
int seq[1010];
int N;
vector<int> path;
void DFS(int i){
    if(i > N){
        return;
    }
    path.push_back(seq[i]);
    if(i<=N && i > N/2){
        for(int k = 0 ; k < path.size()-1 ; ++k){
            printf("%d ",path[k]);
        }
        printf("%d\n",*(path.end()-1));
        path.pop_back();
        return;
    }else{
        DFS(i*2+1);
        DFS(i*2);
    }
    path.pop_back();
}
int main(){
    cin >> N;
    for(int i = 1 ; i <= N ; ++i){
        scanf("%d",&seq[i]);
    }
    path.clear();
    DFS(1);
    int isMax=1,isMin=1;
    for(int i = 2 ; i <= N;++i){
        if(seq[i/2] > seq[i]){
            isMin = 0;
        }
        if(seq[i/2] < seq[i]){
            isMax = 0;
        }
    }
    if(isMin){
        printf("Min Heap\n");
    }else if(isMax){
        printf("Max Heap\n");
    }else{
        printf("Not Heap\n");
    }
    return 0;


}