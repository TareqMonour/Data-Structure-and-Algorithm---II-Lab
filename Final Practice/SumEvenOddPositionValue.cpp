#include <iostream>
using namespace std;

void sumEvenOddPositions(const int arr[], int start, int end, int& sumEven, int& sumOdd) {
    if (start > end) {
        return;
    }

    if (start == end) {
        if (start % 2 == 0) {
            sumEven += arr[start];
        } else {
            sumOdd += arr[start];
        }
        return;
    }

    int mid = start + (end - start) / 2;

    sumEvenOddPositions(arr, start, mid, sumEven, sumOdd);
    sumEvenOddPositions(arr, mid + 1, end, sumEven, sumOdd);
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

    int sumEven = 0, sumOdd = 0;

    sumEvenOddPositions(arr, 0, n - 1, sumEven, sumOdd);

    cout << "Sum of Elements at Even Positions: " << sumEven << endl;
    cout << "Sum of Elements at Odd Positions: " << sumOdd << endl;

    return 0;
}
