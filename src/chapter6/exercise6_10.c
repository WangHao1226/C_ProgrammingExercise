//10. 第 5 章的编程题 9 要求编写程序判断哪个日期更早。泛化该程序，使用户可以输入任意个日期。用
//0/0/0 指示输入结束，不再输入日期。
//Enter a date (mm/dd/yy): 3/6/08
//Enter a date (mm/dd/yy): 5/17/07
//Enter a date (mm/dd/yy): 6/3/07
//Enter a date (mm/dd/yy): 0/0/0
//5/17/07 is the earliest date

#include <stdio.h>

int exercise6_10() {
    int mm, dd, yy;
    int earliest_mm, earliest_dd, earliest_yy;

    // 读取第一个日期
    printf("Enter a date (mm/dd/yy): ");
    fflush(stdout);
    scanf("%d/%d/%d", &mm, &dd, &yy);

    // 如果第一个日期就是0/0/0，则直接返回
    if (mm == 0 && dd == 0 && yy == 0) {
        printf("No dates were entered.\n");
        return 0;
    }

    // 将第一个日期设为当前最早日期
    earliest_mm = mm;
    earliest_dd = dd;
    earliest_yy = yy;

    // 继续读取后续日期
    while (1) {
        printf("Enter a date (mm/dd/yy): ");
        fflush(stdout);
        scanf("%d/%d/%d", &mm, &dd, &yy);

        // 检查是否结束输入
        if (mm == 0 && dd == 0 && yy == 0) {
            break;
        }

        // 比较日期，更新最早日期
        if (yy < earliest_yy) {
            earliest_yy = yy;
            earliest_mm = mm;
            earliest_dd = dd;
        } else if (yy == earliest_yy) {
            if (mm < earliest_mm) {
                earliest_mm = mm;
                earliest_dd = dd;
            } else if (mm == earliest_mm) {
                if (dd < earliest_dd) {
                    earliest_dd = dd;
                }
            }
        }
    }

    printf("%d/%d/%02d is the earliest date\n", earliest_mm, earliest_dd, earliest_yy);
}