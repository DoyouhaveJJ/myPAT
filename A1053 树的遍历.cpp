#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <string>
#include <iostream>

using  namespace std;
int W;
int path[100];
struct Node{
    int data;
    vector<int> child;
}Node[100];


bool cmp(int a,int b){
    return  Node[a].data>Node[b].data;
}

void DPS(int id,int deep,int weight){
    //到达边界
    path[deep] = Node[id].data;
    if(Node[id].child.empty() && weight != W){
        return;
    }else{
        if (weight == W && Node[id].child.empty()) {
            for(int i = 0 ; i <= deep ; ++i){
                printf("%d",path[i]);
                if(i < deep)
                    printf(" ");
            }
            printf("\n");
            return;
        } else {
            for (int i = 0; i < Node[id].child.size(); ++i) {
                //剪枝
                if((Node[Node[id].child[i]].data + weight) <= W){
                    DPS(Node[id].child[i] , deep+1 , Node[Node[id].child[i]].data + weight);
                }
            }
        }
    }
}

int main(){
    int N,noneL,id,n,nodeid;
    scanf("%d %d %d",&N,&noneL,&W);
    for(int i = 0 ; i < N ; ++i){
        scanf("%d",&Node[i].data);
    }
    for(int i = 0 ; i < noneL;++i){
        scanf("%d %d",&id,&n);
        for(int j = 0 ; j < n ;++j){
            scanf("%d", &nodeid);
            Node[id].child.push_back(nodeid);
        }
        sort(Node[id].child.begin(),Node[id].child.end(),cmp);
    }

    DPS(0,0,Node[0].data);

}