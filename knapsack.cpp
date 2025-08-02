#include <iostream>
#include <cstring> // for memset
using namespace std;

const int MAX_ITEMS = 50;
const int MAX_CAPACITY = 50;

int P[MAX_ITEMS], W[MAX_ITEMS];
int memo[MAX_CAPACITY + 1];

int knapsack01(int C, int n) {
    memset(memo, 0, sizeof(memo)); // Initialize memoization array

    for (int i = 1; i <= n; ++i) {
        for (int j = C; j >= W[i]; --j) {
            memo[j] = max(memo[j], P[i] + memo[j - W[i]]);
        }
    }

    return memo[C];
}

int totalThief(int C, int n) {
    int totalValue = knapsack01(C, n);
    int totalThieves = (totalValue == 0) ? 0 : (totalValue + C - 1) / C; // Ceil(totalValue / C)
    return totalThieves;
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

    int totalThieves = totalThief(capacity, n);
    cout << "Total Thieves Required: " << totalThieves << endl;

    return 0;
}
