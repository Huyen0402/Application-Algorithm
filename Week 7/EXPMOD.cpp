#include <bits/stdc++.h>

using namespace std;

#define ULL unsigned long long
#define P 1000000007

ULL exp(ULL a, ULL b) {
	if(b == 0) return 1;
	ULL T = exp(a, b/2);
	T = (T * T) % P;
	if(b % 2 == 1) T = (T * (a % P)) % P;
	return T;
}

int main() {
	ULL a, b;
	cin >> a >> b;
	ULL res = exp(a, b);
	cout << res;
	return 0;
}
