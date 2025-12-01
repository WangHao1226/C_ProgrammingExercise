//15. 编程计算正整数的阶乘：
//Enter a positive integer: 6
//Factorial of 6: 720
//(a) 用 short 类型变量存储阶乘的值。为了正确打印出 n 的阶乘，n 的最大值是多少？
//(b) 用 int 类型变量重复(a)。
//(c) 用 long 类型变量重复(a)。
//(d) 如果你的编译器支持 long long 类型，用 long long 类型变量重复(a)。
//(e) 用 float 类型变量重复(a)。
//(f) 用 double 类型变量重复(a)。
//(g) 用 long double 类型变量重复(a)。
//在(e)~(g)这几种情况下，程序会显示阶乘的近似值，不一定是准确值。

#include <stdio.h>
#include <math.h>
int exercise7_15() {
    printf("Enter a positive integer: ");
    fflush(stdout);

    int n;
    scanf("%d", &n);

    short factorial1 = 1;
    for(int i = 1; i <= n; i ++){
        factorial1 *= i;
    }
    printf("Factorial of %d: %d\n", n, factorial1);

    int factorial2 = 1;
    for(int i = 1; i <= n; i ++){
        factorial2 *= i;
    }
    printf("Factorial of %d: %d\n", n, factorial2);

    long factorial3 = 1;
    for(int i = 1; i <= n; i ++){
        factorial3 *= i;
    }
    printf("Factorial of %d: %ld\n", n, factorial3);

    long long factorial4 = 1;
    for(int i = 1; i <= n; i ++){
        factorial4 *= i;
    }
    printf("Factorial of %d: %lld\n", n, factorial4);

    float factorial5 = 1;
    for(int i = 1; i <= n; i ++){
        factorial5 *= i;
    }
    printf("Factorial of %d: %f\n", n, factorial5);

    double factorial6 = 1;
    for(int i = 1; i <= n; i ++){
        factorial6 *= i;
    }
    printf("Factorial of %d: %f\n", n, factorial6);

    long double factorial7 = 1;
    for(int i = 1; i <= n; i ++){
        factorial7 *= i;
    }
    printf("Factorial of %d: %Lf\n", n, factorial7);

}