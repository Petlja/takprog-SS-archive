#include <bits/stdc++.h>
using namespace std;
int Interesantnost(int N,int *A);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
    int N;
    cin >> N;

    int* A = new int[(1<<N)+1];

    for (int i=1; i<=(1<<N); i++) cin >> A[i];

    cout << Interesantnost(N, A);

    delete[] A;
}
