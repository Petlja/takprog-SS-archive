#include <bits/stdc++.h>
#include "code.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string a;
	int m;
	vector<string> b;

	cin >> a >> m;
	b.resize(m);
	for (auto& s : b)
		cin >> s;

	int n = a.size();
	char* A = new char[n+2];
	A[0] = A[n+1] = 0;
	copy(a.begin(), a.end(), A+1);

	char** B = new char*[m+1];
	int* L = new int[m+1];

	for (int i=1; i<=m; i++) {
		L[i] = b[i-1].size();
		B[i] = new char[L[i] + 2];
		B[i][0] = B[i][L[i]+1] = 0;
		copy(b[i-1].begin(), b[i-1].end(), B[i]+1);
	}

	cout << Resi(n, A, m, L, B) << '\n';
}