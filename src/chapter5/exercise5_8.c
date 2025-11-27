//8. 表 5-8 给出了从一个城市到另一个城市的每日航班信息。
//表 5-8 每日航班信息
//        起飞时间 抵达时间
//8:00 a.m. 10:16 a.m.
//9:43 a.m. 11:52 a.m.
//11:19 a.m. 1:31 p.m.
//12.47 p.m. 3:00 p.m.
//2:00 p.m. 4:08 p.m.
//3:45 p.m. 5:55 p.m.
//7:00 p.m. 9:20 p.m.
//9:45 p.m. 11:58 p.m.
//编写一个程序，要求用户输入一个时间（用 24 小时制的时分表示）。程序选择起飞时间与用户输入
//        最接近的航班，显示出相应的起飞时间和抵达时间。
//Enter a 24-hour time: 13:15
//Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
//提示：把输入用从午夜开始的分钟数表示。将这个时间与表格里（也用从午夜开始的分钟数表示）
//的起飞时间相比。例如，13:15 从午夜开始是 13×60+15 = 795 分钟，与下午 12:47（从午夜开始是
//767 分钟）最接近。

#include <stdio.h>

int exercise5_8() {
    int h, m, t;

    printf("Enter a 24-hour time: ");
    fflush(stdout);
    scanf("%d:%d", &h, &m);

    t = h * 60 + m;

    // 使用条件判断直接输出结果
    if (t < 531) printf("8:00 a.m., arriving at 10:16 a.m.\n");
    else if (t < 631) printf("9:43 a.m., arriving at 11:52 a.m.\n");
    else if (t < 723) printf("11:19 a.m., arriving at 1:31 p.m.\n");
    else if (t < 803) printf("12:47 p.m., arriving at 3:00 p.m.\n");
    else if (t < 892) printf("2:00 p.m., arriving at 4:08 p.m.\n");
    else if (t < 1042) printf("3:45 p.m., arriving at 5:55 p.m.\n");
    else if (t < 1222) printf("7:00 p.m., arriving at 9:20 p.m.\n");
    else printf("9:45 p.m., arriving at 11:58 p.m.\n");
}