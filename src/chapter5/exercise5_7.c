//7. 编写一个程序，从用户输入的 4 个整数中找出最大值和最小值：
//Enter four integers: 21 43 10 35
//Largest: 43
//Smallest: 10
//要求尽可能少用 if 语句。提示：4 条 if 语句就足够了。

#include <stdio.h>

void exercise5_7(void) {
    int a, b, c, d;
    int max, min;

    printf("Enter four integers: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    // 第一步：比较前两个数，找到较大的和较小的
    if (a > b) {
        max = a;
        min = b;
    } else {
        max = b;
        min = a;
    }

    // 第二步：用第三个数更新最大值和最小值
    if (c > max) {
        max = c;
    } else if (c < min) {
        min = c;
    }

    // 第三步：用第四个数更新最大值和最小值
    if (d > max) {
        max = d;
    } else if (d < min) {
        min = d;
    }

    printf("Largest: %d\n", max);
    printf("Smallest: %d\n", min);
}