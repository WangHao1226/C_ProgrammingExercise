//*5. 第4章的编程题1要求编写程序显示出两位数的逆序。设计一个更具一般性的程序，可以处理一位、
//两位、三位或者更多位的数。提示：使用 do 循环将输入的数重复除以 10，直到值达到 0 为止。

#include <stdio.h>

int exercise6_5() {
    printf("Enter a n-digit number:  ");
    fflush(stdout);
    int number;
    scanf("%d", &number);

    int digit;
    do {
        digit = number % 10;
        printf("%d", digit);
        number /= 10;
    } while (number != 0);

}