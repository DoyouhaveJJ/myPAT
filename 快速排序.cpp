#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
//快速排序 ，两点法
int Partition(int A[],int left,int right){
    int temp = A[left];
    while (left < right){
        while (A[right] > temp && right > left) right--;
        A[left] = A[right];
        while (A[left] <temp &&right>left) left++;
        A[right] = A[left];
    }
    A[left] = temp;
    return left;
}

void QuickSort(int A[],int left,int right){
    if(left < right){
        int mid = Partition(A,left,right);
        QuickSort(A,left,mid-1);
        QuickSort(A,mid+1,right);
    }
}

int main(){
    //快速排序
    int A[8] = {6,21,3,52,4,24,2,99};
    QuickSort(A,0,7);
    for(int i:A){
        printf("%d ",i);
    }
}