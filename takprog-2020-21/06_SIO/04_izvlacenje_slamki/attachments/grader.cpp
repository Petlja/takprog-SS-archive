#include <iostream>
using namespace std;

int Slamke(int N, int* A, int M, int* T, int* X, int* Y);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    int* A = new int[N+1];
    for(int i = 1; i <= N; i++) cin >> A[i];
    int M; cin >> M;
    int* T = new int[M+1];
    int* X = new int[M+1];
    int* Y = new int[M+1];
    for(int i = 1; i <= M; i++) cin >> T[i] >> X[i] >> Y[i];
    cout << Slamke(N, A, M, T, X, Y) << endl;
    delete[] A;
    delete[] T;
    delete[] X;
    delete[] Y;
    return 0;
}
