#include <iostream>
#include <cstdio>
#include "code.h"

using namespace std;


static int n, k;
static int L1, L2, M, I, J;
static int question_num = 0;
static int rowI[1000010];
static int colJ[1000010];
static int rand1[1000010], rand2[1000010];

int Pitaj(int i, int j)
{
	question_num++;
	if ((i < 1) || (i > n)) return -1;
	if ((j < 1) || (j > n)) return -1;
	if (i == I) return rowI[j];
	if (j == J) return colJ[i];

	long long ind = (long long)n * (long long)(i - 1) + j;

	long long val = (long long)rand1[ind % L1] * (ind % M) + rand2[ind % L2];
	int ret = (int)(val % M);
	if (ret <= 0) ret = M;
	if (ret > M) ret = 1;
	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    cin >> n >> k;
    cin >> L1 >> L2 >> M >> I >> J;

	// scanf("%d%d%d", &n, &k);
	// scanf("%d%d%d%d%d", &L1, &L2, &M, &I, &J);


	for (int i = 1; i <= n; i++)
		cin >> rowI[i];
		// scanf("%d", &rowI[i]);
	for (int j = 1; j <= n; j++)
		cin >> colJ[j];
		// scanf("%d", &colJ[j]);

	for (int i = 0; i < L1; i++)
		cin >> rand1[i];
		// scanf("%d", &rand1[i]);
	for (int i = 0; i < L2; i++)
		cin >> rand2[i];
		// scanf("%d", &rand2[i]);

	std::vector<int> out = Nadji(n, k);

	if ((int)out.size() >= 2)
		printf("%d %d %d\n", out[0], out[1], question_num);
	else
		printf("%d %d %d\n", -1, -1, question_num);

	return 0;
}
