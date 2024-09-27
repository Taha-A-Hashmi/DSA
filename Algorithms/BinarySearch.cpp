#include <iostream>

int main() {
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    int high = sizeof(arr) / sizeof(arr[0]) - 1;
    int low  = 0;
    int target = 3;
    int step = 0;

    while (high >= low) {  // Ensure `>=` to handle all cases
        int midpoint = low + (high - low) / 2;  // Correct midpoint calculation

        step++;  // Count steps at each iteration

        if (arr[midpoint] == target) {
            std::cout << target << " was found at index " << midpoint << std::endl;
            std::cout << "Steps taken: " << step << std::endl;
            return 0;
        } else if (arr[midpoint] < target) {
            low = midpoint + 1;
        } else if (arr[midpoint] > target) {
            high = midpoint - 1;
        }
    }

    std::cout << "Target was not found" << std::endl;
    std::cout << "Steps taken: " << step << std::endl;  // Total steps taken
    return 0;
}
