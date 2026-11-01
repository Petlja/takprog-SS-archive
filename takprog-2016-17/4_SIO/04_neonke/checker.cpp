// Neonke (SIO 2016-17), output-only. Scores the contestant's neon placement as the statement says: an invalid file
// gets nothing; otherwise k lit cells give 25 * (k - A) / (B - A) points, rounded down and clamped to 0..25, where the
// expected output holds A and B. Prints the points (scoring.yaml divides by 25). Written in 2026: Petlja kept only a
// Windows binary of the original checker.
//
//   checker <contestant output> <expected output> <input>    exit 0 = valid (points on stdout), 1 = invalid
#include <algorithm>
#include <cctype>
#include <cstdio>
#include <numeric>
#include <set>
#include <utility>
#include <vector>

typedef long long ll;

int n, m;
std::vector<std::vector<int> > walls;  // 2D prefix sums of wall cells, 1-based

int walls_between(int x1, int y1, int x2, int y2)
{
    if (x1 > x2) std::swap(x1, x2);
    if (y1 > y2) std::swap(y1, y2);
    return walls[x2][y2] - walls[x1 - 1][y2] - walls[x2][y1 - 1] + walls[x1 - 1][y1 - 1];
}

std::vector<int> parent;
int find(int v) { return parent[v] == v ? v : parent[v] = find(parent[v]); }

int main(int argc, char *argv[])
{
    FILE *out = fopen(argv[1], "r"), *ans = fopen(argv[2], "r"), *in = fopen(argv[3], "r");
    if (!out || !ans || !in) return 1;

    int r;
    ll c, p, budget, a, b;
    if (fscanf(in, "%d %d %d %lld %lld %lld", &n, &m, &r, &c, &p, &budget) != 6) return 1;
    if (fscanf(ans, "%lld %lld", &a, &b) != 2) return 1;
    std::vector<std::vector<char> > plan(n + 1, std::vector<char>(m + 2, '#'));
    walls.assign(n + 1, std::vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (fscanf(in, " %c", &plan[i][j]) != 1) return 1;
            walls[i][j] = (plan[i][j] != '.') + walls[i - 1][j] + walls[i][j - 1] - walls[i - 1][j - 1];
        }

    // The contestant's file: whole numbers only, in pairs.
    std::vector<ll> nums;
    for (;;) {
        int ch;
        while ((ch = fgetc(out)) != EOF && isspace(ch)) {}
        if (ch == EOF) break;
        ungetc(ch, out);
        ll v;
        if (fscanf(out, "%lld", &v) != 1) return 1;
        ch = fgetc(out);
        if (ch != EOF && !isspace(ch)) return 1;
        nums.push_back(v);
    }
    if (nums.size() % 2) return 1;
    int k = nums.size() / 2;
    std::vector<std::pair<int, int> > neon(k);
    std::set<std::pair<int, int> > seen;
    for (int i = 0; i < k; i++) {
        ll x = nums[2 * i], y = nums[2 * i + 1];
        if (x < 1 || x > n || y < 1 || y > m || plan[x][y] != '.') return 1;
        neon[i] = std::make_pair((int)x, (int)y);
        if (!seen.insert(neon[i]).second) return 1;
    }

    // Light is symmetric (the same rectangle either way), so a neon lit by another switches on with it: one manual
    // switch per connected group.
    parent.resize(k);
    std::iota(parent.begin(), parent.end(), 0);
    int groups = k;
    for (int i = 0; i < k; i++)
        for (int j = i + 1; j < k; j++) {
            int dx = neon[i].first - neon[j].first, dy = neon[i].second - neon[j].second;
            if (dx < -r || dx > r || dy < -r || dy > r) continue;
            if (walls_between(neon[i].first, neon[i].second, neon[j].first, neon[j].second)) continue;
            int u = find(i), v = find(j);
            if (u != v) parent[u] = v, groups--;
        }
    if (k * c + groups * p > budget) return 1;

    std::vector<std::vector<char> > lit(n + 1, std::vector<char>(m + 1, 0));
    ll cells = 0;
    for (int i = 0; i < k; i++) {
        int xn = neon[i].first, yn = neon[i].second;
        for (int x = std::max(1, xn - r); x <= std::min(n, xn + r); x++)
            for (int y = std::max(1, yn - r); y <= std::min(m, yn + r); y++)
                if (!lit[x][y] && !walls_between(xn, yn, x, y)) lit[x][y] = 1, cells++;
    }

    ll points = cells >= b ? 25 : cells <= a ? 0 : 25 * (cells - a) / (b - a);
    printf("%lld\n", points);
    return 0;
}
