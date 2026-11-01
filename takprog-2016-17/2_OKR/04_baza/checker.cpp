// Baza (Okružno 2016-17). Any placement of sensors with exactly M safe sectors is correct, so the answer is checked
// against the input rather than compared. Written in 2026: Petlja kept only a Windows binary of the original checker.
//
//   checker <contestant output> <expected output> <input>    exit 0 = accepted, 1 = wrong
#include <cstdio>
#include <set>
#include <utility>

typedef long long ll;

int main(int argc, char *argv[])
{
    FILE *out = fopen(argv[1], "r"), *ans = fopen(argv[2], "r"), *in = fopen(argv[3], "r");
    if (!out || !ans || !in) return 1;

    ll n, m, expected, k;
    if (fscanf(in, "%lld %lld", &n, &m) != 2 || fscanf(ans, "%lld", &expected) != 1) return 1;
    if (fscanf(out, "%lld", &k) != 1) return 1;
    if (k == -1) return expected == -1 ? 0 : 1;
    if (k < 1 || k > m) return 1;  // every sensor's own sector is safe, so there are at most M of them

    std::set<std::pair<ll, ll> > sensors;
    std::set<ll> rows, cols;
    for (ll i = 0; i < k; i++) {
        ll x, y;
        if (fscanf(out, "%lld %lld", &x, &y) != 2) return 1;
        if (x < 1 || x > n || y < 1 || y > n) return 1;
        if (!sensors.insert(std::make_pair(x, y)).second) return 1;  // at most one sensor per sector
        cols.insert(x);
        rows.insert(y);
    }

    // Unsafe sectors are those whose row and column both have no sensor. N goes up to 10^18, so N^2 needs 128 bits.
    __int128 N = n, safe = N * N - (N - (ll)rows.size()) * (N - (ll)cols.size());
    return safe == m ? 0 : 1;
}
