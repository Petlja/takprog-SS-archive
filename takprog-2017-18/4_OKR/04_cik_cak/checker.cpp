// Petlja's grader before 2025 read the exit code as a score: < 0 wrong, 0 accepted (score 1), > 0 accepted
// with that score. Today's grader accepts only exit 0 and reads the score from stdout, so main below maps one to the
// other. The checker's own code is unchanged.
#define main legacy_main
#include <bits/stdc++.h>
using namespace std;

vector<int> read(istream& is) {
	vector<int> r;
	string s;
	while (is >> s) {
		int x;
		try {
			x = stoi(s);
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

	auto res = read(sol);

	int n, z;
	{
		auto v = read(in);
		n = v[0];
		z = v[1];
	}

	if (res[0] == -1) {
		if (a.empty()) {
			return -1;
		}
		if (a[0] == -1) {
			return 5;
		} else {
			return -1;
		}
	}

	if ((int)a.size() != n) {
		return -1;
	}

	if (accumulate(a.begin(), a.end(), 0ll) != z) {
		return -1;
	}

	if (a[0] != 0) {
		return -1;
	}

	for (int i=1; i<n; i++) {
		if (abs(a[i] - a[i-1]) != 1) {
			return -1;
		}
	}

	// identicno?
	if (equal(a.begin(), a.end(), res.begin())) {
		return 5;
	} else {
		return 3;
	}
}

#undef main
#include <cstdio>
int main(int argc, char *argv[])
{
    int r = legacy_main(argc, argv);
    if (r < 0) return 1;
    if (r > 0) printf("%d\n", r);
    return 0;
}
