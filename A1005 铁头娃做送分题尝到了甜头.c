#include <stdio.h>
void Print(int num);
char words[10][10]={{'z','e','r','o'},
                    {'o','n','e'},
                    {'t','w','o'},
                    {'t','h','r','e','e'},
                    {'f','o','u','r'},
                    {'f','i','v','e'},
                    {'s','i','x'},
                    {'s','e','v','e','n'},
                    {'e','i','g','h','t'},
                    {'n','i','n','e'},
};

int main(void) {
    char number[100]={'\0'};
    scanf("%s",number);
    int i = 0,sum = 0;
    for(i = 0 ; number[i]!='\0';++i){
        sum += (number[i] - '0');
    }
    if(sum == 0){
        printf("%s",words[0]);
        return 0;
    }
    Print(sum);
}

void Print(int num){
    if(num == 0){
        return;
    }
    Print(num / 10);
    if(num < 10){
        printf("%s",words[num%10]);
    }else{
        printf(" %s",words[num%10]);
    }
}
