#include <bits/stdc++.h>
#include "code.h"
using namespace std;

namespace {
    static vector<vector<long long>> a;
    static int n;
    static int m;
    static int qt;
}
long long ProceniSumu(int n, int m, int q);

long long Pitaj(int i, int j) {
    qt--;
    assert(1<=i && i<=n);
    assert(1<=j && j<=m);
    assert(qt >= 0);
    return a[i - 1][j - 1];
}

int main() {
    int q;
    cin >> n >> m >> q;
    a.resize(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    qt = q;
    long long result = ProceniSumu(n, m, q);
    cout  << result << endl;

    return 0;
}
