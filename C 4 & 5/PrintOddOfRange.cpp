#include <bits/stdc++.h>
using namespace std;

void printOddNumbers(int start, int end) {
    if (start > end) {
        return;
    }
    if (start % 2 != 0) { // Check if the number is odd
        cout << start << " ";
    }
    printOddNumbers(start + 1, end);
}

int main() {
    int start, end;

    cout << "Enter the start of the range: ";
    cin >> start;
    cout << "Enter the end of the range: ";
    cin >> end;

    cout << "Odd Numbers in the Range " << start << " to " << end << " are: ";
    printOddNumbers(start, end);

    return 0;
}
