//8. 修改第 7 章的编程题 5，使其包含如下函数：
//int compute_scrabble_value(const char *word);
//函数返回 word 所指向的字符串的拼字值。
//5. 在十字拼字游戏中，玩家利用小卡片组成英文单词，每张卡片包含一个英文字母和面值。面值根据
//        字母稀缺程度的不同而不同。（面值与字母的对应关系如下：1——AEILNORSTU；2——DG；3——
//BCMP；4——FHVWY；5——K；8——JX；10——QZ。）编写程序，通过对单词中字母的面值求和
//        来计算单词的值：
//Enter a word: pitfall
//        Scrabble value: 12
//编写的程序应该允许单词中混合出现大小写字母。提示：使用 toupper 库函数。

#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LEN 100
int compute_scrabble_value(const char *word);

int exercise13_8() {
    char word[MAX_WORD_LEN + 1];

    printf("Enter a word: ");
    fflush(stdout);

    scanf("%s", word);
    printf("Scrabble value = %d\n", compute_scrabble_value(word));
}

int compute_scrabble_value(const char *word){
    char ch;
    int value = 0;
    for(int i = 0; word[i] != '\0'; i++){
        ch = toupper(word[i]);

        if (ch >= 'A' && ch <= 'Z') {
            if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'L' || ch == 'N' || ch == 'O' || ch == 'R' || ch == 'S'
                || ch == 'T' || ch == 'U')
                value += 1;
            else if (ch == 'D' || ch == 'G')
                value += 2;
            else if (ch == 'B' || ch == 'C' || ch == 'M' || ch == 'P')
                value += 3;
            else if (ch == 'F' || ch == 'H' || ch == 'V' || ch == 'W' || ch == 'Y')
                value += 4;
            else if (ch == 'K')
                value += 5;
            else if (ch == 'J' || ch == 'X')
                value += 8;
            else if (ch == 'Q' || ch == 'Z')
                value += 10;
        }
    }
    return value;
}
