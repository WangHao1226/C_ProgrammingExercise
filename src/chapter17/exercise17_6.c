//6. 修改编程题 5，用 qsort 对指针数组排序。

/* Prints a one-month reminder list (dynamic string version) */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LEN 20
#define MAX_WORDS 1000

int read_line(char str[], int n);

// qsort 比较函数
int compare_strings(const void *a, const void *b)
{
    // 注意：参数是指向指针的指针
    const char **str1 = (const char **)a;
    const char **str2 = (const char **)b;
    return strcmp(*str1, *str2);
}

int exercise17_6(void){
    char temp_word[MAX_WORD_LEN + 1];
    char *words[MAX_WORDS];
    int num_words = 0;
    int i;

    for(;;){
        printf("Enter word: ");
        fflush(stdout);
        int chars_read = read_line(temp_word, MAX_WORD_LEN);

        if(chars_read == 0){
            break;
        }

        words[num_words] = malloc(strlen(temp_word) + 1);
        if(words[num_words] == NULL){
            printf("Memory allocation failed!\n");

            for(i = 0; i < num_words; i++){
                free(words[i]);
            }

            return 1;
        }

        strcpy(words[num_words], temp_word);
        num_words++;
    }

    if(num_words == 0){
        printf("No words entered.\n");
        return 0;
    }

    // 使用 qsort 排序
    qsort(words, num_words, sizeof(char *), compare_strings);

    // 显示结果
    printf("In sorted order:");
    for (i = 0; i < num_words; i++) {
        printf(" %s", words[i]);
    }
    printf("\n");

    // 释放内存
    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }

    return 0;
}
int read_line(char str[], int n)
{
    int ch, i = 0;
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0';
    return i;
}