#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef enum {FALSE=0, TRUE=1} bool;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bulbbleSort(int arr[], int length){
    for (int i = 0; i < length; i++){
        // Modifikasi algoritma swap
        bool swapped = FALSE; 
        for (int j = 0; j < length-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = TRUE;
            }
        }
        if (swapped == FALSE) // Jika dalam satu loop tidak ada yg diswap, maka array sudah terurut dan sort tidak dilanjutkan
            break;
    }
}

void selectionSort(int arr[], int length){
    for (int i = 0; i < length; i++){
        int idxMin = i;
        for (int j = i+1; j < length; j++){
            if (arr[idxMin] > arr[j])
                swap(&arr[idxMin], &arr[j]);
        }
    }
}

void insertionSort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void printArr(int arr[], int length){
    printf("Isi Array : ");
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {5, 12, 10, 50, 24, 42};
    int length = 5;

    printArr(arr, length);
    // bulbbleSort(arr, length);
    // selectionSort(arr, length);
    insertionSort(arr, length);
    printArr(arr, length);
}