#include <bits/stdc++.h>
using namespace std;
long long Resi(int N, int *A, int K);
int main()
{
    int N,K;
    cin >> N >> K;
    int* A = new int[N+1];

    for (int i=1; i<=N; i++) cin >> A[i];

    cout<<Resi(N, A, K)<<endl;

    delete[] A;
}
