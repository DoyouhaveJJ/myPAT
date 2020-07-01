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
int node[1000];
int tree[1000];
int N;
int num;


void LRU(int root){
    if(root > N){
        return;
    }
    if(num == N){
        return;
    }
    LRU(2*root);
    tree[root] = node[num++];
    LRU(2*root+1);
}

int main(){

    //完全BST 的 中序遍历是有序的！，利用这个思想，通过造一个没数据的树
    //用中序遍历来给他赋值（逆向）



    cin >> N;
    num = 0;
    for(int i =0 ; i < N ; ++i){
        cin >> node[i];
    }
    sort(node,node+N);
    LRU(1);
    for(int i = 1 ; i <= N ; ++i){
        cout << tree[i];
        if(i <= N-1){
            cout << " ";
        }
    }







}