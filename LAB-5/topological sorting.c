#include <stdio.h>
#define MAX 20
void calculateIndegree(int adj[MAX][MAX], int indegree[], int n) {
    int i, j;
    for(i = 0; i < n; i++) {
        indegree[i] = 0;
    }
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1) {
                indegree[j]++;
            }
        }
    }
}
void topologicalSort(int adj[MAX][MAX], int n) {
    int indegree[MAX];
    int queue[MAX], front = 0, rear = 0;
    int topo[MAX];
    int i, j, k, count = 0;
    calculateIndegree(adj, indegree, n);
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0) {
            queue[rear++] = i;
        }
    }
    while(front < rear) {
        k = queue[front++];
        topo[count++] = k;
        for(j = 0; j < n; j++) {
            if(adj[k][j] == 1) {
                indegree[j]--;

                if(indegree[j] == 0) {
                    queue[rear++] = j;
                }
            }
        }
    }
    if(count != n) {
        printf("Topological ordering is not possible.\n");
    } else {
        printf("Topological Ordering:\n");

        for(i = 0; i < count; i++) {
            printf("%d ", topo[i]);
        }
        printf("\n");
    }
}
void readGraph(int adj[MAX][MAX], int n) {
    int i, j;
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
}
int main() {
    int adj[MAX][MAX];
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    readGraph(adj, n);
    topologicalSort(adj, n);
    return 0;
}
