//3. 修改 7.1 节的程序 sum2.c，对 double 型值组成的数列求和。

#include <stdio.h>

int exercise7_3() {
    double n, sum = 0;

    printf("This program sums a series of integers.\n");
    printf("Enter integers (0 to terminate): ");
    fflush(stdout);

    scanf("%lf", &n);
    while (n != 0) {
        sum += n;
        scanf("%lf", &n);
    }
    printf("The sum is: %lf\n", sum);
}