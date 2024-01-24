#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1e9 + 7;

long long calculateExpression(vector<long long>& a, vector<int>& b) {
    stack<long long> numbers;
    long long res = 0;

    numbers.push(a[0]);

    for (int i = 1; i < a.size(); i++) {
        if (b[i - 1] == 0) {
            numbers.push(-a[i]);
        } else if (b[i - 1] == 1) {
            numbers.push(a[i]);
        } else if (b[i - 1] == 2) {
            long long operand = numbers.top();
            numbers.pop();
            numbers.push((operand * a[i]) % MOD);
        }
    }

    while (!numbers.empty()) {
        long long operand = numbers.top();
        numbers.pop();

        res = (res + operand) % MOD;
    }

    return res;
}

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> b[i];
    }

    long long result = calculateExpression(a, b);
    cout << result << endl;

    return 0;
}
