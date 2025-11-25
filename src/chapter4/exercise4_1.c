//1. 编写一个程序，要求用户输入一个两位数，然后按数位的逆序打印出这个数。程序会话应类似下面
//        这样：
//Enter a two-digit number: 28
//The reversal is: 82
//用%d 读入两位数，然后分解成两个数字。提示：如果 n 是整数，那么 n % 10 是个位数，而 n / 10
//则是移除个位数后剩下的数。

#include <stdio.h>

void exercise4_1(void) {
    printf("Enter a two-digit number:  ");
    fflush(stdout);
    int number;
    scanf("%d", &number);
    int units, tens;
    units = number % 10;
    tens = number / 10;

    printf("%d%d", units, tens);



}