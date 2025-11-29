//11. 数学常量 e 的值可以用一个无穷级数表示：
//e=1+1/1!+1/2!+1/3!+...
//编写程序，用下面的公式计算 e 的近似值：
//1+1/1!+1/2!+1/+3!+...+1/n!
//        这里 n 是用户输入的整数。

#include <stdio.h>

int exercise6_11() {
    printf("Enter n: ");
    fflush(stdout);
    int n;
    scanf("%d", &n);

    float e = 1.0; // 第一项是1
    float fraction;
    int denominator;

    for(int i = 1; i <= n; i++) {
        denominator = 1; // 每次循环重置分母

        // 计算i的阶乘
        for(int j = 1; j <= i; j++) {
            denominator *= j;
        }

        fraction = 1.0 / denominator;
        e += fraction;
    }

    printf("e = %.10f\n", e); // 使用更多小数位显示更精确的结果
}