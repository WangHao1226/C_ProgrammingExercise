//1. 编写程序，要求用户输入一串整数（把这串整数存储在数组中），然后通过调用 selection_sort
//函数来排序这些整数。在给定 n 个元素的数组后，selection_sort 函数必须做下列工作：
//(a) 搜索数组找出最大的元素，然后把它移到数组的最后；
//(b) 递归地调用函数本身来对前 n-1 个数组元素进行排序。

#include <stdio.h>

#define N 100

void selection_sort(int arr[], int n){
    if(n <= 1){
        return ;
    }

    int max_index = 0;
    for(int i = 0 ; i < n ; i++){
        if(arr[i] > arr[max_index]){
            max_index = i;
        }
    }
    if(max_index != n - 1){
        int temp = arr[max_index];
        arr[max_index] = arr[n - 1];
        arr[n - 1] = temp;
    }
    selection_sort(arr, n - 1);
}

int exercise9_1() {
    int arr[N], len = 0;
    char ch;

    printf("Enter a string of integers (max %d, end with non-digit or EOF): ", N);
    fflush(stdout);

    // 读取整数，直到数组满或遇到非数字输入
    while (len < N && scanf("%d", &arr[len]) == 1) {
        len++;
    }

    // 清除缓冲区中剩余的字符（包括换行符）
    while ((ch = getchar()) != '\n' && ch != EOF);

    // 如果没有输入任何整数
    if (len == 0) {
        printf("No integers entered.\n");
        fflush(stdout);
        return 0;
    }

    printf("Original array: ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // 调用选择排序
    selection_sort(arr, len);

    printf("Sorted array (ascending order): ");
    for (int i = 0; i < len; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");


}