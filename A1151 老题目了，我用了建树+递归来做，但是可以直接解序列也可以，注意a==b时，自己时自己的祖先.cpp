
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

int in[10005],pre[10005];

struct Node{
    int val;
    Node *left,*right;
};

Node* create(int inL,int inR,int preL,int preR){
    if(preL > preR){
        return nullptr;
    }
    Node *p = new Node();
    p->val = pre[preL];

    //找到中序
    int k=inL;
    for(int i = inL ; i <= inR ; ++i){
        if(in[i] == pre[preL]){
            k = i;
            break;
        }
    }
    int length = k - inL;
    p->left = create(inL,k-1,preL+1,preL+length);
    p->right = create(k+1,inR,preL+length+1,preR);
    return p;

}



bool find(Node *p,int a,int b,int &res){
    if(p == nullptr){
        return false;
    }
    bool flag1 = find(p->left,a,b,res);
    bool flag2 = find(p->right,a,b,res);
    if(flag1 && flag2){
        res = p->val;
        return true;
    }else if(flag1 || flag2){
        if(p->val == a || p->val == b){
            res = p->val;
        }
        return true;
    }else if(p->val == a || p->val == b){
        return true;
    }else{
        return false;
    }
}

unordered_map<int,bool> imap;
int main(){
    int M,N;
    cin >> M >> N;
    for(int i = 1 ; i <= N ; ++i){
        scanf("%d",&in[i]);
        imap[in[i]] = true;

    }
    for(int i = 1 ; i <= N ; ++i){
        scanf("%d",&pre[i]);
        imap[in[i]] = true;
    }

    Node *root = create(1,N,1,N);
    int res=0;
    for(int i = 0 ; i < M ; ++i){
        int x,y;
        cin >> x>>y;
        if(!imap[x] && !imap[y]){
            printf("ERROR: %d and %d are not found.",x,y);
        }else if(!imap[x]){
            printf("ERROR: %d is not found.",x);
        }else if(!imap[y]){
            printf("ERROR: %d is not found.",y);
        }else if(x==y){
            printf("%d is an ancestor of %d.",x,y);
        }else{
            find(root,x,y,res);

            if(x==res || y ==res){
                printf("%d is an ancestor of %d.",res,res==x?y:x);
            }else{
                printf("LCA of %d and %d is %d.",x,y,res);
            }
        }
        printf("\n");
    }
}