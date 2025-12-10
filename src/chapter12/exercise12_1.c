//1. (a) 编写程序读一条消息，然后逆序打印出这条消息：
//Enter a message: Don't get mad, get even.
//Reversal is: .neve teg ,dam teg t'noD
//提示：一次读取消息中的一个字符（用 getchar 函数），并且把这些字符存储在数组中，当数组
//        满了或者读到字符'\n'时停止读操作。
//(b) 修改上述程序，用指针代替整数来跟踪数组中的当前位置。

#include <stdio.h>

#define N 100

//void exercise12_1(void){
//    printf("Enter a message: ");
//    fflush(stdout);
//
//    char ch, arr[N];
//    int len = 0;
//    while ((ch = getchar()) != '\n' && len < N){
//        arr[len++] = ch;
//    }
//    printf("Reversal is: ");
//    for(int i = 1; i <= len; i++){
//        printf("%c", arr[len - i]);
//    }
//}

void exercise12_1(void){
    printf("Enter a message: ");
    fflush(stdout);

    char ch, arr[N];
    char *p = arr;
    while ((ch = getchar()) != '\n' && p < arr + N){
        *p++ = ch;
    }
    printf("Reversal is: ");
    while (p > arr){
        printf("%c", *--p);
    }
}