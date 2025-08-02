#include<iostream>
using namespace std;

const int MAX_N = 100;
const int MAX_COINS = 100;

int N, numOfCoins;
int coins[MAX_COINS];
int memo[MAX_N][MAX_COINS];
char printTable[MAX_N][MAX_COINS];

void initializeMemo(){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= numOfCoins; j++){
            memo[i][j] = -1;
        }
    }
    for(int i = 0; i <= numOfCoins; i++){
        memo[0][i] = 0;
    }

    for(int i = 0; i <= N; i++){
        memo[i][0] = 9999;
    }
}

void printMemo(){
    cout<<"***************The Memo***************"<<endl;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= numOfCoins; j++){
            cout<<memo[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n***************The Memo***************"<<endl;

    cout<<"***************The PrintTable***************"<<endl;
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= numOfCoins; j++){
            cout<<printTable[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<"\n***************The PrintTable***************"<<endl;
}

int coinChange(int amount, int index) {
    if (amount == 0) return 0;
    if (index == 0) return 9999;
    if (amount < 0) return 9999;

    if (memo[amount][index] != -1) return memo[amount][index];

    int call1 = coinChange(amount, index - 1); // Exclude current coin
    int call2 = 1 + coinChange(amount - coins[index], index); // Include current coin

    if (call1 <= call2) {
        memo[amount][index] = call1;
        printTable[amount][index] = 'N';
        return call1;
    } else {
        memo[amount][index] = call2;
        printTable[amount][index] = 'T';
        return call2;
    }
}
void printTheCoins(int N, int i) {
    if (N == 0 || i == 0)
        return;

    if (printTable[N][i] == 'T') {
        printTheCoins(N - coins[i], i);
        cout << "Coin " << i << " has been taken, coin value: " << coins[i] << endl;
    } else { // 'N'
        printTheCoins(N, i - 1);
    }
}


int main(){
    cout << "Enter the amount of money: ";
    cin >> N;

    cout << "Enter the number of finite coins needed for that amount (excluding infinite coins): ";
    cin >> numOfCoins;

    cout << "Enter the coin values:\n";
    for(int i = 1; i <= numOfCoins; ++i){
        cout << "Coin " << i << " value: ";
        cin >> coins[i];
    }

    // Add infinite coins for first and last coin
    coins[0] = 1; // First coin is infinite
    coins[numOfCoins + 1] = 1; // Last coin is infinite
    numOfCoins += 2;

    initializeMemo();

    int result = coinChange(N, numOfCoins - 1);
    if(result == 9999){
        cout << "It is not possible to make the given amount." << endl;
    }else{
        cout << "Minimum number of coins: " << result << endl;
    }

    printMemo();
    printTheCoins(N, numOfCoins - 1);

    return 0;
}
