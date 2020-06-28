#include <stdio.h>
#include <stdlib.h>
struct Node{
    char ID[16];
    int In;
    int Out;
    struct Node *next;

}Head;
int turn(char time[8]);
void find(struct Node *p);
int make_record(char temp[3][16],char ID[15],int *In,int *Out);

struct Node *e,*l;
int main(){
    int M;
    scanf("%d",&M);
    struct Node *p ;
    p = &Head;
    char temp[3][16];
    if(M == 0){
        return 0;
    }
    while (M--){
        struct Node *record = (struct Node*)malloc(sizeof(struct Node));
        scanf("%s %s %s",temp[0],temp[1],temp[2]);
        make_record(temp,record->ID,&record->In,&record->Out);
        p->next = record;
        p = record;

    }
    find(Head.next);
    printf("%s %s",e->ID,l->ID);
}
//1 找最早 0 找最迟
void find(struct Node *p){
    int eariest = 86401;
    int last = -1;

    while (p!=NULL){
        if(p->In < eariest){
            eariest = p->In;
            e = p;
        }
        if(p->Out > last){
            last = p->Out;
            l = p;
        }
        p=p->next;
    }
}

int turn(char *time){
    return (3600*(10*(time[0]-'0')+1*(time[1]-'0')))+(60*(10*(time[3]-'0')+1*(time[4]-'0')))+(10*(time[6]-'0')+1*(time[7]-'0'));
}

int make_record(char temp[3][16],char ID[15],int *In,int *Out){
    int i = 0;
    for(i = 0;temp[0][i]!='\0';++i){
        ID[i]=temp[0][i];
    }

    *In = turn(temp[1]);
    *Out = turn(temp[2]);
}