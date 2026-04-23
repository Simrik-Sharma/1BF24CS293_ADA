#include <stdio.h>
#define MAX 100
void sort(int n, float ratio[], int value[], int weight[]) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (ratio[j] < ratio[j + 1]) {
                float tempR = ratio[j];
                ratio[j] = ratio[j + 1];
                ratio[j + 1] = tempR;
                int tempV = value[j];
                value[j] = value[j + 1];
                value[j + 1] = tempV;
                int tempW = weight[j];
                weight[j] = weight[j + 1];
                weight[j + 1] = tempW;
            }
        }
    }
}
int main() {
    int n, capacity;
    int value[MAX], weight[MAX];
    float ratio[MAX];
    printf("Enter number of items: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d: ", i + 1);
        scanf("%d %d", &value[i], &weight[i]);
        ratio[i] = (float)value[i] / weight[i];
    }
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);
    sort(n, ratio, value, weight);
    float totalValue = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= weight[i]) {
            totalValue += value[i];
            capacity -= weight[i];
        } else {
            totalValue += value[i] * ((float)capacity / weight[i]);
            break;
        }
    }
    printf("Maximum value in knapsack = %.2f\n", totalValue);
    return 0;
}
