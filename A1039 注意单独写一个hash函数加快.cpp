#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
using  namespace std;
const int maxS = 26*26*26*10 + 1;

//maxS个学生选的课程编号的数组
vector<int> selectCoueses[maxS];


int getID(char name[]){
    int id = 0;
    for(int i = 0 ; i < 3 ; ++i){
        id = id*26 + name[i]-'A';
    }
    id = id * 10 + (name[3]-'0');
    return id;
}


int main(){
    int N,K;
    int n,k;
    char name[5];

    scanf("%d %d",&N,&K);
    char namelist[40010][5];
    for(int i = 0 ; i < K ; ++i){
        scanf("%d %d",&n,&k);
        for(int j=0;j<k;j++){
            scanf("%s",name);
            selectCoueses[getID(name)].push_back(n);
        }
    }
    for(int i = 0 ; i < N ; ++i){
        scanf("%s",namelist[i]);
    }
    for(int i = 0 ; i < N ; ++i){
        int id = getID(namelist[i]);
        sort(selectCoueses[id].begin(),selectCoueses[id].end());
        printf("%s %lu",namelist[i],selectCoueses[id].size());

        for (int j = 0; j < selectCoueses[id].size(); ++j) {
            printf(" %d",selectCoueses[id][j]);
        }



        printf("\n");
    }



}