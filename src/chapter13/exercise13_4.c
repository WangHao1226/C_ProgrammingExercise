////4. 编写名为 reverse.c 的程序，用来逆序输出命令行参数。如果输入
////        reverse void and null
////        运行程序，产生的输出应为
////        null and void
//
//#include <stdio.h>
//
//int exercise13_4(int argc, char *argv[]){
//    // 从最后一个参数开始遍历到第二个参数（跳过程序名）
//    for (int i = argc - 1; i >= 1; i--) {
//        printf("%s", argv[i]);
//
//        // 如果不是最后一个输出的参数，后面加空格
//        if (i > 1) {
//            printf(" ");
//        }
//    }
//
//    printf("\n");
//}
