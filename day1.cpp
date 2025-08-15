#include <bits/stdc++.h>
using namespace std;

void SortNumbers(vector<int> &arr){
    int low = 0;
    int high = arr.size() - 1;
    int mid = 0;

    while(mid <= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void printArray(const vector<int>& arr){
    for(int num : arr){
        cout << num << " ";
    }
    cout << endl; 
}

int main(){
    vector<int> arr = {0,1,2,1,0,2,1,0};
    cout << "Original array: ";
    printArray(arr);
    SortNumbers(arr);
    cout << "Sorted Array: ";
    printArray(arr);

    return 0;
}
