//7. 修改第 5章的编程题 11，用字符串指针数组取代 switch 语句。例如，现在不再用 switch 语句来显示
//        第一位数字对应的单词，而把该数字用作下标，从包含"twenty"、"thirty"等字符串的数组中搜索。
//11. 编写一个程序，要求用户输入一个两位数，然后显示该数的英文单词：
//Enter a two-digit number: 45
//You entered the number forty-five.
//提示：把数分解为两个数字。用一个 switch 语句显示第一位数字对应的单词（“twenty”“thirty”等），
//用第二个 switch 语句显示第二位数字对应的单词。不要忘记 11～19 需要特殊处理。

#include <stdio.h>

int exercise13_7() {
    int number, tens, units;

    printf("Enter a two-digit number: ");
    fflush(stdout);
    scanf("%d", &number);

    // 验证输入是否为两位数
    if (number < 10 || number > 99) {
        printf("Error: Please enter a two-digit number (10-99)\n");
        return 1;
    }

    tens = number / 10;  // 十位数
    units = number % 10; // 个位数

    printf("You entered the number ");

    char *tens_digit[] = {"twenty","thirty","forty","fifty",
                          "sixty","seventy","eighty","ninety"};
    char *special_tens_digit[] = {"ten","eleven","twelve","thirteen","fourteen","fifteen",
                                  "sixteen","seventeen","eighteen","nineteen"};
    char *units_digit[] = {"one","two","three","four","five",
                           "six","seven","eight","nine"};
    if(tens == 1){
        printf("%s",special_tens_digit[units]);
    } else{
        printf("%s-%s",tens_digit[tens - 2], units_digit[units - 1]);
    }

    printf(".\n");
}