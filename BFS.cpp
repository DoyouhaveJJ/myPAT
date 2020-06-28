#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>
#include <iostream>
#include <queue>

using namespace std;

const int maxn = 100;

struct node{
    int x,y;
}Node;

int n,m;
//01矩阵
int matrix[maxn][maxn];
//是否访问过了
bool inq[maxn][maxn];

//四个方向
int X[]={0,0,1,-1};
int Y[]={1,-1,0,0};
//判断是否访问过了//是否越界
bool judge(int x,int y){
    if(x >= maxn || x < 0 || y >= maxn || y <0){
        return false;
    }
    return !(matrix[x][y] == 0 || inq[x][y]);
}

int res = 0;
void BFS_block(int x,int y){
    //入队
    queue<node> Q;
    Node.x = x;
    Node.y = y;
    Q.push(Node);

    inq[x][y] = true;

    while (!Q.empty()){
        //取出队首元素top
        node top = Q.front();
        //出队
        Q.pop();
        //依次将剩余的周围结点入队
        for(int i=0;i<4;++i){
            if(judge(top.x + X[i],top.y+Y[i])){
                //入队
                inq[top.x+ X[i]][top.y+ Y[i]] = true;
                Node.x = top.x + X[i];
                Node.y = top.y + Y[i];
                Q.push(Node);
            }
        }
    }
}
//遍历矩阵，如果遇到一个1且没被访问过，就用BFS把一层一层都都给遍历过（设置被访问过）



struct node2{
    int x;
    int y;
    int step;
}Node2;

bool test(int x,int y){
    if(x >= maxn || x < 0 || y >= maxn || y <0){
        return false;
    }
    return !(matrix[x][y] == '*' || inq[x][y]);
}


int BFS_migong(int x,int y){
    //起点
    Node2.x = x;
    Node2.y = y;
    Node2.step = 0;
    queue<node2> q;
    q.push(Node2);
    while (!q.empty()){
        node2 top = q.front();
        q.pop();
        //到了终点
        if(matrix[top.x][top.y]=='T'){
            return top.step;
        }
        for(int i=0;i<4;++i){
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if(test(newX,newY)){
                Node2.x = newX;
                Node2.y = newY;
                //下一层了，是顶层结点的层数+1
                Node2.step = top.step + 1;
                inq[newX][newY] = true;
                q.push(Node2);
            }
        }
    }
    //无法到达终点
    return -1;
}

void BFS_tempelet(int s){
    queue<int> q;
    q.push(s);
    while (!q.empty()){
        //取出队首元素top

        //访问队首元素top

        //队首元素出队

        //将top的下一层结点中未曾入队的结点全部入队，并且设置为已入队。
    }
}

int main(){

}