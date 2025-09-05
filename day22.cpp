#include <bits/stdc++.h>
using namespace std;

int firstElementKTimes(const vector<int> &arr, int k) {
    unordered_map<int, int> freq;

    for (int num : arr) {
        freq[num]++;
    }

    for (int num : arr) {
        if (freq[num] == k) {
            return num;
        }
    }

    return -1;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter the value of k: ";
    cin >> k;

    int result = firstElementKTimes(arr, k);
    cout << "The first element to appear exactly " << k << " times is: " << result << endl;

    return 0;
}
