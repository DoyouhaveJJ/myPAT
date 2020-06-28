#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>
void reverse(char str1[],char str2[]){
    int len = strlen(str1);
    for(int i = 0 ; i < len; ++i){
        str2[len - i - 1] = str1[i];
    }
    str2[len*2]='\0';
}



int main(){
    char str1[1001],str2[1001];
    gets(str1);
    reverse(str1,str2);
    int len = strlen(str1);
    int max=0;
    for(int i = 0 ; i < len; ++i){
        for(int j = 0 ; j < len ; ++j){
            int k = 0;
            if(str1[i] == str2[j]){
                int start = j;
                for(k = 0 ; start+k<len;k++){
                    if(str1[i+k] != str2[start+k]){
                        break;
                    }
                }
            }
            if(max < k){
                max = k;
            }

        }

    }

    printf("%d",max);
}
