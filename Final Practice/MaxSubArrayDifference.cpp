#include <iostream>
#include <climits>
using namespace std;

struct ReturnValues {
    int difference;
    int start;
    int end;
};

struct ReturnValues maxCrossingSubArray(int A[], int start, int end) {
    int middle = (start + end) / 2;

    int difference = 0;
    int leftDifference = INT_MIN;
    int leftIndex = -1;

    for (int i = middle; i >= start; i--) {
        difference += A[i];
        if (difference > leftDifference) {
            leftDifference = difference;
            leftIndex = i;
        }
    }

    difference = 0;
    int rightDifference = INT_MIN;
    int rightIndex = -1;

    for (int i = middle + 1; i <= end; i++) {
        difference += A[i];
        if (difference > rightDifference) {
            rightDifference = difference;
            rightIndex = i;
        }
    }

    ReturnValues returnValues;
    returnValues.difference = rightDifference - leftDifference;
    returnValues.start = leftIndex;
    returnValues.end = rightIndex;

    return returnValues;
}

ReturnValues maxDifferenceSubArray(int A[], int start, int end) {
    if (start == end) {
        ReturnValues returnValues;
        returnValues.difference = 0;
        returnValues.start = start;
        returnValues.end = end;
        return returnValues;
    }

    int middle = (start + end) / 2;

    ReturnValues left = maxDifferenceSubArray(A, start, middle);
    ReturnValues right = maxDifferenceSubArray(A, middle + 1, end);
    ReturnValues cross = maxCrossingSubArray(A, start, end);

    if (left.difference > right.difference && left.difference > cross.difference) {
        return left;
    } else if (right.difference > left.difference && right.difference > cross.difference) {
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

    ReturnValues result = maxDifferenceSubArray(A, 0, n - 1);

    cout << "Maximum Subarray Difference: " << result.difference << endl;
    cout << "Start Index: " << result.start << endl;
    cout << "End Index: " << result.end << endl;

    return 0;
}
