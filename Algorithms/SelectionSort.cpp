#include <iostream>
using namespace std;



void selectionSort(int arr[], int length) {
    for (int i = 0; i <= length; i++) {
        int lowIndex = i;
        int lowVal = arr[i];

        for (int j = i + 1; j <= length; j++) {
            if (lowVal > arr[j]) {
                lowVal = arr[j];
                lowIndex = j;
            }
        }

        if (lowIndex != i) {
            int temp = arr[i];
            arr[i] = arr[lowIndex];
            arr[lowIndex] = temp;
        }
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
    selectionSort(arr, length);
    display(arr, length);
    return 0;
}