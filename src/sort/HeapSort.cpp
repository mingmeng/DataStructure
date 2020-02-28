//
// Created by mingmeng on 2020/2/27.
//

#include "HeadSort.h"

void percDown(int *arr, int i, int n) {
    int child;
    int temp;

    for (temp = arr[i]; 2 * i + 1 < n; i = child) {
        child = 2 * i + 1;
        if (child != n - 1 && arr[child] < arr[child + 1])
            child++;

        if (temp < arr[child])
            arr[i] = arr[child];
        else
            break;
    }
    arr[i] = temp;
}

void heapSort(int *arr) {
    int length = sizeof(arr) / sizeof(int); //计算数组长度

    for (int i = length / 2 - 1; i >= 0; i--)
        percDown(arr, i, length);               //构造最大堆

    for (int i = length - 1; i > 0; i--) {
        swap(arr, 0, i);
        percDown(arr, 0, i);
    }
}

void swap(int *arr, int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}