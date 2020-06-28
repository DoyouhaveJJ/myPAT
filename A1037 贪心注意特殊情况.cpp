#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>
#include <iostream>
#include <queue>

using namespace std;
const int maxN = 100010;


int main(){
    int coupons[maxN],items[maxN];
    int clow=0,chigh,ilow=0,ihigh;
    int Nc=0,Np=0;
    scanf("%d",&Nc);
    for(chigh=0;chigh<Nc;chigh++){
        scanf("%d",&coupons[chigh]);
    }

    scanf("%d",&Np);
    for(ihigh=0;ihigh<Nc;ihigh++){
        scanf("%d",&items[ihigh]);
    }
    sort(coupons,coupons+chigh);
    sort(items,items+ihigh);
    int ans = 0;
    int breakpoint = 0;
    //找 - -
    for(int i = 0 ; i < chigh && i < ihigh ; ++i){
        breakpoint = i;
        if(coupons[i] * items[i] >0){
            ans += coupons[i] * items[i];
        }else{
            break;
        }
    }
    clow = ilow = breakpoint;
    if(!(breakpoint == Nc - 1 || breakpoint == Np -1)){
        //找 + +
        while (coupons[clow] < 0){
            clow++;
        }
        while (items[ilow] < 0){
            ilow++;
        }
        while (chigh > clow && ihigh > ilow){
            ans += coupons[--chigh]*items[--ihigh];
        }
    }

    printf("%d",ans);


}
