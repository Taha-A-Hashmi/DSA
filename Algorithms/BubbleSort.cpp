#include <iostream>
using namespace std;

void bubbleSort (int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void display (int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}


int main () {
    int arr[10] = {3,5,7,5,2,3,5,7,4,3};
    int n = sizeof(arr)/sizeof(arr[0]);
    display(arr, n);
    bubbleSort(arr, n);
    display(arr, n);

    return 0;
}