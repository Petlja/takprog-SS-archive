#include <stdio.h>

void Resi(int N, int Q, int P, int *U1, int *V1, int *U2, int *V2, int *A1, int *B1, int *C1, int *D1, int *R);

int main(){
	int N, Q, P;
	scanf("%i %i %i", &N, &Q, &P);

	int *U1 = new int[N], *V1 = new int[N];
	for(int i = 1; i <= N-1; i++){
		scanf("%i %i", &U1[i], &V1[i]);
	}

	int *U2 = new int[N], *V2 = new int[N];
	for(int i = 1; i <= N-1; i++){
		scanf("%i %i", &U2[i], &V2[i]);
	}

	int *A1 = new int[Q+1], *B1 = new int[Q+1], *C1 = new int[Q+1], *D1 = new int[Q+1];
	for(int i = 1; i <= Q; i++){
		scanf("%i %i %i %i", &A1[i], &B1[i], &C1[i], &D1[i]);
	}

	int *R = new int[Q+1];
	Resi(N, Q, P, U1, V1, U2, V2, A1, B1, C1, D1, R);

	for(int i = 1; i <= Q; i++){
		printf("%i\n", R[i]);
	}

	delete[] U1;
	delete[] V1;
	delete[] U2;
	delete[] V2;
	delete[] A1;
	delete[] B1;
	delete[] C1;
	delete[] D1;
	delete[] R;

	return 0;
}
