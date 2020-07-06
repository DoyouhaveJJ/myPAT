
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
    //大概是剪枝把，比最小距离还大的就不要了
    if(d>minDist) return;
    temp.push_back(s);
    visit[s]=true;
    //dfs到达了终点
    if(s==last){
        int cnt=0;
        //计算连接点数量，换乘站数量//即前一个和后一个是否是同一号线
        for(int i=0;i<temp.size()-2;i++){
            if(line[temp[i]*10000+temp[i+1]]!=line[temp[i+1]*10000+temp[i+2]]){
                cnt++;
            }
        }
        //更新最小距离，且距离相等情况下换乘较少的
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
            //都是一个站的//
            //我失误的理由是 没处理好换乘站的，
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
            //如果下一个换乘站不是现在的
            if(line[path[j-1]*10000+path[j]]!=now){

                printf("Take Line#%d from %04d to %04d.\n",now,path[i],path[j-1]);
                //回一格子
                i=j-1;
                //更新当前站
                now=line[path[j-1]*10000+path[j]];
            }
        }
        printf("Take Line#%d from %04d to %04d.\n",now,path[i],path[j-1]);
    }
    return 0;
}


/*
 *
 *

#include <cstdio>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <set>
#include <math.h>
#include <cstring>
#include <iostream>
#define INF 1e9


using namespace std;

const int maxN=10001;

vector<int> G[maxN];
int TypeMap[maxN]={0};
map<int,int> StationMap;
map<int,int> iMap;
int N,M;
int num = 0;
int d[maxN];
bool visit[maxN];
vector<int> Pre[maxN];
优化，在DIJK可以找到一条唯一的路线了 憨批
void Dijkstra(int root){
    fill(d,d+num,INF);
    memset(visit,false,sizeof(visit));
    d[root] = 0;
    for(int i = 0 ; i < num ; ++i){
        int u=-1,min=INF;
        for(int j = 0 ; j < num ; ++j){
            if(!visit[j] && d[j] < min){
                min = d[j];
                u=j;
            }
        }
        if(u==-1)return;
        visit[u] = true;
        for(int j = 0 ; j < G[u].size();++j){
            int v = G[u][j];
            if(!visit[v] && d[v] > d[u] + 1){
                d[v] = d[u]+1;
                Pre[v].clear();
                Pre[v].push_back(u);
            }else if(!visit[v] && d[v] == d[u] + 1){
                Pre[v].push_back(u);
            }
        }
    }
}
vector<int> tempPath,optPath;
int optLength=INF,optTransfer = INF;
void DFS(int now,int length,int Target,int Transfer){
    if(now == Target){
        tempPath.push_back(now);
        if(length < optLength){
            optPath = tempPath;
            optLength = length;
        }else if(length == optLength){
            if(Transfer < optTransfer){
                optPath = tempPath;
                optTransfer = Transfer;
            }
        }
        tempPath.pop_back();
        return;
    }
    tempPath.push_back(now);
    for(int i = 0 ; i < Pre[now].size(); ++i){

        int v = Pre[now][i];
        DFS(v,length+1,Target,Transfer+((TypeMap[v]==-1)?1:0));
    }
    tempPath.pop_back();

}



int main(){

    int x,y;
    cin >> N;

    for(int i = 1 ;i <= N ; ++i){
        cin >> M;
        cin >> x;
        int ix,iy;
        if(StationMap.find(x) == StationMap.end()){
            StationMap[x] = num;
            iMap[num++] = x;
        }
        ix = StationMap[x];
        if(TypeMap[ix] == 0){
            TypeMap[ix] = i;
        }else if(TypeMap[ix] != i){
            TypeMap[ix] = -1;//换乘站
        }

        for(int j = 1; j < M ; ++j){
            cin >> y;

            if(StationMap.find(y) == StationMap.end()){
                StationMap[y] = num;
                iMap[num++] = y;
            }
            iy = StationMap[y];
            if(TypeMap[iy] == 0){
                TypeMap[iy] = i;
            }else if(TypeMap[iy] != i){
                TypeMap[iy] = -1;//换乘站
            }

            G[ix].push_back(iy);
            G[iy].push_back(ix);
            ix = iy;
        }
    }
    cin >> M;
    for(int index = 0 ; index < M ; ++index){
        int u,v;
        cin >> u >> v;
        Dijkstra(StationMap[u]);
        tempPath.clear();
        optPath.clear();
        optLength=INF;
        DFS(StationMap[v],0,StationMap[u],0);
        int Start = optPath.size()-1;
        int preLine = TypeMap[optPath[Start]];
        cout << optPath.size()-1 << endl;
        for(int i = optPath.size()-1 ; i >= 0 ; --i ){
            if(preLine != TypeMap[optPath[i]]){

                cout <<"Take Line#"<<preLine<<" from "<<iMap[optPath[Start]]<<" to "<<iMap[optPath[i]]<<"."<<endl;
                Start = i;
                preLine = TypeMap[optPath[Start-1]];
            }
        }
        if(Start != 0){
            cout <<"Take Line#"<<preLine<<" from "<<iMap[optPath[Start]]<<" to "<<iMap[optPath[0]]<<"."<<endl;
        }





    }



}
 */
