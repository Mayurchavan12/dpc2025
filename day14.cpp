#include <bits/stdc++.h>
using namespace std;

int countDist(string s, int k){
    int n = s.size();

    int res = 0;

    int cnt[26];

    for(int i=0; i<n; i++){
        int dist_count = 0;
        memset(cnt, 0, sizeof(cnt));

        for(int j=i; j<n; j++){
            if(cnt[s[j] - 'a'] == 0){
                dist_count++;
            }
            cnt[s[j] - 'a']++;

            if(dist_count == k){
                res++;
            }
        }
    }
    return res;
}


int main(){
    string s;
    int k;

    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the value of k: ";
    cin >> k;

    int result = countDist(s, k);
    cout << "Number of substrings with exactly " << k << " distinct characters: " << result << endl;
    return 0;
}
