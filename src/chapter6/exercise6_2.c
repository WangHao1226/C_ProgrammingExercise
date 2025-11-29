//2. 编写程序，要求用户输入两个整数，然后计算并显示这两个整数的最大公约数（GCD）：
//Enter two integers: 12 28
//Greatest common divisor: 4
//提示：求最大公约数的经典算法是 Euclid 算法，方法如下。分别让变量 m 和 n 存储两个数的值。如
//        果 n 为 0，那么停止操作，m 中的值是 GCD；否则计算 m 除以 n 的余数，把 n 保存到 m 中，并把余
//        数保存到 n 中。然后重复上述过程，每次都先判定 n 是否为 0。

#include <stdio.h>

int exercise6_2() {
    printf("Enter two integers: ");
    fflush(stdout);

    int m, n;
    scanf("%d %d", &m, &n);
    int GCD;
    while (n != 0){
        int mod = m % n;
        m = n;
        n = mod;
    }
    GCD = m;
    printf("Greatest common divisor: %d", GCD);


}