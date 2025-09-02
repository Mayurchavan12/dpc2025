#include<bits/stdc++.h>
using namespace std;

int evaluatePostfix(const string &expression) {
    stack<int> s;
    istringstream iss(expression);
    string token;

    while (iss >> token) {
        if (isdigit(token[0]) || (token.size() > 1 && token[0] == '-')) {
            s.push(stoi(token));
        } else {
            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result;

            switch (token[0]) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break; 
            }
            s.push(result);
        }
    }
    return s.top();
}


int main() {
    string expression;
    cout << "Enter a postfix expression: ";
    getline(cin, expression);

    int result = evaluatePostfix(expression);
    cout << "Result: " << result << endl;

    return 0;
}
