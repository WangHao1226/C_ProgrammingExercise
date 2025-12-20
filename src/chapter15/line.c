#include <stdio.h>
#include <string.h>
#include "line.h"
#include <stdbool.h>

#define MAX_LINE_LEN 60
char line[MAX_LINE_LEN+1];
int line_len = 0;
int num_words = 0;
void clear_line(void)
{
    line[0] = '\0';
    line_len = 0;
    num_words = 0;
}
void add_word(const char *word)
{
    if (num_words > 0) {
        line[line_len] = ' ';
        line[line_len+1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}
int space_remaining(void)
{
    return MAX_LINE_LEN - line_len;
}
void write_line(void) {
    int extra_spaces, spaces_to_insert, i, j;
    // 静态变量用于跟踪交替方向
    static bool right_justify = true;

    extra_spaces = MAX_LINE_LEN - line_len;

    // 如果没有多余的空白或只有一个单词，直接输出
    if (extra_spaces == 0 || num_words == 1) {
        puts(line);
        right_justify = !right_justify;  // 仍然切换方向
        return;
    }

    // 如果需要右对齐（行尾间隔大）
    if (right_justify) {
        for (i = 0; i < line_len; i++) {
            if (line[i] != ' ')
                putchar(line[i]);
            else {
                spaces_to_insert = extra_spaces / (num_words - 1);
                for (j = 1; j <= spaces_to_insert + 1; j++)
                    putchar(' ');
                extra_spaces -= spaces_to_insert;
                num_words--;
            }
        }
    }
        // 如果需要左对齐（行首间隔大）
    else {
        // 复制 line 到一个数组中以便处理
        char line_copy[MAX_LINE_LEN + 1];
        strcpy(line_copy, line);

        // 计算每个单词间隔应该插入的空格数
        int gaps = num_words - 1;
        int spaces_per_gap = extra_spaces / gaps;
        int remaining_spaces = extra_spaces % gaps;

        // 遍历行，输出单词和空格
        i = 0;
        int word_count = 0;

        while (line_copy[i] != '\0' && word_count < num_words) {
            // 输出一个单词
            while (line_copy[i] != ' ' && line_copy[i] != '\0') {
                putchar(line_copy[i]);
                i++;
            }

            word_count++;

            // 如果不是最后一个单词，输出空格
            if (word_count < num_words) {
                // 计算这个间隔的空格数
                int spaces = 1 + spaces_per_gap;  // 基础空格

                // 在行首分配额外的空格
                if (remaining_spaces > 0) {
                    spaces++;
                    remaining_spaces--;
                }

                // 输出空格
                for (j = 0; j < spaces; j++) {
                    putchar(' ');
                }

                // 跳过原行中的空格
                while (line_copy[i] == ' ') {
                    i++;
                }
            }
        }
    }

    putchar('\n');
    right_justify = !right_justify;  // 切换方向
}
void flush_line(void)
{
    if (line_len > 0)
        puts(line);
}