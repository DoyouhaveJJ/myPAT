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
const int maxN = 50010;

struct Node{
    int value;
    int cnt;
    bool operator < (const Node &a) const {
        return (cnt != a.cnt) ? cnt > a.cnt : value < a.value;
    }
};
int query[maxN];

int main(){
    int n, k, num;
    scanf("%d%d", &n, &k);
    set<Node> s;
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (i != 0) {
            printf("%d:", num);
            int tempCnt = 0;
            for(auto it = s.begin(); tempCnt < k && it != s.end(); it++) {
                printf(" %d", it->value);
                tempCnt++;
            }
            printf("\n");
        }
        //找到当前点
        auto it = s.find(Node{num, query[num]});
        if (it != s.end())
            //找到了，就要更新，因为又访问了一次
            s.erase(it);
        query[num]++;
        s.insert(Node{num, query[num]});
    }
    return 0;
}