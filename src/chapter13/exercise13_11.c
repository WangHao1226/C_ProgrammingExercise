//11. 修改第 7 章的编程题 13，使其包含如下函数：
//double compute_average_word_length(const char *sentence);
//函数返回 sentence 所指向的字符串中单词的平均长度。
//13. 编写程序计算句子的平均词长：
//Enter a sentence: It was deja vu all over again.
//Average word length: 3.4
//简单起见，程序中把标点符号看作其前面单词的一部分。平均词长显示一个小数位。

#include <stdio.h>
#include <ctype.h>

#define MAX_SENTENCE_LEN 100

double compute_average_word_length(const char *sentence);

int exercise13_11() {
    printf("Enter a sentence: ");
    fflush(stdout);

    char sentence[MAX_SENTENCE_LEN + 1];
    fgets(sentence, sizeof (sentence), stdin);

    double average_length = compute_average_word_length(sentence);
    printf("Average word length: %.1f\n", average_length);
}

double compute_average_word_length(const char *sentence){
    char ch;
    int total_chars = 0;  // 所有单词的总字符数
    int word_count = 0;   // 单词数量
    int in_word = 0;      // 标记当前是否在单词中
    // 读取句子直到换行符
    int i = 0;
    while ((ch = sentence[i]) != '\n') {
        i++;
        if (ch == ' ') {
            // 遇到空格，表示一个单词结束
            if (in_word) {
                word_count++;
                in_word = 0;
            }
        } else {
            // 非空格字符，统计字符数
            total_chars++;
            if (!in_word) {
                in_word = 1;
            }
        }
    }

    // 如果最后一个字符不是空格，需要统计最后一个单词
    if (in_word) {
        word_count++;
    }

    // 计算平均词长
    if (word_count > 0) {
        float average_length = (float)total_chars / word_count;
        return average_length;
    } else {
        printf("No words found.\n");
    }
}