// C++ program to find maximum in arr[] of size n
#include <bits/stdc++.h>
using namespace std;

int largest(int arr[], int n)
{
	int i;
	int max = arr[0];

	for (i = 1; i < n; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

int main()
{
	int arr[] = { 10, 324, 45, 90, 9808 };
	int n = sizeof(arr) / sizeof(arr[0]);
	cout << "Largest in given Array is: " << largest(arr, n);
	return 0;
}


//// C++ program to find maximum in arr[] of size n

//#include <bits/stdc++.h>
//using namespace std;
//
//int largest(int arr[], int n)
//{
//	return *max_element(arr, arr + n);
//}
//
//int main()
//{
//	int arr[] = { 10, 324, 45, 90, 9808 };
//	int n = sizeof(arr) / sizeof(arr[0]);
//
//	cout << largest(arr, n);
//	return 0;
//}

