#include <iostream>
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
        char line[100];
        char in;
        int i = 0;
        cin.getline(line, 100, '\n');
        cin.getline(line, 100, '\n');
        cout << "Input " << line << endl;
        do {
            in = line[i++];
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
                        in = line[i++];
                        if (!IsParenthesis(in)) {
                            cout << in;
                        }
                    } while (in != '(');
                }
            }
        } while (in != '\n' && in != '\0');
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
