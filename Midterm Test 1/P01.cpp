//C++11
#include <iostream>
#include <string>
#include <cctype>

bool isValid(const std::string& str) {
    int len = str.length();
    bool hasOperator = false;

    if (!isdigit(str[0])) {
        return false;
    }

    for (int i = 1; i < len; i++) {
        char c = str[i];

        if (!isdigit(c) && c != '+') {
            return false;
        }

        if (c == '+') {
            if (!isdigit(str[i - 1]) || !isdigit(str[i + 1])) {
                return false;
            }
            hasOperator = true;
        }
    }

    return hasOperator;
}

int evaluateExpression(const std::string& str) {
    int result = 0;
    std::string numberString;

    for (char c : str) {
        if (isdigit(c)) {
            numberString += c;
        } else if (c == '+') {
            // std::cout << numberString << std::endl;
            result += std::stoi(numberString);
            numberString.clear();
        }
    }
    result += std::stoi(numberString);

    return result;
}

int main() {
    std::string inputString;
    std::cin >> inputString;

    if (isValid(inputString)) {
        int output = evaluateExpression(inputString);
        std::cout << output << std::endl;
    } else {
        std::cout << "NOT_CORRECT" << std::endl;
    }

    return 0;
}

