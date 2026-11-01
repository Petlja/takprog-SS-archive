#include <bits/stdc++.h>
#include "code.h"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, q, v;
	cin >> n >> m >> q >> v;

	// ucitaj matricu
	int** a = new int*[n+1];
	int* b = new int[v+1];

	for (int i=1; i<=n; i++) {
		a[i] = new int[m+1];
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
		}
	}

	for (int i=1; i<=v; i++)
		cin >> b[i];

	int* x1 = new int[q+1];
	int* x2 = new int[q+1];
	int* y1 = new int[q+1];
	int* y2 = new int[q+1];

	int q1 = 0;

	for (int i=1; i<=q; i++) {
		int t;
		cin >> t;
		if (t == 1) { // pravougaonik
			q1++;
			cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		} else {
			cin >> x1[i] >> y1[i] >> x2[i];
			y2[i] = -1;
		}
	}

	int* o = new int[q1+1];

	Resi(n, m, q, v, a, b, x1, y1, x2, y2, o);

	for (int i=1; i<=q1; i++)
		cout << o[i] << '\n';

	// delete[] opcion ali u krajnjoj liniji nepotreban
}