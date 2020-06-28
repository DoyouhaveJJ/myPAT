#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
int main(){
    char S[100010];
    int leftP[100010]={0},rightT[100010]={0};
    scanf("%s",S);
    int i=0 , sum = 0;
    //初始化数组
    leftP[0]=0;
    while (S[i] != '\0'){
        if(S[i] == 'P')
            leftP[i+1] = leftP[i]+1;
        else
            leftP[i+1] = leftP[i];
        i++;
    }

    while (i>0){
        if(S[i]=='T')
            rightT[i-1]=rightT[i]+1;
        else
            rightT[i-1]=rightT[i];
        i--;
    };

    while (S[i] != '\0'){
        if(S[i] == 'A')
            sum = (sum + leftP[i]*rightT[i])%1000000007;
        i++;
    }

    printf("%d\n",sum);
}