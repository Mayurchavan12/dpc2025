#include<bits/stdc++.h>
using namespace std;

void sorted(stack<int> &s, int temp) {
    if (s.empty() || temp > s.top()) {
        s.push(temp);
        return;
    }
    int val = s.top();
    s.pop();
    sorted(s, temp);
    s.push(val);
}

void inserted(stack<int> &s) {
    if (s.empty()) {
        return;
    }
    int temp = s.top();
    s.pop();
    inserted(s);
    sorted(s, temp);
}

int main(){
    stack<int> s;

    cout << "Enter number of elements in stack: ";
    int n;
    cin >> n;
    cout << "Enter elements of stack: ";
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        s.push(x);
    }   

    inserted(s);
    cout << "Reversed stack is: ";
    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}
