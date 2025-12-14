//6. 改进 13.7 节的程序 planet.c，使它在对命令行参数和 planets 数组中的字符串进行比较时忽略大
//        小写。

/* Checks planet names */
/* Checks planet names */
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define NUM_PLANETS 9

int strcasecmp_custom(const char *s1, const char *s2){
    while (*s1 && s2){
        if(tolower(*s1) != tolower(*s2)){
            return *s1 - *s2;
        }
        s1++;
        s2++;
    }
    return *s1 - *s2;
}

int exercise13_6(int argc, char *argv[]){
    char *planets[] = {"Mercury", "Venus", "Earth",
                       "Mars", "Jupiter", "Saturn",
                       "Uranus", "Neptune", "Pluto"};
    int i, j;

    for (i = 1; i < argc; i++) {
        for (j = 0; j < NUM_PLANETS; j++)
            if (strcasecmp_custom(argv[i], planets[j]) == 0) {
                printf("%s is planet %d\n", argv[i], j + 1);
                break;
            }
        if (j == NUM_PLANETS)
            printf("%s is not a planet\n", argv[i]);
    }
    return 0;
}