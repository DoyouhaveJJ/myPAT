#include <string>
//#include <cstdio>
//#include <algorithm>
//#include <map>
//#include <math.h>
//#include <iostream>


using namespace std;
const int maxLen = 10010;
int main(){
    char A[maxLen];
    char B[maxLen];
    int bMap[10000]={0};
    gets(A);
    gets(B);
    int lenA = strlen(A),lenB = strlen(B);
    for(int i = 0 ;i < lenB ; ++i){
        bMap[(int)B[i]] = 1;
    }
    for(int i = 0 ; i < lenA;++i){

        if(bMap[(int)A[i]])
            continue;

        printf("%c",A[i]);

    }

}

