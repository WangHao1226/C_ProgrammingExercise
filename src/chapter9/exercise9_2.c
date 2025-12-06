//2. 修改第 5 章的编程题 5，用函数计算所得税的金额。在输入应纳税所得额后，函数返回税金。
//        收入（美元） 税 金
//未超过 750 收入的 1%
//750～2250 7.50 美元加上超出 750 美元部分的 2%
//2250～3750 37.50 美元加上超出 2250 美元部分的 3%
//3750～5250 82.50 美元加上超出 3750 美元部分的 4%
//5250～7000 142.50 美元加上超出 5250 美元部分的 5%
//超过 7000 230.00 美元加上超出 7000 美元部分的 6%
#include <stdio.h>

void tax(int income){
    if(income < 750){
        printf("%.2f", income * 0.01);
    } else if(income >= 750 && income < 2250){
        printf("%.2f", 7.50 + (income - 750) * 0.02);
    } else if(income >= 2250 && income < 3750){
        printf("%.2f", 37.50 + (income - 2250) * 0.03);
    } else if(income >= 3750 && income < 5250){
        printf("%.2f", 82.50 + (income - 3750) * 0.04);
    } else if(income >= 5250 && income < 7000){
        printf("%.2f", 142.50 + (income - 5250) * 0.05);
    } else{
        printf("%.2f", 230.00 + (income - 7000) * 0.06);
    }
}

int exercise9_2() {
    printf("输入收入（美元）： ");
    fflush(stdout);

    int income;
    scanf("%d", &income);
    tax(income);




}