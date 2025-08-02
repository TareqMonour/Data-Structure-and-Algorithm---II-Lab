#include <bits/stdc++.h>
using namespace std;

int minimumCoins(vector<int> &num, int x)
{
    // Step 1: Create dp array
    vector<int> dp(x+1, INT_MAX);

    // Step 2: Assign base case values in dp array
    dp[0]=0;

    // Step 3: Calculating every current problem using previously solved subproblems
    for(int i=1; i<=x; i++){
        // Solving every amount from 1 to x
        for(int j=0; j<num.size(); j++){
            if (i - num[j] >= 0 && dp[i - num[j]] != INT_MAX) {
                dp[i] = min(dp[i], 1+dp[i - num[j]]);
            }
        }
    }
    if(dp[x]==INT_MAX)
        return -1;

    return dp[x];
}

int main()
{
    int n;
    cout<<"Enter the Number of coins: ";
    cin>>n;

    vector<int> num(n);
    cout<<"Enter the value of the coins: ";
    for(int i=0;i<num.size();i++){
        cin>>num[i];
    }

    int x;
    cout<<"Enter the amount: ";
    cin>>x;


    int ans=minimumCoins(num,x);
    if(ans== -1)
        cout<<"No coins can be choosen for the entered amount"<<endl;
    else
        cout<<"The minimum number of coins required for amount "<<x<<" is: "<<ans<<endl;

    return 0;

}

