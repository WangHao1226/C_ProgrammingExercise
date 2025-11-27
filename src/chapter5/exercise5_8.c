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

#include <stdio.h>
#include <stdlib.h>

void exercise5_8(void) {
    // 定义航班时间表（转换为分钟数）
    int departures[] = {
            8*60,      // 8:00 a.m.
            9*60+43,   // 9:43 a.m.
            11*60+19,  // 11:19 a.m.
            12*60+47,  // 12:47 p.m.
            14*60,     // 2:00 p.m.
            15*60+45,  // 3:45 p.m.
            19*60,     // 7:00 p.m.
            21*60+45   // 9:45 p.m.
    };

    char *departure_str[] = {
            "8:00 a.m.", "9:43 a.m.", "11:19 a.m.", "12:47 p.m.",
            "2:00 p.m.", "3:45 p.m.", "7:00 p.m.", "9:45 p.m."
    };

    char *arrival_str[] = {
            "10:16 a.m.", "11:52 a.m.", "1:31 p.m.", "3:00 p.m.",
            "4:08 p.m.", "5:55 p.m.", "9:20 p.m.", "11:58 p.m."
    };

    int num_flights = sizeof(departures) / sizeof(departures[0]);

    printf("输入时间（24小时制，格式HH:MM）：");
    fflush(stdout);

    int hour, minute;
    scanf("%d:%d", &hour, &minute);

    // 验证输入时间是否有效
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        printf("无效的时间输入！\n");
        return;
    }

    // 将用户输入时间转换为分钟数
    int input_time = hour * 60 + minute;

    // 找到最接近的航班
    int min_diff = 24 * 60; // 初始化为最大值
    int closest_flight = 0;

    for (int i = 0; i < num_flights; i++) {
        int diff = abs(departures[i] - input_time);
        if (diff < min_diff) {
            min_diff = diff;
            closest_flight = i;
        }
    }

    // 显示结果
    printf("\n最接近的航班：\n");
    printf("起飞时间：%s\n", departure_str[closest_flight]);
    printf("抵达时间：%s\n", arrival_str[closest_flight]);
}