#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

typedef long long LL;
const int maxN = 200010;

int main(){
    LL N,nArray[maxN],M,mArray[maxN];
    scanf("%lld",&N);
    for(LL i = 0 ; i < N;++i){
        scanf("%lld",&nArray[i]);
    }
    scanf("%lld",&M);
    for(LL i = 0 ; i < M;++i){
        scanf("%lld",&mArray[i]);
    }
    LL i=0,j=0,index= 0,target = (((N+M)/2) - ((N+M+1)%2));
    LL numNow=0;
    if(N == 0 ){
        printf("%lld",mArray[target]);
        return 0;
    }
    if(M == 0 ){
        printf("%lld",nArray[target]);
        return 0;
    }
    if(N == 0 && M == 0){
        return 0;
    }
    while (i + j < N + M){
        if(i < N && j < M){
            if(nArray[i] < mArray[j]){
                numNow = nArray[i++];
                index ++;
            }else{
                numNow = mArray[j++];
                index ++;
            }
        }else if(i < N && j >= M){
            numNow = nArray[i++];
            index ++;
        }else if(i >= N && j < M){
            numNow = mArray[j++];
            index ++;
        }else{
            return 0;
        }
        if(index - 1 == target){
            printf("%lld",numNow);
            break;
        }
    }


}
