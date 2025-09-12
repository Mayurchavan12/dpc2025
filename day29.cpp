#include<bits/stdc++.h>
using namespace std;


string addStrings(string &a, string &b){
    string result = "";
    int carry = 0;
    int sum = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while(i >= 0 ||  j >= 0 || carry){
        sum = carry;
        if(i >= 0) sum += a[i--] - '0';
        if(j >= 0) sum += b[j--] - '0';
        carry = sum / 10;
        result += (sum % 10) + '0';
    }
    reverse(result.begin(), result.end());
    return result;
}


string fibonacci(int n){
    if(n == 0) return "0";
    if(n == 1) return "1";

    vector<string> dp(n + 1);
    dp[0] = "0";
    dp[1] = "1";

    for(int i = 2; i <= n; i++){
        dp[i] = addStrings(dp[i - 1], dp[i - 2]);
    }

    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

    if(n < 0 || n > 1000) {
        cout << "Invalid input. Please enter a value between 0 and 1000." << endl;
        return 1;
    }

    cout << fibonacci(n) << endl;
    return 0;
}
