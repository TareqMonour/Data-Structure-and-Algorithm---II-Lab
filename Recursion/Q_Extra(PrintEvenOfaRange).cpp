#include<bits/stdc++.h>
using namespace std;

void printEvenNumbers(int start, int end) {
    if (start > end) {
        return;
    }
    if (start % 2 == 0) {
        cout << start << " ";
    }
    printEvenNumbers(start + 1, end);
}

int main() {
    int start, end;

    cout << "Enter the start of the range: ";
    cin >> start;
    cout << "Enter the end of the range: ";
    cin >> end;

    cout << "Even Numbers in the Range " << start << " to " << end << " are: ";
    printEvenNumbers(start, end);

    return 0;
}

