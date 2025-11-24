//1. 编写一个程序，以月/日/年（即 mm/dd/yy）的格式接受用户输入的日期信息，并以年月日（即
//        yyyymmdd）的格式将其显示出来：
//Enter a date (mm/dd/yyyy): 2/17/2011
//You entered the date 20110217

#include <stdio.h>

void exercise3_1(void) {
    printf("=== 练习3.1 ===\n");
    printf("Enter a date (mm/dd/yyyy):");
    fflush(stdout);
    int mm, dd, yyyy;
    scanf("%d/%d/%d", &mm, &dd, &yyyy);
    printf("You entered the date %04d%02d%02d", yyyy, mm, dd);
}