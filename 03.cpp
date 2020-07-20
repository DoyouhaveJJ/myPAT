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
const int maxN = 15;
struct Node{
    int v;
    int lchild,rchild;
}nodes[maxN];
vector<int> levelres;
void level(int root){
    queue<int> Q;
    Q.push(root);
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        levelres.push_back(nodes[now].v);
        if(nodes[now].rchild != -1){
            Q.push(nodes[now].rchild);
        }
        if(nodes[now].lchild != -1){
            Q.push(nodes[now].lchild);
        }
    }
}
vector<int> inres;
void in(int root){
    if(root == -1){
        return;
    }
    in(nodes[root].rchild);
    inres.push_back(nodes[root].v);
    in(nodes[root].lchild);
}


int main(){
    int N;
    cin >> N;
    bool hasParent[maxN]={false};
    for(int i = 0 ;i < N; ++i){
        string x,y;
        int xc,yc;
        cin >> x >> y;
        if(x == "-"){
            xc=-1;
        }else{
            xc = stoi(x);
        }
        if(y == "-"){
            yc =-1;
        }else{
            yc = stoi(y);
        }
        nodes[i].lchild = xc;
        nodes[i].rchild = yc;
        nodes[i].v = i;
        hasParent[xc]= true;
        hasParent[yc] =true;
    }
    int root=0;
    for(int i = 0 ; i < N ; ++i){
        if(!hasParent[i]){
            root = i;
        }
    }

    level(root);
    in(root);
    for(int i = 0 ; i < levelres.size() ; ++i){
        printf("%d",levelres[i]);
        if(i < levelres.size()-1){
            printf(" ");
        }
    }
    printf("\n");
    for(int i = 0 ; i < inres.size() ; ++i){
        printf("%d",inres[i]);
        if(i < inres.size()-1){
            printf(" ");
        }
    }

}