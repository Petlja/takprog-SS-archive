// Virus (SIO 2016-17). The answer is K paths that together cover every vertex of the tree, with K as small as
// possible: K = ceil(L / 2) for L leaves (1 when N = 1). The expected outputs are empty, so the checker computes the
// minimum itself. Written in 2026: Petlja kept only a Windows binary of the original checker.
//
//   checker <contestant output> <expected output> <input>    exit 0 = accepted, 1 = wrong
#include <cstdio>
#include <vector>

int main(int argc, char *argv[])
{
    FILE *out = fopen(argv[1], "r"), *in = fopen(argv[3], "r");
    if (!out || !in) return 1;

    int n;
    if (fscanf(in, "%d", &n) != 1) return 1;
    std::vector<std::vector<int> > adj(n + 1);
    for (int i = 1; i < n; i++) {
        int a, b;
        if (fscanf(in, "%d %d", &a, &b) != 2) return 1;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int leaves = 0;
    for (int v = 1; v <= n; v++)
        if (adj[v].size() == 1) leaves++;
    long long best = n == 1 ? 1 : (leaves + 1) / 2;

    long long k;
    if (fscanf(out, "%lld", &k) != 1 || k != best) return 1;

    // Root the tree at 1 (BFS order, no recursion) and build binary lifting for LCA.
    int LOG = 1;
    while ((1 << LOG) < n) LOG++;
    std::vector<std::vector<int> > up(LOG + 1, std::vector<int>(n + 1, 0));
    std::vector<int> depth(n + 1, 0), order;
    order.reserve(n);
    order.push_back(1);
    up[0][1] = 1;
    for (size_t i = 0; i < order.size(); i++) {
        int v = order[i];
        for (int w : adj[v])
            if (w != up[0][v]) {
                up[0][w] = v;
                depth[w] = depth[v] + 1;
                order.push_back(w);
            }
    }
    if ((int)order.size() != n) return 1;
    for (int j = 1; j <= LOG; j++)
        for (int v = 1; v <= n; v++) up[j][v] = up[j - 1][up[j - 1][v]];
    auto lca = [&](int a, int b) {
        if (depth[a] < depth[b]) std::swap(a, b);
        for (int j = LOG; j >= 0; j--)
            if (depth[a] - (1 << j) >= depth[b]) a = up[j][a];
        if (a == b) return a;
        for (int j = LOG; j >= 0; j--)
            if (up[j][a] != up[j][b]) a = up[j][a], b = up[j][b];
        return up[0][a];
    };

    // Each path a-b adds 1 to every vertex on it: +1 at a and b, -1 at the LCA and at its parent, then subtree sums.
    std::vector<long long> cover(n + 1, 0);
    for (long long i = 0; i < k; i++) {
        int a, b;
        if (fscanf(out, "%d %d", &a, &b) != 2) return 1;
        if (a < 1 || a > n || b < 1 || b > n) return 1;
        int c = lca(a, b);
        cover[a]++;
        cover[b]++;
        cover[c]--;
        if (c != 1) cover[up[0][c]]--;
    }
    for (int i = n - 1; i > 0; i--) cover[up[0][order[i]]] += cover[order[i]];
    for (int v = 1; v <= n; v++)
        if (cover[v] <= 0) return 1;
    return 0;
}
