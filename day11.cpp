#include <bits/stdc++.h>
using namespace std;

int solve(string s, vector<string> &ans, int index)
{
    if (index >= s.length())
    {
        ans.push_back(s);
        return 1;
    }
    int count = 0;
    for (int i = index; i < s.length(); i++)
    {
        swap(s[index], s[i]);
        count += solve(s, ans, index + 1);
        swap(s[index], s[i]);
    }
    return count;
}

vector<string> find_permutations(string s)
{
    vector<string> ans;
    solve(s, ans, 0);
    sort(ans.begin(), ans.end());
    ans.erase(unique(ans.begin(), ans.end()), ans.end());
    return ans;
}


int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    vector<string> ans = find_permutations(s);
    cout << "The permutations of the string are: \n";
    for (auto x : ans)
        cout << x << "\n";
    return 0;
}
