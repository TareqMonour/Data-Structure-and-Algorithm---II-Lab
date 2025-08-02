#include <bits/stdc++.h>
#include <vector>
using namespace std;

int minThievesRequired(int n, vector<int> &prices, vector<int> &weights, int thiefCapacity) {
    vector<int> dp(thiefCapacity + 1, 0);

    for (int i = 0; i < n; ++i) {
        for (int w = thiefCapacity; w >= weights[i]; --w) {
            dp[w] = max(dp[w], dp[w - weights[i]] + prices[i]);
        }
    }

    return dp[thiefCapacity];
}

int main() {
    int n;
    cout << "Enter the Number of Items: ";
    cin >> n;

    vector<int> prices(n), weights(n);

    cout << "Enter the Prices of the Items: ";
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    cout << "Enter the Weights of the Items: ";
    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    int thiefCapacity;
    cout << "Enter the Capacity of Each Thief's Bag: ";
    cin >> thiefCapacity;

    int minThieves = minThievesRequired(n, prices, weights, thiefCapacity);
    cout << "Minimum Number of Thieves Required to Empty the House: " << minThieves << endl;

    return 0;
}
