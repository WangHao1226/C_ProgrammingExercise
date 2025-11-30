//6. 编写程序显示 sizeof(int)、sizeof(short)、sizeof(long)、sizeof(float)、sizeof(double)
//和 sizeof(long double)的值。

#include <stdio.h>
#include <ctype.h>

int exercise7_6() {
    printf("sizeof(int) = %d\n", sizeof(int));
    printf("sizeof(short) = %d\n", sizeof(short));
    printf("sizeof(long) = %d\n", sizeof(long));
    printf("sizeof(float) = %d\n", sizeof(float));
    printf("sizeof(double) = %d\n", sizeof(double));
    printf("sizeof(long double) = %d\n", sizeof(long double));
}