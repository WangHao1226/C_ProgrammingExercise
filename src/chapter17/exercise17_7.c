//7. 修改 17.2 节的 remind2.c 程序，使得 reminders 数组中的每个元素都是指向 vstring 结构（见
//17.9 节）的指针，而不是指向普通字符串的指针。

/* Prints a one-month reminder list (dynamic string version) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_REMIND 50 /* maximum number of reminders */
#define MSG_LEN 60 /* max length of remider message */

struct vstring {
    int len;
    char chars[];       /* flexible array member */
};

struct vstring *reminders[MAX_REMIND];

int num_remind = 0;

int read_line(char str[], int n);

int exercise17_7(void)
{    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }

        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;

        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        // 组合日期和提醒信息
        int total_len = strlen(day_str) + strlen(msg_str) + 1;  // +1 for null terminator

        // 分配vstring结构的内存
        struct vstring *new_reminder = malloc(sizeof(struct vstring) + total_len);
        if (new_reminder == NULL) {
            printf("-- No space left --\n");
            break;
        }

        // 设置长度
        new_reminder->len = total_len - 1;  // 不包括null terminator

        // 组合字符串
        strcpy(new_reminder->chars, day_str);
        strcat(new_reminder->chars, msg_str);

        // 找到插入位置（按日期排序）
        for (i = 0; i < num_remind; i++) {
            if (strcmp(day_str, reminders[i]->chars) < 0)
                break;
        }

        // 移动元素为新项腾出空间
        for (j = num_remind; j > i; j--) {
            reminders[j] = reminders[j - 1];
        }

        // 插入新提醒
        reminders[i] = new_reminder;
        num_remind++;
    }

    printf("\nDay Reminder\n");
    for (i = 0; i < num_remind; i++) {
        printf(" %s\n", reminders[i]->chars);
    }

    // 释放内存
    for (i = 0; i < num_remind; i++) {
        free(reminders[i]);
    }
    return i;
}