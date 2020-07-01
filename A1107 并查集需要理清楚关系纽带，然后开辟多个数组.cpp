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

//father记录爸爸
int father[1001]={0};
//course记录关系（人-活动）
int course[1001]={0};
//记录每个结点是否是某个集合的根结点
int isRoot[1001]={0};


int findFather(int x){
    int temp = x;

    while (x!=father[x]){
       x= father[x];
    }

    //路径压缩
    while (temp!=father[temp]){
        int temp2 = temp;
        temp = father[temp2];
        father[temp2]=x;
    }

    return x;
}

void Union(int a,int b){
    int fa = findFather(a);
    int fb = findFather(b);
    if(fa!=fb){
        father[fa]=fb;
    }

}

bool cmp(int a , int b){
    return a>b;
}

int main(){
    int N;
    scanf("%d",&N);
    //喜欢活动i的人编号course[i]
    //关键在于找联系的纽带--人， 人将各类活动联系成一个网。

    for(int i = 1 ; i <= 1001 ; i++){
        //各自为伍
        father[i]=i;
        //谁喜欢谁
        course[i]=0;
        isRoot[i]=0;
    }
    for(int i = 1 ; i <= N ; ++i){
        int n;
        scanf("%d:",&n);
        for(int j = 0 ; j < n ; ++j){
            int fav;
            scanf("%d",&fav);
            //第一个喜欢的
            if(course[fav]==0){
                course[fav] = i; //第i个人喜欢fav
            }
            //之后喜欢的合并
            Union(i,findFather(course[fav]));
        }
    }



    //所有活动 每个人的活动的根结点  初始状态一个人一个根，为false
    for(int i = 1 ; i <= N ; ++i){
        isRoot[findFather(i)]++;
    }
    int ans=0;
    //统计根的个数 ， 即总的圈子
    for(int i = 1 ;i <= N ; ++i){
        if(isRoot[i]!=0){
            ans++;
        }
    }
    printf("%d\n",ans);
    sort(isRoot+1,isRoot+N+1,cmp);
    for(int i = 1 ; i <= ans ; ++i){
        printf("%d",isRoot[i]);
        if(i<ans){
            printf(" ");
        }
    }


}