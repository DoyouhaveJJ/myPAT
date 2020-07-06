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
#define INF 1e9

using namespace std;
int pre[50010],in[50010];
int N;

int num = 0;
bool flag = true;
struct Node{
    int v;
    Node *left,*right;
};
Node* create_p(int preL,int preR,int inL,int inR){
    //根据先序中的序号来作为递归边界
    if(preL > preR){
        return NULL;
    }
    //创建一个新结点
    Node *root = new Node;
    //传入的preR就是根结点
    root->v = pre[preL];

    //在中序中找到根结点序号，将先序和中序分别划分成两段.
    int k;
    //inL是中序序列的左端
    for(k = inL;k<=inR;k++){
        if(in[k] == pre[preL]){
            break;
        }
    }
    //记录左子树长度，这一步非常重要，因为在中序中可以确定子树长度。
    int lChildLen = k - inL;
    //将先序的左子树和中序的左子树创建，并给根结点 注意区别
    root->left = create_p(preL+1,preL+lChildLen,inL,k-1);
    root->right = create_p(preL+1+lChildLen,preR,k+1,inR);
    //都创建好了 返回根
    return root;

    //递归思想，每一次创建子树的步骤都相同，即从两段序列中找到根，然后分别建立。直到lChild为0，表示左子树没了。
}


void LRU(Node *p){
    if(p== nullptr){
        return;
    }
    if(flag){

        LRU(p->left);
        LRU(p->right);
        if(flag){
            printf("%d",p->v);
            flag = false;
        }


    }else{
        return;
    }
}
int main(){

    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        scanf("%d",&pre[i]);
    }
    for(int i = 0 ; i < N ; ++i){
        scanf("%d",&in[i]);
    }

    Node *root = create_p(0,N-1,0,N-1);
    LRU(root);

}


