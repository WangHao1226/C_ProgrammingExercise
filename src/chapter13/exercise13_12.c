//12. 修改第 8 章的编程题 14，读取句子时把单词存储在一个二维的 char 类型数组中，每行存储一个单
//        词。假定句子中的单词数不超过30，且每个单词的长度都不超过20个字符。注意，要在每个单词的
//        后面存储一个空字符，使其可以作为字符串处理。
//14. 编写程序颠倒句子中单词的顺序：
//Enter a sentence: you can cage a swallow can't you?
//Reversal of sentence: you can't swallow a cage can you?
//提示：用循环逐个读取字符，然后将它们存储在一个一维字符数组中。当遇到句号、问号或者感叹
//        号（称为“终止字符”）时，终止循环并把终止字符存储在一个 char 类型变量中。然后再用一个循
//        环反向搜索数组，找到最后一个单词的起始位置。显示最后一个单词，然后反向搜索倒数第二个单
//        词。重复这一过程，直至到达数组的起始位置。最后显示出终止字符。

#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_NUM 30
#define MAX_WORD_LEN 20

int exercise13_12() {
    char words[MAX_WORD_NUM + 1][MAX_WORD_LEN + 1];
    int word_count = 0;
    char terminating_char;

    printf("Enter a sentence: ");
    fflush(stdout);

    char ch;
    int word_index = 0;
    int char_index = 0;

    while ((ch = getchar()) == ' ');

    while (ch != '\n' && word_index < MAX_WORD_NUM){
        if(ch == '.' || ch == '!' || ch == '?'){
            terminating_char = ch;
            break;
        }

        if(isspace(ch)){
            if(char_index > 0){
                words[word_index][char_index] = '\0';
                word_index++;
                char_index = 0;
            }
        } else{
            if(char_index < MAX_WORD_LEN){
                words[word_index][char_index] = ch;
                char_index++;
            }
        }

        ch = getchar();
    }
    // 处理最后一个单词（如果有的话）
    if (char_index > 0 && word_index < MAX_WORD_NUM) {
        words[word_index][char_index] = '\0';
        word_index++;
    }

    word_count = word_index;

    // 打印反向句子
    printf("Reversal of sentence: ");

    // 从最后一个单词开始向前打印
    for (int i = word_count - 1; i >= 0; i--) {
        printf("%s", words[i]);
        if (i > 0) {
            printf(" ");
        }
    }

    // 打印终止字符
    if (terminating_char != 0) {
        printf("%c", terminating_char);
    }

    printf("\n");

}