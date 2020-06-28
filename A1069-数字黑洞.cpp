#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

void turn_array(int N,int A[]){
    for(int i = 0 ; i < 4;i++){
        A[3-i] = N % 10;
        N /= 10;
    }
}
int pow(int a){
    if(a==0)
        return 1;
    int sum = 1;
    while (a--){
        sum *= 10;
    }
    return sum;
}
int turn_int(int A[]){
    int sum = 0;
    for(int i = 0 ; i  < 4;i++){
        sum += pow(3-i)*A[i];
    }
    return sum;
}

bool desc(int a,int b){
    return a<b;
}
bool asc(int a,int b){
    return a>b;
}

void print_array(int Array[]){
    for(int i = 0 ; i < 4 ; ++i){
        printf("%d",Array[i]);
    }
}
int main(){
    int N,M,N_array[4];
    int count = 0;
    scanf("%d",&N);

    turn_array(N,N_array);
    while(true){
        if(N == 0){
            break;
        }
        sort(N_array , N_array+4 ,asc);
        print_array(N_array);
        N = turn_int(N_array);
        printf(" - ");
        sort(N_array , N_array+4 ,desc);
        print_array(N_array);
        M = turn_int(N_array);
        N = N - M;
        turn_array(N,N_array);
        printf(" = ");
        print_array(N_array);
        if(N != 6174){
            printf("\n");
        }
        if(N == 6174){
            break;
        }
    }

}