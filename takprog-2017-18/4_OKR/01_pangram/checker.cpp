#include <bits/stdc++.h>
#define OK 0
#define WA -1
#define MAXN 255
using namespace std;

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ifstream outf(argv[1]);
	ifstream solf(argv[2]);
	ifstream inf(argv[3]);

	int N;
	string out, sol, in;
	outf >> out;
	solf >> sol;
	inf >> N >> in;
	if (out == "SAN" && sol == "SAN") {
		return OK;
	} else if (out == "SAN" || sol == "SAN") {
		// mismatch
		return WA;
	}
	if (out.size() != N) {
		// wrong length
		return WA;
	}
	unordered_map<char, int> cnt;
	for (int i = 0; i < N; i++) {
		if (in[i] != '?' && in[i] != out[i]) {
			// does not align with input
			return WA;
		}
		// branch on char type
		if (out[i] >= 'a' && out[i] <= 'z') {
			// letter
			cnt[out[i]]++;
		} else if (out[i] == '_') {
			// space
			if (i == 0 || i == N-1 || out[i-1] == '_') {
				// invalid space placement
				return WA;
			}
		} else {
			// invalid char
			return WA;
		}
	}
	for (char c = 'a'; c <= 'z'; c++) {
		if (cnt[c] != 1) {
			// not a perfect pangram
			return WA;
		}
	}
	// ok
	return OK;
}
