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
struct Node{
    int data;
    int l;
    int r;
}node[10];

bool ischild[10]={false};
int N,dCounter;
void level(int root){
    queue<int> Q;
    int counter = N;
    Q.push(root);
    while (!Q.empty()){
        int p = Q.front();

        cout << node[p].data ;
        counter --;
        if(counter > 0){
            cout << " ";
        }

        Q.pop();
        if(node[p].r!=-1)
            Q.push(node[p].r);
        if(node[p].l!=-1)
            Q.push(node[p].l);

    }
}


void RUL(int root){
    if(root == -1){
        return;
    }
    RUL(node[root].r);
    dCounter --;
    cout << node[root].data;
    if(dCounter > 0){
        cout << " ";
    }

    RUL(node[root].l);


};

int main(){

    cin >> N;
    dCounter = N;
    char l,r;
    for(int i = 0 ; i < N ; ++i){
        cin >> l >> r;
        node[i].data = i;
        node[i].l = -1;
        node[i].r = -1;
        if(l != '-'){
            node[i].l = l - '0';
            ischild[node[i].l] = true;
        }
        if(r != '-'){
            node[i].r = r - '0';
            ischild[node[i].r] = true;
        }
    }
    //找爸爸
    int father= 0 ;
    for(int i = 0; i < N ; ++i){
        if(!ischild[i]){
            father = i;
            break;
        }
    }

    level(father);
    cout << endl;
    RUL(father);




}