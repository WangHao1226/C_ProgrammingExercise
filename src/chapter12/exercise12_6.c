////6. 修改 9.6 节的 qsort.c 程序，使得 low、high 和 middle 是指向数组元素的指针而不是整数。split 函
////数应返回指针而不再是整数。
//
///* Sorts an array of integers using Quicksort algorithm */
//
//#include <stdio.h>
//#define N 10
//
//void quicksort(int *low, int *high);
//int *split(int *low, int *high);
//
//int exercise12_6(){
//    int a[N], i;
//    printf("Enter %d numbers to be sorted: ", N);
//    for (i = 0; i < N; i++)
//        scanf("%d", &a[i]);
//
//    quicksort(a, a + N - 1);
//
//    printf("In sorted order: ");
//    for (i = 0; i < N; i++)
//        printf("%d ", a[i]);
//    printf("\n");
//    return 0;
//}
//
//void quicksort(int *low, int *high){
//    int *middle;
//    if (low >= high) return;
//
//    middle = split(low, high);
//    quicksort(low, middle - 1);
//    quicksort(middle + 1, high);
//}
//
//int *split(int *low, int *high){
//    int part_element = *low;
//
//    for (;;) {
//        while (low < high && part_element <= *high)
//            high--;
//        if (low >= high) break;
//
//        *low++ = *high;
//        while (low < high && *low <= part_element)
//            low++;
//        if (low >= high) break;
//
//        *high-- = *low;
//    }
//    *high = part_element;
//    return high;
//}