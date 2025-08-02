#include <bits/stdc++.h>
#include <climits>
using namespace std;

void findMinMaxRecursive(int arr[], int start, int end, int &minElement, int &maxElement) {
    // Base case: If there is only one element in the array
    if (start == end) {
        minElement = arr[start];
        maxElement = arr[start];
        return;
    }

    // Divide the array into two halves
    int mid = (start + end) / 2;
    int minLeft, maxLeft, minRight, maxRight;

    // Recursively find the min and max in each half
    findMinMaxRecursive(arr, start, mid, minLeft, maxLeft);
    findMinMaxRecursive(arr, mid + 1, end, minRight, maxRight);

    // Combine the results
    minElement = min(minLeft, minRight);
    maxElement = max(maxLeft, maxRight);
}

int main() {
    int arr[] = {3, 7, 1, 9, 5, 4, 8, 2, 6};

    int n = sizeof(arr) / sizeof(arr[0]);
    int minElement = INT_MAX, maxElement = INT_MIN;

    findMinMaxRecursive(arr, 0, n - 1, minElement, maxElement);

    cout << "Smallest element: " << minElement <<endl;
    cout << "Largest element: " << maxElement <<endl;

    return 0;
}

