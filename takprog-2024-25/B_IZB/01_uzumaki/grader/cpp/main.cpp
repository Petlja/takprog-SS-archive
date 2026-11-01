#include <bits/stdc++.h>
using namespace std;
int Vrednost(int N,int *A,int Q,int *T,int *L,int *R,int K);

int main()
{
    int N,K,Q;
    cin >> N;
    int* A = new int[N+1];

    for (int i=1; i<=N; i++) cin >> A[i];

    cin >> Q;

    int* T = new int[Q+1];
    int* L = new int[Q+1];
    int* R = new int[Q+1];

    for (int i=1; i<=Q; i++) cin >> T[i] >> L[i] >> R[i];

    cin >> K;

    cout << Vrednost(N,A,Q,T,L,R,K) <<endl;

    delete[] A;
    delete[] T;
    delete[] L;
    delete[] R;
}
