#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <string>

#include <iostream>



using namespace std;

struct Node{
    int id;
    int procuctAmount ;
    int deep;
    vector<int> childres;
}node[100010];
//层次遍历
queue<int> level(int root){
    queue<int> res;
    node[root].deep = 1;
    queue<int> Q;
    Q.push(root);
    while (!Q.empty()){

        int now = Q.front();
        Q.pop();
        //如果是根
        if(node[now].childres.empty()){
            //结果
            res.push(now);
        }else{
            for(auto it = node[now].childres.begin();it!=node[now].childres.end();it++){
                node[*it].deep = node[now].deep + 1;
                Q.push(*it);
            }
        }
    }

    return res;

}



int main(){
    //N: the total number of the members in the supply chain
    //P: the unit price given by the root supplier
    //r: the percentage rate of price increment for each distributor or retailer
    int N ;
    double P ,r;
    cin >> N >> P >> r;
    for(int i = 0 ; i < N ; ++i){
        //Ki ID[1] ID[2] ... ID[Ki]
        //where in the i-th line, K​i is the total number of distributors or retailers who receive products from supplier i
        //K​j being 0 means that the j-th member is a retailer,
        //then instead the total amount of the product will be given after Kj
        node[i].id = i;
        int n,c;
        cin >> n;

        if(n==0){
            cin >> node[i].procuctAmount;
        }else{
            for(int j = 0 ; j < n ; ++j){
                cin >> c;
                node[i].childres.push_back(c);
            }
        }
    }

    queue<int> result= level(0);
    double res=0;
    while (!result.empty()){

        int now = result.front();
        result.pop();
        res += node[now].procuctAmount*pow(((100+r)/100),(node[now].deep-1))*P;
    }
    printf("%.1lf",res);
}