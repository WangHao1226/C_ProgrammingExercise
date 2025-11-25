//4. 编写一个程序，读入用户输入的整数并按八进制（基数为 8）显示出来：
//Enter a number between 0 and 32767: 1953
//In octal, your number is: 03641
//输出应为 5 位数，即便不需要这么多数位也要如此。提示：要把一个数转换成八进制，首先将其除
//        以 8，所得的余数是八进制数的最后一位（本例中为 1）；然后把原始的数除以 8，对除法结果重复上
//        述过程，得到倒数第二位。（如第 7 章所示，printf 可以显示八进制的数，所以这个程序实际上有
//        更简单的写法。）

#include <stdio.h>

void exercise4_4(void) {
    printf("Enter a number between 0 and 32767: ");
    fflush(stdout);
    int number;
    scanf("%d", &number);

    int last_digit;
    int eight_number[5];
    for(int i = 0; i < 5; i ++){
        last_digit = number;
        last_digit %= 8;
        number /= 8;
        eight_number[i] = last_digit;
    }

    for(int i = 4; i >= 0; i --){
        printf("%d", eight_number[i]);
    }
}