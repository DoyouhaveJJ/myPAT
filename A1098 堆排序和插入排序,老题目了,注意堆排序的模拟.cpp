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


int main(){
    int N;
    int origin[100],now[100];
    bool flag = true;
    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        cin >> origin[i];
    }

    for(int i= 0 ; i < N ; ++i){
        cin >> now[i];
    }

    //判断插入排序
    int k;
    for(k = 1 ; k < N ;k++ ){
        if(now[k] < now[k-1]) {
            break;
        }
    }
    for(int i = k ; i < N ; i++){
        if(origin[i] != now[i]){
            flag = false;
        }
    }
    if(flag){
        cout <<"Insertion Sort\n";
        //下一步
        int temp = now[k];
        int index = 0;
        for( index = 0 ; index < N ; ++index){
            if(now[index] > now[k]){
                break;
            }
        }

        for(int i = k ; i > index ; --i){
            now[i] = now[i-1];
        }
        now[index] = temp;
    }else{
        cout <<"Heap Sort\n";
        //下一步
        //找堆顶,堆顶就是那个大大的
        int top = 0;
        //找堆尾
        int index=0;

        for(index = N -1 ; index >=0 ; --index){
            if(now[top] > now[index]){
                break;
            }
        }
        //交换头尾
        int temp = now[index];
        now[index] = now[top];
        now[top] = temp;
        index--;
        //向下调整,必然是有左孩子的
        while (top <= index/2){
            //找孩子
            int lchild = 2*(top+1)-1;
            int rchild =2*(top+1);
            int maxchild = lchild,ttemp;
            //没有有右孩子
            if(rchild > index && lchild <= index){
                maxchild = lchild;
                if(now[top] < now[maxchild]){
                    ttemp = now[top];
                    now[top] = now[maxchild];
                    now[maxchild] = ttemp;
                    top = maxchild;
                }
            }
            else{
                if(now[maxchild] < now[rchild]){
                    maxchild = rchild;
                }
                if(now[top] < now[maxchild]){
                    ttemp = now[top];
                    now[top] = now[maxchild];
                    now[maxchild] = ttemp;
                    top = maxchild;
                }
            }




        }
    }


    for(int i = 0 ; i < N; ++i){
        cout << now[i];
        if(i < N - 1){
            cout << " ";
        }
    }

}