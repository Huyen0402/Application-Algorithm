#include <bits/stdc++.h>

using namespace std;

bool isCorrectExpression(const string& expression) {
    stack<char> brackets;
    map<char, char> matchingBrackets;
    matchingBrackets['('] = ')';
    matchingBrackets['['] = ']';
    matchingBrackets['{'] = '}';

    for (size_t i = 0; i < expression.length(); i++) {
        char c = expression[i];
        if (c == '(' || c == '[' || c == '{') {
            brackets.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (brackets.empty() || matchingBrackets[brackets.top()] != c) {
                return false;
            }
            brackets.pop();
        }
    }

    return brackets.empty();
}

int main() {
    string expression;
    getline(cin, expression);

    int result = isCorrectExpression(expression) ? 1 : 0;
    cout << result << endl;

    return 0;
}
