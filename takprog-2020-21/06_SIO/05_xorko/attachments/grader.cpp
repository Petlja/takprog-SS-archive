#include <iostream>
using namespace std;

void LexMax(int N, long long* A, long long* B);

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N;
	cin >> N;
	long long* A = new long long[N+1];
	for (int i=1; i<=N; i++)
		cin >> A[i];
    long long* B = new long long[N+1];
	for (int i=1; i<=N; i++)
		B[i]=0;
    LexMax(N, A, B);
	for(int i=1;i<=N;i++)
        cout<<B[i]<<" ";
	delete[] A;
	delete[] B;
}
