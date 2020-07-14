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
const int maxN = 22;
struct Node{
    string s;
    int left,right;
}tree[maxN];
string res;
int root=0;
void in(int r){
    if(r == -1){
        return;
    }
    if( r!=root&&(tree[r].left!=-1 || tree[r].right!=-1))
        res+= "(";
    in(tree[r].left);
    res+= tree[r].s;
    in(tree[r].right);
    if( r!=root&&(tree[r].left!=-1 || tree[r].right!=-1))
        res+= ")";
}

int main(){
    int N;
    cin >> N;
    bool hasParent[maxN]={false};
    for(int i = 1 ; i <= N ; ++i){
        cin >> tree[i].s >> tree[i].left >> tree[i].right;
        if(tree[i].left != -1 ){
            hasParent[tree[i].left] = true;
        }
        if(tree[i].right != -1){
            hasParent[tree[i].right] = true;
        }
    }
    //找根

    for(int i = 1 ; i <= N ; ++i){
        if(!hasParent[i]){
            root = i;
            break;
        }
    }

    in(root);
    cout << res;

}

