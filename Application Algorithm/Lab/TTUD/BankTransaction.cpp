#include <bits/stdc++.h>

using namespace std;

struct transaction {
    string account;
    string time_point;
};

int transactions_cnt = 0, total_money = 0;
set<string> accounts;
map<string, int> money_from;
map<string, vector<transaction>> transaction_from, transaction_to;

// bool inspect_cycle(string inspected_account, string from_account, string from_time, int count, map<string, vector<transaction>>& transaction_from) {
//     if (count == 0) {
//         for (transaction transaction : transaction_from[from_account]) {
//             if (transaction.account == inspected_account) {
//                 return true;
//             }
//         }
//         return false;
//     }

//     for (transaction transaction : transaction_from[from_account]) {
//         if (from_time < transaction.time_point) {
//             if (inspect_cycle(inspected_account, transaction.account, transaction.time_point, count - 1, transaction_from)) {
//                 return true;
//             }
//         }
//     }
//     return false;
// }

// set<string> get_cycle_starts(string account, int count, string time_point) {
//     if (count == 0) {
//         return { account };
//     }

//     set<string> ans;
//     for (transaction t : transaction_to[account]) {
//         if (t.time_point < time_point) {
//             set<string> accounts = get_cycle_starts(t.account, count - 1, t.time_point);
//             ans.insert(accounts.begin(), accounts.end());
//         }
//     }
//     return ans;
// }

bool check_cycle_end(string account, int count, string start, set<string>& visit) {
    if (count == 0) {
        return start == account;
    }

    for (transaction t : transaction_from[account]) {
        if (visit.count(t.account)) {
            continue;
        }
        visit.insert(t.account);
        if (check_cycle_end(t.account, count - 1, start, visit)) {
            return true;
        }
        visit.erase(t.account);
    }
    return false;
}

bool in_cycle(string inspected_account, int cycle_length) {
    set<string> visit;
    if (check_cycle_end(inspected_account, cycle_length, inspected_account, visit)) {
        return true;
    }

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string q, from_account, to_account, time_point, atm;
    int money, cycle_length;
    while (true) {
        cin >> from_account;
        if (from_account == "#") {
            break;
        }

        cin >> to_account >> money >> time_point >> atm;
        transactions_cnt++;
        total_money += money;
        accounts.insert(from_account);
        accounts.insert(to_account);
        if (money_from.count(from_account)) {
            money_from[from_account] += money;
        } else {
            money_from[from_account] = money;
        }

        if (from_account != to_account) {
            transaction_from[from_account].push_back({ to_account, time_point });
            transaction_to[to_account].push_back({ from_account, time_point });
        }
    }

    while (true) {
        cin >> q;
        if (q == "#") {
            break;
        }

        if (q == "?number_transactions") {
            cout << transactions_cnt << '\n';
        } else if (q == "?total_money_transaction") {
            cout << total_money << '\n';
        } else if (q == "?list_sorted_accounts") {
            for (string account : accounts) {
                cout << account << " ";
            }
            cout << '\n';
        } else if (q == "?total_money_transaction_from") {
            cin >> from_account;
            cout << money_from[from_account] << '\n';
        } else {
            cin >> from_account >> cycle_length;
            cout << (int)in_cycle(from_account, cycle_length) << '\n';
        }
    }
}