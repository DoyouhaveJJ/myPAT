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
int main() {
    int first,N,id,val,nex,pr;
    int final[100010],value[100010],next[100010],pre[100010],removed[100010],visited[100010]={false},newfinal[100010];
    cin >> first >> N;
    pr = -1;
    for(int i = 0 ; i < N ; ++i){
        cin >> id >> val >> nex;
        pre[id] = pr;
        value[id]=val;
        next[id]=nex;
        pr = id;
    }
    //去除无效
    int p=first,num=0;
    while (p!=-1){
        final[num++]=p;
        p=next[p];
    }

    //去除重复
    int rnum=0,nnum=0;
    for(int i = 0 ; i < num ; ++i){
        if(visited[abs(value[final[i]])]){
            removed[rnum++] = final[i];
        }else{
            newfinal[nnum++] = final[i];
        }
        visited[abs(value[final[i]])] = true;
    }


    for(int i = 0 ; i < nnum-1 ; ++i){
        printf("%05d %d %05d\n",newfinal[i],value[newfinal[i]],newfinal[i+1]);
    }
    printf("%05d %d -1\n",newfinal[nnum-1],value[newfinal[nnum-1]]);
    if(rnum >0){
        for(int i = 0 ; i < rnum-1 ; ++i){
            printf("%05d %d %05d\n",removed[i],value[removed[i]],removed[i+1]);
        }
        printf("%05d %d -1",removed[rnum-1],value[removed[rnum-1]]);
    }


}