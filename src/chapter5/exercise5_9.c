//9. 编写一个程序，提示用户输入两个日期，然后显示哪一个日期更早：
//Enter first date (mm/dd/yy): 3/6/08
//Enter second date (mm/dd/yy): 5/17/07
//5/17/07 is earlier than 3/6/08

#include <stdio.h>

int exercise5_9() {
    printf("Enter first date (mm/dd/yy): ");
    fflush(stdout);

    int mm1, dd1, yy1;
    scanf("%d/%d/%d", &mm1, &dd1, &yy1);

    printf("Enter second date (mm/dd/yy): ");
    fflush(stdout);

    int mm2, dd2, yy2;
    scanf("%d/%d/%d", &mm2, &dd2, &yy2);

    int before;
    if(yy1 < yy2){
        before = 0;
    } else if(yy1 > yy2){
        before = 1;
    } else{
        if(mm1 < mm2){
            before = 0;
        } else if(mm1 > mm2){
            before = 1;
        } else{
            if(dd1 < dd2){
                before = 0;
            } else if(dd1 > dd2){
                before = 1;
            } else{
                printf("The two days are same day");
            }
        }
    }
    if(before == 0){
        printf("%2d/%2d/%2d is earlier than %2d/%2d/%2d", mm1, dd1, yy1, mm2, dd2, yy2);
    } else{
        printf("%2d/%2d/%2d is earlier than %2d/%2d/%2d", mm2, dd2, yy2, mm1, dd1, yy1);
    }
}