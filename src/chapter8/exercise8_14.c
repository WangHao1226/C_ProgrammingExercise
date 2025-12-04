//14. 编写程序颠倒句子中单词的顺序：
//Enter a sentence: you can cage a swallow can't you?
//Reversal of sentence: you can't swallow a cage can you?
//提示：用循环逐个读取字符，然后将它们存储在一个一维字符数组中。当遇到句号、问号或者感叹
//        号（称为“终止字符”）时，终止循环并把终止字符存储在一个 char 类型变量中。然后再用一个循
//        环反向搜索数组，找到最后一个单词的起始位置。显示最后一个单词，然后反向搜索倒数第二个单
//        词。重复这一过程，直至到达数组的起始位置。最后显示出终止字符。

#include <stdio.h>

#define MAX_LENGTH 100

int exercise8_14() {
    char sentence[MAX_LENGTH];
    char terminating_char;
    int length = 0;

    printf("Enter a sentence: ");
    fflush(stdout);

    // 读取字符直到遇到终止字符
    while (1) {
        char ch = getchar();

        if (ch == '.' || ch == '?' || ch == '!') {
            terminating_char = ch;
            break;
        } else if (length < MAX_LENGTH - 1) {
            sentence[length++] = ch;
        }
    }

    printf("Reversal of sentence: ");

    // 从后向前搜索单词
    int end = length;  // 当前单词的结束位置（数组末尾或最后一个字符）

    for (int i = length - 1; i >= 0; i--) {
        // 如果遇到空格或者到达开头，说明找到了一个单词的开始
        if (i == 0 || sentence[i - 1] == ' ') {
            // 打印单词
            for (int j = i; j < end; j++) {
                putchar(sentence[j]);
            }

            // 如果不是最后一个单词（不是第一个单词），打印空格
            if (i > 0) {
                putchar(' ');
            }

            // 更新end为下一个单词的结束位置
            if (i > 0) {
                // 跳过空格
                i--;  // 移动到空格位置
                while (i > 0 && sentence[i - 1] == ' ') {
                    i--;  // 跳过多个连续空格
                }
                end = i;
            }
        }
    }

    // 打印终止字符
    printf("%c\n", terminating_char);

}