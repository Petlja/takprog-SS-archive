#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
	ifstream outFile(argv[1]);
	ifstream solFile(argv[2]);
	ifstream inFile(argv[3]); 

	// ucitaj ulaz
	long long a[4];
	inFile >> a[0] >> a[1] >> a[2];

	// pazljivo ucitaj takmicarski izlaz
	string s;
	outFile >> s;

	if (s.size() == 0 || s.size() > 11) {
		return -1; // predugacak string istampan
	}

	// proveri da li je zvanicno resenje -1
	string sol;
	solFile >> sol;

	if (sol == "-1") {
		return s == "-1" ? 0 : -1;
	}

	// zvanicno resenje nije -1, parsiraj takmicarev izlaz
	// takmicar ne sme da istampa minus

	long long val = 0;
	for (char x : s) {
		if (x < '0' || x > '9') {
			return -1;
		}
		val = 10*val + (x - '0');
	}

	// proveri da li je val ok resenje
	a[3] = val;

	if (val == 0) {
		return -1;
	}

	sort(a, a+4);
	long long d1 = a[1] - a[0];
	long long d2 = a[2] - a[1];
	long long d3 = a[3] - a[2];

	return (d1 == d2 && d2 == d3) ? 0 : -1;
}
