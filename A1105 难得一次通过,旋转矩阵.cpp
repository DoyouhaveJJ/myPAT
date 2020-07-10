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


//不是质数
using namespace std;

int seq[10010],res[10010];
bool vis[10010]={false};
int dir[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int findM(int a){
    int mid = (int)sqrt(a);
    int min = INF;
    int res=1;
    for(int i = mid ; i > 1; --i){
        if(a % i == 0){
            int m = i,n = a/i;
            if(abs(m-n) < min){
                res = m;
                min = abs(m-n);
            }

        }
    }
    return res;

}

bool cmp(int a,int b){
    return a>b;
}


int main(){
    int N;
    cin >> N;
    for(int i =0;i<N;++i){
        scanf("%d",&seq[i]);
    }
    int m = findM(N);
    int n = N / m;
    m = max(m,n);
    n = N / m;

    sort(seq,seq+N,cmp);
    int counter = 0;
    int d = 0,x=0,y=0;

    while (counter < N){
        while( !(x >= m || y >= n || x < 0 || y < 0 || vis[x*n+y] )){
            res[x*n+y]= seq[counter];
            vis[x*n+y] = true;
            counter ++;
            x = x+dir[d][0];
            y = y+dir[d][1];
        }
        x = x-dir[d][0];
        y = y-dir[d][1];
        d= (d+1)%4;
        x = x+dir[d][0];
        y = y+dir[d][1];
    }

    for(int i = 0 ; i < m ; ++i){
        for(int j = 0 ; j < n ; ++j){
            printf("%d",res[i*n+j]);
            if(j<n-1){
                printf(" ");
            }
        }
        printf("\n");
    }


}