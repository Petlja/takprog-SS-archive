#include <iostream>
using namespace std;

long long Resi(int N, int *A, int *B);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int N;
    cin >> N;

    int *A = new int[N], *B = new int[N];
    for(int i = 0; i < N; i++)
        cin >> A[i] >> B[i];
    
    long long res = Resi(N, A, B);
    cout << res << endl;

    delete[] A;
    delete[] B;
    
    return 0;
}
