#include <bits/stdc++.h>
using namespace std;

void mergeArrays(vector<int>& arr1, vector<int>& arr2) {
    int m = arr1.size();
    int n = arr2.size();

    for (int i = 0; i < m; i++) {
        if (arr1[i] > arr2[0]) {
            swap(arr1[i], arr2[0]);
            
            int first = arr2[0];
            int k;
            for (k = 1; k < n && arr2[k] < first; k++) {
                arr2[k - 1] = arr2[k];
            }
            arr2[k - 1] = first;
        }
    }
}

int main() {
    vector<int> arr1 = {1, 3, 5};
    vector<int> arr2 = {2, 4, 6};

    mergeArrays(arr1, arr2);

    cout << "Merged array: ";
    for (int x : arr1) cout << x << " ";
    for (int x : arr2) cout << x << " ";
    cout << endl;

    return 0;
}
