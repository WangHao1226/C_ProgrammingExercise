//5. 修改 8.1 节的程序 interest.c，使得修改后的程序可以每月整合一次利息，而不是每年整合一次利息。
//不要改变程序的输出格式，余额仍按每年一次的时间间隔显示。

#include <stdio.h>

#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define INITIAL_BALANCE 100.00
#define MONTHS_PER_YEAR 12

int exercise8_5() {
    int i, low_rate, num_years, year, month;
    double value[5];

    printf("Enter interest rate: ");
    fflush(stdout);
    scanf("%d", &low_rate);

    printf("Enter number of years: ");
    fflush(stdout);
    scanf("%d", &num_years);

    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++) {
        printf("%3d   ", year);

        // 对于每种利率，计算12个月的利息
        for (i = 0; i < NUM_RATES; i++) {
            // 每月计算一次利息
            for (month = 0; month < MONTHS_PER_YEAR; month++) {
                // 月利率 = 年利率 / 12
                value[i] += (low_rate + i) / 100.0 / MONTHS_PER_YEAR * value[i];
            }
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

}