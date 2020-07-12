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
    int v,high;
    Node *left,*right;
};
int getHigh(Node *p){
    if(p== nullptr) return 0;
    return p->high;
}
void updateHigh(Node *p){
    p->high = max(getHigh(p->left),getHigh(p->right))+1;
}

int getBalance(Node *p){
    return getHigh(p->left) - getHigh(p->right);
}

void L(Node* &p){
    Node *next = p->right;
    p->right = next->left;
    next->left = p;
    updateHigh(p);
    updateHigh(next);
    p=next;
}

void R(Node* &p){
    Node *next = p->left;
    p->left = next->right;
    next->right = p;
    updateHigh(p);
    updateHigh(next);
    p=next;
}
void create(Node* &r,int v){
    if(r== nullptr){
        r = new Node;
        r->v = v;
        r->high = 1;
        r->right = r->left = nullptr;
        return;
    }
    if(v < r->v){
        create(r->left,v);
        updateHigh(r);
        if(getBalance(r)==2){
            if(getBalance(r->left)==1){
                R(r);
            }else if(getBalance(r->left)==-1){
                L(r->left);
                R(r);
            }
        }
    }else if(v > r->v){
        create(r->right,v);
        updateHigh(r);
        if(getBalance(r)==-2){
            if(getBalance(r->right)==-1){
                L(r);
            }else if(getBalance(r->right)==1){
                R(r->right);
                L(r);
            }
        }
    }

}
vector<int> res;
int counter=0;
bool flag2[1000]={false};

void level(Node *p){
    queue<Node*> Q;
    Q.push(p);
    while (!Q.empty()){
        Node *now = Q.front();
        Q.pop();
        counter++;
        if(now == nullptr){
            flag2[counter] = true;
            continue;
        }else{
            res.push_back(now->v);
        }

        Q.push(now->left);
        Q.push(now->right);


    }
}

int main(){
    int N;
    cin >> N;
    Node *p = nullptr;
    for(int i = 0 ; i < N ; ++i){
        int x;
        cin >> x ;
        create(p,x);
    }

    level(p);

    for(int i = 0 ; i < res.size();++i){
        printf("%d",res[i]);
        if(i<res.size()-1){
            printf(" ");
        }
    }
    bool flag = true;
    for(int i = 1 ; i <= N ; ++i){
        if(flag2[i]){
            flag = false;
        }
    }

    if(flag){
        printf("\nYES");
    }else{
        printf("\nNO");
    }
}