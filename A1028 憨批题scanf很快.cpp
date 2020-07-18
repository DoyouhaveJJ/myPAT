#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#include <iostream>
#include<unordered_map>
#define INF 0x3fffffff
typedef long long LL;
using namespace std;

struct Student{
    int id;
    string name;
    int grade;
}stu[100010];
bool cmp1(Student a,Student b){
    return a.id<b.id;
}
bool cmp2(Student a,Student b){
    if(a.name!=b.name){
        return a.name < b.name;
    }else{
        return a.id < b.id;
    }
}
bool cmp3(Student a,Student b){
    if(a.grade!=b.grade){
        return a.grade < b.grade;
    }else{
        return a.id < b.id;
    }
}
int main(){
    int N,M;
    cin >> N >> M;
    for(int i = 0 ; i < N ; ++i){
        scanf("%d",&stu[i].id);
        cin >>  stu[i].name ;
        scanf("%d",&stu[i].grade);
    }
    if(M==1){
        sort(stu,stu+N,cmp1);
    }else if(M==2){
        sort(stu,stu+N,cmp2);
    }else if(M==3){
        sort(stu,stu+N,cmp3);
    }
    for(int i = 0 ; i < N ; ++i){
        printf("%06d ",stu[i].id);
        cout << stu[i].name;
        printf(" %d\n", stu[i].grade);

    }


}
