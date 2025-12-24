//5. 修改第 5 章的编程题 8，以便用一个单独的数组存储时间。数组的元素都是结构，每个结构包含航班
//        的起飞时间和抵达时间。（时间都是整数，表示从午夜开始的分钟数。）程序用一个循环从数组中搜
//        索与用户输入的时间最接近的起飞时间。
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
#include <math.h>

struct time{
    int departure_time;
    int arrival_time;
};

// 函数：将小时和分钟转换为从午夜开始的分钟数
int convert_to_minutes(int hours, int minutes) {
    return hours * 60 + minutes;
}

// 函数：将分钟数转换为12小时制的时间字符串
void convert_to_12_hour_format(int minutes, char *time_str) {
    int hours = minutes / 60;
    int mins = minutes % 60;

    // 处理12小时制
    if (hours == 0) {
        sprintf(time_str, "12:%02d a.m.", mins);
    } else if (hours < 12) {
        sprintf(time_str, "%d:%02d a.m.", hours, mins);
    } else if (hours == 12) {
        sprintf(time_str, "12:%02d p.m.", mins);
    } else {
        sprintf(time_str, "%d:%02d p.m.", hours - 12, mins);
    }
}

int exercise16_5() {
    // 初始化航班时间表
    struct time flights[] = {
            {convert_to_minutes(8, 0), convert_to_minutes(10, 16)},   // 8:00 a.m. - 10:16 a.m.
            {convert_to_minutes(9, 43), convert_to_minutes(11, 52)},  // 9:43 a.m. - 11:52 a.m.
            {convert_to_minutes(11, 19), convert_to_minutes(13, 31)}, // 11:19 a.m. - 1:31 p.m.
            {convert_to_minutes(12, 47), convert_to_minutes(15, 0)},  // 12:47 p.m. - 3:00 p.m.
            {convert_to_minutes(14, 0), convert_to_minutes(16, 8)},   // 2:00 p.m. - 4:08 p.m.
            {convert_to_minutes(15, 45), convert_to_minutes(17, 55)}, // 3:45 p.m. - 5:55 p.m.
            {convert_to_minutes(19, 0), convert_to_minutes(21, 20)},  // 7:00 p.m. - 9:20 p.m.
            {convert_to_minutes(21, 45), convert_to_minutes(23, 58)}  // 9:45 p.m. - 11:58 p.m.
    };

    int num_flights = sizeof(flights) / sizeof(flights[0]);
    int hours, minutes, user_time;
    int closest_index = 0;
    int min_difference = 24 * 60;  // 初始化为一天的总分钟数

    // 获取用户输入
    printf("Enter a 24-hour time: ");
    fflush(stdout);
    scanf("%d:%d", &hours, &minutes);

    user_time = convert_to_minutes(hours, minutes);

    // 搜索最接近的起飞时间
    for (int i = 0; i < num_flights; i++) {
        int difference = abs(flights[i].departure_time - user_time);

        // 如果找到更接近的时间，更新最接近的索引和最小差值
        if (difference < min_difference) {
            min_difference = difference;
            closest_index = i;
        }
    }

    // 准备输出字符串
    char departure_str[20];
    char arrival_str[20];

    convert_to_12_hour_format(flights[closest_index].departure_time, departure_str);
    convert_to_12_hour_format(flights[closest_index].arrival_time, arrival_str);

    // 输出结果
    printf("Closest departure time is %s, arriving at %s\n", departure_str, arrival_str);
}