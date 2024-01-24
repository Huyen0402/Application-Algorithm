#include <bits/stdc++.h>

using namespace std;

const int m = 1e9 + 7;
int n;
int arr[1000000];
int t_arr[1000000];

long long dnq(int start, int end) {
    if (start >= end - 1) {
        return 0;
    }

    int mid = (end + start) / 2;

    long long left_inversions = dnq(start, mid);
    long long right_inversions = dnq(mid, end);
    long long inversions = 0;

    int li = start, ri = mid, i = start;
    while (li < mid && ri < end) {
        if (arr[li] > arr[ri]) {
            t_arr[i++] = arr[ri++];
        } else {
            t_arr[i++] = arr[li++];
            inversions += ri - mid;
        }
    }

    while (li < mid) {
        inversions += ri - mid;
        t_arr[i++] = arr[li++];
    }
    while (ri < end) {
        t_arr[i++] = arr[ri++];
    }

    for (i = start; i < end; i++) {
        arr[i] = t_arr[i];
    }

    return left_inversions + right_inversions + inversions;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // freopen("input.txt", "r", stdin);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << dnq(0, n) % m;

    return 0;
}