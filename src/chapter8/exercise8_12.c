//12. 修改第 7 章的编程题 5，用数组存储字母的面值。数组有 26 个元素，对应字母表中的 26 个字母。例
//        如，数组元素 0 存储 1（因为字母 A 的面值为 1），数组元素 1 存储 3（因为字母 B 的面值为 3），等
//        等。每读取输入单词中的一个字母，程序都会利用该数组确定字符的拼字值。使用数组初始化器来
//        建立该数组。

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LENGTH 100

int exercise8_12() {
    // 初始化字母面值数组，对应A-Z
    int letter_values[26] = {
            1,  // A
            3,  // B
            3,  // C
            2,  // D
            1,  // E
            4,  // F
            2,  // G
            4,  // H
            1,  // I
            8,  // J
            5,  // K
            1,  // L
            3,  // M
            1,  // N
            1,  // O
            3,  // P
            10, // Q
            1,  // R
            1,  // S
            1,  // T
            1,  // U
            4,  // V
            4,  // W
            8,  // X
            4,  // Y
            10  // Z
    };

    char word[MAX_LENGTH];
    int total_score = 0;

    printf("Enter a word: ");
    scanf("%s", word);  // 读取整个单词

    // 计算单词的总分
    for (int i = 0; word[i] != '\0'; i++) {
        char ch = toupper(word[i]);  // 转换为大写

        if (ch >= 'A' && ch <= 'Z') {
            // 使用数组查询字母的面值
            total_score += letter_values[ch - 'A'];
        }
    }

    printf("Scrabble value: %d\n", total_score);

}