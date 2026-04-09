#include <stdio.h>
#include <conio.h>
#include <time.h>
void merge(int a[], int low, int mid, int high, double time_spent[]);
void mergeSort(int a[], int low, int high, double time_spent[]);
void merge(int a[], int low, int mid, int high, double time_spent[])
{
    int i, j, k;
    int temp[100];
    i = low;
    j = mid + 1;
    k = low;
    while (i <= mid && j <= high)
    {
        clock_t start = clock();
        if (a[i] <= a[j])
        {
            temp[k] = a[i];
            time_spent[i] += (double)(clock() - start) / CLOCKS_PER_SEC;
            i++;
        }
        else
        {
            temp[k] = a[j];
            time_spent[j] += (double)(clock() - start) / CLOCKS_PER_SEC;
            j++;
        }
        k++;
    }
    while (i <= mid)
    {
        clock_t start = clock();
        temp[k] = a[i];
        time_spent[i] += (double)(clock() - start) / CLOCKS_PER_SEC;
        i++;
        k++;
    }
    while (j <= high)
    {
        clock_t start = clock();
        temp[k] = a[j];
        time_spent[j] += (double)(clock() - start) / CLOCKS_PER_SEC;

        j++;
        k++;
    }
    for (i = low; i <= high; i++)
        a[i] = temp[i];
}
void mergeSort(int a[], int low, int high, double time_spent[])
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        mergeSort(a, low, mid, time_spent);
        mergeSort(a, mid + 1, high, time_spent);
        merge(a, low, mid, high, time_spent);
    }
}
void main()
{
    int a[100], n, i;
    double time_spent[100] = {0};
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    mergeSort(a, 0, n - 1, time_spent);
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n\nTime spent per element:\n");
    for (i = 0; i < n; i++)
        printf("Element %d: %f seconds\n", a[i], time_spent[i]);
    getch();
}
