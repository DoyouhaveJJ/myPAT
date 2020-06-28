#include <stdio.h>

int main() {
    double P1[21];
    double P2[21];
    double res[41];
    int i,j,k=1,count=0;
    scanf("%lf",P1);
    for(i = 1 ; i<= (2*P1[0]) ; ++i){
        scanf("%lf",P1+i);
    }

    scanf("%lf",P2);
    for(i = 1 ; i<= (2*P2[0]) ; ++i){
        scanf("%lf",P2+i);
    }

    for(i=1,j=1;(i <= (2*P1[0])) && (j <= (2*P2[0]));){
        if(P1[i] < P2[j]){
            count += 1;
            res[k] = P2[j];
            res[k+1] = P2[j+1];
            j += 2;
            k += 2;
        }
        else if(P1[i] > P2[j]){
            count += 1;
            res[k] = P1[i];
            res[k+1] = P1[i+1];
            i += 2;
            k += 2;
        }
        else{
            if(P1[i+1] + P2[j+1] == 0){
                i += 2;
                j += 2;
                continue;
            }else{
                count += 1;
                res[k] = P1[i];
                res[k+1] = P1[i+1]+ P2[j+1];
                j += 2;
                i += 2;
                k += 2;
            }
        }
    }
    while(i <= (2*P1[0])){
        res[k++] = P1[i++];
        res[k++] = P1[i++];
        count += 1;
    }
    while (j <= (2*P2[0])){
        res[k++] = P2[j++];
        res[k++] = P2[j++];
        count += 1;
    }

    res[0] = count;
    printf("%d",(int)res[0]);
    for(k = 1; k <= (2*res[0]);k+=2){
        printf(" %d %.1lf",(int)res[k],res[k+1]);
    }
    return 0;
}