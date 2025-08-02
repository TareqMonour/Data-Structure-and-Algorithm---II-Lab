#include <iostream>
#include <climits>
using namespace std;

struct ReturnValues{
    int product;
    int start;
    int end;
};

struct ReturnValues maxCrossingSubArray(int A[], int start, int end) {
    int middle = (start + end) / 2;

    int product = 1;
    int leftProduct = INT_MIN;
    int leftIndex = -1;

    for (int i = middle; i >= start; i--) {
        product *= A[i];
        if (leftProduct < product) {
            leftProduct = product;
            leftIndex = i;
        }
    }

    product = 1;
    int rightProduct = INT_MIN;
    int rightIndex = -1;

    for (int i = middle + 1; i <= end; i++) {
        product *= A[i];
        if (rightProduct < product) {
            rightProduct = product;
            rightIndex = i;
        }
    }

    ReturnValues returnValues;
    returnValues.product = leftProduct * rightProduct;
    returnValues.start = leftIndex;
    returnValues.end = rightIndex;
    return returnValues;
}

ReturnValues maxProductSubArray(int A[], int start, int end) {
    if (start == end) {
        ReturnValues returnValues;
        returnValues.product = A[start];
        returnValues.start = start;
        returnValues.end = end;
        return returnValues;
    }

    int middle = (start + end) / 2;

    ReturnValues left = maxProductSubArray(A, start, middle);
    ReturnValues right = maxProductSubArray(A, middle + 1, end);
    ReturnValues cross = maxCrossingSubArray(A, start, end);

    if (left.product > right.product && left.product > cross.product) {
        return left;
    } else if (right.product > left.product && right.product > cross.product) {
        return right;
    } else {
        return cross;
    }
}

int main() {
    int n;
    cout << "Enter the Size of the Array: ";
    cin >> n;
    int A[n];
    cout << "Enter " << n << " Elements of the Array: ";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    ReturnValues test = maxProductSubArray(A, 0, n-1);

    cout << "Maximum Product: " << test.product << endl;
    cout << "Start Index: " << test.start + 1 << endl;
    cout << "End Index: " << test.end + 1 << endl;

    return 0;
}
