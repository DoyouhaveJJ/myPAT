
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
const int maxN = 100010;
struct Node{
    int ID;
    int value;
    int next;
    int flag;
    int order;
    int avai;
}node[100010];

bool cmp(Node a,Node b){
    if(a.avai!=b.avai){
        return a.avai > b.avai;
    }else{
        if(a.flag != b.flag){
            return a.flag > b.flag;
        }else{
            return a.order<b.order;
        }
    }
}



int main(){
    int first,N,K;
    int x,y,z;
    int final;


    for(int i = 0 ; i < maxN ; ++i){
        node[i].flag = -9;
        node[i].avai = -1;
        node[i].ID = -1;
    }
    cin >> first >> N >> K;
    for(int i = 0 ; i < N ; ++i){
        cin >> x >> y >>z;
        node[x].ID =x;
        node[x].value = y;
        node[x].next  = z;
        if(y < 0){
            node[x].flag = 2;
        }else{
            if(y>K){
                node[x].flag = 0;
            }else{
                node[x].flag = 1;
            }
        }
    }

    int p = first;
    int counter=0;
    while (p!=-1){
        node[p].avai = 1;
        node[p].order = counter++;
        p = node[p].next;

    }

    sort(node,node+maxN,cmp);
    for(int i = 0 ; i < counter-1 ; ++i){
        printf("%05d %d %05d\n",node[i].ID,node[i].value,node[i+1].ID);
    }
    printf("%05d %d -1",node[counter-1].ID,node[counter-1].value);


}
