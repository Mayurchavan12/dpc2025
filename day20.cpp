#include <bits/stdc++.h>
using namespace std;


void InsertInSort(stack<int> &s, int num) {
    if (s.empty() || s.top() <= num) {
        s.push(num);
        return;
    }
    int n = s.top();
    s.pop();
    InsertInSort(s, num);
    s.push(n);
}

void sortStack(stack<int> &s) {
    if (s.empty()) {
        return;
    }
    int num = s.top();
    s.pop();
    sortStack(s);
    InsertInSort(s, num);
}

int main() {
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

    sortStack(s);

    vector<int> sortedElements;
    while (!s.empty()) {
        sortedElements.push_back(s.top());
        s.pop();
    }

    reverse(sortedElements.begin(), sortedElements.end());

    cout << "Sorted stack in ascending order: ";
    for (int num : sortedElements) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
