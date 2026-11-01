#include <cstdlib>
#include <cstdio>
#include "code.h"

static int n;
static int a[500005];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int sol = TamanPodela(n, a);

	printf("%d\n", sol);
	return 0;
}