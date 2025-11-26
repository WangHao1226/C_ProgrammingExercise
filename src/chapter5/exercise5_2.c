//2. 编写一个程序，要求用户输入 24 小时制的时间，然后显示 12 小时制的格式：
//Enter a 24-hour time: 21:11
//Equivalent 12-hour time: 9:11 PM
//        注意不要把 12:00 显示成 0:00。

#include <stdio.h>

void exercise5_2(void) {
    printf("Enter a 24-hour time: ");
    fflush(stdout);

    int hour, minute;
    scanf("%d:%d", &hour, &minute);

    const char *AMorPM;

    if (hour == 0) {
        hour = 12;
        AMorPM = "AM";
    } else if (hour == 12) {
        AMorPM = "PM";
    } else if (hour > 12) {
        hour -= 12;
        AMorPM = "PM";
    } else {
        AMorPM = "AM";
    }

    printf("Equivalent 12-hour time: %d:%02d %s\n", hour, minute, AMorPM);
}