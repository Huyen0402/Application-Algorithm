#include <bits/stdc++.h> 

using namespace std;

void generateBinarySequence(int n, string seq) {
	if(seq.length() == n) {
		cout << seq << endl;
		return;
	}
	
	generateBinarySequence(n, seq + "0");
	generateBinarySequence(n, seq + "1");
}

int main() {
	int n;
	cin >> n;
	generateBinarySequence(n, "");
	
	return 0;
}
