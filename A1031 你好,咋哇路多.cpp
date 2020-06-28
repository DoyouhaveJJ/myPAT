#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
    char words[81];
    scanf("%s",words);
    int len = strlen(words),n1,n2,n3;
    n3 = n1 =(len + 2) / 3;
    n2 = len - n1 - n3 + 2;
    for(int i = 0 ; i < n1 ; ++i){
        //打印空格
        printf("%c",words[i]);
        if(i == n1 - 1){
            while (i < n1 + n2 -2){
                printf("%c",words[++i]);
            }
            break;
        }else{
            for(int j = 0 ; j < n2-2;++j){
                printf(" ");
            }
        }
        printf("%c",words[len-1-i]);
        printf("\n");
    }


}