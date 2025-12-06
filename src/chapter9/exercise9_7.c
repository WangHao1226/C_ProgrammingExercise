//7. 如果换一种方法计算 x ^ n ，9.6 节的 power 函数速度可以更快。我们注意到，如果 n 是 2 的幂，则可以
//        通过自乘的方法计算 x ^ n 。例如， x ^ 4 是 x ^ 2 的平方，所以 x ^ 4 可以用两次乘法计算，而不需要三次乘
//        法。这种方法甚至可以用于 n 不是 2 的幂的情况。如果 n 是偶数，则 x ^ n = (x ^ (n / 2)) ^ 2；如果 n 是奇数，则
//        x ^ n = x * x ^ (n - 1) 。编写计算 x ^ n 的递归函数（递归在 n=0 时结束，此时函数返回 1）。为了测试该函数，写
//        一个程序要求用户输入 x 和 n 的值，调用 power 计算 x ^ n ，然后显示函数的返回值。

#include <stdio.h>

int power(int x, int n){
    if(n == 0){
        return 1;
    } else if(n % 2 == 0){
        int half_power = power(x, n / 2);
        return half_power * half_power;
    } else{
        return x * power(x, n - 1);
    }
}

int exercise9_7() {
    printf("Enter x, n: ");
    fflush(stdout);

    int x, n;
    scanf("%d %d", &x, &n);

    printf("%d", power(x, n));
}