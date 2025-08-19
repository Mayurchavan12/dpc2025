#include <bits/stdc++.h>
using namespace std;

vector<int> Leaders(vector<int> &arr){
    int n = arr.size();
    vector<int> leaders;

    int max = arr[n-1];
    leaders.push_back(max);

    for(int i=n-2; i>=0; i--){
        if(arr[i] > arr[i-1]){
            max = arr[i];
            leaders.push_back(max);
        }

    }
    reverse(leaders.begin(), leaders.end());
    return leaders;
}

int main(){

    int n;
    cout<< "Enter the size of the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<int> leaders = Leaders(arr);
    cout << "Leaders in the array: ";
    for(int leader : leaders) {
        cout << leader << " ";
    }   
    return 0;
}
