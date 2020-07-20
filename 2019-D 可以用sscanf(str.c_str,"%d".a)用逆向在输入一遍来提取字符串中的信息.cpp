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
#define INF 1000000000
typedef long long LL;
using namespace std;
const int maxN = 35;
struct Node{
    int value;
    Node *lchild,*rchild;
    int deep;
};

int N;
int post[maxN],in[maxN];
Node* create(int postL,int postR,int inL,int inR){
    if(postL > postR){
        return nullptr;
    }
    //找根
    Node *node = new Node;
    node->value = post[postR];
    int index=0;
    for(int i = inL ; i <= inR ; ++i){
        if(in[i] == post[postR]){
            index = i;
        }
    }
    int len = index - inL;
    node->lchild = create(postL,postL+len-1,inL,index-1);
    node->rchild = create(postL+len,postR-1,index+1,inR);
    return node;
}
bool isfull=true;
void DFS(Node *p,int deep){
    if(p== nullptr){
        return;
    }
    p->deep=deep;
    if((p->lchild==nullptr && p->rchild!=nullptr) || (p->rchild==nullptr && p->lchild!=nullptr)){
        isfull=false;
    }
    DFS(p->lchild,deep+1);
    DFS(p->rchild,deep+1);
}

void DFS_2(Node *p,bool &flag,int a,int b){
    if(p== nullptr){
        return;
    }
    if(p->lchild!= nullptr &&p->rchild != nullptr){
        if((p->lchild->value==a && p->lchild->value==b)||(p->lchild->value==b && p->lchild->value==a) ){
            flag = true;
            return;
        }
    }

    DFS_2(p->lchild,flag,a,b);
    DFS_2(p->rchild,flag,a,b);

}
void DFS_3(Node *p,bool &flag,int a,int b){
    if(p== nullptr){
        return;
    }
    if(p->value==a){
        if(p->lchild!= nullptr && p->lchild->value==b ){
            flag = true;
            return;
        }
        if(p->rchild!= nullptr && p->rchild->value==b ){
            flag=true;
            return;
        }
    }

    DFS_3(p->lchild,flag,a,b);
    DFS_3(p->rchild,flag,a,b);

}
void DFS_4(Node *p,bool &flag,int a,int b){
    if(p== nullptr){
        return;
    }
    if(p->value==b){
        if(p->lchild!= nullptr && p->lchild->value==a ){
            flag = true;
            return;
        }
    }

    DFS_4(p->lchild,flag,a,b);
    DFS_4(p->rchild,flag,a,b);

}
void DFS_5(Node *p,bool &flag,int a,int b){
    if(p== nullptr){
        return;
    }
    if(p->value==b){
        if(p->rchild!= nullptr && p->rchild->value==a ){
            flag = true;
            return;
        }
    }
    DFS_5(p->lchild,flag,a,b);
    DFS_5(p->rchild,flag,a,b);
}
void DFS_6(Node *p,int a,int &deep){
    if(p== nullptr){
        return;
    }
    if(p->value==a){
        deep = p->deep;
    }
    DFS_6(p->lchild,a,deep);
    DFS_6(p->rchild,a,deep);
}

int main(){

    cin >> N;
    for(int i = 1 ; i <= N ; ++i){
        cin >> post[i];
    }
    for(int i = 1 ; i <= N ; ++i){
        cin >> in[i];
    }
    Node *root = create(1,N,1,N);
    DFS(root,1);

    int M;
    cin >> M;
    getchar();
    string cmd;
    for(int i = 0 ; i < M ; ++i){
        getline(cin,cmd);
        bool flag=false;
        int type1 = cmd.find("root");
        int type2 = cmd.find("siblings");
        int type3 = cmd.find("parent");
        int type4 = cmd.find("left");
        int type5 = cmd.find("right");
        int type6 = cmd.find("level");
        int type7 = cmd.find("tree");
        if(type1!=-1){
            for(auto it = cmd.begin();it!=cmd.end();++it){
                string word;
                int index=cmd.find(" is");
                if(root->value == stoi(cmd.substr(0,index))){
                    flag=true;
                }
            }
        }else if(type2!=-1){
            int andindex=cmd.find(" and ");
            int areindex=cmd.find(" are ");
            int p1 = stoi(cmd.substr(0,andindex));
            int p2 = stoi(cmd.substr(andindex+5,areindex-(andindex+5)+1));
            if(p1==p2){
                flag=true;
            }else{
                DFS_2(root,flag,p1,p2);
            }


        }else if(type3!=-1){
            int isindex=cmd.find(" is ");
            int ofindex=cmd.find(" of ");
            int p1 = stoi(cmd.substr(0,isindex));
            int p2 = stoi(cmd.substr(ofindex+4,cmd.length()-(ofindex+4)+1));
            DFS_3(root,flag,p1,p2);
        }else if(type4!=-1){
            int isindex=cmd.find(" is ");
            int ofindex=cmd.find(" of ");
            int p1 = stoi(cmd.substr(0,isindex));
            int p2 = stoi(cmd.substr(ofindex+4,cmd.length()-(ofindex+4)+1));
            DFS_4(root,flag,p1,p2);
        }
        else if(type5!=-1){
            int isindex=cmd.find(" is ");
            int ofindex=cmd.find(" of ");
            int p1 = stoi(cmd.substr(0,isindex));
            int p2 = stoi(cmd.substr(ofindex+4,cmd.length()-(ofindex+4)+1));
            DFS_5(root,flag,p1,p2);
        }else if(type6!=-1){
            int andindex=cmd.find(" and ");
            int areindex=cmd.find(" are ");
            int p1 = stoi(cmd.substr(0,andindex)),deep1;
            int p2 = stoi(cmd.substr(andindex+5,areindex-(andindex+5)+1)),deep2;
            DFS_6(root,p1,deep1);
            DFS_6(root,p2,deep2);
            if(deep1==deep2){
                flag=true;
            }
        }else if(type7!=-1){
            flag=isfull;
        }

        if(flag){
            cout <<"Yes"<<endl;
        }else{
            cout <<"No"<<endl;
        }
    }
}