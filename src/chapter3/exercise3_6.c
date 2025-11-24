//6. 修改 3.2 节的 addfrac.c 程序，使用户可以同时输入两个分数，中间用加号隔开：
//Enter two fractions separated by a plus sign: 5/6+3/4
//The sum is 38/24

#include <stdio.h>

void exercise3_6(void) {
    printf("Enter two fractions separated by a plus sign: ");
    fflush(stdout);
    int a, b, c, d;
    scanf("%d/%d+%d/%d", &a, &b, &c, &d);
    printf("The sum is %d/%d", a * d + b * c, b * d);


}