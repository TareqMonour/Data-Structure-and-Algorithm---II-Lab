#include <bits/stdc++.h>
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


int knapsack01(int weights[], int item, int sizeOfBag)
{
    for (int i = 0; i <= item; i++)
    {
        for (int j = 0; j <= sizeOfBag; j++)
        {
            if (i == 0 || j == 0)
            {
                memo[i][j] = 0;
            }
            else if (weights[i - 1] <= j)
            {
                memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - weights[i - 1]] + 1);
            }
            else
            {
                memo[i][j] = memo[i - 1][j] + 1;
            }
        }
    }

    return memo[item][sizeOfBag];
}

int main()
{
    int n;
    cout << "Number of Items: ";
    cin >> n;

    int prices[n];
    int weights[n];

    cout << "Prices of the Items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> prices[i];
    }

    cout << "Weights of the Items: ";
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    int sizeOfBag;
    cout << "Enter the Bag Size of Each Thief: ";
    cin >> sizeOfBag;

    int result = knapsack01(weights, n, sizeOfBag);

    cout << result << endl;

    return 0;
}
