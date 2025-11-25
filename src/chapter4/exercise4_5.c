//5. 重写 4.1 节的 upc.c 程序，使用户可以一次输入 11 位数字，而不用先输入 1 位，再输入 5 位，最后再
//        输入 5 位。
//Enter the first 11 digits of a UPC: 01380015173
//Check digit: 5

#include <stdio.h>

void exercise4_5(void) {
    printf("Enter the first 11 digits of a UPC: ");
    fflush(stdout);

    // 一次性读取11位数字
    char upc[12]; // 11位数字 + 空字符
    scanf("%11s", upc);

    // 计算奇数位和偶数位的和
    int sum_odd = 0;  // 第1、3、5、7、9、11位
    int sum_even = 0; // 第2、4、6、8、10位

    // 遍历每个数字字符
    for (int i = 0; i < 11; i++) {
        int digit = upc[i] - '0'; // 将字符转换为数字

        if ((i + 1) % 2 == 1) { // 奇数位（数组索引从0开始，所以+1）
            sum_odd += digit;
        } else { // 偶数位
            sum_even += digit;
        }
    }

    // 计算校验位
    int total = sum_odd * 3 + sum_even;
    int check_digit = 10 - (total % 10);
    if (check_digit == 10) {
        check_digit = 0;
    }

    printf("Check digit: %d\n", check_digit);
}