#include <string.h>
#include <stdio.h>
//#include <algorithm>

void reverst(char sentence[]){
    char temp;
    int len = strlen(sentence);
    for(int i = 0 ; i < len/2;++i){
        temp = sentence[len-1-i];
        sentence[len-i-1] = sentence[i];
        sentence[i]=temp;
    }

}

int main(){
   int N,maxlen=0,num=0;
   char sentence[100][257],first[257];
   scanf("%d",&N);
   getchar();//接受换行符
   for(int i = 0 ; i < N;++i){
       gets(sentence[i]);
       if(strlen(sentence[i]) > maxlen){
           maxlen = strlen(sentence[i]);
       }
       reverst(sentence[i]);
   }
   bool flag = true;
    for(int i = 0 ; i < maxlen;++i){
        char temp;
        temp = sentence[0][i];
        for(int j = 0 ; j < N ; ++j){
            if(temp != sentence[j][i]){
                flag = false;
            }
        }
        if(flag){
            first[num++] = temp;
        }else{
            break;
        }
    }
    if(num==0){
        printf("nai");
    }else{
        while(num--){
            printf("%c",first[num]);
        }
    }


}