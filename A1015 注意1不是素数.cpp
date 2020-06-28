#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
using  namespace std;
bool pri[100010]={false}; //true=非素数
//计算反转后的
int reverse(int n,int radix){
    stack<int> S;
    while (n){
        S.push(n%radix);
        n/=radix;
    }
    int res=0;
    int temp = 1;
    while (!S.empty()){
        int top = S.top();
        res += top*temp;
        temp*=radix;
        S.pop();
    }
    return res;
}

void init(){
    pri[0] = false;
    pri[1] = true;
    pri[2] = false;
    for(int i = 2;i<100010;++i){
        if(!pri[i]){
            for(int j = i+i;j<100010;j+=i){
                pri[j]=true;
            }
        }
    }
}


int main(){
    int n,radix;
    init();
    while (scanf("%d",&n) !=EOF){
        if(n < 0)
            break;
        scanf("%d",&radix);
        if(!pri[reverse(n, radix)] && !pri[n]){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
}