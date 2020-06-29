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
int main() {
    int first, k, n, sum = 0;
    cin >> first >> n >> k;
    int temp, data[100005], next[100005], list[100005], result[100005];
    for (int i = 0; i < n; i++) {
        cin >> temp;
        cin >> data[temp] >> next[temp];
    }
    //去除无效点
    while (first != -1) {
        list[sum++] = first;
        first = next[first];
    }
    //赋值
    for (int i = 0; i < sum; i++)
        result[i] = list[i];

    //sum - sum % k 个 块
    for (int i = 0; i < (sum - sum % k); i++)
        //逆序保存 只有块里的
        result[i] = list[i / k * k + k - 1 - i % k];

    for (int i = 0; i < sum - 1; i++)
        printf("%05d %d %05d\n", result[i], data[result[i]], result[i + 1]);

    //最后一个单独打印
    printf("%05d %d -1", result[sum - 1], data[result[sum - 1]]);
    return 0;
}