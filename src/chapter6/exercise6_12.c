//12. 修改编程题 11，使得程序持续执行加法运算，直到当前项小于epsilon 为止，其中epsilon 是用户输入的较小的
//（浮点）数。

#include <stdio.h>

int exercise6_12() {
    printf("Enter n: ");
    fflush(stdout);
    int n;
    scanf("%d", &n);

    printf("Enter epsilon: ");
    fflush(stdout);
    float epsilon;
    scanf("%f", &epsilon);

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
        if(fraction < epsilon){
            break;
        }
        e += fraction;
    }

    printf("e = %.10f\n", e); // 使用更多小数位显示更精确的结果
}