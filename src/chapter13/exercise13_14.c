//14. 修改第 8 章的编程题 16，使其包含如下函数：
//bool are_anagrams(const char *word1, const char *word2);
//如果 word1 和 word2 指向的字符串是变位词，函数返回 true。
//16. 编程测试两个单词是否为变位词（相同字母的重新排列）：
//Enter first word: smartest
//        Enter second word: mattress
//        The words are anagrams.
//Enter first word: dumbest
//        Enter second word: stumble
//        The words are not anagrams.
//用一个循环逐个字符地读取第一个单词，用一个 26 元的整数数组记录每个字母的出现次数。（例
//        如，读取单词 smartest 之后，数组包含的值为 10001000000010000122000000，表明 smartest 包
//        含一个 a、一个 e、一个 m、一个 r、两个 s 和两个 t。）用另一个循环读取第二个单词，这次每读取
//        一个字母就把相应数组元素的值减 1。两个循环都应该忽略不是字母的那些字符，并且不区分大小
//        写。第二个单词读取完毕后，再用一个循环来检查数组元素是否为全 0。如果是全 0，那么这两个单
//        词就是变位词。提示：可以使用<ctype.h>中的函数，如 isalpha 和 tolower。

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define N 100

bool are_anagrams(const char *word1, const char *word2);

int exercise13_14() {
    char word1[N], word2[N];

    printf("Enter first word: ");
    fflush(stdout);
    fgets(word1, sizeof (word1), stdin);

    printf("Enter second word: ");
    fflush(stdout);
    fgets(word2, sizeof (word2), stdin);

    if(are_anagrams(word1, word2)){
        printf("The words are anagrams.");
    } else{
        printf("The words are not anagrams.");
    }

}

bool are_anagrams(const char *word1, const char *word2){
    int len1 = strlen(word1), len2 = strlen(word2);
    bool is_anagrams = 1;

    if(len1 != len2){
        printf("The words are not anagrams.");
    }

    int times[26];
    for(int i = 0 ; i < 26 ; i++){
        times[i] = 0;
    }

    for(int i = 0 ; i < len1 ; i++){
        times[(word1[i] - 'a')]++;
    }

    for(int i = 0 ; i < len2 ; i++){
        times[(word2[i] - 'a')]--;
    }

    for(int i = 0 ; i < 26 ; i ++){
        if(times[i] != 0){
            is_anagrams = 0;
            break;
        }
    }
    return is_anagrams;
}