#include <stdio.h>
int cost[10][10], vis[10], VT[10], ET[10][2];
int e = 0, i, j, n, m;
int sum = 0;
void prims()
{
    int u = 1, v, min;
    VT[1] = 1;
    vis[1] = 1;
    sum = 0;
    e = 0;
    for(i = 1; i < n; i++)
    {
        min = 999;

        for(j = 1; j <= i; j++)
        {
            int k = VT[j];

            for(m = 1; m <= n; m++)
            {
                if(cost[k][m] < min && vis[m] == 0)
                {
                    min = cost[k][m];
                    u = k;
                    v = m;
                }
            }
        }

        VT[i + 1] = v;
        ET[i][1] = u;
        ET[i][2] = v;
        e++;
        vis[v] = 1;
        sum += cost[u][v];
    }
}
int main()
{
    printf("Enter no. of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
            scanf("%d", &cost[i][j]);
    }

    for(i = 1; i <= n; i++)
        vis[i] = 0;

    prims();

    printf("\nMinimum Spanning Tree:\n");
    for(i = 1; i <= e; i++)
        printf("%d -> %d\n", ET[i][1], ET[i][2]);

    printf("Total cost = %d\n", sum);

    return 0;
}

