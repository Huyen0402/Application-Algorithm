#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

bool isValid(const string& str) {
    int len = str.length();
    bool hasOperator = false;

    if (!isdigit(str[0])) {
        return false;
    }

    for (int i = 1; i < len; i++) {
        char c = str[i];

        if (!isdigit(c) && c != '+' && c != '*') {
            return false;
        }

        if (c == '+' || c == '*') {
            if (!isdigit(str[i - 1]) || !isdigit(str[i + 1])) {
                return false;
            }
            hasOperator = true;
        }
    }

    return hasOperator;
}

long long evaluateExpression(const string& str) {
    long long result = 0;
    string numberString;
    stack<long long> numbers;
    stack<char> operators;

    for (char c : str) {
        if (isdigit(c)) {
            numberString += c;
        } else if (c == '+' || c == '*') {
            numbers.push(stoll(numberString));
            numberString.clear();

            while (!operators.empty() && operators.top() == '*') {
                long long operand2 = numbers.top();
                numbers.pop();
                long long operand1 = numbers.top();
                numbers.pop();
                numbers.push((operand1 * operand2) % MOD);
                operators.pop();
            }

            operators.push(c);
        }
    }

    numbers.push(stoll(numberString));

    while (!operators.empty()) {
        long long operand2 = numbers.top();
        numbers.pop();
        long long operand1 = numbers.top();
        numbers.pop();

        if (operators.top() == '+') {
            numbers.push((operand1 + operand2) % MOD);
        } else if (operators.top() == '*') {
            numbers.push((operand1 * operand2) % MOD);
        }

        operators.pop();
    }

    result = numbers.top();

    return result;
}

int main() {
    string inputString;
    cin >> inputString;

    if (isValid(inputString)) {
        long long output = evaluateExpression(inputString);
        cout << output << endl;
    } else {
        cout << "NOT_CORRECT" << endl;
    }

    return 0;
}

