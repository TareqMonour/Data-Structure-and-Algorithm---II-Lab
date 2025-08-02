#include <iostream>
using namespace std;

void countOddEven(const int arr[], int start, int end, int& oddCount, int& evenCount) {
    if (start > end) {
        return;
    }

    int mid = start + (end - start) / 2;

    countOddEven(arr, start, mid, oddCount, evenCount);
    countOddEven(arr, mid + 1, end, oddCount, evenCount);

    for (int i = start; i <= mid; ++i) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    for (int i = mid + 1; i <= end; ++i) {
        if (arr[i] % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the size of the Array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the Elements of the Array:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Element " << i + 1 << " is: ";
        cin >> arr[i];
    }

    int oddCount = 0, evenCount = 0;

    countOddEven(arr, 0, n - 1, oddCount, evenCount);

    cout << "Number of Odd Elements: " << oddCount << endl;
    cout << "Number of Even Elements: " << evenCount << endl;

    return 0;
}
