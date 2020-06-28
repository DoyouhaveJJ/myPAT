#include <string>
#include <cstdio>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

int n;//有效位数
//处理字符串 - 处理数
//s:要处理的数字 e指数
string deal(string s,int &e){
    int k = 0;//小数点后的位置
    //去除前面的0
    while (s.length() > 0 && s[0] == '0'){
        s.erase(s.begin());
    }

    //是否是小于1的数
    if(s[0]=='.'){
        //去除小数点
        s.erase(s.begin());
        //去除小数点后的所有0，并计数
        while (s.length() > 0 && s[0]=='0'){
            s.erase(s.begin());
            //小数点后去掉一个0，指数要-1
            e--;
        }
    }else{
        //找到小数点
        while (k < s.length() && s[k]!='.'){
            k++;
            e++;
        }
        //说明小数点存在
        if(k < s.length()){
            //删除小数点
            s.erase(s.begin()+k);
        }
    }
    //删完了
    if(s.length() == 0){
        e = 0;
    }


    int num = 0;
    k = 0;
    string res;
    //精度n
    while (num < n){
        if(k < s.length())
            res += s[k++];
        else
            res += '0';
        num++;
    }
    return res;


}
int main(){
    string s1,s2,s3,s4;
    cin >> n >> s1 >> s2;
    int e1 =0 , e2 = 0;
    s3 = deal(s1,e1);
    s4 = deal(s2,e2);
    if(s3==s4 && e1 == e2){
        cout << "YES 0." << s3 << "*10^" << e1 << endl;
    }else{
        cout << "NO 0." << s3 << "*10^" << e1<<" 0." <<s4<< "*10^" << e2 << endl;
    }
    return 0;
}


