#include <bits/stdc++.h>

using namespace std;

int Sabiranje(int N, int M, long long K, int* U, int* V); 

int main() {
    int n, m;
    long long k;
    cin >> n >> m >> k;
    int u[m + 1], v[m + 1];
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i];
    }
    int result = Sabiranje(n, m, k, u, v);
    cout  << result;
    return 0;
}
