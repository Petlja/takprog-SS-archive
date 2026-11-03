#include <iostream>

using namespace std;

void Trening(int N, int* T, int Q, int* X, int* Y, int* Z, int* Ans);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, Q;
    cin >> N >> Q;

    int* T = new int[N + 1];
    int* X = new int[Q + 1];
    int* Y = new int[Q + 1];
    int* Z = new int[Q + 1];
    int* Ans = new int[Q + 1];

	for (int i=1; i<=N; i++) cin >> T[i];
    for (int i=1; i<=Q; i++) cin >> X[i] >> Y[i] >> Z[i];
    for (int i=1; i<=Q; i++) Ans[i]=-1;

    Trening(N, T, Q, X, Y, Z, Ans);
    
    for (int i=1; i<=Q; i++) cout << Ans[i] << " ";

    delete[] T;
    delete[] X;
    delete[] Y;
    delete[] Z;
    delete[] Ans;
}
