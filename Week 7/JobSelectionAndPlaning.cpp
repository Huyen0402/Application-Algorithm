#include <bits/stdc++.h>

using namespace std;

struct Job {
    int deadline;
    int profit;
};

bool sortByProfit(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

int findAvailableSlot(vector<bool>& slots, int deadline) {
    for (int i = deadline; i > 0; i--) {
        if (!slots[i]) {
            return i;
        }
    }
    return -1;
}

int scheduleJobs(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), sortByProfit);
    
    vector<bool> slots(100001, false); // Maximum possible deadline
    
    int totalProfit = 0;
    for (int i = 0; i < jobs.size(); i++) {
        int slot = findAvailableSlot(slots, jobs[i].deadline);
        if (slot != -1) {
            slots[slot] = true;
            totalProfit += jobs[i].profit;
        }
    }
    
    return totalProfit;
}

int main() {
    int n;
    cin >> n;
    
    vector<Job> jobs(n);
    for (int i = 0; i < n; i++) {
        cin >> jobs[i].deadline >> jobs[i].profit;
    }
    
    int maxProfit = scheduleJobs(jobs);
    cout << maxProfit << endl;
    
    return 0;
}
