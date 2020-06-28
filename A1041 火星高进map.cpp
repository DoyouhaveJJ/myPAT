#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;
const int MaxN = 100010;
int main(){
    map<int,int> bMap;
    bool flag = false;
    int N,number[MaxN];
    scanf("%d",&N);
    for(int i= 0  ; i < N; ++i){
        scanf("%d",&number[i]);
        bMap[number[i]]++;
    }
    for(int i= 0  ; i < N; ++i){
        if(bMap[number[i]]==1){
            N = number[i];
            flag = true;
            break;
        }
    }
    if(flag){
        printf("%d",N);
    }else{
        printf("None");
    }


}