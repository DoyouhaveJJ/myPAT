#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

struct submitons{
    char id[6];
    int p_id;
    int score;
}S[100010];

struct user_info{
    char id[6];
    int score[5];
    int total;
    int prefect;
    bool success;
}userInfo[10010];

//排序
bool compare_id(submitons a,submitons b){
    return strcmp(a.id,b.id) < 0;
}

bool compare(user_info a,user_info b){
    if(a.total == b.total){
        if(a.prefect == b.prefect){
            return strcmp(a.id,b.id)<0;
        }else{
            return a.prefect>b.prefect;
        }
    }else{
        return a.total>b.total;
    }
}
void print_info(user_info a,int N){
    printf(" %s %d",a.id,a.total);
    for(int i = 1;i<=N;++i){
        if( a.score[i] ==-2){
            printf(" -");
        }else{
            if(a.score[i] ==-1)
                printf(" 0");
            else
                printf(" %d",a.score[i]);
        }
    }

}
int main(){
    int full_mark[5];
    int N,K,M,user_count=0;
    scanf("%d %d %d",&N,&K,&M);
    for(int i = 0 ; i < K ; ++i){
        scanf("%d",&full_mark[i]);
    }
    for(int i  = 0 ; i < M;++i){
        scanf("%s %d %d",S[i].id,&S[i].p_id,&S[i].score);
    }
    sort(S,S+M,compare_id);

    char temp_id[6]={'0'};
    //第一个学生赋值

    for(int i  = 0 ; i < M;++i){
        //学号不同，则新建一个学生
        if(strcmp(S[i].id,temp_id)!=0){
            user_count++;
            strcpy(temp_id,S[i].id);
            strcpy(userInfo[user_count].id,temp_id);
            //初始化成绩
            for(int j = 0 ; j <= K ; ++j){
                userInfo[user_count].score[j] = -2;
            }
        }
        if(S[i].score == -1){
            userInfo[user_count].score[S[i].p_id] = -1;
        }
        if(userInfo[user_count].score[S[i].p_id] < S[i].score)
            userInfo[user_count].score[S[i].p_id] = S[i].score;

    }

    for(int i = 1 ;i<=user_count; ++i){
        int flag = false;
        int total = 0,prefect = 0;
        for(int j = 1 ; j <= K ; ++j){
            if(userInfo[i].score[j]==-2 || userInfo[i].score[j]==-1)
                continue;
            flag = true;
            if(userInfo[i].score[j] == full_mark[j-1] ){
                prefect++;
            }
            total += userInfo[i].score[j];
        }
        userInfo[i].success = flag;
        userInfo[i].total = total;
        userInfo[i].prefect = prefect;
    }

    sort(userInfo+1,userInfo+user_count+1,compare);
    int rank = 1;
    printf("%d",rank);
    print_info(userInfo[1],K);
    printf("\n");
    for (int i = 2; i <= user_count; ++i) {
        if(userInfo[i].success){
            if(userInfo[i].total == userInfo[i-1].total){
                rank = rank;
            }else{
                rank = i ;
            }
            printf("%d",rank);
            print_info(userInfo[i],K);
            printf("\n");
        }
    }
}


