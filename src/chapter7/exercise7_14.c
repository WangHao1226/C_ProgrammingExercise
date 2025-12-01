//14. 编写程序，用牛顿方法计算正浮点数的平方根：
//Enter a positive number: 3
//Square root: 1.73205
//设 x 是用户输入的数。牛顿方法需要先给出 x 平方根的猜测值 y（我们使用 1）。后续的猜测值通过计
//        算 y 和 x/y 的平均值得到。表 7-6 中给出了求解 3 的平方根的过程。
//表 7-6 用牛顿方法求解 3 的平方根
//        x y x/y y 和 x/y 的平均值
//3 1 3 2
//3 2 1.5 1.75
//3 1.75 1.714 29 1.732 14
//3 1.732 14 1.731 96 1.732 05
//3 1.732 05 1.732 05 1.732 05
//注意，y 的值逐渐接近 x 的平方根。为了获得更高的精度，程序中应使用 double 类型的变量代替
//float类型的变量。当y的新旧值之差的绝对值小于0.000 01和y的乘积时程序终止。提示：调用fabs
//        函数求 double 类型数值的绝对值。（为了使用 fabs 函数，需要在程序的开头包含<math.h>头。

#include <stdio.h>
#include <math.h>
int exercise7_14() {
    printf("Enter a positive number: ");
    fflush(stdout);

    double x, y = 1, temp;
    scanf("%lf", &x);
    while (1) {
        temp = (y + x / y) / 2;
        if ((fabs(temp - y) < 0.00001 * y)) {
            break;
        }
        y = temp;
    }
    printf("Square root: %lf", temp);

}