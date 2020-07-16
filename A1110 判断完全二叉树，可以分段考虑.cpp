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
const int maxN=22;
struct Node{
    int left,right;
    int degree;
}tree[maxN];
int N;
bool flag = true;
vector<int> res;
void BFS(int root){
    queue<int> Q;
    Q.push(root);
    int counter = 1;
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        res.push_back(now);
        if(counter > N/2){
            if(tree[now].degree != 0){
                flag =false;
            }
        }else if(counter == N/2){
            if(tree[now].left == -1){
                flag=false;
            }
        }else{
            if(tree[now].degree != 2){
                flag = false;
            }
        }
        counter++;
        if(tree[now].left!=-1){
            Q.push(tree[now].left);
        }
        if(tree[now].right!=-1){
            Q.push(tree[now].right);
        }
    }


}


int main(){

    cin >> N;
    string x,y;

    bool hasParent[maxN]={false};
    for(int i = 1 ; i <= N ; ++i){
        cin >> x >> y;
        if (y != "-" && x == "-"){
            flag=false;
        }
        if(x=="-"){
            tree[i].left = -1;
        }
        else{
            tree[i].left = stoi(x)+1;
            tree[i].degree++;
            hasParent[tree[i].left]=true;
        }
        if(y=="-"){
            tree[i].right = -1;
        }
        else{
            tree[i].right = stoi(y)+1;
            tree[i].degree++;
            hasParent[tree[i].right]=true;
        }
    }
    int root;
    for(int i = 1 ; i <= N ;++i){
        if(!hasParent[i]){
            root = i;
            break;
        }
    }
    BFS(root);
    if(flag){
        printf("YES %d",*(res.end()-1)-1);
    }else{
        printf("NO %d",root-1);
    }





}