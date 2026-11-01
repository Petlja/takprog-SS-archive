#include <iostream>
using namespace std;

void Resi(int N, int R, int C, int Q, int** U, int** V, int** W,
	int* X1, int* Y1, int* X2, int* Y2, int* O);

static int** matrica(int R, int C) {
	int** a = new int*[R+1];
	for (int i=1; i<=R; i++)
		a[i] = new int[C+1];
	return a;
}

static void pocisti(int** a, int R) {
	for (int i=1; i<=R; i++)
		delete[] a[i];
	delete a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, R, C, Q;
	cin >> N >> R >> C >> Q;

	int** U = matrica(R, C);
	int** V = matrica(R, C);
	int** W = matrica(R, C);

	int* X1 = new int[Q+1];
	int* Y1 = new int[Q+1];
	int* X2 = new int[Q+1];
	int* Y2 = new int[Q+1];
	int* O  = new int[Q+1];

	for (int i=1; i<=R; i++)
		for (int j=1; j<=C; j++)
			cin >> U[i][j] >> V[i][j] >> W[i][j];

	for (int i=1; i<=Q; i++)
		cin >> X1[i] >> Y1[i] >> X2[i] >> Y2[i];

	Resi(N, R, C, Q, U, V, W, X1, Y1, X2, Y2, O);

	for (int i=1; i<=Q; i++)
		cout << O[i] << '\n';

	delete[] X1;
	delete[] Y1;
	delete[] X2;
	delete[] Y2;
	delete[] O;

	pocisti(U, R);
	pocisti(V, R);
	pocisti(W, R);
}
