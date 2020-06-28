#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <string>
#include <iostream>

using  namespace std;
const int maxN = 2510;
struct Course{
    vector<string> stu;
}courses[maxN];


bool cmp(string a ,string b){
    return (a<b);
}

int main(){
    int N,K;
    int k,n;
    string name;
    scanf("%d %d",&N,&K);
    for(int i = 0 ; i < N ;++i){
        cin >> name;
        scanf("%d",&k);
        for(int j = 0 ; j < k;j++){
            scanf("%d",&n);
            courses[n].stu.push_back(name);
        }
    }

    for(int i = 1; i <= K ; ++i){
        printf("%d %lu\n",i,courses[i].stu.size());
        sort(courses[i].stu.begin(),courses[i].stu.end(),cmp);
        for(int j =0;j<courses[i].stu.size();++j){
            cout << courses[i].stu[j];
            printf("\n");

        }

    }



}