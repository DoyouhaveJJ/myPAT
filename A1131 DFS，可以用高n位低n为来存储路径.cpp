
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

using namespace std;
const int inf = 0x3fffffff;
const int maxn = 10010;
int n,m,last;
//int line[maxn][maxn];
int dist[maxn][maxn];
bool visit[maxn];
vector<int>path;
vector<int>temp;
vector<vector<int>> v(maxn);
unordered_map<int,int>line;
int minDist=inf;
int transfer=inf;
void dfs(int s,int d){
    if(d>minDist) return;
    temp.push_back(s);
    visit[s]=true;
    if(s==last){
        int cnt=0;
        for(int i=0;i<temp.size()-2;i++){
            if(line[temp[i]*10000+temp[i+1]]!=line[temp[i+1]*10000+temp[i+2]]){
                cnt++;
            }
        }
        if(d<minDist || (d==minDist&&cnt<transfer)){
            path=temp;
            minDist=d;
            transfer=cnt;
        }
        visit[s]=false;
        temp.pop_back();
        return;
    }
    for(int i=0;i<v[s].size();i++){
        if(visit[v[s][i]]==false){
            dfs(v[s][i],d+1);
        }
    }
    temp.pop_back();
    visit[s]=false;
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        int sum,t1,t2;
        scanf("%d %d",&sum,&t1);
        for(int j=1;j<sum;j++){
            scanf("%d",&t2);
            v[t1].push_back(t2);
            v[t2].push_back(t1);
            line[t1*10000+t2]=line[t2*10000+t1]=i;
            t1=t2;
        }
    }
    int m;
    scanf("%d",&m);
    for(int k=0;k<m;k++){
        int a;
        scanf("%d %d",&a,&last);
        path.clear();
        temp.clear();
        minDist=inf;
        transfer=inf;
        fill(visit,visit+maxn,false);
        dfs(a,0);
        printf("%d\n",minDist);
        int now=line[path[0]*10000+path[1]];
        int i=0,j;
        for(j=1;j<path.size();j++){
            if(line[path[j-1]*10000+path[j]]!=now){
                printf("Take Line#%d from %04d to %04d.\n",now,path[i],path[j-1]);
                i=j-1;
                now=line[path[j-1]*10000+path[j]];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",now,path[i],path[j-1]);
    }
    return 0;
}
