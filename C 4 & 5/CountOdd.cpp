#include <iostream>
using namespace std;

int countOdd(int Arr[], int i, int j) {
    if (i == j) {  // Base case: array size 1
        if (Arr[i] % 2 != 0) // If the number is odd
            return 1;
        else
            return 0;
    } else {
        int mid = (i + j) / 2;
        int c1 = countOdd(Arr, i, mid);     // Solution to the first half
        int c2 = countOdd(Arr, mid + 1, j);  // Solution to the second half
        return c1 + c2;
    }
}

int main() {
    int A[] = {6, 11, 4, 5, 8, 2};
    int N = sizeof(A) / sizeof(A[0]);
    cout << "Count of odd numbers: " << countOdd(A, 0, N - 1);
    return 0;
}

