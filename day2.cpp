#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n-1);
    cout << "Enter elements: ";
    long long actualSum = 0;
    for(int i=0; i<n-1; i++){
        cin >> arr[i];
        actualSum += arr[i];
    }

    long long expectedSum = (n*(n+1))/2;
    long missingNumber = expectedSum - actualSum;

    cout << "The missing number is: " << missingNumber << endl;
    return 0;
}
