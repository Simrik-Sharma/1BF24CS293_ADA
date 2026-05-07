#include <stdio.h>
void printPermutation(int perm[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", perm[i]);
    printf("\n");
}
int getMobile(int perm[], int dir[], int n) {
    int mobile = 0, mobileIndex = -1;
    for (int i = 0; i < n; i++) {
        if (dir[i] == 0 && i != 0 && perm[i] > perm[i - 1]) {
            if (perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
        if (dir[i] == 1 && i != n - 1 && perm[i] > perm[i + 1]) {
            if (perm[i] > mobile) {
                mobile = perm[i];
                mobileIndex = i;
            }
        }
    }
    return mobileIndex;
}
void johnsonTrotter(int n) {
    int perm[n], dir[n];
    for (int i = 0; i < n; i++) {
        perm[i] = i + 1;
        dir[i] = 0;
    }
    printPermutation(perm, n);
    while (1) {
        int mobileIndex = getMobile(perm, dir, n);
        if (mobileIndex == -1)
            break;
        int swapIndex;
        if (dir[mobileIndex] == 0)
            swapIndex = mobileIndex - 1;
        else
            swapIndex = mobileIndex + 1;
        int temp = perm[mobileIndex];
        perm[mobileIndex] = perm[swapIndex];
        perm[swapIndex] = temp;
        temp = dir[mobileIndex];
        dir[mobileIndex] = dir[swapIndex];
        dir[swapIndex] = temp;
        mobileIndex = swapIndex;
        for (int i = 0; i < n; i++) {
            if (perm[i] > perm[mobileIndex]) {
                dir[i] = 1 - dir[i];
            }
        }

        printPermutation(perm, n);
    }
}
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    johnsonTrotter(n);
    return 0;
}
