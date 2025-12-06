//4. 修改第 8 章的编程题 16，使其包含下列函数：
//void read_word(int counts[26]);
//bool equal_array(int counts1[26], int counts2[26]);
//main 函数将调用 read_word 两次，每次用于读取用户输入的一个单词。读取单词时，read_word 用
//单词中的字母更新 counts 数组，详见原题的描述。（main 将声明两个数组，每个数组用于一个单
//        词。这些数组用于跟踪单词中每个字母出现的次数。）接下来，main 函数调用 equal_array 函数，
//以前面提到的两个数组作为参数。如果两个数组中的元素相同（表明这两个单词是变位词），
//equal_array 返回 true，否则返回 false。
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>  // 用于tolower函数

#define ALPHABET_SIZE 26

// 读取单词并统计字母出现次数
void read_word(int counts[ALPHABET_SIZE]) {
    char ch;

    // 将计数器数组清零
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        counts[i] = 0;
    }

    // 读取单词直到遇到换行符
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // 只处理字母字符
        if (isalpha(ch)) {
            // 转换为小写并统计
            ch = tolower(ch);
            counts[ch - 'a']++;
        }
    }
}

// 比较两个计数数组是否相同
bool equal_array(int counts1[ALPHABET_SIZE], int counts2[ALPHABET_SIZE]) {
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (counts1[i] != counts2[i]) {
            return false;  // 发现不同，不是变位词
        }
    }
    return true;  // 所有字母计数都相同，是变位词
}

int exercise9_4() {
    int counts1[ALPHABET_SIZE];
    int counts2[ALPHABET_SIZE];

    printf("Enter first word: ");
    fflush(stdout);
    read_word(counts1);

    printf("Enter second word: ");
    fflush(stdout);
    read_word(counts2);

    if (equal_array(counts1, counts2)) {
        printf("The words are anagrams.\n");
    } else {
        printf("The words are not anagrams.\n");
    }

}