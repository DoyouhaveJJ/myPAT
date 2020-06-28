#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
const int maxApp = 40010;
const int maxK = 5;
const int maxM = 100;
struct Application{
    int ID;
    int GE;
    int GI;
    int Rank;
    int GF;
    int school[maxK];
}App[maxApp];
struct School{
    int ID;
    int Max;
    int Now;
    int App[maxApp];
    int Rank;
}schools[maxM];

bool compare(Application a,Application b){
    if(a.GF != b.GF){
        return  a.GF > b.GF;
    }else{
        if(a.GE != b.GE){
            return a.GE > b.GE;
        }else{
            return a.ID < b.ID;
        }
    }
}

int main(){
    int N,M,K;
    int tempGE,tempGI,tempS;
    scanf("%d %d %d",&N,&M,&K);
    for(int i=0 ; i<M;++i){
        schools[i].ID=i;
        schools[i].Now = 0;
        scanf("%d",&schools[i].Max);
    }
    for(int i = 0 ; i < N;++i){
        scanf("%d %d",&tempGE,&tempGI);
        App[i].ID = i;
        App[i].GE = tempGE;
        App[i].GI = tempGI;
        App[i].GF = ((tempGE + tempGI));
        for(int j = 0 ; j < K ; ++j){
            scanf("%d",&tempS);
            App[i].school[j] = tempS;
        }
    }
    sort(App,App+N,compare);
    //标记排名
    int Rank = 1;
    App[0].Rank = 1;
    for(int i = 1 ; i<N;++i){
        if(App[i].GF == App[i-1].GF && App[i].GE == App[i-1].GE){
            App[i].Rank = App[i-1].Rank;
        }else{
            App[i].Rank = i + 1;
        }
    }


    //录取
    for(int i = 0 ; i < N ;++i){
        for(int j = 0 ; j < K ; ++j){
            if(schools[App[i].school[j]].Now < schools[App[i].school[j]].Max){
                //录取成果
                schools[App[i].school[j]].App[schools[App[i].school[j]].Now++] = App[i].ID;
                schools[App[i].school[j]].Rank = App[i].Rank;
                break;
            }else{
                if(App[i].Rank == schools[App[i].school[j]].Rank){
                    schools[App[i].school[j]].App[schools[App[i].school[j]].Now++] = App[i].ID;
                    break;
                }
            }
        };
    }
    //结果
    for(int i=0 ; i<M;++i){
        if(schools[i].Now==0){
            printf("\n");
        }else{
            sort(schools[i].App,schools[i].App+schools[i].Now);
            for(int j = 0; j < schools[i].Now;++j){
                if(j == schools[i].Now-1){
                    printf("%d", schools[i].App[j]);
                }else{
                    printf("%d ", schools[i].App[j]);
                }

            }
            printf("\n");
        }
    }




















}