//Recursive C++ program to find minimum

#include <iostream>
using namespace std;

int findMin(int A[], int n)
{
	// if size = 0 means whole array has been traversed
	if (n == 1)
		return A[0];
	return min(A[n-1], findMin(A, n-1));
}

int main()
{
	int A[] = {1, 4, 45, 6, -50, 10, 2};
	int n = sizeof(A)/sizeof(A[0]);
	cout <<"The Minimum Element of the given Array is: "<< findMin(A, n);
	return 0;
}

