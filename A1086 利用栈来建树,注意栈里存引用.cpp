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
}root;
int counter;
void LRU(Node *r){
    if(r == NULL){
        return;
    }
    LRU(r->l);
    LRU(r->r);
    cout << r->data;
    counter --;
    if(counter > 0){
       cout << " ";

    }
}


int main(){
    int N;
    string op;
    Node *p = &root;
    stack<Node*> S;
    S.push(&root);
    cin >> N;
    counter = N;
    for(int i = 0 ; i < 2*N ; ++i){
        cin >> op;
        if(op =="Push"){
            Node *newNode = new Node;
            cin >> newNode->data ;
            while (!S.empty()) {
                if (p->l == nullptr) {
                    p->l = newNode;
                    break;
                } else if (p->r == nullptr) {
                    p->r = newNode;
                    break;
                } else {
                    p = S.top();
                    S.pop();
                }
            }
            p = newNode;
            S.push(p);
        }else{
            p = S.top();
            S.pop();
        }
    }
    LRU(root.l);
}