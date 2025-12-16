//9. 修改第 7 章的编程题 10，使其包含如下函数：
//int compute_vowel_count(const char *sentence);
//函数返回 sentence 所指向的字符串中元音字母的个数。
//10. 编写程序统计句子中元音字母（a、e、i、o、u）的个数：
//
//Enter a sentence: And that's the way it is.
//Your sentence contains 6 vowels.

#include <stdio.h>
#include <ctype.h>

#define MAX_SENTENCE_LEN 100

int compute_vowel_count(const char *sentence);

int exercise13_9() {
    printf("Enter a sentence: ");
    fflush(stdout);

    char sentence[MAX_SENTENCE_LEN + 1];

    fgets(sentence, sizeof(sentence), stdin);

    int number = compute_vowel_count(sentence);
    printf("Your sentence contains %d vowels.", number);

}

int compute_vowel_count(const char *sentence){
    char ch;
    int number = 0;
    for(int i = 0; sentence[i] != '\n'; i++){
        ch = toupper(sentence[i]);
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
            number++;
        }
    }
    return number;
}