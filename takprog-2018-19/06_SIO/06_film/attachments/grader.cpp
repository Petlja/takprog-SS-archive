#include <iostream>
#include <string>
using namespace std;

int Resi(int N, int K, int* L, char** A, char* S);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int N, K;
	cin >> N >> K;
	char** A = new char*[N+1];
	int* L = new int[N+1];
	char* S = new char[65536];
	for (int i=1; i<=N; i++) {
		string s;
		cin >> s;
		A[i] = new char[s.size() + 2];
		copy(s.begin(), s.end(), A[i]+1);
		A[i][s.size() + 1] = 0;
		L[i] = s.size();
	}
	int res = Resi(N, K, L, A, S);
	cout << res << '\n';
	if (res >= 0) {
		for (int i=1; i<=res; i++)
			cout << S[i];
		cout << '\n';
	}
	for (int i=1; i<=N; i++)
		delete[] A[i];
	delete[] A;
	delete[] L;
	delete[] S;
}