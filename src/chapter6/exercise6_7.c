//*7. 重新安排程序square3.c，在for循环中对变量i进行初始化、判定以及自增操作。不需要重写程序，
//特别是不要使用任何乘法。

#include <stdio.h>

int exercise6_7() {
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    fflush(stdout);
    int n;
    scanf("%d", &n);
    for (int square = 1, i = 1, odd = 3; i <= n; odd += 2) {
        printf("%10d%10d\n", i, square);
        ++i;
        square += odd;
    }
}