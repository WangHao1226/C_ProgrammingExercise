//1. 修改第 2 章的编程题 7，使其包含下列函数：
//void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);
//函数需要确定：为支付参数 dollars 表示的付款金额，所需 20 美元、10 美元、5 美元和 1 美元钞票
//        的最小数目。twenties 参数所指向的变量存储所需 20 美元钞票的数目，tens、fives 和 ones 参数
//类似。

#include <stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones){
    *twenties = dollars / 20;
    dollars %= 20;  // 剩余金额

    *tens = dollars / 10;
    dollars %= 10;  // 剩余金额

    *fives = dollars / 5;
    dollars %= 5;   // 剩余金额

    *ones = dollars;
}

int exercise11_1(){
    int dollars;
    int twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    fflush(stdout);
    scanf("%d", &dollars);

    // 调用函数计算钞票数量
    pay_amount(dollars, &twenties, &tens, &fives, &ones);

    // 输出结果
    printf("\nResult:\n");
    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf("$5 bills: %d\n", fives);
    printf("$1 bills: %d\n", ones);
}