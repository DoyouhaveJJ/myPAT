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

int deep[100010]={0};
int maxdeep = 0;
struct Node{
    int id;
    vector<int> childrens;
    int deep;
}node[100010];

void level(int root){
    queue<int> Q;
    Q.push(root);
    node[root].deep = 1;
    while (!Q.empty()){
        int now = Q.front();
        Q.pop();
        if(node[now].childrens.empty()){
            if(node[now].deep > maxdeep){
                maxdeep = node[now].deep;
            }
            deep[node[now].deep]++;

        }

        for(auto it = node[now].childrens.begin(); it!=node[now].childrens.end();++it){
            node[*it].deep = node[now].deep+1;
            Q.push(*it);
        }
    }
}


int main(){
    int N,id,root;
    double P,r;
    cin >> N >> P >> r;
    for(int i = 0 ; i < N ; ++i){
        cin >> id;
        if(id == -1){
            node[i].id = i;
            root = i;
        }else{
            node[id].id = id;
            node[id].childrens.push_back(i);
        }
    }
    level(root);
    printf("%.2lf %d",P*pow((100+r)/100,maxdeep-1),deep[maxdeep]);

}