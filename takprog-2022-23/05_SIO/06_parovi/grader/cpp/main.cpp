#include <bits/stdc++.h>
using namespace std;

long long Resi(int N, int M, int K, int *U, int *V);

int main()
{
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    int *U = new int[M + 1];
    int *V = new int[M + 1];
    for(int i = 1; i <= M; i++) {
        scanf("%d %d", &U[i], &V[i]);
    }

    long long res = Resi(N, M, K, U, V);
    printf("%lld\n", res);

    delete[] U;
    delete[] V;
    return 0;
}