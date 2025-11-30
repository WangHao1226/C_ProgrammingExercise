//8. 修改第 5章的编程题 8，要求用户输入 12小时制的时间。输入时间的格式为时:分后跟 A、P、AM或
//        PM（大小写均可）。数值时间和 AM/PM 之间允许有空白（但不强制要求有空白）。有效输入的示
//        例如下：
//
//1:15P
//1:15PM
//1:15p
//1:15pm
//1:15 P
//1:15 PM
//1:15 p
//1:15 pm
//        可以假定输入的格式就是上述之一，不需要进行错误判定。
//        起飞时间 抵达时间
//8:00 a.m. 10:16 a.m.
//9:43 a.m. 11:52 a.m.
//11:19 a.m. 1:31 p.m.
//12.47 p.m. 3:00 p.m.
//2:00 p.m. 4:08 p.m.
//3:45 p.m. 5:55 p.m.
//7:00 p.m. 9:20 p.m.
//9:45 p.m. 11:58 p.m.

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
int exercise7_8() {
    int hour, minute;
    char period[3];

    printf("Enter a 12-hour time: ");
    fflush(stdout);
    scanf("%d:%d %2s", &hour, &minute, period);

    // 转换为24小时制的总分钟数
    int total_minutes;
    if (toupper(period[0]) == 'P' && hour != 12) {
        total_minutes = (hour + 12) * 60 + minute;
    } else if (toupper(period[0]) == 'A' && hour == 12) {
        total_minutes = minute; // 12:xx AM 是 0:xx
    } else {
        total_minutes = hour * 60 + minute;
    }

    // 航班时间表（起飞时间，以分钟表示）
    int flights[] = {480, 583, 679, 767, 840, 945, 1140, 1305};

    // 找到最接近的航班
    int closest = 0;
    for (int i = 1; i < 8; i++) {
        if (abs(total_minutes - flights[i]) < abs(total_minutes - flights[closest])) {
            closest = i;
        }
    }

    // 输出结果
    printf("Closest departure time is ");

    // 起飞时间
    int dep_hour = flights[closest] / 60;
    int dep_min = flights[closest] % 60;

    if (dep_hour < 12) {
        printf("%d:%02d a.m.", dep_hour, dep_min);
    } else if (dep_hour == 12) {
        printf("12:%02d p.m.", dep_min);
    } else {
        printf("%d:%02d p.m.", dep_hour - 12, dep_min);
    }

    printf("\n");

}