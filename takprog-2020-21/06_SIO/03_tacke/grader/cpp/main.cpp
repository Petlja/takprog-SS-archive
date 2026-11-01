#include <stdio.h>

void Resi(int N, int Px, int Py, int *X, int *Y, int Q, int *L, int *R, bool *O);

int main(){
	int N, Px, Py;
	scanf("%i %i %i", &N, &Px, &Py);

	int *X = new int[N+1], *Y = new int[N+1];
	for(int i = 1; i <= N; i++){
		scanf("%i %i", &X[i], &Y[i]);
	}

	int Q;
	scanf("%i", &Q);

	int *L = new int[Q+1], *R = new int[Q+1];
	for(int i = 1; i <= Q; i++){
		scanf("%i %i", &L[i], &R[i]);
	}

	bool *O = new bool[Q+1];

	Resi(N, Px, Py, X, Y, Q, L, R, O);

	for(int i = 1; i <= Q; i++){
		if(O[i]){
			printf("Da\n");
		}else{
			printf("Ne\n");
		}
	}

	delete[] X;
	delete[] Y;
	delete[] L;
	delete[] R;
	delete[] O;

	return 0;
}
