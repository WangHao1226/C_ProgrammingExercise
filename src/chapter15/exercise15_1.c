//1. 15.3 节的 justify 程序通过在单词间插入额外的空格来调整行。当前编写的函数 writen_line 的工作
//        方法是，与开始处的单词间隔相比，靠近行末尾单词的间隔略微宽一些。（例如，靠近末尾的单词彼
//        此之间可能有 3 个空格，而靠近开始的单词彼此之间可能只有 2 个空格。）请修改函数 write_line
//来改进此程序，要求函数能够使较大的间隔交替出现在行的末尾和行的开头。
/* Formats a file of text */
#include <string.h>
#include "line.h"
#include "word.h"
#define MAX_WORD_LEN 20
int exercise15_1(void)
{
    char word[MAX_WORD_LEN+2];
    int word_len;
    clear_line();
    for (;;) {
        read_word(word, MAX_WORD_LEN+1);
        word_len = strlen(word);

        if (word_len == 0) {
            flush_line();
            return 0;
        }

        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }

        add_word(word);
    }
}