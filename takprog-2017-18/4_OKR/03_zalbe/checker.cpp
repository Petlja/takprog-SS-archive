// Petlja's grader before 2025 read the exit code as a score: < 0 wrong, 0 accepted (score 1), > 0 accepted
// with that score. Today's grader accepts only exit 0 and reads the score from stdout, so main below maps one to the
// other. The checker's own code is unchanged.
#define main legacy_main
#include <cstdlib>
#include <cstdio>

const int MAX_N = 200010;

int p[MAX_N], pSol[MAX_N];
char s[MAX_N];
bool mark[MAX_N];

int main(int argc, char **argv)
{
	FILE* fout = fopen(argv[1], "r");
	FILE* fsol = fopen(argv[2], "r");
	FILE* fin = fopen(argv[3], "r");

	// Podaci iz in fajla
	int n, k;
	fscanf(fin, "%d%d", &n, &k);
	fscanf(fin, "%s", s + 1);
	fclose(fin);

	// Podaci iz sol fajla
	for (int i = 1; i <= n; i++)
		fscanf(fsol, "%d", &pSol[i]);
	fclose(fsol);

	// Ucitavanje iz out fajla
	for (int i = 1; i <= n; i++)
	{
		if (!feof(fout))
		{
			fscanf(fout, "%d", &p[i]);
		}
		else // nema dovoljno brojeva
		{
			fclose(fout);
			return -1;
		}
	}
	fclose(fout);

	// provera da li su brojevi iz [1, n] i da li je u pitanju permutacija
	for (int i = 1; i <= n; i++) mark[i] = false;
	for (int i = 1; i <= n; i++)
	{
		if (p[i] < 1 || p[i] > n)
			return -1; // broj nije iz [1, n];
		if (mark[p[i]])
			return -1; // nije permutacija, ponavljanje broja p[i]
		mark[p[i]] = true;
	}

	// provera da li je resenje identicno optimalnom
	bool maxPoints = true;
	for (int i = 1; i <= n; i++)
		maxPoints = maxPoints && (p[i] == pSol[i]);
	if (maxPoints)
		return 5; // takmicar osvaja 100% poena

	// provera da li je resenje u skladu sa bacanjem novcica
	for (int i = 1; i < n; i++)
	{
		if (s[i] == 'P' && p[i + 1] > p[i]) // treblo ulevo a nije
			return -1;
		if (s[i] == 'G' && p[i + 1] < p[i]) // trebalo udesno a nije
			return -1;
	}

	return 3;
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
