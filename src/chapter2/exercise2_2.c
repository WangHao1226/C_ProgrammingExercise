//编写一个计算球体体积的程序，其中球体半径为 10 m，参考公式 v = 4/3pir^3
//注意，分数 4/3 应写为
//4.0f/3.0f。（如果分数写成 4/3 会产生什么结果？）提示：C 语言没有指数运算符，所以需要对 r
//自乘两次来计算 r^3

#include <stdio.h>
#define pi 3.14

void exercise2_2(void) {
    printf("=== 练习2.2 ===\n");
    int r = 10;
    double v;
    v = 4.0f / 3.0f * pi * r * r * r;
    printf("%f",v);
}