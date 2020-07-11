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

struct Node{
    int v,deep;
    Node *left,*right;
};
int counter[1010]={0},maxDeep = 0;
void create(Node* &p,int v){
    if(p == nullptr){
        p = new Node;
        p->v=v;
        p->deep=1;
        p->right=p->left= nullptr;
        return;
    }
    if(p->v >= v){
        create(p->left,v);
    }else{
        create(p->right,v);
    }
}

void BFS(Node *p){
    queue<Node*> Q;
    Q.push(p);
    while (!Q.empty()){
        Node *now = Q.front();
        Q.pop();
        counter[now->deep]++;
        if(maxDeep < now->deep){
            maxDeep = now->deep;
        }
        if(now->left!=nullptr){
            now->left->deep = now->deep+1;
            Q.push(now->left);
        }
        if(now->right!=nullptr){
            now->right->deep = now->deep+1;
            Q.push(now->right);
        }
    }
}

int main(){
    int N,x;
    cin >> N;
    Node *root= nullptr;
    for(int i = 0 ; i < N ; ++i){
        cin >> x;
        create(root,x);
    }
    BFS(root);
    printf("%d + %d = %d",counter[maxDeep] , counter[maxDeep-1], counter[maxDeep] + counter[maxDeep-1]);


}