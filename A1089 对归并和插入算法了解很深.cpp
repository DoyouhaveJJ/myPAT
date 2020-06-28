#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int n, a[100], b[100], i, j;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    //找到前几个有序的 i
    for (i = 0; i < n - 1 && b[i] <= b[i + 1]; i++);
    //在后面找是否都相等
    for (j = i + 1; a[j] == b[j] && j < n; j++);

    //以上是找插入排序的特征，前几个有序，后面都相等

    if (j == n) {
        cout << "Insertion Sort" << endl;
        //下一步
        sort(a, a + i + 2);
    } else {
        //否则就是归并排序
        cout << "Merge Sort" << endl;
        int k = 1, flag = 1;
        while(flag) {
            //这里保证了 进行到了目的排序后，还能进行一次归并
            flag = 0;

            //仍然不一样,这一步为进行到这一步
            for (i = 0; i < n; i++) {
                if (a[i] != b[i])
                    flag = 1;
            }

            //模拟归并排序
            k = k * 2;
            //不断排序
            for (i = 0; i < n / k; i++)
                sort(a + i * k, a + (i + 1) * k);
            sort(a + n / k * k, a + n);
        }
    }
    //打印
    for (j = 0; j < n; j++) {
        if (j != 0) printf(" ");
        printf("%d", a[j]);
    }
    return 0;
}