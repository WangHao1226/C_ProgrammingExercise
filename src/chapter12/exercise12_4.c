//4. 请利用数组名可以用作指针的事实简化编程题 2(b)的程序。
//2. (a) 编写程序读一条消息，然后检查这条消息是否是回文（消息中的字母从左往右读和从右往左读是
//        一样的）：
//Enter a message: He lived as a devil, eh?
//Palindrome
//        Enter a message: Madam, I am Adam.
//Not a palindrome
//        忽略所有不是字母的字符。用整型变量来跟踪数组中的位置。
//(b) 修改上述程序，使用指针代替整数来跟踪数组中的位置。

#include <stdio.h>
#include <ctype.h>

#define N 100

void exercise12_4(void){
    printf("Enter a message: ");
    fflush(stdout);

    char ch, arr[N];
    char *p = arr;

    while ((ch = getchar()) != '\n' && p < arr + N) {
        if (isalpha(ch)) {
            *p++ = tolower(ch);
        }
    }

    char *start = arr;
    char *end = p - 1;

    while (start < end){
        if(*start != *end){
            printf("Not a palindrome");
            return;
        }
        start++;
        end--;
    }
    printf("Palindrome");
}