#include<bits/stdc++.h>

using namespace std; 

const int N = 100;
int n, k, m;
int a[N];
int Q = 0, ans;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

	//Cau hinh
    string first_number;
    string last_number;
	//Sinh cac cau hinh
    for(int i = 1; i <= k; i++) {
        first_number += (i + 48); // Cong 48 de chuyen tu int sang char trong bang ascii
        last_number += (n - k + i + 48);//Dung toan de ra bieu thuc
    }
    // //In ra cau hinh dau tien
    // cout << first_number << endl;

    
    for(int i = 1; i <= k; i++) {
            ans += a[i];
        }
    if(ans == m) {
        Q = 1;
        ans = 0;
    }

    //Thuat toan
    while(first_number != last_number){
        for(int i = k - 1; i >= 0; i--){
            if(first_number[i] < last_number[i]){
                first_number[i] = first_number[i] + 1;
                for(int j = i + 1; j < k; j++){
                    first_number[j] = first_number[j - 1] + 1;
                }
                break;//Sau khi tang 1 don vi thanh cong => ra 1 cau hinh => break
            }
        }

        for(int i = 0; i < k; i++) {
            ans += a[first_number[i] - 48];
        }
        if(ans == m) Q += 1;
        ans = 0;
       
        
    }

    cout << Q << endl;
    return 0;
}