//4. 编写一个程序，要求用户输入一个美元数额，然后显示出增加5%税率后的相应金额。格式如下所示：
//Enter an amount: 100.00
//With tax added: $105.00

#include <stdio.h>

int exercise2_4(){
    printf("Enter an amount:");
    fflush(stdout);
    float amount;
    scanf("%f",&amount);
    printf("With tax added: $%.2f",amount * 1.05);
    return 0;
}