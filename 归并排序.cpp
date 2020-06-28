#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
//归并排序
const int N = 10;
//合并并排序
void Merge(int A[],int L1,int R1,int L2,int R2){
    //L1 ,...., L2 , R1 ,....., R2
    int i = L1 , j = L2;
    int temp[N],index=0;
    while(i <= R1 && j <= R2){
        if(A[i] < A[j]){
            temp[index++] = A[i++];
        }else{
            temp[index++] = A[j++];
        }
    }
    while (i<=R1) temp[index++] = A[i++];
    while (j<=R2) temp[index++] = A[j++];

    for(i = 0 ; i < index ; i ++){
        A[i+L1] = temp[i];
    }
}


void MergeSort(int A[],int left,int right){
    if(left < right){
        int mid = (left + right)/2;
        MergeSort(A,left,mid);
        MergeSort(A,mid+1,right);
        Merge(A,left,mid,mid+1,right);
    }
}
int main(){
    int A[8]= {1,5,66,8,3,9,23,55};
    MergeSort(A,0,7);
    for (int i:A) {
        printf("%d ",i);
    }
}