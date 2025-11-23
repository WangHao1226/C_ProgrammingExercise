//5. 编程要求用户输入 x 的值，然后显示如下多项式的值：
//3x^5+2x^4-5x^3-x^2+7x-6
//提示：C语言没有指数运算符，所以需要对x进行自乘来计算其幂。（例如，x*x*x就是x的三次方。）

#include <stdio.h>

int exercise2_5(){
    printf("输入x的值:");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    printf("3x^5+2x^4-5x^3-x^2+7x-6的值为:%d", 3 * x * x * x * x * x +
        2 * x * x * x * x - 5 * x * x * x - x * x + 7 * x - 6);
    return 0;
}