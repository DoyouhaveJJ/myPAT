#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;


int Primary[100010];
bool flag[100010] = {false};
int maxN = 100010,counter = 0;
long int N;

//筛选法
void Find_Primary(){
    for(int i = 2 ; i < maxN ; ++i){
        if(!flag[i]){
            if(counter >= maxN) break;
            Primary[counter++] = i;
            for(int j = i+i ; j < maxN ; j+=i){
                flag[j] = true;
            }
        }
    }
}

struct Factors{
    int num;
    int amount;
}fac[12];
int main(){
    Find_Primary();
    int index1 = 0,index2 = 0;
    int Number,temp;
    scanf("%d",&Number);
    temp = Number;
    if(Number == 1){
        fac[index1].num = 1;
        fac[index1++].amount = 1;

    }else{
        while (Number > Primary[index2] ){
            if(Number % Primary[index2] == 0){
                fac[index1].amount = 0;
                fac[index1].num = Primary[index2];
                while (Number % Primary[index2] == 0 ){
                    fac[index1].amount ++ ;
                    Number /= Primary[index2];
                }
                index2++;
                index1++;
            }else{
                index2++;
            }

        }
    }



    if(Number > 1){
        fac[index1].num = Number;
        fac[index1++].amount = 1;
    }

    printf("%d=",temp);
    for(int i = 0 ; i < index1 ;++i){
        printf("%d",fac[i].num);
        if(fac[i].amount > 1){
            printf("^%d",fac[i].amount);
        }
        if(i < index1-1){
            printf("*");
        }
    }

}