#include <iostream>
using namespace std;



void insertionSort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (arr[j] > temp && j >= 0) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}


void display(int arr[], int length) {
    for (int i = 0; i <= length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main() {
    int arr[10] = {3,5,7,5,2,3,5,7,4,3};
    int length = sizeof(arr) / sizeof(arr[0]) - 1;

    display(arr, length);
    insertionSort(arr, length);
    display(arr, length);
    return 0;
}