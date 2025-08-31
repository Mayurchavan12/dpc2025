#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> factors;
    for(int i=2; i*i<=n; i++){
        while(n%i == 0){
            factors.push_back(i);
            n /= i;
        }
    }
    if(n > 1) factors.push_back(n);
    for(int i : factors) cout << i << " ";
    cout << endl;
    return 0;
}
