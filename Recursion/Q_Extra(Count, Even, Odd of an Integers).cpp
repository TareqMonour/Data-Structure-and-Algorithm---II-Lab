#include <bits/stdc++.h>
using namespace std;
void countOddEven(const int arr[], int n, int& oddCount, int& evenCount, int index = 0) {
    if (index == n) {
        return;
    }
    if (arr[index] % 2 == 0) {
        evenCount++;
    } else {
        oddCount++;
    }
    countOddEven(arr, n, oddCount, evenCount, index + 1);
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

    countOddEven(arr, n, oddCount, evenCount);

    cout << "Number of Odd Elements: " << oddCount <<endl;
    cout << "Number of Even Elements: " << evenCount <<endl;

    return 0;
}

