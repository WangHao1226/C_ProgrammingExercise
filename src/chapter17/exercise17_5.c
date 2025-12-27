////5. 编写程序对用户输入的一系列单词排序：
////Enter word: foo
////        Enter word: bar
////        Enter word: baz
////        Enter word: quux
////        Enter word:
////In sorted order: bar baz foo quux
////假设每个单词不超过 20 个字符。当用户输入空单词（即敲击回车键而没有输入任何单词）时停止读
////        取。把每个单词存储在一个动态分配的字符串中，像 remind2.c 程序（17.2 节）那样用一个指针数组
////        来跟踪这些字符串。读完所有的单词后对数组排序（可以使用任何排序算法），然后用一个循环按存
////        储顺序显示这些单词。提示：像 remind2.c 那样，使用 read_line 函数读取每个单词。
//
///* Prints a one-month reminder list (dynamic string version) */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//#define MAX_WORD_LEN 20
//#define MAX_WORDS 1000
//
//int read_line(char str[], int n);
//
//// qsort 比较函数
//int compare_strings(const void *a, const void *b)
//{
//    // 注意：参数是指向指针的指针
//    const char **str1 = (const char **)a;
//    const char **str2 = (const char **)b;
//    return strcmp(*str1, *str2);
//}
//
//int exercise17_5(void){
//    char temp_word[MAX_WORD_LEN + 1];
//    char *words[MAX_WORDS];
//    int num_words = 0;
//    int i;
//
//    for(;;){
//        printf("Enter word: ");
//        fflush(stdout);
//        int chars_read = read_line(temp_word, MAX_WORD_LEN);
//
//        if(chars_read == 0){
//            break;
//        }
//
//        words[num_words] = malloc(strlen(temp_word) + 1);
//        if(words[num_words] == NULL){
//            printf("Memory allocation failed!\n");
//
//            for(i = 0; i < num_words; i++){
//                free(words[i]);
//            }
//
//            return 1;
//        }
//
//        strcpy(words[num_words], temp_word);
//        num_words++;
//    }
//
//    if(num_words == 0){
//        printf("No words entered.\n");
//        return 0;
//    }
//
//    // 使用 qsort 排序
//    qsort(words, num_words, sizeof(char *), compare_strings);
//
//    // 显示结果
//    printf("In sorted order:");
//    for (i = 0; i < num_words; i++) {
//        printf(" %s", words[i]);
//    }
//    printf("\n");
//
//    // 释放内存
//    for (i = 0; i < num_words; i++) {
//        free(words[i]);
//    }
//
//    return 0;
//}
//int read_line(char str[], int n)
//{
//    int ch, i = 0;
//    while ((ch = getchar()) != '\n')
//        if (i < n)
//            str[i++] = ch;
//    str[i] = '\0';
//    return i;
//}