#include <stdio.h>
#include "code.h"

# define MAXN 1010

int m, n, k, vv;
static int nq;
static int mat[MAXN][MAXN];

int DajVisinu(int i, int j) {
	nq++;
	if ((i < 1) || (i > n)) return -1;
	if ((j < 1) || (j > n)) return -1;
	return mat[i][j];
}

int main() {
	int i, j;
	int ians = -1, jans = -1;
	scanf("%d%d%d", &n, &k, &vv);

	for (i = 1; i <= n; i++)
		for (j = 1; j <= n; j++)
			scanf("%d", &mat[i][j]);
			
	Resi(n, k, vv, &ians, &jans);
    
	printf("%d %d %d\n", ians, jans, nq);

	return 0;
}
