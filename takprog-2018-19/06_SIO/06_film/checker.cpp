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

int num_occ(string needle, string haystack) {
	int z = 0;
	for (int i=0; i+(int)needle.size()<=(int)haystack.size(); i++) {
		if (equal(needle.begin(), needle.end(), haystack.begin() + i)) {
			z++;
		}
	}
	return z;
}

int main(int argc, char** argv) {
	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);

	int n, k;
	inf >> n >> k;
	vector<string> a(n);
	for (int i=0; i<n; i++) {
		inf >> a[i];
	}

	int sol;
	sof >> sol;

	if (sol == -1) {
		string s;
		ouf >> s;
		if (s != "-1")
			return -1;
		if (has_extra_tokens(ouf))
			return -1;
		return 0;
	} else {
		int user_out = read_int_8(ouf);
		if (user_out != sol) 
			return -1;
		string s;
		ouf >> s;
		if ((int)s.size() != sol)
			return -1;
		for (char x : s) {
			int y = (int)x - 'a';
			if (y < 0 || y >= k)
				return -1;
		}
		for (auto b : a)
			if (num_occ(b, s) != 1)
				return -1;
		return 0;
	}
}
