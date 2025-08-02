#include <bits/stdc++.h>
using namespace std;

double calculateAverage(int arr[], int n, int index = 0, double sum = 0) {
    if (index == n) {
        return sum / n;
    } else {
        return calculateAverage(arr, n, index + 1, sum + arr[index]);
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
    double avg = calculateAverage(arr, n);
    cout << "The Average of the Elements is: " << avg <<endl;

    return 0;
}

