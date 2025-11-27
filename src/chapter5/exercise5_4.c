//4. 表 5-6 中展示了用于测量风力的蒲福风级的简化版本。
//表 5-6 简化的蒲福风级
//        速率（海里／小时） 描 述
//小于 1 Calm（无风）
//1～3 Light air（轻风）
//4～27 Breeze（微风）
//28～47 Gale（大风）
//48～63 Storm（暴风）
//大于 63 Hurricane（飓风）
//编写一个程序，要求用户输入风速（海里/小时），然后显示相应的描述。

#include <stdio.h>

void exercise5_4(void) {
    printf("输入风速（海里/小时）： ");
    fflush(stdout);

    int wind_speed;
    scanf("%d", &wind_speed);
    if(wind_speed < 1){
        printf("Calm");
    } else if(wind_speed >= 1 && wind_speed <= 3){
        printf("Light air");
    } else if(wind_speed >= 4 && wind_speed <= 27){
        printf("Breeze");
    } else if(wind_speed >= 28 && wind_speed <= 47){
        printf("Gale");
    } else if(wind_speed >= 48 && wind_speed <= 63){
        printf("Storm");
    } else{
        printf("Hurricane");
    }

}