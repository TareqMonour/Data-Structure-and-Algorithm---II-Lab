#include <bits/stdc++.h>
using namespace std;

void printArrayReverse(int arr[], int n, int index) {
    if (index < n) {
        printArrayReverse(arr, n, index + 1);
        cout << arr[index] << " ";
    }
}

int main() {
    int n;
    cout << "Enter the Size of the Array: ";
    cin >> n;

    int arr[n];
    cout << "Enter the Elements of the Array:";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array in Reverse Order: ";
    printArrayReverse(arr, n, 0);

    return 0;
}

