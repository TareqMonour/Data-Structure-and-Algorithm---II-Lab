#include<iostream>
#include<limits>
using namespace std;

struct ReturnValues{
    int sum;
    int start;
    int end;
};

struct ReturnValues minCrossingSubArray(int A[], int start, int end){
    int middle = (start + end) / 2;

    int sum = 0;
    int leftSum = INT_MAX;
    int leftIndex = -1;

    for(int i = middle; i >= start; i--){
        sum = sum + A[i];
        if(leftSum > sum){
            leftSum = sum;
            leftIndex = i;
        }
    }
    sum = 0;
    int rightSum = INT_MAX;
    int rightIndex = -1;

    for(int i = middle + 1; i <= end; i++){
        sum = sum + A[i];
        if(sum < rightSum){
            rightSum = sum;
            rightIndex = i;
        }
    }

    ReturnValues returnValues;
    returnValues.sum = leftSum + rightSum;
    returnValues.start = leftIndex;
    returnValues.end = rightIndex;

    return returnValues;
}

ReturnValues minimumSubArray(int A[], int start, int end){
    if(start == end){
        ReturnValues returnValues;
        returnValues.sum = A[start];
        returnValues.start = start;
        returnValues.end = end;
        return returnValues;
    }

    int middle = (start + end) / 2;

    ReturnValues left = minimumSubArray(A, start, middle);
    ReturnValues right = minimumSubArray(A, middle + 1, end);
    ReturnValues cross = minCrossingSubArray(A, start, end);

    if(left.sum < right.sum && left.sum < cross.sum){
        return left;
    } else if(right.sum < left.sum && right.sum < cross.sum){
        return right;
    } else{
        return cross;
    }
}

int main(){
    int A[] = {16, 23, 18, 20, 7, 12, 5};
    int start = 0;
    int end = 6;
    struct ReturnValues test = minimumSubArray(A, start, end);

    cout << "Test.sum=" << test.sum << endl;
    cout << "Test.start=" << test.start << endl;
    cout << "Test.end=" << test.end << endl;

    return 0;
}

