//1. 编写一个程序，确定一个数的位数：
//Enter a number: 374
//The number 374 has 3 digits
//        假设输入的数最多不超过 4 位。提示：利用 if 语句进行数的判定。例如，如果数在 0 和 9 之间，那
//        么位数为 1；如果数在 10 和 99 之间，那么位数为 2。

#include <stdio.h>

void exercise5_1(void) {
    printf("Enter a number: ");
    fflush(stdout);
    int number;
    scanf("%d", &number);
    int digits;
    if(number >= 0 && number <= 9){
        digits = 1;
    } else if(number >= 10 && number <= 99){
        digits = 2;
    } else if(number >= 100 && number <= 999){
        digits = 3;
    } else{
        digits = 4;
    }
    printf("The number %d has %d digits", number, digits);
}