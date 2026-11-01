#include <bits/stdc++.h>
using namespace std;

vector<int> read(istream& is) {
	vector<int> r;
	string s;
	while (is >> s) {
		int x;
		if (s == "J") {
			r.push_back(0);
			continue;
		}
		if (s.size() >= 8) {
			return {};
		}
		try {
			x = stoi(s);
			if (x == 0) {
				return {};
			}
		} catch (...) {
			return {};
		}
		r.push_back(x);
	}
	return r;
}

int main(int argc, char** argv) {
	ifstream out(argv[1]);
	ifstream sol(argv[2]);
	ifstream in(argv[3]);

	auto a = read(out);

	int n, k;
	{
		auto a = read(in);
		n = a[0];
		k = a[1];
	}

	if ((int)a.size() != 2*n+k) {
		return -1;
	}

	vector<vector<int>> inv(n+1);

	for (int i=0; i<2*n+k; i++) {
		if (a[i] < 0 || a[i] > n) {
			return -1;
		}
		inv[a[i]].push_back(i);
	}

	for (int i=1; i<=n; i++) {
		if (inv[i].size() != 2) {
			return -1;
		}
		if (inv[i][1] - inv[i][0] != i+1) {
			return -1;
		}
	}

	// ovo nece nikad da se desi ali ok
	if ((int)inv[0].size() != k) {
		return -1;
	}
} 
