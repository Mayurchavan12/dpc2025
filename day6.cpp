#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> findSubarray(vector<int> & arr){
    int n = arr.size();
    vector<pair<int, int>> result;

    for(int start = 0; start < n; start++){
        int sum = 0;
        for(int end = start; end < n; end++){
            sum += arr[end];
            if(sum == 0){
                result.push_back({start, end});
            }
        }
    }
    return result;
}

void printResult(const vector<pair<int, int>> &result){
    for(const auto &p : result){
        cout << "(" << p.first << ", " << p.second << " ) ";
    }
    cout << endl;
}


int main(){
    vector<int> arr = {1, 2, -3, 3, -1, 2};
    vector<pair<int, int>> result = findSubarray(arr);
    printResult(result);

    return 0;
}
