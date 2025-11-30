//修改第 3章的编程题 6，使得用户可以对两个分数进行加、减、乘、除运算（在两个分数之间输入+、
//-、*或/符号）。

#include <stdio.h>
#include <ctype.h>

int gcd(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int exercise7_7() {
   int num1, denom1, num2, denom2, result_num, result_denom;
   char op;

    printf("Enter two fractions separated by an operator (+, -, *, /): ");
    fflush(stdout);
    scanf("%d/%d %c %d/%d", &num1, &denom1, &op, &num2, &denom2);

    switch (op) {
        case '+':
            result_num = num1 * denom2 + num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        case '-':
            result_num = num1 * denom2 - num2 * denom1;
            result_denom = denom1 * denom2;
            break;
        case '*':
            result_num = num1 * num2;
            result_denom = denom1 * denom2;
            break;
        case '/':
            result_num = num1 * denom2;
            result_denom = num2 * denom1;
            break;
        default:
            printf("op is err");
            return 1;
    }

    int common_divisor = gcd(result_num, result_denom);
    result_num /= common_divisor;
    result_denom /= common_divisor;

    if(result_denom < 0){
        result_num = - result_num;
        result_denom = - result_denom;
    }
    printf("%d/%d%c%d/%d is %d/%d", num1, denom1, op, num2, denom2, result_num, result_denom);
}