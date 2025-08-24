#include<bits/stdc++.h>
using namespace std;

vector<vector<string>> groupAna(vector<string> &str){

    unordered_map<string, vector<string>> mp;

    for(int i=0; i<str.size();i++){
        string s = str[i];
        sort(s.begin(), s.end());

        mp[s].push_back(str[i]);
    }


    vector<vector<string>> ans(mp.size());
    int index = 0;

    for(auto x : mp){

        auto temp = x.second;

        for(auto x : temp){
            ans[index].push_back(x);
        }

        index++;
    }

    return ans;
}


int main() {

    vector<string> str;
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cout << "Enter strings: ";
    for(int i=0; i<n; i++){
        string s;
        cin >> s;
        str.push_back(s);
    }

    vector<vector<string>> result = groupAna(str);
    cout << "Grouped Anagrams: " << endl;
    for(auto x : result){
        cout << "[ ";
        for(auto y : x){
            cout << y << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
