//10. 修改第 5 章的编程题 8，用一个数组存储航班起飞时间，另一个数组存储航班抵达时间。（时间用整
//        数表示，表示从午夜开始的分钟数。）程序用一个循环搜索起飞时间数组，以找到与用户输入的时间
//        最接近的起飞时间。
// 起飞时间   抵达时间
//8:00 a.m. 10:16 a.m.
//9:43 a.m. 11:52 a.m.
//11:19 a.m. 1:31 p.m.
//12.47 p.m. 3:00 p.m.
//2:00 p.m. 4:08 p.m.
//3:45 p.m. 5:55 p.m.
//7:00 p.m. 9:20 p.m.
//9:45 p.m. 11:58 p.m.

#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int exercise8_10() {
    // 修正后的时间数组（以分钟表示）
    int departure[SIZE] = {480, 583, 679, 767, 840, 945, 1140, 1305};  // 8:00, 9:43, 11:19, 12:47, 14:00, 15:45, 19:00, 21:45
    int arrival[SIZE] = {616, 712, 811, 900, 968, 1075, 1280, 1438};   // 10:16, 11:52, 13:31, 15:00, 16:08, 17:55, 21:20, 23:58

    printf("Enter a 24-hour time (hh:mm): ");

    int h, m;
    if (scanf("%d:%d", &h, &m) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    // 将输入时间转换为分钟
    int time = h * 60 + m;

    // 找到最接近的起飞时间
    int min_diff = abs(time - departure[0]);
    int closest_index = 0;

    for (int i = 1; i < SIZE; i++) {
        int diff = abs(time - departure[i]);
        if (diff < min_diff) {
            min_diff = diff;
            closest_index = i;
        }
    }

    // 格式化输出起飞时间
    int dep_hour = departure[closest_index] / 60;
    int dep_minute = departure[closest_index] % 60;

    printf("Closest departure time is ");
    if (dep_hour < 12) {
        printf("%d:%02d a.m.", dep_hour, dep_minute);
    } else if (dep_hour == 12) {
        printf("12:%02d p.m.", dep_minute);
    } else {
        printf("%d:%02d p.m.", dep_hour - 12, dep_minute);
    }

    // 格式化输出到达时间
    int arr_hour = arrival[closest_index] / 60;
    int arr_minute = arrival[closest_index] % 60;

    printf(", arriving at ");
    if (arr_hour < 12) {
        printf("%d:%02d a.m.", arr_hour, arr_minute);
    } else if (arr_hour == 12) {
        printf("12:%02d p.m.", arr_minute);
    } else {
        printf("%d:%02d p.m.", arr_hour - 12, arr_minute);
    }
    printf("\n");

}