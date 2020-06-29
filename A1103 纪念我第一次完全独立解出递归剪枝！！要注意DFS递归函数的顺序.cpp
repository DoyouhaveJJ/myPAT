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

int res[400],maxres[400];
bool finded=false;
int N,K,p;
int pow(int a,int b){
    int resa=1;
    for(int i = 0 ; i < b; ++i){
        resa*=a;
    }
    return resa;
}

bool cmp(){
    int resa=0,resb=0;
    for(int i = 1 ; i <= K;++i){
        resa+=res[i];
        resb+=maxres[i];
    }
    if(resa!=resb){
        return resa>resb;
    }else{
        for(int i = 1 ; i <= K;++i){
            if(res[i]!=maxres[i]){
                return res[i]>maxres[i];
            }
        }
    }
    return false;
}

void change(){
    finded = true;
    for(int i = 1 ; i <= K;++i){
        maxres[i] =res[i];
    }
}

void DPS(int now,int deep,int next){
    if(deep > K){
        return;
    }
    for(int i = next ; i <= 400 ; ++i){
        int temp = pow(i,p);
        res[deep]=i;
        if(now + temp > N){
            return;
        }else if(now + temp == N && deep == K){
            if(cmp()){
                change();
            }
        }else{
            DPS(now + temp,deep+1,i);
        }
    }
}


int main() {

    cin >> N >> K >> p;
    DPS(0,1,1);
    if(finded){
        printf("%d =",N);
        for(int i = K ; i >= 1;--i){
            printf(" %d^%d",maxres[i],p);
            if(i!=1){
                printf(" +");
            }
        }
    }else{
        printf("Impossible");
    }


}