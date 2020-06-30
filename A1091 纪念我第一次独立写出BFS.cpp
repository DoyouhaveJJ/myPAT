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
int M,N,L,T;
struct Silice{
    int martx[1286][128];
    bool visited[1286][128];
}silice[60];
int res = 0;
struct Loc{
    int s;
    int x;
    int y;
}loc;

int direction[6][3] = {{-1,0,0},{1,0,0},{0,1,0},{0,-1,0},{0,0,-1},{0,0,1}};
bool checkdir(Loc a){
    if(a.x >= M || a.x<0) return false;
    if(a.y >= N || a.y<0) return false;
    if(a.s >= L || a.s < 0) return false;
    return true;
}

void BFS(int s, int x ,int y){
    queue<Loc> Q;
    int counter=0;
    for(int k = 0 ; k < L ; ++k){
        for(int i = 0; i < M ; i++){
            for(int j = 0 ; j < N ; ++j){
                if(!silice[k].visited[i][j] && silice[k].martx[i][j]==1) {
                    loc.s = k;
                    loc.x = i;
                    loc.y = j;
                    silice[k].visited[i][j] = true;
                    Q.push(loc);
                    while (!Q.empty()) {
                        Loc temp = Q.front();
                        counter++;
                        Q.pop();
                        for (int d = 0; d < 6; ++d) {
                            loc.s = temp.s + direction[d][0];
                            loc.x = temp.x + direction[d][1];
                            loc.y = temp.y + direction[d][2];
                            //将其入栈
                            if (checkdir(loc)) {
                                if (!silice[loc.s].visited[loc.x][loc.y] && silice[loc.s].martx[loc.x][loc.y] == 1) {
                                    silice[loc.s].visited[loc.x][loc.y] = true;
                                    Q.push(loc);
                                }
                            }
                        }
                    }
                    if (counter >= T) {
                        res += counter;
                    }
                    counter = 0;
                }
            }
        }
    }
}


int main(){

    cin >> M >> N >> L >> T;

    for(int k = 0 ; k < L ; ++k){
        for(int i = 0; i < M ; i++){
            for(int j = 0 ; j < N ; ++j){
                cin >> silice[k].martx[i][j];
            }
        }
    }

    BFS(0,0,0);
    cout <<res;


}