#include<bits/stdc++.h>
using namespace std;

string LongestCommonString(vector<string> &s, int n){
    
    string ans = "";

    for(int i=0; i<s[0].length(); i++){
        char ch = s[0][i];
        bool match = true;
        for(int j=1; j<n; j++){
            if(s[j].size() < i || ch != s[j][i]){
                match = false;
                break;
            }
        }
        if(match == false){
            break;
        }
        else{
            ans.push_back(ch);
        }
    }
    return ans;
}


int main () {
    int n;
    cout << "Enter number of strings : ";
    cin >> n;

    vector<string> s(n);
    cout << "Enter strings : ";
    for(int i=0; i<n ;i++){
        cin >> s[i];
    }

    string result = LongestCommonString(s, n);
    cout << "Longest Common Prefix : " << result << endl;
    return 0;
}
