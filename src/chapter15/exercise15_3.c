//3. 修改 9.6 节的 qsort.c 程序，把 quicksort 函数和 split 函数放在一个单独的文件 quicksort.c 中。
//创建一个名为 quicksort.h 的头文件来包含这两个函数的原型，并让 qsort.c 和 quicksort.c 都包含这个
//头文件。
/* Sorts an array of integers using Quicksort algorithm */
#include <stdio.h>
#define N 10
void quicksort(int a[], int low, int high);
int split(int a[], int low, int high);
int exercise15_3(void)
{
    int a[N], i;
    printf("Enter %d numbers to be sorted: ", N);
    fflush(stdout);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, N - 1);
    printf("In sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
