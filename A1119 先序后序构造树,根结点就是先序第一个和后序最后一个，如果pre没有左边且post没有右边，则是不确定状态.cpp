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


const int maxN =31;
vector<int> pre;
vector<int> post;
bool isunique = true;
vector<int> in;
void findIn(int preL,int preR,int postL,int postR){
    //到达边界，肯定是根
    if(preL == preR){
        in.push_back(pre[preL]);
        return ;
    }
    //如果当前序列能形成树
    if(pre[preL] == post[postR]){

        //找孩子的根 (preL+1 ~ preR（先） postL~postR-1(后)
        //如果在孩子中：先序的某一个点和后序的最后一个点相同，那就是根)
        int i = preL + 1;
        while (i <= preR && pre[i] != post[postR-1]) ++i;
        //判断孩子能否划分成左右子树，方法就是看孩子先序的左边长度是否为0？
        int len = i-preL-1;
        if(len > 0){
            //确定状态，根结点的左边和右边都有至少一个1结点，那么就表明能成功分出左右子树
            findIn(preL+1,i-1,postL,postL+len-1);
        }else{
            //不确定状态，i-preL<=1 表示先序的左边没有东西，无法区分左右子树，因此只能将其默认为(右子树)左子树也可以
            //例如： [1] 3 2 4 6 7 5
            //      2 6 7 4 5 3 [1]
            //      初始状态，不用判断
            //      1: 1是根结点，(3 2 4 6 7 5为先序的所有孩子) (2 6 7 4 5 3为后序的所有孩子）
            //      1 【(3) 2 4 6 7 5】
            //      【2 6 7 4 5 (3)】 1
            //      发现 孩子的左边长度len=0，表示无法区分剩余右边序列是左子树还是右子树。

            isunique = false;
        }
        //对于不确定的，直接当右子树处理
        in.push_back(post[postR]);
        findIn(i,preR,postL+len,postR-1);

    }

}
int main(){
    int N;
    scanf("%d", &N);
    pre.resize(N), post.resize(N);
    for (int i = 0; i < N; i++)
        scanf("%d", &pre[i]);
    for (int i = 0; i < N; i++)
        scanf("%d", &post[i]);
    findIn(0, N-1, 0, N-1);
    printf("%s\n%d", isunique ? "Yes" : "No", in[0]);
    for (int i = 1; i < in.size(); i++)
        printf(" %d", in[i]);
    printf("\n");
    return 0;


}