

#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student{
    char name[12];
    char gender;
    char ID[12];
    int score;
}Male,Female,temp;//temp用于交换

int main(){
    int N;
    scanf("%d",&N);
    int i=0;
    char name[12];
    char gender;
    char ID[12];
    int score;
    Male.score = 101;
    Male.gender = 'N';
    Female.score = -1;
    Female.gender = 'N';
    while (i < N){
        scanf("%s %c %s %d",name,&gender,ID,&score);
        if(gender=='M'){
            if(Male.score > score){
                strcpy(Male.ID,ID);
                Male.score = score;
                strcpy(Male.name,name);
                Male.gender = gender;
            }
        }else {
            if (Female.score < score) {
                strcpy(Female.ID, ID);
                Female.score = score;
                strcpy(Female.name, name);
                Female.gender = gender;

            }
        }
        i++;
    }
    bool flag = true;
    if(Female.gender != 'N'){
        printf("%s %s\n",Female.name,Female.ID);
    }else{
        printf("Absent\n");
        flag = false;
    }
    if(Male.gender != 'N'){
        printf("%s %s\n",Male.name,Male.ID);
    }else{
        printf("Absent\n");
        flag = false;
    }
    if(flag){
        printf("%d",Female.score-Male.score);
    }else{
        printf("NA");
    }

}