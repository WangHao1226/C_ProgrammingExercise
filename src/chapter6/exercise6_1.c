//1. 编写程序，找出用户输入的一串数中的最大数。程序需要提示用户一个一个地输入数。当用户输入
//0 或负数时，程序必须显示出已输入的最大非负数：
//Enter a number: 60
//Enter a number: 38.3
//Enter a number: 4.89
//Enter a number: 100.62
//Enter a number: 75.2295
//Enter a number: 0
//The largest number entered was 100.62
//注意，输入的数不一定是整数。

#include <stdio.h>

int exercise6_1() {
    float number;
    printf("Enter a number: ");
    fflush(stdout);
    scanf("%f", &number);
    float max_non_negative_number;
    if(number <= 0){
        printf("The largest number entered was 0");
        return 0;
    }
    max_non_negative_number = number;
    while (number > 0){
        printf("Enter a number: ");
        fflush(stdout);
        scanf("%f", &number);
        if(number > max_non_negative_number){
            max_non_negative_number = number;
        }
    }
    printf("The largest number entered was %g", max_non_negative_number);
}