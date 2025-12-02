//4. 修改 8.1 节的程序 reverse.c，利用表达式(int)(sizeof(a) / sizeof(a[0]))（或者具有相同值的宏）
//来计算数组的长度。

#include <stdio.h>

#define N 10

int exercise8_4() {
    int a[N], i;
    printf("Enter %d numbers: ", N);
    fflush(stdout);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    printf("In reverse order:");
    for (i = N - 1; i >= 0; i--)
        printf(" %d", a[i]);
    printf("\n");
    printf("%d", (int)(sizeof (a) / sizeof (a[0])));


}