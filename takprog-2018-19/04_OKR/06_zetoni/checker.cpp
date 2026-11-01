#include <bits/stdc++.h>
using namespace std;

#define cin blabla
#define cout blablabaklldf

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef pair<int, int> pii;

bool has_extra_tokens(ifstream& ifs) {
	string s;
	ifs >> s;
	return s.size() != 0;
}

int read_int_8(ifstream& ifs) {
	string s;
	ifs >> s;
	if (s.size() == 0 || s.size() > 8)
		exit(-1);
	int z = 0;
	for (char x : s) {
		if ('0' <= x && x <= '9')
			z = 10*z + x - '0';
		else
			exit(-1);
	}
	return z;
}

int main(int argc, char** argv) {
	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);

	string sol, out;

	sof >> sol;
	ouf >> out;

	if (sol != out)
		return -1;

	if (sol != "-1") {
		int n;
		inf >> n;
		multiset<pii> s_target, s_user = {{1, 1}};

		int t = stoi(sol);

		for (int i=0; i<n; i++) {
			int x, y;
			inf >> x >> y;
			if (i < t)
				s_target.insert({x, y});
		}

		for (int j=0; j<t-1; j++) {
			int x = read_int_8(ouf);
			int y = read_int_8(ouf);

			auto it = s_user.find({x, y});
			if (it == s_user.end())
				return -1;

			s_user.erase(it);
			s_user.insert({x+1, y});
			s_user.insert({x, y+1});
		}

		if (has_extra_tokens(ouf))
			return -1;

		return s_target == s_user ? 0 : -1;
	}

	if (has_extra_tokens(ouf))
		return -1;
}
