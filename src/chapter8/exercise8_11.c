//11. 修改第 7 章的编程题 4，给输出加上标签：
//Enter phone number: 1-800-COL-LECT
//        In numeric form: 1-800-265-5328
//在显示电话号码之前，程序需要将其（以原始格式或数值格式）存储在一个字符数组中。可以假定电话号码的
//        长度不超过 15 个字符。

#include <stdio.h>
#include <ctype.h>

#define N 15

int exercise8_11() {
    printf("Enter phone number: ");
    fflush(stdout);

    char ch, arr[N];
    for(int i = 0 ; i < N ; i++){
        arr[i] = ' ';
    }
    for(int i = 0 ; i < N ; i++){
        scanf("%c", &ch);
        ch = toupper(ch);
        if (ch >= 'A' && ch <= 'Z') {

            if (ch == 'A' || ch == 'B' || ch == 'C')
                ch = '2';
            else if (ch == 'D' || ch == 'E' || ch == 'F')
                ch = '3';
            else if (ch == 'G' || ch == 'H' || ch == 'I')
                ch = '4';
            else if (ch == 'J' || ch == 'K' || ch == 'L')
                ch = '5';
            else if (ch == 'M' || ch == 'N' || ch == 'O')
                ch = '6';
            else if (ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S')
                ch = '7';
            else if (ch == 'T' || ch == 'U' || ch == 'V')
                ch = '8';
            else if (ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z')
                ch = '9';
        }
        arr[i] = ch;

    }
    printf("In numeric form: ");
    for(int i = 0 ; i < N ; i++){
        printf("%c", arr[i]);
    }
}