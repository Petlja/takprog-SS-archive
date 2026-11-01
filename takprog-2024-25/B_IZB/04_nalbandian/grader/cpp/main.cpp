#include <bits/stdc++.h>
using namespace std;

void Nalbandian(int N, int Q, int* A, int* B, int* K, vector<int>* U, int* O);

int main() {
    int N, Q;
    scanf("%d %d", &N, &Q);

    int* A = new int[N + 1];
    int* B = new int[N + 1];
    int* K = new int[Q + 1];
    vector<int>* U = new vector<int>[Q + 1];
    int* O = new int[Q + 1];

    for (int i = 1; i < N; i++)
        scanf("%d %d", &A[i], &B[i]);

    for (int i = 1; i <= Q; i++) {
        scanf("%d", &K[i]);
        U[i].resize(K[i] + 1, 0);
        for (int j = 1; j <= K[i]; j++)
            scanf("%d", &U[i][j]);
    }

    Nalbandian(N, Q, A, B, K, U, O);

    for (int i = 1; i <= Q; i++)
        printf("%d\n", O[i]);

    delete[] A;
    delete[] B;
    delete[] K;
    delete[] U;
    delete[] O;

    return 0;
}
