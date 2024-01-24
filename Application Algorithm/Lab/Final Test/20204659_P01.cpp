#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
struct dateInt{
    int year;
    int month;
    int day;
};

int peopleBornAtDate(string date, string inputDate) {
    if(date == inputDate) return 1;
    return 0;
}  

dateInt converseDate(string date) {
    int dateYear = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0');
    int dateMonth = (date[5]-'0')*10 + (date[6]-'0');
    int dateDay = (date[8]-'0')*10 + (date[9]-'0');
    return {dateYear, dateMonth, dateDay};
}

int peopleBornBetweenDate(string date, string startDate, string endDate) {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
    string code;
    string date[N];
    string fatherCode[N];
    string motherCode[N];
    int i = 0;
    int numberPeople = 0;
    do {
        cin >> code; 
        if(code == "*") 
            break;

        string date_of_birth, father_code, mother_code, is_alive, region_code;
        cin >>  date_of_birth >> father_code >> mother_code >> is_alive >> region_code;
        date[i] = date_of_birth;
        fatherCode[i] = father_code;
        motherCode[i] = mother_code;
        i++;
        numberPeople++; 
    } while (code != "*");

    code = "";

    do {
        string inputDate;
        string date1, date2;
        cin >> code;
        int num = 0;
        if(code == "***") break;
        if(code == "NUMBER_PEOPLE") { // truy van 1
            cout << numberPeople << "\n";
        }

        if(code == "NUMBER_PEOPLE_BORN_AT") { // truy van 2
            cin >> inputDate;
            for(int j = 0; j < i; j++) {
                if(peopleBornAtDate(date[j], inputDate)) {
                    num += 1;
                }
            }
            cout << num << "\n";
        }

        if(code == "NUMBER_PEOPLE_BORN_BETWEEN") {
            int num2 = 0;
            cin >> date1 >> date2;
            dateInt date1out = converseDate(date1); dateInt date2out = converseDate(date2);
            for(int j = 0; j < i; j++) {
                dateInt dateout = converseDate(date[j]);
                if(date1out.year == date2out.year &&  date1out.month == date2out.month && date1out.day <= dateout.day && dateout.day <= dateout.day) {
                    num2++;
                } else {
                    if(date1out.year == date2out.year && date1out.month <= dateout.month && dateout.month <= date2out.month) {
                        num2++;
                    } else if (date1out.year <= dateout.year && dateout.year <= date2out.year) {
                        num2++;
                    }
                }
            }
            cout << num2 << "\n";
        }

        if(code == "MAX_UNRELATED_PEOPLE") {
            int num3 = 0;
            for(int j = 0; j < i; j++) {
                if(fatherCode[j] == "0000000" && motherCode[j] == "0000000") {
                    num3++;
                }
            }
            cout << num3 << "\n";
        }

    } while (code != "*");

    return 0;
}
    
