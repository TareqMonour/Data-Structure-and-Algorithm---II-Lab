#include<bits/stdc++.h>
using namespace std;

// Memoization table to store computed values
unordered_map<int, unordered_map<int, int>> dp;

// Recursive function to find the minimum number of thieves
int minThieves(int i, int j, int W, const vector<int>& weights) {
    if (i > j) return 0; // Base case: no items left

    // Check if the result for this subproblem is already computed
    if (dp.find(i) != dp.end() && dp[i].find(j) != dp[i].end()) {
        return dp[i][j];
    }

    // If the weight of the current item is within the bag size
    if (weights[i] + weights[j] <= W) {
        // Recur for the next pair of items
        int result = minThieves(i + 1, j - 1, W, weights);
        // Store the result in memoization table
        dp[i][j] = result;
        return result;
    }

    // Otherwise, we have to take one item at a time
    int result = 1 + minThieves(i, j - 1, W, weights);
    // Store the result in memoization table
    dp[i][j] = result;
    return result;
}

int main() {
    int n;
    cout << "Enter the number of items: ";
    cin >> n;

    vector<int> Prices(n);
    cout << "Prices:";
    for(int i=0; i<n; i++) {
        cin >> Prices[i];
    }

    vector<int> weights(n);
    cout << "Enter the weights of the items: ";
    for(int i=0; i<n; i++) {
        cin >> weights[i];
    }

    int W;
    cout << "Bag size: ";
    cin >> W;

    sort(weights.begin(), weights.end());

    int numThieves = minThieves(0, n - 1, W, weights);

    cout << "The minimum number of thieves required to empty the house is: " << numThieves << endl;

    return 0;
}
