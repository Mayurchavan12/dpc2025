#include<bits/stdc++.h>
using namespace std;


vector<int> MaximumWindow(vector<int> &arr, int k){
    deque<int> dq;
    vector<int> ans;

    for(int i=0; i<arr.size(); i++){

        while(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }

        while(!dq.empty() && arr[dq.back()] < arr[i]){
            dq.pop_back();
        }

        dq.push_back(i);

        if(i >= k-1){
            ans.push_back(arr[dq.front()]);
        }

    }
    return ans;

}


int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    int k;
    cout << "Enter the size of the window: ";
    cin >> k;
    vector<int> result = MaximumWindow(arr, k);
    cout << "The maximum elements in each sliding window are: ";
    for(int i=0; i<result.size(); i++){
        cout << result[i] << " ";
    }
    return 0;
}
