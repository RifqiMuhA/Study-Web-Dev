#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linearSearch(int arr[], int length, int target) {
    for (int i = 0; i < length; i++)
        if(arr[i] == target)
            return i;
    return -1;
}

int binarySearch(int arr[], int length, int target) {
    int left = 0, right = length - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target) return mid; // Mengembalikan indeks elemen yang ditemukan
        if (arr[mid] < target) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}

int main() {
    
}