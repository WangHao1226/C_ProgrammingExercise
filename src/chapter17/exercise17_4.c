//4. 修改 15.3 节的程序 justify，重新编写 line.c 文件使其存储链表中的当前行。链表中的每个结点存储一
//
//        个单词。用一个指向包含第一个单词的结点的指针变量来替换原有的 line 数组，当行为空时该变量
//        存储空指针。

/* Formats a file of text */
#include <string.h>
#include "line.h"
#include "word.h"
#define MAX_WORD_LEN 20
int exercise17_4(void)
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
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        add_word(word);
    }
}