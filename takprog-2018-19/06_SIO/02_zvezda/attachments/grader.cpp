#include <iostream>
using namespace std;

int Zvezda(int N, int *A);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int N;
    cin >> N;

    int *A = new int[N+1];
    for(int i = 1; i <= N; i++)
        cin >> A[i];

    int res = Zvezda(N, A);

    cout << res << endl;

    delete[] A;

    return 0;
}
