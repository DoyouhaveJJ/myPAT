#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
struct Node{
    char data;
    int next;
    bool flag;
}nodes[100010];


int main(){
    int s1,s2,N;
    int temp_add,temp_next;
    char temp_data;
    scanf("%d %d %d",&s1,&s2,&N);
    for(int i = 0 ; i < 100010;++i){
        nodes[i].next = -1;
        nodes[i].flag = false;
    }
    for(int i = 0 ; i < N ; ++i){
        scanf("%d %c %d",&temp_add,&temp_data,&temp_next);
        nodes[temp_add].next = temp_next;
        nodes[temp_add].data = temp_data;
    }
    temp_add = s1;
    while (nodes[temp_add].next!= -1){
        nodes[temp_add].flag=true;
        temp_add = nodes[temp_add].next;
    }
    temp_add = s2;
    while (nodes[temp_add].next!= -1 && !nodes[temp_add].flag){
        temp_add = nodes[temp_add].next;
    }
    if(nodes[temp_add].next == -1){
        printf("-1");
    }else{
        printf("%05d",temp_add);
    }



}