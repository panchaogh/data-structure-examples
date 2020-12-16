/**
 * Created by PANCHAO on 2020/12/16.
 * 插入排序
 */
#include <stdio.h>

#define ARR_LEN 10 //数组长度

/**
 * 插入排序
 * @param arr
 * @param len
 */
void insertion_sort(int arr[], int len) {
    for (int i = 1; i < len; ++i) {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j) {
            int temp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = temp;
        }
    }
}

int main() {
    int arr[ARR_LEN] = {1, 3, 5, 7, 9, 0, 8, 6, 4, 2};
    insertion_sort(arr, ARR_LEN);
    printf("[");
    for (int i = 0; i < ARR_LEN; ++i) {
        if (i < ARR_LEN - 1) {
            printf("%d,", arr[i]);
        } else {
            printf("%d", arr[i]);
        }
    }
    printf("]\n");
    return 0;
}
