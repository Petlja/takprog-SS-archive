#include <iostream>
using namespace std;

void Raspored(int N, int M, int *P, int* T, int *L, int* D, int** A, bool** B);

template <class T> static T** matrica(int R, int C){ /// nova matrica tipa T sa R redova i C kolona
    T** a = new T*[R+1];
    for (int i=1; i<=R; i++)
        a[i] = new T[C+1];
    return a;
}

template <class T> static void pocisti(T** a, int R) { /// brisemo matricu tipa T sa R redova
    for (int i=1; i<=R; i++)
        delete[] a[i];
    delete a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    int** A = matrica <int> (N*M, 250);
    bool** B = matrica <bool> (N*M, 250);

    int* T = new int[N*M + 1];
    int* L = new int[N*M + 1];
    int* D = new int[N*M + 1];

    int P;

    Raspored(N, M, &P, T, L, D, A, B);

    cout << P << "\n";
    for(int i=1; i<=N*M; i++){
        cout << D[i] << " " << T[i] << " ";
        for(int j=1; j<=D[i]; j++){
            cout << A[i][j];
            if(B[i][j] == 0) cout << 'p';
            else if(B[i][j] == 1) cout << 'd';
            else cout << "*";
            cout << " ";
        }
        cout << L[i] << "\n";
    }

    delete[] T;
    delete[] L;
    delete[] D;

    pocisti <int> (A, N*M);
    pocisti <bool> (B, N*M);
}
