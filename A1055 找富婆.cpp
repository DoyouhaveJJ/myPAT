#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

int N,K,age_count[201]={0};

struct People{
    char name[10];
    int age;
    int net_worth;
}people[100010],vaildPeople[100010];

struct Case{
    int M;
    int Amin;
    int Amax;
    int num;
    struct People people[10010];
}cases[1010];

bool compare(People a,People b){
    if(a.net_worth != b.net_worth){
        return a.net_worth>b.net_worth;
    }else{
        if(a.age != b.age){
            return a.age<b.age;
        }else{
            return strcmp(a.name,b.name)<0;
        }
    }

}


int main(){
    int vaildCount = 0;
    scanf("%d %d",&N,&K);
    for(int i = 0 ; i < N ; i++){
        scanf("%s %d %d",people[i].name,&people[i].age,&people[i].net_worth);
    }
    for(int i = 0 ; i < K ; ++i){
        scanf("%d %d %d",&cases[i].M,&cases[i].Amin,&cases[i].Amax);
    }
    sort(people,people+N,compare);
    for(int i = 0 ; i < N ; ++i){
        if(age_count[people[i].age] < 100){
            age_count[people[i].age]++;
            vaildPeople[vaildCount++] = people[i];
        }
    }


    for(int i = 0 ; i < K ;++i){
        printf("Case #%d:\n",i+1);
        int printNum = 0;
        for(int j = 0 ; j<vaildCount && printNum <cases[i].M;++j ){
            if(vaildPeople[j].age >= cases[i].Amin && vaildPeople[j].age <= cases[i].Amax){
                printf("%s %d %d\n",vaildPeople[j].name,vaildPeople[j].age,vaildPeople[j].net_worth);
                printNum++;
            }
        }
        if(printNum == 0){
            printf("None\n");
        }
    }


}


