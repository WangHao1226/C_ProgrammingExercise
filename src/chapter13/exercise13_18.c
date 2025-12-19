//18. 编写程序，按“月/日/年”的格式接受用户输入的日期，然后按“月 日，年”的格式显示，其中
//“月”用英文全名：
//Enter a date (mm/dd/yyyy): 2/17/2011
//You entered the date February 17, 2011
//用字符串指针数组存储月份的名字。

#include <stdio.h>

int exercise13_18(){
    char *months[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
    };

    int month, day, year;

    printf("Enter a date (mm/dd/yyyy): ");
    fflush(stdout);

    if(scanf("%d/%d/%d", &month, &day, &year) != 3){
        printf("Invalid date format.\n");
        return 1;
    }

    if(month < 1 || month > 12){
        printf("Invalid month. Please enter a value between 1 and 12.\n");
        return 1;
    }

    if (day < 1 || day > 31) {
        printf("Invalid day. Please enter a value between 1 and 31.\n");
        return 1;
    }

    // 输出结果
    printf("You entered the date %s %d, %d\n", months[month-1], day, year);
}