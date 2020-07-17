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
//number的个数
int numbers[100010];
//0~i*316-1
int blocks[316];
void add(int a){
    //在第几块？
    int b = a / 316;
    blocks[b]++;
    numbers[a]++;
}

void remove(int a){
    //在第几块
    int b = a/316;
    blocks[b]--;
    numbers[a]--;
}

int peekMedian(int index){
    //枚举块
    int temp = 0;
    int i = 0,j=0;
    while(temp + blocks[i] < index){
        temp += blocks[i++];
    }
    j=i*316;
    while(temp + numbers[j] < index){
        temp += numbers[j++];
    }
    return j;
}

int main(){
    int N;
    stack<int> S;
    string op;
    int num;
    cin >> N;
    for(int i = 0 ; i < N;++i){
        cin >> op;
        if(op=="Pop"){
            if(S.empty()){
                cout << "Invalid"<<endl;
                continue;
            }else{
                remove(S.top());
                cout << S.top() << endl;
                S.pop();
            }
        }
        if(op=="PeekMedian"){
            if(S.empty()){
                cout << "Invalid"<<endl;
                continue;
            }else{
                int s = S.size();
                cout << peekMedian(s%2==1?(s+1)/2:s/2)<<endl;
            }
        }
        if(op=="Push"){
            cin >> num;
            S.push(num);
            add(num);
        }

    }

}
