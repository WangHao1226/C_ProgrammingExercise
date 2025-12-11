//5. 修改第 8 章的编程题 14，用指针而不是整数来跟踪包含该语句的数组的当前位置。
//14. 编写程序颠倒句子中单词的顺序：
//Enter a sentence: you can cage a swallow can't you?
//Reversal of sentence: you can't swallow a cage can you?
//提示：用循环逐个读取字符，然后将它们存储在一个一维字符数组中。当遇到句号、问号或者感叹
//        号（称为“终止字符”）时，终止循环并把终止字符存储在一个 char 类型变量中。然后再用一个循
//        环反向搜索数组，找到最后一个单词的起始位置。显示最后一个单词，然后反向搜索倒数第二个单
//        词。重复这一过程，直至到达数组的起始位置。最后显示出终止字符。

#include <stdio.h>

#define MAX_LENGTH 100

int exercise12_5() {
    char sentence[MAX_LENGTH];
    char terminating_char;
    char *p = sentence;

    printf("Enter a sentence: ");
    fflush(stdout);

    // 读取字符直到遇到终止字符
    char ch;
    while ((ch = getchar()) != '.' && ch != '?' && ch != '!' && p < sentence + MAX_LENGTH - 1) {
        *p++ = ch;
    }
    // 存储终止字符
    terminating_char = ch;

    printf("Reversal of sentence: ");

    // 从后向前搜索单词
    char *word_end = p;
    char *current = p - 1;

    while (current >= sentence && *current == ' ') {
        current--;
    }
    while (current >= sentence){
        char *word_start = current;
        while (word_start > sentence && *(word_start - 1) != ' '){
            word_start--;
        }

        char *ptr;
        for(ptr = word_start; ptr <= word_end; ptr++){
            if(*ptr != ' '){
                putchar(*ptr);
            }
        }

        if(word_start >sentence){
            putchar(' ');
        }

        current = word_start - 1;

        while (current >= sentence && *current == ' '){
            current--;
        }
        word_end = current;
    }

    // 打印终止字符
    printf("%c\n", terminating_char);

}