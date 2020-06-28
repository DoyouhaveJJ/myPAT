#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <string>

#include <iostream>

using  namespace std;




int main(){
    int N,M,c;
    map<int,int> cMap;
    scanf("%d %d",&M,&N);
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < M;++j){
            scanf("%d",&c);
            cMap[c]++;
        }
    }

    /*
    map.find()!=map.end()
     * */
    int color,max=0;
    for(map<int,int>::iterator it = cMap.begin();it!=cMap.end();++it){
        if(it->second > max){
            color = it->first;
            max = it->second;
        }
    }
    printf("%d",color);


}