#include<bits/stdc++.h>
using namespace std;

int coinChange(vector<int> &Coins, int amount){
    vector<int> dp(amount + 1, amount + 1);
    dp[0] = 0;

    for(int i = 1; i <= amount; i++){
        for(auto coin : Coins){
            if(i - coin >= 0){
                dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
    }
    return dp[amount] > amount ? -1 : dp[amount];
}


int main(){
    int n;
    cout << "Enter number of coin denominations: ";
    cin >> n;

    vector<int> Coins(n);
    cout << "Enter the coin denominations: ";
    for(int i = 0; i < n; i++){
        cin >> Coins[i];
    }

    int amount;
    cout << "Enter the amount: ";
    cin >> amount;
    
    cout << coinChange(Coins, amount) << endl;
    return 0;
}
