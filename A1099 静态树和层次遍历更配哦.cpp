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

int N;
int num=0;
int value[100];
struct Node{
    int value;
    int l;
    int r;
    Node(){
        value = -1;
        l=-1;
        r=-1;
    }
}node[100];

void LRU(int root){
    if(root==-1){
        return;
    }
    LRU(node[root].l);
    node[root].value = value[num++];
    LRU(node[root].r);
}




void layer(int root){
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()){
        int now = Q.front();
        Q.pop();
        cout << node[now].value;
        if(num--){
            cout << " ";
        }
        if(node[now].l!=-1){
            Q.push(node[now].l);
        }
        if(node[now].r!=-1){
            Q.push(node[now].r);
        }

    }
}

int main(){

    cin >>N;
    for(int i = 0 ; i < N ;++i){
        cin >> node[i].l >> node[i].r;
    }

    for(int i = 0 ; i < N ;++i){
        cin >> value[i];
    }
    sort(value,value+N);
    LRU(0);
    num--;
    layer(0);


}