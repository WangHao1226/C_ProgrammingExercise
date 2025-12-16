//10. 修改第 7 章的编程题 11，使其包含如下函数：
//void reverse_name(char *name);
//在参数 name 指向的字符串中，名在前、姓在后。在修改后的字符串中，姓在前，其后跟一个逗号和
//        一个空格，然后是名的首字母，最后加一个点。原始的字符串中，名的前面、名和姓之间、姓的后
//        面都可以有额外的空格。
//11. 编写一个程序，要求用户输入英文名和姓，并根据用户的输入先显示姓，其后跟一个逗号，然后显
//        示名的首字母，最后加一个点：
//Enter a first and last name: Lloyd Fosdick
//Fosdick, L.
//用户的输入中可能包含空格（名之前、名和姓之间、姓氏之后）。

#include <stdio.h>
#include <ctype.h>

#define MAX_NAME_LEN 100

void reverse_name(char *name);

int exercise13_10() {
    printf("Enter a first and last name: ");
    fflush(stdout);

    char name[MAX_NAME_LEN + 1];
    fgets(name, sizeof (name), stdin);

    reverse_name(name);

    printf("%s\n", name);

}

void reverse_name(char *name) {
    char first_initial;
    char ch;
    char last_name[MAX_NAME_LEN];
    int last_name_index = 0;
    int i = 0;

    // 跳过名前的空格
    while ((ch = name[i]) == ' ') {
        i++;
    }

    // 获取名的首字母
    first_initial = toupper(ch);

    // 跳过名的剩余部分
    while ((ch = name[i]) != ' ' && ch != '\n' && ch != '\0') {
        i++;
    }

    // 跳过名和姓之间的空格
    while ((ch = name[i]) == ' ') {
        i++;
    }

    // 获取姓
    if (ch != '\n' && ch != '\0') {
        // 将姓的第一个字母大写
        last_name[last_name_index++] = toupper(ch);
        i++;

        // 获取姓的剩余部分
        while ((ch = name[i]) != '\n' && ch != ' ' && ch != '\0') {
            last_name[last_name_index++] = tolower(ch);
            i++;
        }
    }

    // 在姓的末尾添加逗号、空格、名的首字母和点
    last_name[last_name_index++] = ',';
    last_name[last_name_index++] = ' ';
    last_name[last_name_index++] = first_initial;
    last_name[last_name_index++] = '.';
    last_name[last_name_index] = '\0';

    // 将修改后的结果复制回原字符串
    for (int j = 0; j <= last_name_index; j++) {
        name[j] = last_name[j];
    }
}