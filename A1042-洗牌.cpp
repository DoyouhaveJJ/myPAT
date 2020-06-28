#include <iostream>
#include <cstring>
#include <algorithm>
const int N = 54;
char CardType[5] = {'S','H','C','D','J'};

int main() {
    int Start[N+1],End[N+1];
    int Shift[N+1];
    int i,K;
    scanf("%d",&K);
    for(i = 1 ; i <= N ; i++){
        Start[i]=i;
    }
    for(i = 1 ; i <= N; i++){
        scanf("%d", &Shift[i]);
    }
    while(K--){
        for(i = 1 ; i <= N ; i++){
            End[Shift[i]]=Start[i];
        }
        for(i = 1 ; i <= N ; i++)
            Start[i] = End[i];
    }
    for(i = 1 ; i <= N ; i++){
        Start[i]--;
        if(i==N){
            printf("%c%d",CardType[Start[i]/13],Start[i]%13 + 1);
        }else{
            printf("%c%d ",CardType[Start[i]/13],Start[i]%13 + 1);
        }

    }





}