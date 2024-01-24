#include <bits/stdc++.h>

using namespace std;

int n = 0;
bool allValid = true;
map<string, int> callFromNumber;
map<string, int> callTimeFromNumber;

int calcCallTime(string start, string end) {
    int startInt = stoi(start.substr(0, 2)) * 3600 + stoi(start.substr(3, 2)) * 60 + stoi(start.substr(6, 2));
    int endInt = stoi(end.substr(0, 2)) * 3600 + stoi(end.substr(3, 2)) * 60 + stoi(end.substr(6, 2));
    return endInt - startInt;
}

bool validateNumber(string number) {
    if (number.size() != 10) {
        return false;
    }
    for (char digit : number) {
        if (digit > '9' || digit < '0') {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string q, q1, from, to, date, start, end;

    while (true) {
        cin >> q;
        if (q == "#") {
            break;
        }

        cin >> from >> to >> date >> start >> end;
        if (!validateNumber(from) || !validateNumber(to)) {
            allValid = false;
        }

        n++;
        if (callFromNumber.count(from)) {
            callFromNumber[from]++;
        } else {
            callFromNumber[from] = 1;
        }
        if (callTimeFromNumber.count(from)) {
            callTimeFromNumber[from] += calcCallTime(start, end);
        } else {
            callTimeFromNumber[from] = calcCallTime(start, end);
        }
    }

    while (true) {
        cin >> q1;
        if (q == "#") {
            break;
        }

        if (q == "?check_phone_number") {
            if (allValid) {
                cout << 1 << '\n';
            }
        } else if (q == "?number_calls_from") {
            cin >> from;
            cout << callFromNumber[from] << '\n';
        } else if (q == "?number_total_calls") {
            cout << n << '\n';
        } else {
            cin >> from;
            cout << callTimeFromNumber[from] << '\n';
        }
    }
}