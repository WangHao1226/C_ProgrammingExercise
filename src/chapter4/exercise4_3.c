//1. 编写一个程序，要求用户输入一个两位数，然后按数位的逆序打印出这个数。程序会话应类似下面
//        这样：
//Enter a two-digit number: 28
//The reversal is: 82
//用%d 读入两位数，然后分解成两个数字。提示：如果 n 是整数，那么 n % 10 是个位数，而 n / 10
//则是移除个位数后剩下的数。

//2. 扩展上题中的程序，使其可以处理 3 位数。

//3. 重新编写编程题2中的程序，使新程序不需要利用算术分割就可以显示出3位数的逆序。提示：参考
//4.1 节的 upc.c 程序。

#include <stdio.h>

void exercise4_3(void) {
    printf("Enter a three-digit number:  ");
    fflush(stdout);

    char digits[4];
    scanf("%3s", digits);

    printf("%c%c%c", digits[2], digits[1], digits[0]);
}