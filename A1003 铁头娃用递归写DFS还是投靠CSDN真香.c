#include <stdio.h>
#define Max 500
#define NaN 99999
int City[Max]={0},Roads[Max][Max],Visit[Max];
int N,M,C1,C2;
int minRoads = 1,maxRescue = 0;
int minDistence = Max;
int DFS(int,int,int,int);
int main() {
    int i=0,j=0,k=0,v=0;
    scanf("%d %d %d %d",&N,&M,&C1,&C2);
    while(i < N){
        scanf("%d ",City+i);
        i++;
    }
    for(i = 0 ; i < N ; ++i){
        Visit[i] = 0;
        for (j = 0; j < N; ++j) {
            Roads[i][j] = NaN;
        }
    }
    while (k<M){
        scanf("%d %d %d",&i,&j,&v);
        Roads[i][j] = v;
        Roads[j][i] = v;
        k++;
    }
    DFS(C1,C2,0,City[C1]);
    printf("%d %d",minRoads,maxRescue);

}


int DFS(int source,int target,int dist, int rescue){
    if (source == target) {
        if (dist < minDistence){
            minRoads = 1;
            minDistence = dist;
            maxRescue = rescue;
        }
        else if (dist == minDistence) {
            minRoads++;
            if(maxRescue < rescue){
                maxRescue = rescue;
            }
        }
        return 1;
    }
    if(dist > minDistence) return -1;

    for(int i = 0; i < N; ++i) {
        if (!Visit[i] && Roads[source][i] != Max) {
            Visit[i] = 1;
            DFS(i, target, dist+Roads[source][i], rescue+City[i]);
            Visit[i] = 0;
        }
    }
    return 0;
}
