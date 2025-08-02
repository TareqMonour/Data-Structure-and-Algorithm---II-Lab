//Calculate the nth term of a Fibonacci series and solve it recursively using c++

#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
}

int main()
{
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    if (n < 0)
    {
        cout << "Please Enter a Non-Negative Integer!\n";
    }
    else
    {
        int result = fibonacci(n);
        cout << "The " << n << "th term of the Fibonacci Series is: " << result <<endl;
    }
    return 0;
}

