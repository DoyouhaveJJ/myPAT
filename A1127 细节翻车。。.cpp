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

int N;
int in[35],post[35];
struct Node{
    int val,deep{1};
    Node *left,*right;
};
struct Record{
    int val;
    int order;
}record;

bool cmp1(Record a,Record b){
    return a.order > b.order;

}
bool cmp2(Record a,Record b){
    return a.order < b.order;

}
/*
 1  2  3 4  5  6 7 8
12 11 20 17 1 15 8 5
12 20 17 11 15 8 5 1
 */
Node* create(int inL,int inR,int postL,int postR){
    if(postL > postR){
        return nullptr;
    }
    Node *p = new Node;
    p->val = post[postR];
    //找到
    int index;
    for(int i = inL; i <= inR ; ++i ){
        if(in[i] == post[postR]){
            index = i;
            break;
        }
    }
    int len = index - inL;
    p->left = create(inL,index-1,postL,postL+len-1);
    p->right = create(index+1,inR,postL+len,postR-1);
    return p;
}
vector<Record> res;
int layer[35];
int maxLayer=0;
void zigzag(Node *p){
    queue<Node*> Q;
    Q.push(p);
    int counter =1;
    while(!Q.empty()){
        Node *now = Q.front();
        Q.pop();
        layer[now->deep]++;
        if(maxLayer < now->deep){
            maxLayer = now->deep;
        }
        record.val = now->val;
        record.order = counter++;
        res.push_back(record);
        if(now->left != nullptr){
            now->left->deep  = now->deep+1;
            Q.push(now->left);
        }
        if(now->right != nullptr){
            now->right->deep  = now->deep+1;
            Q.push(now->right);
        }
    }

}

int main(){

    cin >> N;
    for(int i = 1 ; i <= N; ++i){
        cin >> in[i];
    }
    for(int i = 1 ; i <= N; ++i){
        cin >> post[i];
    }
    Node *root = create(1,N,1,N);
    zigzag(root);

    int tempsum = 0;



    for(int i = 1 ; i <= maxLayer ; ++i){
        int amount = layer[i];
        if(i % 2 ==0){
            sort(res.begin()+tempsum,res.begin()+tempsum+amount,cmp2);
        }else{
            sort(res.begin()+tempsum,res.begin()+tempsum+amount,cmp1);
        }
        tempsum+=amount;
    }


    for(int i = 0 ; i < res.size() ; ++i){
        cout << res[i].val;
        if(i < res.size()-1){
            cout << " ";
        }

    }
}

