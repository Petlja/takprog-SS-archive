#include <bits/stdc++.h>
using namespace std;
void Gradovi(int N, int M, int K, int Q, int* U, int* V, int* G, int* S);

int main()
{
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    int* U = new int[M + 1];
    int* V = new int[M + 1];
    int* G = new int[K + 1];
    int* S = new int[Q + 1];

    for (int i=1; i<=M; i++) cin >> U[i] >> V[i];

    for (int i=1; i<=K; i++) cin >> G[i];

    for (int i=1; i<=Q; i++) S[i] = 0;

    Gradovi(N,M,K,Q,U,V,G,S);

    for (int i=1; i<=Q; i++) cout<< S[i] << " ";

    delete[] U;
    delete[] V;
    delete[] G;
    delete[] S;
}