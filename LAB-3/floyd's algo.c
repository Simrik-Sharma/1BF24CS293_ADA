#include <stdio.h>
#define MAX 100
#define INF 99999
int main() {
    int n;
    int cost[MAX][MAX], D[MAX][MAX];
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter cost matrix (enter %d for no edge):\n", INF);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            D[i][j] = cost[i][j];
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (D[i][k] + D[k][j] < D[i][j]) {
                    D[i][j] = D[i][k] + D[k][j];
                }
            }
        }
    }
    printf("\nShortest distance matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (D[i][j] == INF)
                printf("INF ");
            else
                printf("%d ", D[i][j]);
        }
        printf("\n");
    }
    return 0;
}
