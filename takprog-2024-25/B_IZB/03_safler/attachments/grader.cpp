#include <bits/stdc++.h>
using namespace std;
int Safler(int N, int* A);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;

    int *A = new int[N+1];

    for (int i = 1; i <= N; i++) {
        cin >> A[i];
    }
    
    cout << Safler(N, A) << endl;

    delete[] A;

    return 0;
}