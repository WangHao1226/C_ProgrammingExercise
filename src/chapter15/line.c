//4. 修改 15.3 节的程序 justify，重新编写 line.c 文件使其存储链表中的当前行。链表中的每个结点存储一
//
//        个单词。用一个指向包含第一个单词的结点的指针变量来替换原有的 line 数组，当行为空时该变量
//        存储空指针。
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "line.h"
#include <stdbool.h>

#define MAX_WORD_LEN 20

struct node{
    char word[MAX_WORD_LEN + 1];
    struct node *next;
};

struct node *line_head = NULL;
struct node *line_tail = NULL;
int line_len = 0;
int num_words = 0;

void clear_line(void)
{
    struct node *current = line_head;
    struct node *next;
    while (current != NULL){
        next = current->next;
        free(current);
        current = next;
    }
    line_head = NULL;
    line_tail = NULL;
    line_len = 0;
    num_words = 0;
}
void add_word(const char *word)
{
    struct node *new_node;

    new_node = malloc(sizeof (struct node));
    if (new_node == NULL) {
        printf("Error: Out of memory\n");
        return;
    }

    strncpy(new_node->word, word, MAX_WORD_LEN);
    new_node->word[MAX_WORD_LEN] = '\0';
    new_node->next = NULL;

    if(num_words > 0){
        line_len++;
    }
    line_len += strlen(word);
    num_words++;

    if(line_head == NULL){
        line_head = new_node;
        line_tail = new_node;
    } else{
        line_tail->next = new_node;
        line_tail = new_node;
    }
}
int space_remaining(void)
{
    return MAX_WORD_LEN - line_len;
}
void write_line(void) {
    int extra_spaces, spaces_to_insert, i, j;
    struct node *current;
    // 静态变量用于跟踪交替方向
    static bool right_justify = true;

    extra_spaces = MAX_WORD_LEN - line_len;

    // 如果没有多余的空白或只有一个单词，直接输出
    if (extra_spaces == 0 || num_words == 1) {
        current = line_head;
        while (current != NULL){
            printf("%s", current->word);
            current = current->next;
            if(current != NULL){
                putchar(' ');
            }
        }
        putchar('\n');
        right_justify = !right_justify;  // 仍然切换方向
        return;
    }

    // 如果需要右对齐（行尾间隔大）
    if (right_justify) {
        current = line_head;
        int words_left = num_words;

        while (current != NULL) {
            printf("%s", current->word);
            words_left--;
            current = current->next;

            // 如果不是最后一个单词，添加空格
            if (current != NULL) {
                spaces_to_insert = extra_spaces / words_left;
                for (j = 0; j <= spaces_to_insert; j++) {
                    putchar(' ');
                }
                extra_spaces -= spaces_to_insert;
            }
        }
    }
        // 如果需要左对齐（行首间隔大）
    else {
        int gaps = num_words - 1;
        int spaces_per_gap = extra_spaces / gaps;
        int remaining_spaces = extra_spaces % gaps;

        current = line_head;
        int word_count = 0;

        while (current != NULL) {
            printf("%s", current->word);
            word_count++;
            current = current->next;

            // 如果不是最后一个单词，添加空格
            if (current != NULL) {
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
            }
        }
    }

    putchar('\n');
    right_justify = !right_justify;  // 切换方向
}
void flush_line(void)
{
    struct node *current = line_head;

    if (line_len > 0) {
        while (current != NULL) {
            printf("%s", current->word);
            current = current->next;
            if (current != NULL) {
                putchar(' ');
            }
        }
        putchar('\n');
    }
}