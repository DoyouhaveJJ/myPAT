#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <math.h>
using  namespace std;
//二叉树结点
struct node{
    int data;
    int layer;
    node *lchild;
    node *rchild;
};
int pre[30],in[30];
int N;
//先序序列，中序序列创建二叉树

node* create(int preL,int preR,int inL,int inR){
    //根据先序中的序号来作为递归边界
    if(preL > preR){
        return NULL;
    }
    //创建一个新结点
    node *root = new node;
    //传入的pre就是根结点
    root->data = pre[preL];

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
    //将先序的左子树和中序的左子树创建，并给根结点
    root->lchild = create(preL+1,preL+lChildLen,inL,k-1);
    root->rchild = create(preL+1+lChildLen,preR,k+1,inR);
    //都创建好了 返回根
    return root;

    //递归思想，每一次创建子树的步骤都相同，即从两段序列中找到根，然后分别建立。直到lChild为0，表示左子树没了。
}

//后续遍历
node* create_p(int postL,int postR,int inL,int inR){
    //根据先序中的序号来作为递归边界
    if(postL > postR){
        return NULL;
    }
    //创建一个新结点
    node *root = new node;
    //传入的preR就是根结点
    root->data = pre[postR];

    //在中序中找到根结点序号，将先序和中序分别划分成两段.
    int k;
    //inL是中序序列的左端
    for(k = inL;k<=inR;k++){
        if(in[k] == pre[postR]){
            break;
        }
    }
    //记录左子树长度，这一步非常重要，因为在中序中可以确定子树长度。
    int lChildLen = k - inL;
    //将后序的左子树和中序的左子树创建，并给根结点 注意区别
    root->lchild = create_p(postL,postL+lChildLen-1,inL,k-1);
    root->rchild = create_p(postL+lChildLen,postR-1,k+1,inR);
    //都创建好了 返回根
    return root;

    //递归思想，每一次创建子树的步骤都相同，即从两段序列中找到根，然后分别建立。直到lChild为0，表示左子树没了。
}

void visit(node *root){
    //层次遍历
    queue<node*> Q;
    root->layer = 1;
    Q.push(root);
    int counter= 0;
    while (!Q.empty()){
        node *top = Q.front();
        if(counter == N-1){
            printf("%d",top->data);
        } else{
            printf("%d ",top->data);
        }

        counter++;
        if(top->lchild!=NULL){
            top->lchild->layer = top->layer + 1;
            Q.push(top->lchild);
        }
        if(top->rchild!=NULL){
            top->rchild->layer = top->layer + 1;
            Q.push(top->rchild);
        }
        Q.pop();
    }
}

int main(){

    scanf("%d",&N);
    for(int i = 0 ; i < N ; ++i){
        scanf("%d",&pre[i]);
    }
    for(int i = 0 ; i < N ; ++i){
        scanf("%d",&in[i]);
    }
    node* root = create_p(0,N-1,0,N-1);
    visit(root);
}
