//10. 编写程序统计句子中元音字母（a、e、i、o、u）的个数：
//
//Enter a sentence: And that's the way it is.
//Your sentence contains 6 vowels.

#include <stdio.h>
#include <ctype.h>
int exercise7_10() {
    printf("Enter a sentence: ");
    fflush(stdout);
    char ch;
    int number = 0;
    while ((ch = getchar()) != '\n'){
        ch = toupper(ch);
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U'){
            number ++;
        }
    }
    printf("Your sentence contains %d vowels.", number);

}