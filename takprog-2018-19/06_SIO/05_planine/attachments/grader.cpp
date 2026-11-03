#include <cstdio>
#include "code.h"


static int n, k;
static int question_num = 0;
static int h[1001][1001];

int Pitaj(int i, int j) 
{
	question_num++;
	if ((i < 1) || (i > n)) return -1;
	if ((j < 1) || (j > n)) return -1;
	return h[i][j];
}

int main() 
{
	scanf("%d%d", &n, &k);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			scanf("%d", &h[i][j]);

	std::vector<int> out = Nadji(n, k);

	printf("%d %d %d\n", out[0], out[1], question_num);

	return 0;
}
