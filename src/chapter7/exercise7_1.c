//1. 如果 i * i 超出了 int 类型的最大取值，那么 6.3 节的程序 square2.c 将失败（通常会显示奇怪的答
//        案）。运行该程序，并确定导致失败的 n 的最小值。尝试把变量 i 的类型改成 short 并再次运行该
//程序。（不要忘记更新 printf 函数调用中的转换说明！）然后尝试将其改成 long。从这些实验中，
//你能总结出在你的机器上用于存储整数类型的位数是多少吗？

#include <stdio.h>

int exercise7_1() {
    int i, n;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    fflush(stdout);
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        printf("%10d%10d\n", i, i * i);
}