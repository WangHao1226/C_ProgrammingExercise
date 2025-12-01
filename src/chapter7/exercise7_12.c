//12. 编写程序对表达式求值：
//Enter an expression: 1+2.5*3
//Value of expression: 10.5
//表达式中的操作数是浮点数，运算符是+、-、*和/。表达式从左向右求值（所有运算符的优先级都
//        一样）。

#include <stdio.h>
#include <ctype.h>
int exercise7_12() {
    printf("Enter an expression: ");
    fflush(stdout);

    char op;
    float value, next;
    scanf("%f", &value);

    while (1){
        op = getchar();
        if(op == '\n'){
            break;
        }
        if(op == ' '){
            continue;
        }

        scanf("%f", &next);
        switch (op) {
            case '+':
                value += next;
                break;
            case '-':
                value -= next;
                break;
            case '*':
                value *= next;
                break;
            case '/':
                value /= next;
                break;
            default:
                printf("Error:Invalid operator %c", op);
                fflush(stdout);
                return 1;
        }
    }
    printf("Value of expression: %.2f", value);

}