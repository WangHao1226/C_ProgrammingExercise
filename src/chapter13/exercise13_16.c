//16. 修改第 12 章的编程题 1，使其包含如下函数：
//void reverse(char *message);
//函数的作用是反转 message 指向的字符串。提示：使用两个指针，初始时一个指向字符串的第一个
//        字符，另一个指向最后一个字符；交换这两个字符，然后让两个指针相向移动；重复这一过程直到
//        两个指针相遇。
//1. (a) 编写程序读一条消息，然后逆序打印出这条消息：
//Enter a message: Don't get mad, get even.
//Reversal is: .neve teg ,dam teg t'noD
//提示：一次读取消息中的一个字符（用 getchar 函数），并且把这些字符存储在数组中，当数组
//        满了或者读到字符'\n'时停止读操作。
//(b) 修改上述程序，用指针代替整数来跟踪数组中的当前位置。

#include <stdio.h>
#include <string.h>

#define MAX_MESSAGE_SIZE 100

void reverse(char *message);

void exercise13_16(void){
    printf("Enter a message: ");
    fflush(stdout);

    char message[MAX_MESSAGE_SIZE + 1];

    fgets(message, sizeof (message), stdin);    // 移除fgets可能读取的换行符
    message[strcspn(message, "\n")] = '\0';

    // 调用reverse函数反转字符串
    reverse(message);

    // 输出反转后的字符串
    printf("Reversal is: %s\n", message);

}

void reverse(char *message){
    char *start = message;      // 指向字符串开头的指针
    char *end = message;        // 将用于找到字符串末尾的指针

    // 找到字符串的末尾（指向最后一个字符）
    while (*end != '\0') {
        end++;
    }
    end--;  // 回退一步，指向最后一个有效字符（跳过'\0'）

    // 交换start和end指向的字符，直到它们相遇或交叉
    while (start < end) {
        // 交换两个字符
        char temp = *start;
        *start = *end;
        *end = temp;

        // 移动指针
        start++;
        end--;
    }
}