//1. 编写程序要求用户输入国际电话区号，然后在数组 country_codes 中查找它（见 16.3 节）。如果找
//        到对应的区号，程序需要显示相应的国家（地区）名称，否则显示出错消息。
#include <stdio.h>
#include <stdbool.h>

struct dialing_code {
    char *country;
    int code;
};

const struct dialing_code country_codes[] =
        {{"Argentina", 54}, {"Bangladesh", 880},
         {"Brazil", 55}, {"Burma (Myanmar)", 95},
         {"China", 86}, {"Colombia", 57},
         {"Congo, Dem. Rep. of", 243}, {"Egypt", 20},
         {"Ethiopia", 251}, {"France", 33},
         {"Germany", 49}, {"India ", 91},
         {"Indonesia", 62}, {"Iran", 98},
         {"Italy", 39}, {"Japan", 81},
         {"Mexico", 52}, {"Nigeria", 234},
         {"Pakistan", 92}, {"Philippines", 63},
         {"Poland", 48}, {"Russia", 7},
         {"South Africa", 27}, {"Korea", 82},
         {"Spain", 34}, {"Sudan", 249},
         {"Thailand", 66}, {"Turkey", 90},
         {"Ukraine", 380}, {"United Kingdom", 44},
         {"United States", 1}, {"Vietnam", 84}};

void exercise16_1(){
    printf("Enter international telephone area code: ");
    fflush(stdout);

    int area_code;
    bool find_code = 0;
    scanf("%d", &area_code);

    for(int i =0; i < 32; i++){
        if(area_code == country_codes[i].code){
            printf("Country name is %s.", country_codes[i].country);
            find_code = 1;
        }
    }
    if(find_code == 0){
        printf("Error, don't find code.");
    }
}