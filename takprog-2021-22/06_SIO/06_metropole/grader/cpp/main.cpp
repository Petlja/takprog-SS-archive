#include <iostream>
using namespace std;
int NajduziPut(int N, int M, int* U, int* V);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M;
    cin >> N >> M;

    int* U = new int[M + 1];
    int* V = new int[M + 1];

    for (int i=1; i<=M; i++) cin >> U[i] >> V[i];

    cout << NajduziPut(N, M, U, V);

    delete[] U;
    delete[] V;
}
