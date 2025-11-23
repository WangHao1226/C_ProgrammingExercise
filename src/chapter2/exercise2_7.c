//7. 编写一个程序，要求用户输入一个美元数额，然后显示出如何用最少张数的 20 美元、10 美元、5 美
//        元和 1 美元钞票来付款：
//Enter a dollar amount: 93
//$20 bills: 4
//$10 bills: 1
//$5 bills: 0
//$1 bills: 3
//提示：将付款金额除以 20，确定 20 美元钞票的数量，然后从付款金额中减去 20 美元的总金额。对
//        其他面值的钞票重复这一操作。确保在程序中始终使用整数值，不要用浮点数。

#include <stdio.h>

int exercise2_7(){
    printf("Enter a dollar amount:");
    fflush(stdout);
    int amount;
    scanf("%d", &amount);
    printf("\n$20 bills: %d\n", amount / 20);
    printf("$10 bills: %d\n", amount % 20 / 10);
    printf("$5 bills: %d\n", amount % 10 / 5);
    printf("$1 bills: %d\n", amount % 5 );
    return 0;
}