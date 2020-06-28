#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;

int main(){
   int num,de,res[10010],index=0,temp;
   bool flag=true;
   scanf("%d %d",&num,&de);
   while (num){
       temp = num%de;
       res[index++] = temp;
       num -= temp;
       num /= de;
   }
   for(int i = 0 ; i < index ; ++i){
       if(res[i] != res[index-1-i]){
           flag = false;
       }
   }
   if(flag){
       printf("Yes\n");
   }else{
       printf("No\n");
   }
    for(int i = 0 ; i < index ; ++i){
        if(i == index - 1){
            printf("%d",res[index - 1 - i]);
        }else{
            printf("%d ",res[index - 1 - i]);
        }


    }
}