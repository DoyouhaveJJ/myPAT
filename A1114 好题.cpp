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


set<int> allPeople;
int Ms[100010] = {0};
double Area[10010] = {0};
vector<int> net[100010];

bool vis[100010] = {false};
int N;

struct Family{
    int id;
    int memebers;
    double as;
    double aa;
};
vector<Family> ans;

bool cmp(Family a, Family b){
    if(a.aa != b.aa){
        return a.aa>b.aa;
    }else{
        return a.id < b.id;
    }
}

void BFS(){
    for(auto it = allPeople.begin(); it!=allPeople.end();++it){
        int minID=INF,num=0,sets=0;
        double areas=0.0;
        if(!vis[*it]){
            queue<int> Q;
            Q.push(*it);
            while(!Q.empty()){
                int now = Q.front();
                Q.pop();
                if(!vis[now]){
                    vis[now] = true;

                    if(now < minID){
                        minID = now;
                    }
                    sets += Ms[now];
                    num++;
                    areas += Area[now];
                    for(int i= 0 ; i < net[now].size();++i){
                        int v = net[now][i];
                        if(!vis[v]){
                            Q.push(v);
                        }
                    }
                }
            }

            Family family{};
            family.memebers = num;
            family.id = minID;
            family.aa = areas/num;
            family.as = 1.0*sets/num;
            ans.push_back(family);
        }




    }
}



int main(){

    cin >> N;
    for(int i = 0 ; i < N ; ++i){
        int id,fa,ma,cn;
        scanf("%d %d %d %d",&id,&fa,&ma,&cn);
        allPeople.insert(id);
        if(fa != -1){
            net[id].push_back(fa);
            net[fa].push_back(id);
        }
        if(ma != -1){
            net[id].push_back(ma);
            net[ma].push_back(id);
        }
        for(int j = 0 ; j < cn ; ++j){
            int childid;
            scanf("%d",&childid);
            net[id].push_back(childid);
            net[childid].push_back(id);
        }
        scanf("%d %lf",&Ms[id],&Area[id]);
    }

    BFS();
    printf("%lu\n",ans.size());
    sort(ans.begin(),ans.end(),cmp);
    for(int i = 0 ; i < ans.size();++i){
        printf("%04d %d %.3lf %.3lf\n",ans[i].id,ans[i].memebers,ans[i].as,ans[i].aa);
    }
}