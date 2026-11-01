#include <bits/stdc++.h>
using namespace std;

void Bumerang(int n, int q, int* p, int* w, int* s, int* k, long long* ans);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    int* p = new int[N + 1];
    int* w = new int[N + 1];

    for (int i = 1; i <= N; i++) {
        cin >> p[i];
    }

    for (int i = 1; i <= N; i++) {
        cin >> w[i];
    }

    int* s = new int[Q + 1];
    int* k = new int[Q + 1];
    long long* ans = new long long[Q + 1];

    for (int i = 1; i <= Q; i++) {
        cin >> s[i];
    }

    for (int i = 1; i <= Q; i++) {
        cin >> k[i];
    }

    Bumerang(N, Q, p, w, s, k, ans);

    for (int i = 1; i <= Q; i++) {
        cout << ans[i] << '\n';
    }

    delete[] p;
    delete[] w;
    delete[] s;
    delete[] k;
    delete[] ans;

    return 0;
}