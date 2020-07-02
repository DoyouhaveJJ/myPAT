#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>

#include <iostream>
using namespace std;
//邻接表
vector<int> G[1000];

//当前被删除的结点
int currentV;
bool visit[1000];
//寻找连通块
void DFS(int v){

    if(v == currentV){
        return;
    }else{
        visit[v] = true;
        //遍历临接点
        for(int i = 0 ; i < G[v].size() ; ++i){
            if(!visit[G[v][i]]){
                DFS(G[v][i]);
            }
        }
    }

}


int main(){
    //total number of cities, the number of remaining highways, and the number of cities to be checked.
    int N,M,K;
    cin >> N >> M >> K;
    //查找连通块
    for(int i = 0 ; i < M ; ++i){
        int x,y;
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for(int i = 0 ; i < K ; ++i){
        cin >> currentV;
        //每次查找都要初始化为false
        memset(visit,false, sizeof(visit));
        int blocks = 0; //连通快

        for(int j = 1 ; j <= N ; ++j){
            //遍历每一个结点,如果没有访问过，就遍历一遍，遍历一遍相当于一整个连通快
            //找到没访问的点就是找新的连通快
            //除了被删除的结点
            if(j!=currentV && !visit[j]){
                //通过遍历将一整个连通块设置为访问过了。
                //利用DFS能够遍历一整个连通块的性质
                DFS(j);
                blocks++;
            }
        }
        cout << blocks - 1 << endl;

    }


}