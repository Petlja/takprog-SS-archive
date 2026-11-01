#include <stdio.h>

void Resi(int N, int *A, int M, int *U, int *V, int *W, int *R);

int main(){
	int N, M;
	scanf("%i %i", &N, &M);

	int *A = new int[N + 1];
	for(int i = 1; i <= N; i++){
		scanf("%i", &A[i]);
	}

	int *U = new int[M + 1], *V = new int[M + 1], *W = new int[M + 1];
	for(int i = 1; i <= M; i++){
		scanf("%i %i %i", &U[i], &V[i], &W[i]);
	}

	int *R = new int[N + 1];
	Resi(N, A, M, U, V, W, R);

	for(int i = 1; i <= N; i++){
		printf("%i ", R[i]);
	}
	printf("\n");

	delete[] A;
	delete[] U;
	delete[] V;
	delete[] W;
	delete[] R;

	return 0;
}
