//6. 修改第 5 章的编程题 9，以便用户输入的日期都存储在一个 date 结构（见练习题 5）中。把练习题 5
//中的 compare_dates 函数集成到你的程序中。
//5. 编写下列函数，假定 date 结构包含三个成员：month、day 和 year（都是 int 类型）。
//(a) int day_of_year(struct date d);
//返回 d 是一年中的第多少天（1~366 范围内的整数）。
//(b) int compare_dates(struct date d1, struct date d2);
//如果日期 d1 在 d2 之前，返回1；如果 d1 在 d2 之后，返回+1；如果 d1 和 d2 相等，返回 0。
//9. 编写一个程序，提示用户输入两个日期，然后显示哪一个日期更早：
//Enter first date (mm/dd/yy): 3/6/08
//Enter second date (mm/dd/yy): 5/17/07
//5/17/07 is earlier than 3/6/08

#include <stdio.h>

struct date{
    int month;
    int day;
    int year;
};

int day_of_year(struct date d) {
    int days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int day_count = 0;

    // 检查是否为闰年
    if ((d.year % 4 == 0 && d.year % 100 != 0) || d.year % 400 == 0) {
        days_in_month[2] = 29;  // 闰年2月有29天
    }

    // 累加前几个月的天数
    for (int i = 1; i < d.month; i++) {
        day_count += days_in_month[i];
    }

    // 加上本月的天数
    day_count += d.day;

    return day_count;
}
int compare_dates(struct date d1, struct date d2){
    // 比较年份
    if (d1.year < d2.year)
        return -1;
    else if (d1.year > d2.year)
        return 1;
    else {
        // 年份相同，比较月份
        if (d1.month < d2.month)
            return -1;
        else if (d1.month > d2.month)
            return 1;
        else {
            // 月份相同，比较日
            if (d1.day < d2.day)
                return -1;
            else if (d1.day > d2.day)
                return 1;
            else
                return 0;  // 日期完全相同
        }
    }
}

int exercise16_6() {
    struct date date1, date2;

    // 读取第一个日期
    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year);

    // 读取第二个日期
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year);

    // 处理两位数的年份：假设为2000年之后的年份
    // 如果年份小于50，认为是21世纪，否则认为是20世纪
    if (date1.year < 50) {
        date1.year += 2000;
    } else {
        date1.year += 1900;
    }

    if (date2.year < 50) {
        date2.year += 2000;
    } else {
        date2.year += 1900;
    }

    // 使用 compare_dates 函数比较日期
    int result = compare_dates(date1, date2);

    // 输出结果
    if (result < 0) {
        printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d\n",
               date1.month, date1.day, date1.year % 100,
               date2.month, date2.day, date2.year % 100);
    } else if (result > 0) {
        printf("%02d/%02d/%02d is earlier than %02d/%02d/%02d\n",
               date2.month, date2.day, date2.year % 100,
               date1.month, date1.day, date1.year % 100);
    } else {
        printf("The two dates are the same: %02d/%02d/%02d\n",
               date1.month, date1.day, date1.year % 100);
    }

    // 可选：显示每个日期是一年中的第几天
    printf("First date is day %d of the year.\n", day_of_year(date1));
    printf("Second date is day %d of the year.\n", day_of_year(date2));
}
