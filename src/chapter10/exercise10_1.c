////1. 修改 10.2节的栈示例使它存储字符而不是整数。接下来，增加 main函数，用来要求用户输入一串圆
////        括号或花括号，然后指出它们之间的嵌套是否正确：
////Enter parenteses and/or braces: ((){}{()})
////Parenteses/braces are nested properly
////提示：读入左圆括号或左花括号时，把它们像字符一样压入栈中。当读入右圆括号或右花括号时，
////把栈顶的项弹出，并且检查弹出项是否是匹配的圆括号或花括号。（如果不是，那么圆括号或花括号
////        嵌套不正确。）当程序读入换行符时，检查栈是否为空。如果为空，那么圆括号或花括号匹配；如果
////        栈不为空（或者如果曾经调用过 stack_underflow 函数），那么圆括号或花括号不匹配。如果调用
////        stack_overflow 函数，程序显示信息 Stack overflow，并且立刻终止。
//
//#include <stdbool.h> /* C99 only */
//#include <stdio.h>
//#include <stdlib.h>
//
//#define STACK_SIZE 100
//
///* external variables */
//int contents[STACK_SIZE];
//int top = 0;
//
//void make_empty(void)
//{
//    top = 0;
//}
//
//bool is_empty(void)
//{
//    return top == 0;
//}
//
//bool is_full(void)
//{
//    return top == STACK_SIZE;
//}
//
//void stack_overflow(){
//    printf("Stack overflow\n");
//    exit(EXIT_FAILURE);
//}
//
//void stack_underflow(){
//    printf("Stack underflow\n");
//    exit(EXIT_FAILURE);
//}
//
//void push(int i)
//{
//    if (is_full())
//        stack_overflow();
//    else
//        contents[top++] = i;
//}
//
//int pop(void)
//{
//    if (is_empty())
//        stack_underflow();
//    else
//        return contents [--top];
//}
//
//int exercise10_1(){
//    printf("Enter parenteses and/or braces: ");
//    fflush(stdout);
//
//    char ch;
//    while ((ch = getchar()) != '\n'){
//        if(ch == '(' || ch == '{'){
//            push(ch);
//        } else if(ch == ')' || ch == '}'){
//            if(is_empty()){
//                printf("Parentheses/braces are NOT nested properly\n");
//                return 0;
//            }
//
//            char left = pop();
//            if ((ch == ')' && left != '(') || (ch == '}' && left != '{')) {
//                printf("Parentheses/braces are NOT nested properly\n");
//                return 0;
//            }
//        }
//    }
//    if (is_empty()) {
//        printf("Parentheses/braces are nested properly\n");
//    } else {
//        printf("Parentheses/braces are NOT nested properly\n");
//    }
//}
