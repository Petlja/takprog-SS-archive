#include <bits/stdc++.h>
#include "code.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, q;
	cin >> n >> q;

	Pocetak(n);
	while (q--) {
		int t, p, k;
		cin >> t >> p >> k;
		if (t == 1)
			DodajBombonice(p, k);
		else
			cout << Prebroji(p, k) << '\n';
	}
}