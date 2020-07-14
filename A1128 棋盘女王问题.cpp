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
int board[1005];
bool flag = true;
int K,N,n;
void judge(){
    for(int i = 1; i <= N ; ++i){
        for(int j = i+1 ; j <=N ; ++j){
            if(board[i]==board[j]){
                flag = false;
                return;
            }
            if(abs(board[i] - board[j])==abs(i-j)){
                flag = false;
                return;
            }
        }
    }
}

int main(){

    cin >> K;
    for(int k = 0 ; k < K ; ++k){
        cin >> N;
        memset(board,0, sizeof(board));
        flag = true;
        for(int i = 1 ; i <= N ; ++i){
            cin >> n;
            board[i] = n;
        }
        judge();
        if(flag){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
    }


}