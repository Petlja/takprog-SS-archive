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

	auto takmicar = read(out);
	auto resenje = read(sol);
	auto ulaz = read(in);

	// takmicar ne sme da pokusava da odstampa jos nesto preko
	// (mada ovo ce da prihvati ako ima vodece nule bez razmaka,
	// sto je ok)
	if (takmicar.size() != 3)
		return -1;

	// resenje mora da se poklopi
	if (takmicar[0] != resenje[0])
		return -1;
	if (takmicar[1] != resenje[1])
		return -1;

	// broj poteza < 1 je sumnjiva rabota i ne prihvata se!
	if (takmicar[2] < 1 || takmicar[2] > ulaz[1])
		return -1;

	// sve ok
	return 0;
}
