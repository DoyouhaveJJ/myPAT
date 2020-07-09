
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
#define INF 1e9


using namespace std;

const int maxN = 101;


int main(){
    int N;
    bool human[101]={true}; //是人类？
    bool definded[101]={false}; //是人类？
    int describe[101];
    cin >> N;
    string desc;
    for(int i = 1 ; i <= N; ++i){
        cin >> desc;

        if(desc[0] == '+'){
            desc.erase(desc.begin());
            describe[i] =stoi(desc);
        }
        if(desc[0] == '-'){
            desc.erase(desc.begin());
            describe[i] =-stoi(desc);
        }

    }

    //找狼人
    bool flag = false;
    for(int i = 1; i <= N ; ++i){
        if(flag)
            break;
        for(int j = i+1 ; j <=N ;++j){
            if(flag)
                break;
            if(i == j){
                continue;
            }
            memset(human,true, sizeof(human));
            human[i] = human[j] = false;
            int lair = 0;
            int wolflaier = 0;
            for(int k = 1 ;k <= N ; ++k){
                if(describe[k] < 0 && human[abs(describe[k])]==true){
                    lair ++;
                    if(k== i || k == j){
                        wolflaier ++;
                    }

                }
                else if(describe[k] > 0 && human[abs(describe[k])]==false){
                    lair ++;
                    if(k== i || k == j){
                        wolflaier ++;
                    }
                }
            }
            if(lair == 2 && wolflaier == 1){
                flag = true;
                printf("%d %d",i,j);
            }




        }
    }

    if(!flag){
        printf("No Solution");
    }
}