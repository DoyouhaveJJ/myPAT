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
const int maxN=10010;
int pre[maxN];
int findfather(int a){
    int temp = a;
    while (pre[a]!=a){
        a=pre[a];
    }
    while(pre[temp]!=temp){
        temp = pre[temp];
        pre[temp] = a;
    }
    return a;
}
int main(){

    for(int i = 0 ; i < maxN ; ++i){
        pre[i]=i;
    }

    int N;
    cin >> N;
    int max = 0;
    for(int i = 0 ; i < N ; ++i){
        int n,rootbird;
        cin >> n >> rootbird;
        vector<int> bird(n);
        bird[0] = rootbird;
        int root = findfather(rootbird);
        for(int j = 1 ; j < n ; ++j){
            cin >>bird[j];
            if(findfather(bird[j])!=bird[j]){
                root = findfather(bird[j]);
            }
        }
        for(int j = 0 ; j < n ; ++j){
            if(max < bird[j]){
                max = bird[j];
            }
            pre[bird[j]] = root;
        }

    }

    int trees = 0;
    for(int i = 1 ; i <= max ; ++i){
        if(pre[i]==i){
            trees++;
        }
    }
    printf("%d %d\n",trees,max);
    int K;
    cin >> K;
    for(int i = 0 ; i < K ; ++i){
        int x,y;
        cin >>x >>y;
        if(findfather(x) == findfather(y)){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }

}