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
const int maxN=10020;
struct Person{
    string name;
    int height;
}person[maxN];

bool cmp(Person a,Person b){
    if(a.height!=b.height){
        return a.height > b.height;
    }else{
        return a.name < b.name;
    }
}
int main(){
    int N,K;
    int rows[12];
    cin >> N >> K;
    for(int i = 1 ; i <= N ; ++i){
        cin >> person[i].name >> person[i].height;
    }
    sort(person+1,person+N+1,cmp);
    //每一行多少人
    int m = N/K;
    int extra = N % K;
    for(int i = 1 ; i <= K ; ++i){
        rows[i] = m;
    }
    rows[K] += extra;
    int counter = 1;
    //处理每一行
    for(int i = K ; i > 0 ; --i ){
        int num = rows[i];
        vector<int> p(num+1);
        int mid = num/2+1;
        //方向编号
        p[mid]=counter++;
        int dir = 1;
        for(int j = 1 ; j < num ; ++j){
            if(j % 2==0){
                p[mid + dir] = counter++;
                dir++;
            }else{
                p[mid - dir] = counter++;
            }
        }

        for(int j = 1 ; j <= num ;++j){
            cout << person[p[j]].name;
            if(j < num )
                cout << " ";
        }
        cout << endl;

    }




}