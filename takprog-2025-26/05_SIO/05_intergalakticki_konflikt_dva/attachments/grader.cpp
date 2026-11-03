#include <bits/stdc++.h>
using namespace std;
long long Konflikt(int N,int M,int *A,int *B);

int main()
{
    int N,M;
    cin >> N >> M;
    int* A = new int[N+1];
    int* B = new int[N+1];

    for (int i=1; i<=N; i++) cin >> A[i];
    for (int i=1; i<=N; i++) cin >> B[i];

    cout << Konflikt(N,M,A,B) <<endl;

    delete[] A;
    delete[] B;
    return 0;
}