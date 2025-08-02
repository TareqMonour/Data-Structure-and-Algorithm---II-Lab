#include <iostream>
using namespace std;

const int MAX_ITEMS = 100;
const int MAX_CAPACITY = 100;

int P[MAX_ITEMS], W[MAX_ITEMS];
int memo[MAX_CAPACITY + 1][MAX_ITEMS + 1];

//void printMemo(int C, int n) {
//    cout << "Memoization Table:" << endl;
//    for (int i = 0; i <= n; ++i) {
//        for (int j = 0; j <= C; ++j) {
//            cout << memo[j][i] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

void initializeMemo(int C, int n) {
    for(int r = 0; r <= C; r++) {
        for(int c = 0; c <= n; c++) {
            memo[r][c] = -1;
        }
    }

    for(int r = 0; r <= C; r++) {
        memo[r][0] = 0;
    }

    for(int c = 0; c <= n; c++) {
        memo[0][c] = 0;
    }
}

int knapsack01(int C, int n, int &count) {
    if (C == 0 || n == 0) {
        return 0;
    }

    if(memo[C][n] != -1) return memo[C][n];

    int value1 = 0, value2 = 0;
    value1 = knapsack01(C, n - 1, count);
    if(C >= W[n]) {
        value2 = P[n] + knapsack01(C - W[n], n - 1, count);
    }
    if (value2 > value1) {
        memo[C][n] = value2;
        count++;
    } else {
        memo[C][n] = value1;
    }
    return memo[C][n];
}

int requiredThief(int C, int n) {
    int count = 0;
    knapsack01(C, n, count);
    return count;
}

int main() {
    int capacity, n;

    cout << "Number of Items: ";
    cin >> n;

    cout << " Prices of the Items: ";
    for (int i = 1; i <= n; ++i) {
        cin >> P[i];
    }

    cout << " Weights of the Items : ";
    for (int i = 1; i <= n; ++i) {
        cin >> W[i];
    }

    cout << "Bag Capacity of Each Thief: ";
    cin >> capacity;

    initializeMemo(capacity, n);
    int totalThieves = requiredThief(capacity, n);
    //printMemo(capacity, n);
    //printItems(capacity, n);
    cout << "Total Thieves Required: " << totalThieves << endl;

    return 0;
}
