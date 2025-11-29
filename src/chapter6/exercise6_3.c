//3. 编写程序，要求用户输入一个分数，然后将其约分为最简分式：
//Enter a fraction: 6/12
//In lowest terms: 1/2
//提示：为了把分数约分为最简分式，首先计算分子和分母的最大公约数，然后分子和分母都除以最
//        大公约数。

#include <stdio.h>

int exercise6_3() {
    printf("Enter a fraction: ");
    fflush(stdout);

    int numerator, denominator;
    scanf("%d/%d", &numerator, &denominator);

    int m = numerator, n = denominator;
    int GCD;
    while (n != 0){
        int mod = m % n;
        m = n;
        n = mod;
    }
    GCD = m;
    printf("In lowest terms: %d/%d", numerator / GCD, denominator / GCD);


}