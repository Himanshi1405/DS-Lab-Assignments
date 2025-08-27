//Write a program that checks if an expression has balanced parentheses.

#include <bits/stdc++.h>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;

    for (char ch : str) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } 
        if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty()) {
                return false;
            }
            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; 
            }
        }
    }

    return s.empty();
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    if (isBalanced(str)) {
        cout << "Expression is Balanced" << endl;
    } else {
        cout << "Expression is Not Balanced" << endl;
    }

    return 0;
}
