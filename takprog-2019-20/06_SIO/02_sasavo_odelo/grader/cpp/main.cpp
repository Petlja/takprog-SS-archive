#include <iostream>
using namespace std;

void Oboji(int N, int* U, int* V, int* C);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	int* U = new int[N];
	int* V = new int[N];
	int* C = new int[N+1];

	for (int i=1; i<=N-1; i++) cin >> U[i] >> V[i];

	for (int i=1; i<=N; i++) C[i]=0;

	Oboji(N, U, V, C);

	for (int i=1; i<=N; i++)
		cout << C[i] << '\n';

	delete[] U;
	delete[] V;
	delete[] C;

}
