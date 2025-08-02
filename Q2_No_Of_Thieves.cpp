#include <iostream>
#include <algorithm>
using namespace std;

int minThievesRequired(int n, int prices[], int weights[], int W) {
    int memo[n + 1][W + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            memo[i][w] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {
            if (weights[i - 1] <= w) {
                memo[i][w] = max(prices[i - 1] + memo[i - 1][w - weights[i - 1]], memo[i - 1][w]);
            } else {
                memo[i][w] = memo[i - 1][w];
            }
        }
    }

    int maxValue = memo[n][W];
    int minThieves = (maxValue + W - 1) / W;

    return minThieves;
}

int main() {
    int n;
    cout << "Enter the Number of Items: ";
    cin >> n;

    int prices[n], weights[n];
    cout << "Enter Prices: ";
    for (int i = 0; i < n; i++)
        cin >> prices[i];

    cout << "Enter Weights: ";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    int W;
    cout << "Enter Bag Size: ";
    cin >> W;

    int minThieves = minThievesRequired(n, prices, weights, W);

    cout << "Minimum Number of Thieves Required: " << minThieves << endl;

    return 0;
}
