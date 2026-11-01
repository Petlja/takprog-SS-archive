#include "code.h"

#include <cstdio>

int main() {
	int N;
	scanf("%d", &N);

	int* A = new int[N + 1];
	for (int i = 1; i <= N; ++i)
		scanf("%d", &A[i]);

	int Q;
	scanf("%d", &Q);

	int *T = new int[Q + 1];
	int *_T = new int[Q + 1];
	int *L = new int[Q + 1];
	int *R = new int[Q + 1];
	int *S = new int[Q + 1];

	for (int i = 1; i <= Q; ++i) {
		scanf("%d", &T[i]);
		_T[i] = T[i];
		if (T[i] == 1)
			scanf("%d %d %d", &L[i], &R[i], &S[i]);
		else
			scanf("%d %d", &L[i], &R[i]);
	}

	long long *O = new long long[Q + 1];
	Resi(N, A, Q, T, L, R, S, O);
	for (int i = 1; i <= Q; ++i)
		if (_T[i] == 1)
			printf("%lld\n", O[i]);

	delete[] A;
	delete[] T;
	delete[] _T;
	delete[] L;
	delete[] R;
	delete[] S;
	delete[] O;

	return 0;
}
