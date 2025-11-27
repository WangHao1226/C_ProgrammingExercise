//5. 在美国的某个州，单身居民需要缴纳表 5-7 中列出的所得税。
//表 5-7 美国某州单身居民个人所得税缴纳标准
//        收入（美元） 税 金
//未超过 750 收入的 1%
//750～2250 7.50 美元加上超出 750 美元部分的 2%
//2250～3750 37.50 美元加上超出 2250 美元部分的 3%
//3750～5250 82.50 美元加上超出 3750 美元部分的 4%
//5250～7000 142.50 美元加上超出 5250 美元部分的 5%
//超过 7000 230.00 美元加上超出 7000 美元部分的 6%
//编写一个程序，要求用户输入应纳税所得额，然后显示税金。

#include <stdio.h>

void exercise5_5(void) {
    printf("输入收入（美元）： ");
    fflush(stdout);

    int income;
    scanf("%d", &income);

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