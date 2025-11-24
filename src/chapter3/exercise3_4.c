//4. 编写一个程序，提示用户以(xxx) xxx-xxxx 的格式输入电话号码，并以 xxx.xxx.xxxx 的格式显示该
//号码：
//Enter phone number [(xxx) xxx-xxxx]: (404) 817-6900
//You entered 404.817.6900

#include <stdio.h>

void exercise3_4(void) {
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    fflush(stdout);
    int part1, part2, part3;
    scanf("(%d) %d-%d", &part1, &part2, &part3);
    printf("You entered %d.%d.%d", part1, part2, part3);

}