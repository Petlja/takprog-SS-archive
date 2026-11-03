#include <bits/stdc++.h>
using namespace std;
int Sabiranje(int N, int M, long long K, int* U, int* V);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M; long long K; cin >> N >> M >> K;

    int *U = new int[M+1];
    int *V = new int[M+1];
    
    for (int i = 1; i <= M; i++) {
        cin >> U[i] >> V[i];
    }
    
    cout << Sabiranje(N, M, K, U, V) << endl;

    delete[] U;
    delete[] V;

    return 0;
}