#include <iostream>
#include <vector>
using namespace std;

const int MAX_ITEMS = 100;
const int MAX_CAPACITY = 100;

int P[MAX_ITEMS], W[MAX_ITEMS];
int memo[MAX_CAPACITY + 1][MAX_ITEMS + 1];

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

int knapsack01(int C, int n, int &count, vector<int>& thief_items) {
    if (C == 0 || n == 0) {
        return 0;
    }

    if(memo[C][n] != -1) return memo[C][n];

    int value1 = 0, value2 = 0;
    value1 = knapsack01(C, n - 1, count, thief_items);
    if(C >= W[n]) {
        value2 = P[n] + knapsack01(C - W[n], n - 1, count, thief_items);
    }
    if (value2 > value1) {
        memo[C][n] = value2;
        count++;
        thief_items.push_back(n); // Add item to thief's loot
    } else {
        memo[C][n] = value1;
    }
    return memo[C][n];
}

int main() {
    int n, sizeofBag;

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

    cout << "Bag Size of Each Thief: ";
    cin >> sizeofBag;

    initializeMemo(sizeofBag, n);
    int count = 0;
    vector<int> thief_items;
    int result = knapsack01(sizeofBag, n, count, thief_items);
    cout << "Total Thieves Required: " << count << endl;

    // Output each thief's stolen items and total profit
    int total_profit = 0;
    for (int i = 0; i < count; ++i) {
        cout << "Thief " << i+1 << " stole items: ";
        int thief_profit = 0;
        for (int j = 0; j < thief_items.size(); ++j) {
            if (memo[sizeofBag][thief_items[j]] > 0) {
                cout << thief_items[j] << " ";
                total_profit += P[thief_items[j]];
                thief_profit += P[thief_items[j]];
            }
        }
        cout << " (Total Profit: " << thief_profit << ")" << endl;
    }

    cout << "Total Profit: " << total_profit << endl;

    return 0;
}
