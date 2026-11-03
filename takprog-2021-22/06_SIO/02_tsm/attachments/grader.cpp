#include <iostream>
#include <vector>
using namespace std;

vector<int> NadjiPoredak(int N, int M, int* X, int* Y, int* W);

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    int* X = new int[M+1];
    int* Y = new int[M+1];
    int* W = new int[M+1];
    for(int i = 1; i <= M; i++) cin >> X[i] >> Y[i] >> W[i];
    vector<int> sol = NadjiPoredak(N, M, X, Y, W);
    //if(sol.size() != M) {
    //  cout << -1;
    //} else {
      for(int i = 0; i < sol.size(); i++) {
        cout << sol[i];
        if(i != M-1) cout << ' ';
      }
    //}
    delete[] X;
    delete[] Y;
    delete[] W;
    return 0;
}
