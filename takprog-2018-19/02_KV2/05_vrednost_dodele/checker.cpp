#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {
	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);

	string sol, out;

	sof >> sol;
	ouf >> out;

	return sol == out ? 0 : -1;
}
