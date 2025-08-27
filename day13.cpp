#include <bits/stdc++.h>
using namespace std;

string longestPalindrome(string s) {
        int n = s.size();
        if(n==0) return "";

        int start = 0;
        int maxLen = 1;

        for(int i=1; i<n; i++){

            int l=i, r=i;
            while(l>=0 && r<n && s[l]==s[r]){
                int len = r-l+1;
                if(len > maxLen){
                    start = l;
                    maxLen = len;
                }
                l--;
                r++;
            }


            l=i;
            r-i+1;
            while(l>=0 && r<n && s[l] == s[r]){
                int len = r-l+1;
                if(len > maxLen){
                    start = l;
                    maxLen = len;
                }
                l--;
                r++;
            }
        }
        return s.substr(start,maxLen);
}


int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << "Longest palindrom substring: " << longestPalindrome(s) << endl;
    return 0;
}
