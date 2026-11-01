// Petlja's grader before 2025 read the exit code as a score: < 0 wrong, 0 accepted (score 1), > 0 accepted
// with that score. Today's grader accepts only exit 0 and reads the score from stdout, so main below maps one to the
// other. The checker's own code is unchanged.
#define main legacy_main
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxN 100

int n;
ll a[maxN][maxN], b[maxN][maxN];

void swap_rows(int i, int j) {
	for (int k = 0; k < n; k++) {
		swap(b[i][k], b[j][k]);
	}
}

void swap_cols(int i, int j) {
	for (int k = 0; k < n; k++) {
		swap(b[k][i], b[k][j]);
	}
}

int main(int argc, char* argv[]) {
	ifstream outFile(argv[1]);
	ifstream solFile(argv[2]);
	ifstream inFile(argv[3]);

	ll low, high;
	inFile >> n >> low >> high;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			inFile >> a[i][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			inFile >> b[i][j];

	int m;
	outFile >> m;
	if (m > 2 * n * n)
		return -1;

	while (m--) {
		int x, y;
		string cmd;
		outFile >> cmd >> x >> y;
		if (x < 1 || x > n)
			return -1;
		if (y < 1 || y > n)
			return -1;
		
		x--;
		y--;
		
		if (cmd == "R")
			swap_rows(x, y);
		else if (cmd == "C")
			swap_cols(x, y);
		else
			return -1;
	}

	ll score = 0;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			score += a[i][j] * b[i][j];

	if (score <= low)
		return -1;

	if (score >= high)
		return 25;

	ll ret = 25 * (score - low) / (high - low);
	
	if (ret == 0)
		return -1; // mora ovako jer kad vratis 0 petlja ispise 1
	else
		return ret;
}

#undef main
#include <cstdio>
int main(int argc, char *argv[])
{
    int r = legacy_main(argc, argv);
    if (r < 0) return 1;
    if (r > 0) printf("%d\n", r);
    return 0;
}
