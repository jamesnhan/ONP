#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool IsOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

bool IsParenthesis(char c) {
    return c == '(' || c == ')';
}

bool IsValue(char c) {
    return !(IsOperator(c)) && !(IsParenthesis(c));
}

int GetPrecedence(char c) {
    if (c == '^') {
        return 0;
    } else if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    }
    return 3;
}

int main() {
    int t;
    cin >> t;
    while (t > 0) {
        stack<char> s = stack<char>();
        string input;
        char in;
        cin >> input;
        do {
            in = input.front();
            input.erase(0, 1);
            if (IsValue(in)) {
                cout << in;
            } else if (IsOperator(in)) {
                while (s.size() > 0 && GetPrecedence(in) > GetPrecedence(s.top())) {
                    cout << (char)s.top();
                    s.pop();
                }
                s.push(in);
            } else if (IsParenthesis(in)) {
                if (in == '(') {
                    s.push(in);
                } else if (in == ')') {
                    do {
                        in = s.top();
                        if (!IsParenthesis(in)) {
                            cout << in;
                            s.pop();
                        }
                    } while (in != '(');
                }
            }
        } while (input.length() > 0);
        while (s.size() > 0) {
            if (!IsParenthesis(s.top())) {
                cout << s.top();
            }
            s.pop();
        }
        cout << endl;
        --t;
    }
    return 0;
}
