#include<bits/stdc++.h>

using namespace std;

#define N 10000000
char E[N];

bool match(char O, char C) {
	if(O == '(' && C == ')') return true;
	if(O == '[' && C == ']') return true;
	if(O == '{' && C == '}') return true;
	return false;
}

bool check(char* E) {
	int n = strlen(E);
	stack<char> S;
	for (int i = 0; i < n; i++) {
		if(E[i] == '(' || E[i] == '[' || E[i] == '{') {
			S.push(E[i]);
		} else {
			if(S.empty()) return false;
			char O = S.top(); S.pop();
			if(!match(O, E[i])) return false;
		}
	}
	return S.empty();
}

int main() {
	cin >> E;
	
	int res = check(E) ? 1 : 0;
	cout << res;
	
	return 0;
}
