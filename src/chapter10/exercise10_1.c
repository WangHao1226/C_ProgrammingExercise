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
//#include <stdio.h>
//#include <stdbool.h>
//#include <stdlib.h>
//
//#define STACK_SIZE 100
//
//int contents[STACK_SIZE];
//int top = 0;
//
//void make_empty(void){
//    top = 0;
//}
//
//bool is_empty(void){
//    return top == 0;
//}
//
//bool is_full(void){
//    return top == STACK_SIZE;
//}
//
//int stack_overflow(){
//    printf("Stack overflow.\n");
//    exit(EXIT_FAILURE);
//}
//
//int stack_underflow(){
//    printf("Stack underflow.\n");
//    exit(EXIT_FAILURE);
//}
//
//
//void push(char ch){
//    if (is_full())
//        stack_overflow();
//    else
//        contents[top++] = ch;
//}
//
//int pop(void){
//    if (is_empty())
//        stack_underflow();
//    else
//        return contents [--top];
//}
//
//
//
//int exercise10_1(){
//    char ch;
//
//    printf("Enter parentheses and/or braces: ");
//    fflush(stdout);
//
//    // 读取字符直到换行符
//    while ((ch = getchar()) != '\n') {
//        // 如果是左括号，压入栈中
//        if (ch == '(' || ch == '{') {
//            push(ch);
//        }
//            // 如果是右括号，检查是否匹配
//        else if (ch == ')' || ch == '}') {
//            if (is_empty()) {
//                // 栈为空但遇到右括号，不匹配
//                printf("Parentheses/braces are NOT nested properly\n");
//                return 0;
//            }
//
//            char left = pop();  // 弹出栈顶的左括号
//
//            // 检查是否匹配
//            if ((ch == ')' && left != '(') || (ch == '}' && left != '{')) {
//                printf("Parentheses/braces are NOT nested properly\n");
//                return 0;
//            }
//        }
//        // 如果输入其他字符，可以忽略或给出提示
//        // 根据题目要求，我们只检查括号和花括号，所以其他字符可以忽略
//    }
//
//    // 所有字符处理完毕，检查栈是否为空
//    if (is_empty()) {
//        printf("Parentheses/braces are nested properly\n");
//    } else {
//        printf("Parentheses/braces are NOT nested properly\n");
//    }
//
//}
