#include <bits/stdc++.h>

using namespace std;

int ans == 0;

void generateBinarySeq(int n, string seq) {
	if(n == 0) {
		ans ++;
		return; 
	}
	
	generateBinarySeq(n - 1, seq + '0');
	if(seq.empty() || seq[seq.length() - 1] != '1') generateBinarySeq(n - 1, seq + '1');
}

int main() {
	int n; cin >> n;
	
	generateBinarySeq(n, "");
	
	return 0;
}
