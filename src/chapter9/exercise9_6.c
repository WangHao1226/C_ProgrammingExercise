//6. 编写函数计算下面多项式的值：
//3 * x ^ 5 + 2 * x ^ 4 - 5 * x ^ 3 - x ^ 2 + 7 * x - 6
//编写程序要求用户输入 x 的值，调用该函数计算多项式的值并显示函数返回的值。

#include <stdio.h>
#include <math.h>
int polymerization(int x){
    x = 3 * pow(x, 5) + 2 * pow(x, 4) - 5 * pow(x, 3) - pow(x, 2) + 7 * pow(x, 1) - 6;
    return x;
}

int exercise9_6() {
    printf("Enter x: ");
    fflush(stdout);

    int x;
    scanf("%d", &x);

    printf("%d", polymerization(x));
}