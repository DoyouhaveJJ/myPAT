#include <stdio.h>

int main(void)
{
    int node[100][100] = {0}, depth[100] = {0};
    int n, m, id, cid, k;
    int i, j, count[100] = {0}, queue[100] = {0};

    scanf("%d%d", &n, &m);
    for (i = 0; i < m; i++) {
        scanf("%d%d", &id, &k);
        for (j = 0; j < k; j++) {
            scanf("%d", &cid);
            node[id][j] = cid;
        }
    }
    depth[1] = 1;
    queue[0] = 1;
    int *p = queue, *q = p + 1, maxdepth = -1;
    //遍历所有点
    for (; p < q; p++) {
        for (k = 0; k < 100 && node[*p][k] != 0; k++) {
            //进队列
            *q = node[*p][k];
            depth[*q] = depth[*p] + 1;
            if (depth[*q] > maxdepth)
                maxdepth = depth[*q];
            //出队列
            q++;
        }
        //没有孩子
        if (k == 0)
            count[depth[*p]]++;
    }

    printf("%d", count[1]);
    for (i = 2; i <= maxdepth; i++)
        printf(" %d", count[i]);

    return 0;
}
