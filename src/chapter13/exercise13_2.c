////2. 按如下方式改进 13.5 节的 remind.c 程序。
////(a) 如果对应的日期为负数或大于 31，程序显示出错消息，并忽略提醒。提示：使用 continue 语句。
////(b) 允许用户输入日期、24 小时格式的时间和提醒。显示的提醒列表必须先按日期排序，然后再按
////        时间排序。（原始的 remind.c 程序允许用户输入时间，但是它把时间作为提醒的一部分来处理。）
////(c) 程序显示一年的提醒列表。要求用户按照月/日的格式输入日期。
////这个程序会显示一个月的每日
////        提醒列表。用户需要输入一系列提醒，每条提醒都要有一个前缀来说明是一个月中的哪一天。
////当用户输入的是 0 而不是有效的日期时，程序会显示出输入的全部提醒的列表，并按日期排序。
////下面是与程序的会话示例：
////Enter day and reminder: 24 Susan's birthday
////Enter day and reminder: 5 6:00 - Dinner with Marge and Russ
////        Enter day and reminder: 26 Movie - "Chinatown"
////Enter day and reminder: 7 10:30 - Dental appointment
////Enter day and reminder: 12 Movie - "Dazed and Confused"
////Enter day and reminder: 5 Saturday class
////Enter day and reminder: 12 Saturday class
////Enter day and reminder: 0
////Day Reminder
////5 Saturday class
////5 6:00 - Dinner with Marge and Russ
////7 10:30 - Dental appointment
////12 Saturday class
////12 Movie - "Dazed and Confused"
////24 Susan's birthday
////26 Movie - "Chinatown"
//
///* Prints a one-month reminder list */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_REMIND 50
//#define MSG_LEN 80
//
//int read_line(char str[], int n);
//int days_in_month(int month);
//
//int exercise13_2() {
//    char reminders[MAX_REMIND][MSG_LEN + 15];
//    char date_str[7], msg_str[MSG_LEN + 1], time_str[7];
//    int month, day, hour, minute, i, j, num_remind = 0;
//
//    int month_days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
//
//    for (;;) {
//        if (num_remind == MAX_REMIND) {
//            printf("-- No space left --\n");
//            break;
//        }
//
//        printf("Enter date (mm/dd), time (hh:mm), and reminder: ");
//        fflush(stdout);
//
//        if (scanf("%d/%d", &month, &day) != 2) {
//            printf("Invalid date format. Use mm/dd\n");
//            while (getchar() != '\n');
//            continue;
//        }
//
//        if (month == 0)
//            break;
//
//        if (month < 1 || month > 12) {
//            printf("Error: Month must be between 1 and 12\n");
//            while (getchar() != '\n');
//            continue;
//        }
//
//        if (day < 1 || day > month_days[month - 1]) {
//            printf("Error: Day must be between 1 and %d for month %d\n",
//                   month_days[month - 1], month);
//            while (getchar() != '\n');
//            continue;
//        }
//
//        if (scanf("%d:%d", &hour, &minute) != 2) {
//            printf("Invalid time format. Use HH:MM\n");
//            while (getchar() != '\n');
//            continue;
//        }
//
//        if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
//            printf("Error: Time must be between 00:00 and 23:59\n");
//            while (getchar() != '\n');
//            continue;
//        }
//
//        read_line(msg_str, MSG_LEN);
//
//        sprintf(date_str, "%2d/%2d", month, day);
//        sprintf(time_str, "%02d:%02d", hour, minute);
//
//        char temp_reminder[MSG_LEN + 10];
//        sprintf(temp_reminder, "%s%s %s", date_str, time_str, msg_str);
//
//        for (i = 0; i < num_remind; i++) {
//            int existing_month, existing_day, existing_hour, existing_minute;
//
//            sscanf(reminders[i], "%d/%d", &existing_month, &existing_day);
//            sscanf(reminders[i] + 6, "%d:%d", &existing_hour, &existing_minute);
//
//            if (month < existing_month) {
//                break;
//            } else if (month == existing_month) {
//                if (day < existing_day) {
//                    break;
//                } else if (day == existing_day) {
//                    if (hour < existing_hour || (hour == existing_hour && minute < existing_minute)) {
//                        break;
//                    }
//                }
//            }
//        }
//
//        for (j = num_remind; j > i; j--)
//            strcpy(reminders[j], reminders[j - 1]);
//
//        strcpy(reminders[i], temp_reminder);
//        num_remind++;
//    }
//
//    printf("\nDate     Time  Reminder\n");
//    printf("=======================\n");
//
//    int current_month = 0;
//    for (i = 0; i < num_remind; i++) {
//        int month;
//        sscanf(reminders[i], "%d", &month);
//
//        if (month != current_month) {
//            current_month = month;
//            printf("\n");
//        }
//
//        printf(" %s\n", reminders[i]);
//    }
//
//    return 0;
//}
//
//int read_line(char str[], int n) {
//    int ch, i = 0;
//    while ((ch = getchar()) != '\n')
//        if (i < n)
//            str[i++] = ch;
//    str[i] = '\0';
//    return i;
//}
