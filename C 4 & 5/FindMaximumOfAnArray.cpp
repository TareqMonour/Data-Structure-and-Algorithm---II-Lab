#include <iostream>
using namespace std;

int findMax(int arr[], int n) {
    if (n <= 0) {
        // Handle edge case of empty array or negative size
        return INT_MIN; // Return smallest possible integer
    }

    int maxElement = arr[0]; // Assume first element is the maximum

    for (int i = 1; i < n; ++i) {
        if (arr[i] > maxElement) {
            maxElement = arr[i]; // Update maxElement if a larger element is found
        }
    }

    return maxElement;
}

int main() {
    int arr[] = {5, 10, 3, 8, 15};
    int size = sizeof(arr) / sizeof(arr[0]);

    int maxElement = findMax(arr, size);

    cout << "The maximum element of the array is: " << maxElement << endl;

    return 0;
}
