#include <bits/stdc++.h>

using namespace std;

int checkPhoneNumber (string num) {
    if(num.length() != 10) return 0;
    for(int i = 0; i < 10; i++) {
        if(num[i] > '9' || num[i] < '0')
            return 0;
    }

    return 1;
}

int countTime(string ftime, string etime) {
    int startTime = 3600 * ((ftime[0] - '0') * 10 + ftime[1] - '0') + 60 * ((ftime[3] - '0') * 10 + ftime[4] - '0') + (ftime[6] - '0') * 10 + ftime[7] - '0';
    int endTime = 3600 * ((etime[0] - '0') * 10 + etime[1] - '0') + 60 * ((etime[3] - '0') * 10 + etime[4] - '0') + (etime[6] - '0') * 10 + etime[7] - '0';
    return endTime - startTime;
}

map<string, int> numberCalls, timeCall;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string type;
    int totalCalls = 0;
    int incorrectPhone = 0;
    do {
        cin >> type; // call or #
        if(type == "#") 
            continue;
        ++totalCalls; //truy van 3
        string fnum, tnum, date, ftime, etime;
        cin >> fnum >> tnum >> date >> ftime >> etime;
        if(!checkPhoneNumber(fnum) || !checkPhoneNumber(tnum))
            ++incorrectPhone; //truy van 1
        numberCalls[fnum]++; //truy van 2
        timeCall[fnum] += countTime(ftime, etime); //truy van 4
    } while (type != "#");

    type = "";
    
    do {
        cin >> type;
        string inNum;
        if(type == "#") 
            break;
        if(type == "?check_phone_number") {
            if(incorrectPhone == 0) {
                cout << 1 << "\n";
            } else {
                cout << 0 << "\n";
            }
        } else if(type == "?number_calls_from") {
            cin >> inNum;
            cout << numberCalls[inNum] << "\n";
        } else if(type == "?number_total_calls") {
            cout << totalCalls << "\n";
            continue;
        } else if(type == "?count_time_calls_from") {
            cin >> inNum;
            cout << timeCall[inNum] << "\n";
        }
    } while(type != "#");

    return 0;
}
 if(code == "MAX_UNRELATED_PEOPLE") {
            int num3 = 0;
            for(int j = 0; j < i; j++) {
                if(father_code_array[j] == "0000000" && mother_code_array[j] == "0000000") {
                    num3++;
                }
            }
            cout << num3 << "\n";
        }
int checkCode(string code) {
    for(int j = 0; j < 7; j++) {
        if(code[j] == '0') return 1;
    }
    return 0;
}