#include <iostream>
using namespace std;

void Smestaj(int N,int M,int Q,int *T,int *U,int *X,int *Ans);

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

    int N,M,Q;
    cin >> N >> M >> Q;

    int *T = new int[Q + 1];
    int *U = new int[Q + 1];
    int *X = new int[Q + 1];
    int *Ans = new int[Q + 1];

    int L = 0;

    for(int i = 1; i <= Q; i++) {
        cin >> T[i];
        if(T[i] == 1) {
            cin >> U[i] >> X[i];
        }
        else {
            cin >> U[i];
            X[i] = 0;
            L++;
        }
    }

    Smestaj(N, M, Q, T, U, X, Ans);

    for(int i = 1; i <= L; i++) {
        cout << Ans[i] << endl;
    }

    delete[] T;
    delete[] U;
    delete[] X;
    delete[] Ans;

    return 0;
}
