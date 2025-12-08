//3. 修改第 6 章的编程题 3，使其包含下列函数：
//void reduce(int numerator, int denominator,
//            int *reduced_numerator,
//            int *reduced_denominator);
//numerator 和 denominator 分别是分数的分子和分母。reduced_numerator 和
// reduced_denominator 是指向变量的指针，相应变量中分别存储把分数化为最简形式后的分子和分母。
//3. 编写程序，要求用户输入一个分数，然后将其约分为最简分式：
//Enter a fraction: 6/12
//In lowest terms: 1/2
//提示：为了把分数约分为最简分式，首先计算分子和分母的最大公约数，然后分子和分母都除以最
//        大公约数。

#include <stdio.h>

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
    // 检查分母是否为0
    if (denominator == 0) {
        printf("Error: Denominator cannot be zero!\n");
        *reduced_numerator = numerator;
        *reduced_denominator = denominator;
        return;
    }

    int a = numerator;
    int b = denominator;
    int temp;

    // 使用欧几里得算法计算最大公约数
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }

    int gcd = a;

    // 约分
    *reduced_numerator = numerator / gcd;
    *reduced_denominator = denominator / gcd;
}

int exercise11_3(void) {
    int numerator, denominator;
    int reduced_numerator, reduced_denominator;

    printf("Enter a fraction: ");
    fflush(stdout);
    scanf("%d/%d", &numerator, &denominator);

    // 调用约分函数
    reduce(numerator, denominator, &reduced_numerator, &reduced_denominator);

    // 输出结果
    printf("In lowest terms: %d/%d\n", reduced_numerator, reduced_denominator);


}