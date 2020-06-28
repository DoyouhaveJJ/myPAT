#include <cstring>
#include <cstdio>
#include <algorithm>
#include <math.h>

using namespace std;
struct Node{
    int address;
    int key;
    int next;
    bool flag;

}nodes[100010];
bool cmp(Node a ,Node b){
    if(a.flag && b.flag){
        return a.key<b.key;
    }else{
        return a.flag>b.flag;
    }

}
int main(){
    int N,start,temp_add,temp_key,temp_next,counter = 0;
    scanf("%d %d",&N,&start);
    for(int i = 0;i<100010;++i){
        nodes[i].address=i;
        nodes[i].next=-1;
        nodes[i].flag = false;
    }
    for(int i = 0 ; i < N ; ++i){
        scanf("%d %d %d",&temp_add,&temp_key,&temp_next);
        nodes[temp_add].address = temp_add;
        nodes[temp_add].next=temp_next;
        nodes[temp_add].key = temp_key;
    }
    temp_add = start;
    while (temp_add!=-1){
        nodes[temp_add].flag= true;
        temp_add = nodes[temp_add].next;
        counter++;
    }
    if(counter == 0){
        printf("0 -1\n");
        return 0;
    }
    sort(nodes,nodes+100010,cmp);
    nodes[N-1].next = -1;
    printf("%d %05d\n",counter,nodes[0].address);
    for(int i = 0 ; i < counter ; ++i ){
        if(nodes[i].flag){
            if( i == counter - 1){
                printf("%05d %d -1\n",nodes[i].address,nodes[i].key);
            }else{
                printf("%05d %d %05d\n",nodes[i].address,nodes[i].key,nodes[i+1].address);
            }

        }
    }


}