#include <bits/stdc++.h>
#include "code.h"
using namespace std;

namespace {
    static vector<pair<int, int>> points;
    static vector<int> p;
    static int n;
    static int q;
    static int qt;
}
vector<pair<int, int>> ZapisiTacke(int n);
vector<int> Resi(int n, int q);

int Pitaj(int i, int j, int k) {
    qt--;

    assert(1 <= i && i <= n);
    assert(1 <= j && j <= n);
    assert(1 <= k && k <= n);
    assert(i != j && i != k && j != k);
    assert(qt >= 0);

    int pi = p[i];
    int pj = p[j];
    int pk = p[k];

    assert(1 <= pi && pi <= n);
    assert(1 <= pj && pj <= n);
    assert(1 <= pk && pk <= n);

    auto [ax, ay] = points[pi];
    auto [bx, by] = points[pj];
    auto [cx, cy] = points[pk];

    long long cross =
        1LL * (bx - ax) * (cy - ay) -
        1LL * (by - ay) * (cx - ax);

    if (cross > 0) return 1;
    if (cross < 0) return -1;
    return 0;
}

int main() {
    cin >> n >> q;

    points = ZapisiTacke(n);
    set<pair<int, int>> used_points;

    assert((int)points.size() == n + 1);

    for (int i = 1; i <= n; i++) {
        int x, y;
        x = points[i].first;
        y = points[i].second;

        assert(!used_points.count({x, y}));
        used_points.insert({x, y});
        assert(-1000000000LL <= x && x <= 1000000000LL);
        assert(-1000000000LL <= y && y <= 1000000000LL);
    }

    p.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<int> provera_permutacije = p;
    sort(provera_permutacije.begin()+1, provera_permutacije.end());
    for(int i = 1; i<=n; i++){
        assert(provera_permutacije[i] == i);
    }
    qt = q;

    vector<int> ans = Resi(n, q);

    assert((int)ans.size() == n + 1);

    for (int i = 1; i <= n; i++) {
        if (i > 1) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}