//6. 修改 4.1 节的 upc.c 程序，使其可以检测 UPC 的有效性。在用户输入 UPC 后，程序将显示 VALID 或
//        NOT VALID。

#include <stdio.h>

void exercise5_6(void) {
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, check_digit;
    int first_sum, second_sum, total, calculated_check_digit;

    printf("Enter the first (single) digit: ");
    scanf("%1d", &d);
    printf("Enter first group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
    printf("Enter the check digit: ");
    scanf("%1d", &check_digit);

    // 计算校验和
    first_sum = d + i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = 3 * first_sum + second_sum;

    // 计算校验位
    calculated_check_digit = 9 - ((total - 1) % 10);

    // 验证 UPC 是否有效
    if (calculated_check_digit == check_digit) {
        printf("VALID\n");
    } else {
        printf("NOT VALID\n");
        printf("Expected check digit: %d, but got: %d\n", calculated_check_digit, check_digit);
    }
}