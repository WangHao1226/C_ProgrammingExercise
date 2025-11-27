//11. 编写一个程序，要求用户输入一个两位数，然后显示该数的英文单词：
//Enter a two-digit number: 45
//You entered the number forty-five.
//提示：把数分解为两个数字。用一个 switch 语句显示第一位数字对应的单词（“twenty”“thirty”等），
//用第二个 switch 语句显示第二位数字对应的单词。不要忘记 11～19 需要特殊处理。

#include <stdio.h>

int exercise5_11() {
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

    // 处理11-19的特殊情况
    if (number >= 11 && number <= 19) {
        switch (number) {
            case 11: printf("eleven"); break;
            case 12: printf("twelve"); break;
            case 13: printf("thirteen"); break;
            case 14: printf("fourteen"); break;
            case 15: printf("fifteen"); break;
            case 16: printf("sixteen"); break;
            case 17: printf("seventeen"); break;
            case 18: printf("eighteen"); break;
            case 19: printf("nineteen"); break;
        }
    } else {
        // 处理十位数
        switch (tens) {
            case 1: printf("ten"); break;
            case 2: printf("twenty"); break;
            case 3: printf("thirty"); break;
            case 4: printf("forty"); break;
            case 5: printf("fifty"); break;
            case 6: printf("sixty"); break;
            case 7: printf("seventy"); break;
            case 8: printf("eighty"); break;
            case 9: printf("ninety"); break;
        }

        // 处理个位数（如果不是10的倍数）
        if (units != 0 && tens != 1) {
            printf("-");
            switch (units) {
                case 1: printf("one"); break;
                case 2: printf("two"); break;
                case 3: printf("three"); break;
                case 4: printf("four"); break;
                case 5: printf("five"); break;
                case 6: printf("six"); break;
                case 7: printf("seven"); break;
                case 8: printf("eight"); break;
                case 9: printf("nine"); break;
            }
        }
    }

    printf(".\n");
}