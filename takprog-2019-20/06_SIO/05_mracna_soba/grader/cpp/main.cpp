#include <iostream>
using namespace std;

long long Prebroj(int N, int M, int** A);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin >> N >> M;
	int** A = new int*[N+1];
	for (int i=1; i<=N; i++)
		A[i] = new int[M+1];
	for (int i=1; i<=N; i++)
		for (int j=1; j<=M; j++)
			cin >> A[i][j];

	cout << Prebroj(N, M, A);
	
	for (int i=1; i<=N; i++)
		delete[] A[i];
	delete A;
}
