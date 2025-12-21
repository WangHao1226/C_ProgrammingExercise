////15. 修改第 10 章的编程题 6，使其包含如下函数：
////int evaluate_RPN_expression(const char *expression);
////函数返回 expression 指向的 RPN 表达式的值。
////6. 有些计算器（尤其是惠普的计算器）使用逆波兰表示法（Reverse Polish Notation，RPN）来书写数学
////        表达式。在这一表示法中，运算符放置在操作数的后面而不是放在操作数中间。例如，在逆波兰表
////        示法中 1+2 将表示为 1 2 +，而 1+2*3 将表示为 1 2 3 * +。逆波兰表达式可以很方便地用栈求值。算
////        法从左向右读取运算符和操作数，并执行下列步骤。
////(1) 当遇到操作数时，将其压入栈中。
////(2) 当遇到运算符时，从栈中弹出它的操作数，执行运算并把结果压入栈中。
////编写程序对逆波兰表达式求值。操作数都是个位的整数，运算符为+、-、*、/和=。遇到运算符=
////时，将显示栈顶项，随后清空栈并提示用户计算新的表达式。这一过程持续进行，直到用户输入一
////        个既不是运算符也不是操作数的字符为止：
////Enter an RPN expression: 1 2 3 * + =
////Value of expression: 7
////Enter an RPN expression: 5 8 * 4 9 - / =
////Value of expression: -8
////Enter an RPN expression: q
////        如果栈出现上溢，程序将显示消息 Expression is too complex 并终止。如果栈出现下溢（例如遇
////        到表达式 1 2 + +），程序将显示消息 Not enough operands in expression 并终止。提示：把 10.2
////节的栈代码整合到你的程序中。使用 scanf(" %c", &ch)读取运算符和操作数。
//
//
//#include <stdio.h>
//#include <stdbool.h> /* C99 only */
//#include <stdlib.h>
//#include <string.h>
//#include <ctype.h>
//
//#define STACK_SIZE 100
//
//int evaluate_RPN_expression(const char *expression);
//
///* external variables */
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
//void stack_overflow(){
//    printf("Expression is too complex\n");
//    exit(EXIT_FAILURE);
//}
//
//void stack_underflow(){
//    printf("Not enough operands in expression\n");
//    exit(EXIT_FAILURE);
//}
//
//void push(int i){
//    if (is_full())
//        stack_overflow();
//    else
//        contents[top++] = i;
//}
//
//int pop(void){
//    if (is_empty())
//        stack_underflow();
//    else
//        return contents [--top];
//}
//
//int exercise13_15(void){
//    char expression[STACK_SIZE];
//
//    while (1) {
//        printf("Enter an RPN expression: ");
//        fflush(stdout);
//
//        // 清空表达式数组
//        memset(expression, 0, sizeof(expression));
//
//        // 读取表达式
//        if (fgets(expression, sizeof(expression), stdin) == NULL) {
//            break;  // 读取失败时退出
//        }
//
//        // 检查是否要退出（输入'q'）
//        if (strlen(expression) > 0 && expression[0] == 'q') {
//            break;
//        }
//
//        // 计算并显示结果
//        printf("Value of expression: %d\n", evaluate_RPN_expression(expression));
//    }
//
//}
//
//int evaluate_RPN_expression(const char *expression){
//
//    for(int i = 0; i < strlen(expression); i++){
//        char ch = expression[i];
//
//        if (isspace(ch)) {
//            continue;
//        }
//
//        if(ch >= '0' && ch <= '9'){
//            push(ch - '0');
//        } else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
//            int right_operand = pop();
//            int left_operand = pop();
//            int result;
//
//            switch (ch) {
//                case '+':
//                    result = left_operand + right_operand;
//                    break;
//                case '-':
//                    result = left_operand - right_operand;
//                    break;
//                case '*':
//                    result = left_operand * right_operand;
//                    break;
//                case '/':
//                    if(right_operand == 0){
//                        printf("Error: Division by zero\n");
//                        exit(EXIT_FAILURE);
//                    }
//                    result = left_operand / right_operand;
//                    break;
//                default:
//                    break;
//            }
//            push(result);
//        } else if(ch == '='){
//            int result = pop();
//
//            if(!is_empty()){
//                printf("Error: Extra operands in expression\n");
//                make_empty();
//                exit(EXIT_FAILURE);
//            } else{
//                return result;
//            }
//            break;
//        } else{
//            make_empty();
//            return 0;
//        }
//    }
//    if (!is_empty()) {
//        printf("Error: Incomplete expression (missing '=')\n");
//        make_empty();
//        exit(EXIT_FAILURE);
//    }
//
//}