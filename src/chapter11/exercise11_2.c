//2. 修改第 5 章的编程题 8，使其包含下列函数：
//void find_closest_flight(int desired_time,
//                         int *departure_time,
//                         int *arrival_time);
//函数需查出起飞时间与 desired_time（用从午夜开始的分钟数表示）最接近的航班。该航班的起飞
//        时间和抵达时间（也都用从午夜开始的分钟数表示）将分别存储在 departure_time 和 arrival_time
//所指向的变量中。
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

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {
    // 航班时间表（分钟表示）
    int departures[8] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    int arrivals[8] = {616, 712, 811, 900, 968, 1075, 1280, 1438};

    // 计算相邻航班之间的中点（决定选择哪个航班的边界）
    // 这些中点用于确定desired_time最接近哪个航班
    int midpoints[7];
    for (int i = 0; i < 7; i++) {
        midpoints[i] = (departures[i] + departures[i+1]) / 2;
    }

    // 特殊情况：00:00到第一个中点之间
    if (desired_time < midpoints[0]) {
        *departure_time = departures[0];
        *arrival_time = arrivals[0];
        return;
    }

    // 检查中间的时间段
    for (int i = 0; i < 6; i++) {
        if (desired_time >= midpoints[i] && desired_time < midpoints[i+1]) {
            *departure_time = departures[i+1];
            *arrival_time = arrivals[i+1];
            return;
        }
    }

    // 最后一个中点之后的时间
    *departure_time = departures[7];
    *arrival_time = arrivals[7];
}

int exercise11_2(void) {
    int h, m;

    printf("Enter a 24-hour time: ");
    fflush(stdout);
    scanf("%d:%d", &h, &m);

    // 将时间转换为分钟
    int desired_time = h * 60 + m;
    int departure_time, arrival_time;

    // 查找最接近的航班
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    // 转换起飞时间为12小时制并显示
    printf("Closest departure time is ");

    int dep_hour = departure_time / 60;
    int dep_minute = departure_time % 60;

    if (dep_hour == 0) {
        printf("12:%02d a.m.", dep_minute);
    } else if (dep_hour < 12) {
        printf("%d:%02d a.m.", dep_hour, dep_minute);
    } else if (dep_hour == 12) {
        printf("12:%02d p.m.", dep_minute);
    } else {
        printf("%d:%02d p.m.", dep_hour - 12, dep_minute);
    }

    // 转换抵达时间为12小时制并显示
    printf(", arriving at ");

    int arr_hour = arrival_time / 60;
    int arr_minute = arrival_time % 60;

    if (arr_hour == 0) {
        printf("12:%02d a.m.", arr_minute);
    } else if (arr_hour < 12) {
        printf("%d:%02d a.m.", arr_hour, arr_minute);
    } else if (arr_hour == 12) {
        printf("12:%02d p.m.", arr_minute);
    } else {
        printf("%d:%02d p.m.", arr_hour - 12, arr_minute);
    }

    printf("\n");
    return 0;
}