#include <bits/stdc++.h>
using namespace std;

double dabs(double x) {
	return x < 0 ? -x : x;
}

int main(int argc, char** argv) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ifstream ouf(argv[1]);
	ifstream sof(argv[2]);
	ifstream inf(argv[3]);

	// sol fajl ima -1 ili neki nenegativan double
	double b;
	sof >> b;

	string ous;
	ouf >> ous;
	
	// ako takmicar nije ispisao string on ce biti prazan pa ce
	// kasnije svakako biti judgeovan kao nekorektan

	// necemo biti strogi, samo proveravamo prvi token sa izlaza

	if (b < 0) {
		// zvanicno resenje je -1
		// prvi token mora biti bas -1
		return ous == "-1" ? 0 : -1;
	} else {
		// parsujemo double
		try {
			double a = stod(ous);
			return ((b > 0 && dabs(a-b) / b < 1e-6) || dabs(a-b) < 1e-6) ? 0 : -1;
		} catch (...) {
			return -1;
		}
	}

	return -1;
}
