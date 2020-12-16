/**
 * Created by PANCHAO on 2020/12/16.
 * 冒泡排序
 */
#include <stdio.h>

#define ARR_LEN 10 //数组长度

/**
 * 冒泡排序
 * 1. 从当前元素起，向后依次比较每一对相邻元素，若逆序则交换
 * 2. 对所有元素均重复以上步骤，直至最后一个元素
 * @param arr 排序目标数组
 * @param len 元素个数
 */
void bubble_sort(int arr[], int len) {
    for (int i = 0; i < len - 1; ++i) { //外循环为排序趟数，len个数进行len-1趟
        for (int j = 0; j < len - 1 - i; ++j) { //内循环为每趟比较的次数，第i趟比较len-i次
            if (arr[j] > arr[j + 1]) { //相邻元素比较，若逆序则交换（升序为左大于右，降序反之）
                //数据交换
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[ARR_LEN] = {1, 3, 5, 7, 9, 0, 8, 6, 4, 2};
    bubble_sort(arr, ARR_LEN);
    printf("[");
    for (int i = 0; i < ARR_LEN; ++i) {
        if (i < ARR_LEN-1) {
            printf("%d,", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("]\n");
    return 0;
}
