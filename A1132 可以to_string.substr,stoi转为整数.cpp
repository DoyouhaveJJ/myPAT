
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

int main()
{
    int n, num;
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &num);
        string s = to_string(num);
        int len = s.length();

        int a = stoi(s.substr(0, len/2));
        int b = stoi(s.substr(len/2));

        if(a*b !=0 && num % (a*b)==0)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
