#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
struct Student{
    char ID[10];
    int V;
    int T;
    int type;
    int ALL;
}Stu[100010];


bool compare(Student a,Student b){
    if(a.type != b.type){
        return a.type<b.type;
    }else{
        if(a.ALL != b.ALL){
            return a.ALL > b.ALL;
        }else{
            if(a.V != b.V){
                return a.V>b.V;
            }else{
                return strcmp(a.ID,b.ID)<0;
            }

        }

    }
}
int main(){
    int N,H,L,v,t,type,num=0;
    char temp[10];
    scanf("%d %d %d",&N,&L,&H);
    while(N--){
        scanf("%s %d %d",temp,&v,&t);
        if( v < L || t < L){
            continue;
        }
        else if(v>=H && t>=H){
            type = 1;//圣人
        }
        else if(v>=H && t<H){
            type = 2;//君子
        }
        else if(v < H && t < H){
            if(v >= t){
                type = 3;//笨比
            }else{
                type = 4;//小人
            }
        }
        else{
                type = 4;//小人
        }
        strcpy(Stu[num].ID,temp);
        Stu[num].V = v;
        Stu[num].T = t;
        Stu[num].ALL = v+t;
        Stu[num++].type = type;
    }

    //排序
    sort(Stu,Stu+num,compare);
    printf("%d\n",num);
    for(int i = 0 ; i < num ; ++i){
        printf("%s %d %d\n",Stu[i].ID,Stu[i].V,Stu[i].T);
    }


}