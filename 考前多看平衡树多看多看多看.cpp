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
    int v;
    Node *l;
    Node *r;
    int high{1};
}*root;
int getHigh(Node* p){
    if(p== nullptr) return 0;
    return p->high;
}
//更新树高
void update(Node* p){
    p->high = max(getHigh(p->l),getHigh(p->r))+1;
}

int getBalance(Node *p){
    return getHigh(p->l)-getHigh(p->r);
}

//左旋
void L(Node* &r){
    Node *temp = r->r;
    r->r = temp->l;
    temp->l = r;
    update(r);
    update(temp);
    //这里的r是引用，因此修改了后 原树的r的父亲的孩子（原本是r)现在变为了temp！
    r = temp;

}

void R(Node* &r){
    Node *temp = r->l;
    r->l = temp->r;
    temp->r = r;
    update(r);
    update(temp);
    r = temp;
}
void insert(Node* &p , int v){
    //没有儿子，直接插入
    if(p == nullptr){
        p = new Node;
        p->v = v;
        return;
    }

    if(v < p->v){
        insert(p->l,v);
        update(p);
        //要理解调整平衡，其实分4种 LL LR RR RL 将子结点抽象成一个结点
        if(getBalance(p) == 2){
            // LL型
            if(getBalance(p->l) == 1){
                R(p);
            }else if(getBalance(p->l) == -1){
                L(p->l);
                R(p);
            }
        }
    }else{
        insert(p->r,v);
        update(p);
        //要理解调整平衡，其实分4种 LL LR RR RL 将子结点抽象成一个结点
        if(getBalance(p) == -2){
            // RR型
            if(getBalance(p->r) == -1){
                L(p);
            }else if(getBalance(p->r) == 1){
                R(p->r);
                L(p);
            }
        }
    }
}



int main(){
    int N,n;
    cin >> N;
    for(int i = 0 ; i < N ; ++i){
       cin >> n;
       insert(root,n);
    }
    cout << root->v;
}