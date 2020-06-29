#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <string>

#include <iostream>

using namespace std;

int main() {
   int N,M,K;
   int seq[1001];
   scanf("%d %d %d",&N,&M,&K);
   for(int i = 0 ; i < K ; ++i){

       bool flag = true;
       for(int j = 0 ; j < M ; ++j){
           scanf("%d",&seq[j]);
       }
       if(N == 0){
           flag = false;
       }
       //检查
       for(int j = 0 ; j < M ; ++j){

           if(seq[0] > N){
               flag = false;
               break;
           }
           if(j > 0 && seq[j] - j > N){
               flag = false;
               break;
           }

           int k = j + 1 ;
           int lastmin = 1002;
           while(k < M && flag) {
               if(seq[k] < seq[j]){
                   if(seq[k] < lastmin){
                       lastmin = seq[k];
                   }else{
                       flag =false;
                   }
               }
               k++;
           }
       }
       if(flag){
           printf("YES\n");
       }else{
           printf("NO\n");
       }

   }
}