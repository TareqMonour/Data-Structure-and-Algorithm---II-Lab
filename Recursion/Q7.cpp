//Calculate a to the power b and solve it recursively using C++

#include <bits/stdc++.h>
using namespace std;

double power(double a, int b) {
    if (b == 0) {
        return 1.0;
    }
 // Recursive case: a^b = a * a^(b-1)
    return a * power(a, b - 1);
}

int main() {
    double base;
    int exponent;
    // Get input from the user
    cout << "Enter the base: ";
    cin >> base;

    cout << "Enter the Exponent: ";
    cin >> exponent;
    // Calculate and display the result
    double result = power(base, exponent);
    cout << base << " to the power " << exponent << " is: " << result <<endl;

    return 0;
}

