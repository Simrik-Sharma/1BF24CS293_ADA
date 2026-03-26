#include <stdio.h>
int cost[10][10], t[10][2], parent[10];
int min, i, j, count, k, u, v, n;
void union_ij(int i, int j)
{
    parent[j] = i;
}
int find(int v)
{
    while(parent[v] != v)
        v = parent[v];
    return v;
}
void kruskal()
{
    count = 0;
    k = 0;
    int sum = 0;
    for(i = 0; i < n; i++)
        parent[i] = i;

    while(count != n - 1)
    {
        min = 999;
        for(i = 0; i < n; i++)
        {
            for(j = 0; j < n; j++)
            {
                if(cost[i][j] < min && cost[i][j] != 0)
                {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        i = find(u);
        j = find(v);
        if(i != j)
        {
            t[k][0] = u;
            t[k][1] = v;
            k++;
            count++;
            sum += cost[u][v];
            union_ij(i, j);
        }

        cost[u][v] = cost[v][u] = 999;
    }
    printf("Spanning tree:\n");
    for(i = 0; i < k; i++)
        printf("%d -> %d\n", t[i][0], t[i][1]);
    printf("Total cost = %d\n", sum);
}
int main()
{
    printf("Enter no. of vertices: ");
    scanf("%d", &n);
    printf("Enter cost adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);

            if(i == j)
                cost[i][j] = 999;
        }
    }
    kruskal();
    return 0;
}
