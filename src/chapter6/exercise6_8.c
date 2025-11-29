//8. 编写程序显示单月的日历。用户指定这个月的天数和该月起始日是星期几：
//Enter number of days in month: 31
//Enter starting day of the week (1=Sun, 7=Sat): 3
//1 2 3 4 5
//6 7 8 9 10 11 12
//13 14 15 16 17 18 19
//20 21 22 23 24 25 26
//27 28 29 30 31
//提示：此程序不像看上去那么难。最重要的部分是一个使用变量 i 从 1 计数到 n 的 for 语句（这里
//        n 是此月的天数），for 语句中需要显示 i 的每个值。在循环中，用 if 语句判定 i 是否是一个星期
//        的最后一天，如果是，就显示一个换行符。

#include <stdio.h>

int exercise6_8() {
    printf("Enter number of days in month: ");
    fflush(stdout);
    int number_of_days, starting_day;
    scanf("%d", &number_of_days);

    printf("Enter starting day of the week (1=Sun, 7=Sat): ");
    fflush(stdout);
    scanf("%d", &starting_day);

    for(int i = 0; i < starting_day; i ++){
        printf("   ");
    }
    for(int i = 1; i <= number_of_days; i++){
        printf(" %2d", i);
        if((i + starting_day) % 7 == 0){
            printf("\n");
        }
    }
}