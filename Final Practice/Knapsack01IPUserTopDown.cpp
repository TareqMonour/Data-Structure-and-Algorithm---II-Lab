#include<iostream>
using namespace std;

const int MAX_ITEMS = 50;

int P[MAX_ITEMS]; // Prices
int W[MAX_ITEMS]; // Weights

int memo[50][50];

void printMemo(int C, int i) {
    for(int r = 0; r <= C; r++) {
        for(int c = 0; c <= i; c++) {
            cout << memo[r][c] << "\t";
        }
        cout << endl;
    }
}

void initializeMemo(int C, int i) {
    for(int r = 0; r <= C; r++) {
        for(int c = 0; c <= i; c++) {
            memo[r][c] = -1;
        }
    }

    for(int r = 0; r <= C; r++) {
        memo[r][0] = 0;
    }

    for(int c = 0; c <= i; c++) {
        memo[0][c] = 0;
    }
}

int knapsack01(int C, int i) {
    if (C == 0 || i == 0) {
        return 0;
    }

    if(memo[C][i] != -1) return memo[C][i];

    int value1 = 0, value2 = 0;
    value1 = 0 + knapsack01(C, i - 1);
    if(C >= W[i]) {
        value2 = P[i] + knapsack01(C - W[i], i - 1);
    } else {
        value2 = 0;
    }
    if(value1 >= value2) {
        memo[C][i] = value1;
        return value1;
    } else {
        memo[C][i] = value2;
        return value2;
    }
}

int main() {
    int numItems;

    cout << "Enter the number of items: ";
    cin >> numItems;

    cout << "Enter the prices of items:\n";
    for(int i = 1; i <= numItems; ++i) {
        cout << "Price of item " << i << ": ";
        cin >> P[i];
    }

    cout << "Enter the weights of items:\n";
    for(int i = 1; i <= numItems; ++i) {
        cout << "Weight of item " << i << ": ";
        cin >> W[i];
    }

    int capacity;
    cout << "Enter the capacity of knapsack: ";
    cin >> capacity;

    initializeMemo(capacity, numItems);
    int profit = knapsack01(capacity, numItems);

    cout << "Total profit: " << profit << endl;
    printMemo(capacity, numItems);

    return 0;
}
