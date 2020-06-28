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

bign reverse(bign a){
    bign b;
    b.len = a.len;
    for(int i = 0 ; i < a.len;++i){
        b.d[i] = a.d[a.len - 1 -i];
    }
    return b;
}


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


bign add(bign a,bign b){
    bign c;
    c.len = max(a.len,b.len);
    int carry = 0;
    for(int i = 0 ; i < c.len ; i++){
        c.d[i]=(a.d[i] + b.d[i] + carry)%10;
        carry = (a.d[i] + b.d[i]) / 10;
    }
    while (carry!=0){
        c.d[c.len++] = (carry%10);
        carry /=10;
    }

    while (c.len - 1 >= 1 && c.d[c.len-1]==0){
        c.len--;
    }
    return c;
}

bool judge(bign a){
    for(int i = 0 ; i <= a.len/2 ; ++i){
        if(a.d[i] != a.d[a.len - 1 -i]){
            return  false;
        }
    }
    return true;
}

void print(bign a){
    for(int i = a.len-1;i>=0;--i){
        printf("%d",a.d[i]);
    }
}

int main(){
    char str1[maxN];
    int step;
    scanf("%s %d",str1,&step);
    bign a,b,c;
    a = change(str1);
    b = reverse(a);
    c = a;
    int i = 0;
    for(; i < step ;++i){
        if(judge(c)){
            break;
        }
        c=add(a,b);
        a = c;
        b = reverse(c);
    }
    print(c);
    printf("\n%d\n",i);

}