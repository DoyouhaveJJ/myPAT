#include <string.h>
#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
using  namespace std;
const int maxN=1010;
struct bign{
    int d[maxN];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len = 0;
    };
};

//字符串变为大整数
bign change(char str[]){
    bign a;
    a.len = strlen(str);
    //逆序存
    for(int i = 0 ;i < a.len ; ++i){
        a.d[i] = str[a.len-i-1] - '0';
    }
    return a;
}



//除法， r是余数
bign divide(bign a,int b,int &r){
    bign c;
    c.len = a.len;//c是商
    //倒着除
    for(int i = a.len-1 ; i >= 0 ; --i){
        r = r*10 + a.d[i];//要和上一位的余数结合 相当于进位
        if(r < b){
            //除不完
            c.d[i] = 0;
        }else{
            c.d[i] = r/b;
            r = r % b;//新的余数
        }
    }
    //去除高位的0 有0 且保持至少有一位
    while (c.len - 1 >= 1 && c.d[c.len - 1] ==0){
        c.len--;
    }
    return c;

}



bign mutiple(bign a,int b){
    bign c;
    c.len = a.len;
    int temp=0,carry=0;
    for(int i = 0 ; i < a.len ; ++i){
        temp = b*a.d[i]+carry;
        c.d[i] = temp % 10;
        carry = temp / 10;
    }
    while (carry!=0){
        c.d[c.len++] = carry % 10;
        carry /= 10;
    }
    //去除高位0
    while (c.len-1 >= 1 && c.d[c.len - 1] == 0){
        c.len --;
    }
    return c;
}


void print(bign a){
    for(int i = a.len-1;i>=0;--i){
        printf("%d",a.d[i]);
    }
}

int main(){
    char str1[maxN];
    int b , r = 0;
    int flag1[10]={0};
    int flag2[10]={0};
    bool p=true;
    scanf("%s",str1);
    bign a = change(str1);
    bign res = mutiple(a,2);
    for(int i = 0 ; i < res.len; ++i){
        flag1[res.d[i]]++;
    }
    for(int i = 0 ; i < a.len; ++i){
        flag2[a.d[i]]++;
    }
    for(int i = 0 ; i < 10 ; ++i){
        if(flag1[i] != flag2[i]){
            p = false;
            break;
        }
    }

    if(p){
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    print(res);
}