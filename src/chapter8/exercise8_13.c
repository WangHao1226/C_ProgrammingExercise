//13. 修改第 7 章的编程题 11，给输出加上标签：
//Enter a first and last name: Lloyd Fosdick
//You enered the name: Fosdick, L.
//在显示姓（不是名）之前，程序需要将其存储在一个字符数组中。可以假定姓的长度不超过 20 个字符。

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define N 20

int exercise8_13() {
    printf("Enter a first and last name: ");
    fflush(stdout);

    char first_initial;
    char ch;

    while ((ch = getchar()) == ' ');
    first_initial = ch;

    while ((ch = getchar()) != ' ' && ch != '\n');

    char arr[N];
    for(int i = 0 ; i < N ; i++){
        arr[i] = ' ';
    }

    if (ch == ' ') {
        while ((ch = getchar()) == ' ');
    }

    if (ch != '\n') {
        putchar(ch);
        for(int i = 0 ; i < N ; i ++){
            scanf("%c", &ch);
            arr[i] = ch;
            if(ch == '\n' || ch == ' '){
                break;
            }
        }

    }
    for(int i = 0 ; i < N ; i++){
        if(arr[i] == '\n' || arr[i] == ' '){
            break;
        }
        printf("%c", arr[i]);
    }
    printf(", %c.\n", first_initial);

}