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
    Node *l;
    Node *r;
}*root;
int data[1000],num = 0,N;

void create(Node* &p,int v){
    if(p == nullptr){
        //注意这里要用 指针 的 引用 才能修改子树指针！
        p = new Node;
        p->data = v;
        return;
    }

    if(v >= p->data){
        create(p->r,v);
    }
    else{
        create(p->l,v);
    }
}


void ULR(Node *p,bool &flag){
    if(p==nullptr){
        return;
    }else{
        if(p->data != data[num++]){
            flag = false;
        }
        ULR(p->l,flag);
        ULR(p->r,flag);
    }
}

void exchange(Node* &p){
    if(p== nullptr){
        return;
    }else{
        Node *temp;
        temp = p->l;
        p->l = p->r;
        p->r= temp;
    }
    exchange(p->l);
    exchange(p->r);


}


void RLU(Node *p){
    if(p==nullptr){
        return;
    }else{
        RLU(p->r);
        RLU(p->l);
        N--;
        cout << p->data;
        if(N > 0 ){
            cout <<" ";
        }

    }
}


int main(){
    bool flag1 = true,flag2=true;
    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        cin >> data[i];
    }
    root = new Node;
    //建立查找树
    root->data = data[0];

    for(int i = 1 ; i < N ; ++i){
        create(root,data[i]);
    }
    ULR(root,flag1);
    num = 0;
    exchange(root);
    ULR(root,flag2);
    if(flag1 || flag2){
        cout <<"YES" << endl;
        if(flag1){
            RLU(root);
        }else{
            exchange(root);
            RLU(root);
        }
    }else{
        cout <<"NO"<<endl;
    }



}