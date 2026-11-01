#include "code.h"

#include <cstdio>
#include <cstdlib>
#include <vector>

using namespace std;

namespace {
	const int MAX_N=1010;
	bool jeLazov[MAX_N];
	bool bio[MAX_N];
	int n, q, nq;
}

bool Pitaj(int x, vector<int> s) {
	++nq;
	if (nq > q)
		exit(1);

	if (x < 1 || x > n)
		exit(1);

	int brojLazova = 0;
	for (int osoba : s) {
		if (osoba < 1 || osoba > n)
			exit(1);
		if (bio[osoba])
			exit(1);
		if (jeLazov[osoba])
			++brojLazova;
		bio[osoba] = true;
	}
	for (int osoba : s) {
		bio[osoba] = false;
	}

	if (jeLazov[x])
		return !(brojLazova % 2 == 1);
	else
		return (brojLazova % 2 == 1);
}

int main() {
	scanf("%d %d", &n, &q);
	char *s = new char[n + 2];
	scanf(" %s", s + 1);
	for (int i = 1; i <= n; ++i)
		jeLazov[i] = (s[i] == '1');
	int lazov = NadjiLazova(n, q);
	printf("%d\n", lazov);
	return 0;
}
