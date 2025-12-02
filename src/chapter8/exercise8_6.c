//6. 有一个名叫 B1FF 的人，是典型的网络新手，他有一种独特的编写消息的方式。下面是一条常见的
//        B1FF 公告：
//H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
//编写一个“B1FF 过滤器”，它可以读取用户输入的消息并把此消息翻译成 B1FF 的表达风格：
//Enter message: Hey dude, C is rilly cool
//        In B1FF-speak: H3Y DUD3, C 15 R1LLY C00L!!!!!!!!!!
//程序需要把消息转换成大写字母，用数字代替特定的字母（A→4、B→8、E→3、I→1、O→0、S→
//5），然后添加 10 个左右的感叹号。提示：把原始消息存储在一个字符数组中，然后从数组头开始逐
//        个翻译并显示字符。

#include <stdio.h>
#include <ctype.h>

#define N 100

int exercise8_6() {
    printf("Enter message: ");
    fflush(stdout);
    char arr[N] = {};
    int len = 0;
    for (int i = 0;i < N ; i ++) {
        arr[i] = getchar();
        if(arr[i] == '\n'){
            break;
        }
        len ++;
    }
    for(int i = 0; i < len; i++){
        arr[i] = toupper(arr[i]);
        if(arr[i] == 'A'){
            arr[i] = '4';
        }
        if(arr[i] == 'B'){
            arr[i] = '8';
        }
        if(arr[i] == 'E'){
            arr[i] = '3';
        }
        if(arr[i] == 'I'){
            arr[i] = '1';
        }
        if(arr[i] == 'O'){
            arr[i] = '0';
        }
        if(arr[i] == 'S') {
            arr[i] = '5';
        }
        printf("%c", arr[i]);
    }
    printf("!!!!!!!!!!");

}