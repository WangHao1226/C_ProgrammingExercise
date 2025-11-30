//4. 编写可以把字母格式的电话号码翻译成数值格式的程序：
//Enter phone number: CALLATT
//2255288
//（如果没有电话在身边，参考这里给出的字母在键盘上的对应关系：2=ABC、3=DEF、4=GHI、5=JKL、
//6=MNO、7=PQRS、8=TUV、9=WXYZ。）原始电话号码中的非字母字符（例如数字或标点符号）保持不变：
//Enter phone number: 1-800-COL-LECT
//1-800-265-5328
//可以假设任何用户输入的字母都是大写字母。

#include <stdio.h>
#include <ctype.h>

int exercise7_4() {
    char ch;

    printf("Enter phone number: ");
    fflush(stdout);

    while ((ch = getchar()) != '\n') {
        ch = toupper(ch);

        if (ch >= 'A' && ch <= 'Z') {
            if (ch == 'A' || ch == 'B' || ch == 'C')
                printf("2");
            else if (ch == 'D' || ch == 'E' || ch == 'F')
                printf("3");
            else if (ch == 'G' || ch == 'H' || ch == 'I')
                printf("4");
            else if (ch == 'J' || ch == 'K' || ch == 'L')
                printf("5");
            else if (ch == 'M' || ch == 'N' || ch == 'O')
                printf("6");
            else if (ch == 'P' || ch == 'Q' || ch == 'R' || ch == 'S')
                printf("7");
            else if (ch == 'T' || ch == 'U' || ch == 'V')
                printf("8");
            else if (ch == 'W' || ch == 'X' || ch == 'Y' || ch == 'Z')
                printf("9");
        } else {
            printf("%c", ch);
        }
    }
    printf("\n");

}