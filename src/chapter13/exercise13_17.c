//17. 修改第 12 章的编程题 2，使其包含如下函数：
//bool is_palindrome(const char *message);
//如果 message 指向的字符串是回文，函数返回 true。
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
#include <stdbool.h>

#define MAX_MESSAGE_LEN 100

bool is_palindrome(const char *message);

void exercise13_17(void){
    printf("Enter a message: ");
    fflush(stdout);

    char message[MAX_MESSAGE_LEN];
    fgets(message, sizeof (message), stdin);

    if(is_palindrome(message)){
        printf("Palindrome");
    } else{
        printf("Not a palindrome");
    }
}

bool is_palindrome(const char *message){
    char *start = message;
    char *end = message;

    while (*end != '\0'){
        end++;
    }

    end--;

    while (start < end){
        while (!isalpha(*start)){
            start++;
        }
        while (!isalpha(*end)){
            end--;
        }
        if(tolower(*start) != tolower(*end)){
            return false;
        }

        start++;
        end--;
    }
    return true;

}