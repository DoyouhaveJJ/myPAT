
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


int tree[1002];

int cmp(int a,int b){
    if(a>b)
        return 1;
    else
        return 0;
}
struct Node{
    int v;
    Node *l,*r;
};
vector<int> postQ;
void post(int now,int N){
    if(now < 1 || now > N){
        return;
    }

    post(2*now,N);
    post(2*now+1,N);
    postQ.push_back(tree[now]);
}

int main(){
    int N,M,type;
    cin >> N >> M;
    for(int n = 0 ; n < N ; ++n){
        for(int i = 1 ; i <= M ; ++ i){
            cin >> tree[i];
        }
        postQ.clear();
        post(1,M);

        type = tree[1]>tree[2]?1:0;//1:大顶堆 0:小顶堆
        bool flag = true;
        for(int i = 1 ; i <= M ; ++ i){
            if(!flag){
                break;
            }
            int lchild=2*i,rchild=2*i+1;
            if(lchild <= M && rchild <= M){
                if( cmp(tree[i],tree[lchild]) == type && cmp(tree[i],tree[rchild])==type){
                    continue;
                }else{
                    flag = false;
                }
            }else if(lchild <= M && rchild > M){
                if(cmp(tree[i],tree[lchild]) == type){
                    continue;
                }else{
                    flag = false;
                }
            }else if(lchild > M){
                continue;
            }
        }

        if(flag){
            if(type==1){
                cout << "Max Heap\n";
            }else{
                cout << "Min Heap\n";
            }
        }else{
            cout << "Not Heap\n";
        }
        for(int o = 0 ; o < postQ.size();++o){
            cout << postQ[o];
            if(o < postQ.size()-1){
                cout << " ";
            }
        }
        cout << endl;

    }


}