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
unordered_map<int, bool> arr;
struct node
{
    int a, b;
};
bool cmp(node x, node y)
{
    return x.a != y.a ? x.a < y.a : x.b < y.b;
}
int main()
{
    int n, m, k;
    scanf("%d%d", &n, &m);
    vector<int> v[10000];

    for (int i = 0; i < m; i++)
    {
        string a, b;
        cin >> a >> b;
        int asa= abs(stoi(a)), asb=abs(stoi(b));

        //存储同性关系
        if (a.length() == b.length())
        {
            v[asa].push_back(asb);
            v[asb].push_back(asa);
        }
        //存储异性和同性关系 草
        arr[asa * 10000 + asb] = arr[asb * 10000 + asa] = true;
    }
    scanf("%d", &k);
    for (int i = 0; i < k; i++)
    {
        int c, d;
        cin >> c >> d;
        vector<node> ans;

        //遍历c的同性关系
        for (int j = 0; j < v[abs(c)].size(); j++)
        {
            //遍历d的同性关系
            for (int m = 0; m < v[abs(d)].size(); m++)
            {
                // A在寻找同性朋友时，需要避免找到他想要的伴侣B，所以当前朋友就是B或B的同性朋友就是A时舍弃该结果
                if (v[abs(c)][j] == abs(d) || abs(c) == v[abs(d)][m]) continue;
                // A/B，先找A的所有同性朋友C，再找B的所有同性朋友D，当C和D两人是朋友的时候则可以输出C和D
                if (arr[v[abs(c)][j] * 10000 + v[abs(d)][m]] == true)
                    ans.push_back(node{v[abs(c)][j], v[abs(d)][m]});
            }
        }
        sort(ans.begin(), ans.end(), cmp);

        printf("%d\n", int(ans.size()));
        for(int j = 0; j < ans.size(); j++)
            printf("%04d %04d\n", ans[j].a, ans[j].b);
    }
    return 0;
}