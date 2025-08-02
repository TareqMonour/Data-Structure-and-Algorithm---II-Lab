#include <bits/stdc++.h>
#include <cmath>
using namespace std;

bool isPrime(int num, int divisor = 2) {
    if (num <= 2) {
        return (num == 2);
    }

    if (divisor > sqrt(num)) {
        return true;
    }

    if (num % divisor == 0) {
        return false;
    }

    return isPrime(num, divisor + 1);
}

int main() {
    int num;

    cout << "Enter a Number: ";
    cin >> num;

    if (isPrime(num)) {
        cout << num << " is a Prime Number." <<endl;
    } else {
        cout << num << " is not a Prime Number." <<endl;
    }

    return 0;
}

