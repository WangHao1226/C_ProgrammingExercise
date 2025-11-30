//11. 编写一个程序，要求用户输入英文名和姓，并根据用户的输入先显示姓，其后跟一个逗号，然后显
//        示名的首字母，最后加一个点：
//Enter a first and last name: Lloyd Fosdick
//Fosdick, L.
//用户的输入中可能包含空格（名之前、名和姓之间、姓氏之后）。

#include <stdio.h>
#include <ctype.h>
int exercise7_11() {
    printf("Enter a first and last name: ");
    fflush(stdout);

    char first_initial;
    char ch;

    while ((ch = getchar()) == ' ');

    first_initial = ch;

    while ((ch = getchar()) != ' ' && ch != '\n');

    if (ch == ' ') {
        while ((ch = getchar()) == ' ');
    }

    if (ch != '\n') {
        putchar(ch);
        while ((ch = getchar()) != '\n' && ch != ' ') {
            putchar(ch);
        }
    }

    printf(", %c.\n", first_initial);

}