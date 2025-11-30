//9. 编写程序，要求用户输入 12 小时制的时间，然后用 24 小时制显示该时间：
//Enter a 12-hour time: 9:11 PM
//        Equivalent 24-hour time: 21:11
//参考编程题 8 中关于输入格式的描述。

#include <stdio.h>
#include <ctype.h>
int exercise7_9() {
    printf("Enter a 12-hour time: ");
    fflush(stdout);
    int h, m;
    char a_p;
    scanf("%d:%d %c", &h, &m, &a_p);
    a_p = toupper(a_p);
    if(&a_p >= 'A' && a_p <= 'Z' ){
        if(a_p == 'A'){
            printf("Equivalent 24-hour time: %d:%d", h, m);
        } else{
            printf("Equivalent 24-hour time: %d:%d", h + 12, m);
        }
    }

}