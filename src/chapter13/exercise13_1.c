//1. 编写程序找出一组单词中“最小”单词和“最大”单词。用户输入单词后，程序根据字典顺序决定
//        排在最前面和最后面的单词。当用户输入 4 个字母的单词时，程序停止读入。假设所有单词都不超
//        过 20 个字母。程序会话如下：
//        Enter word: dog
//        Enter word: zebra
//        Enter word: rabbit
//        Enter word: catfish
//        Enter word: walrus
//        Enter word: cat
//        Enter word: fish
//        Smallest word: cat
//        Largest word: zebra
//        提示：使用两个名为 smallest_word 和 largest_word 的字符串来分别记录所有输入中的“最小”
//单词和“最大”单词。用户每输入一个新单词，都要用 strcmp 函数把它与 smallest_word 进行比
//        较。如果新的单词比 smallest_word“小”，就用 strcpy 函数把新单词保存到 smallest_word
//中。用类似的方式与 larges_word 进行比较。用 strlen 函数来判断用户是否输入了 4 个字母的
//        单词。

#include <stdio.h>
#include <string.h>

#define MAX_LEN 20

int exercise13_1(){
    char smallest_word[MAX_LEN + 1], largest_word[MAX_LEN + 1];
    char word[MAX_LEN + 1];

    printf("Enter word: ");
    fflush(stdout);

    scanf("%s", word);
    strcpy(smallest_word, word);
    strcpy(largest_word, word);

    while (strlen(word) != 4){
        printf("Enter word: ");
        fflush(stdout);

        scanf("%s", word);

        if(strcmp(smallest_word, word) > 0){
            strcpy(smallest_word, word);
        } else if(strcmp(largest_word, word) < 0){
            strcpy(largest_word, word);
        }
    }

    printf("Smallest word: %s\n", smallest_word);
    printf("Largest word: %s\n", largest_word);

}