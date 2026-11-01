#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <cstdint>
#include <set>

using namespace std;

typedef vector<int> vi;

bool has_extra_tokens(ifstream& ifs) {
    string s;
    ifs >> s;
    return s.size() != 0;
}

bool broj(string s) {
    if (s.empty()) return false;
    int start = 0;
    if (s[0] == '-') {
        if (s.size() == 1) return false;
        start = 1;
    }
    for (int i = start; i < (int)s.size(); ++i)
        if (s[i] < '0' || s[i] > '9') return false;
    return true;
}

int main(int argc, char** argv) {

    ifstream ouf(argv[1]); // participant solution
    ifstream sof(argv[2]); // official solution 
    ifstream inf(argv[3]); // input

    int T;
    if (!(inf >> T)) return -1;

    while(T--) {
        int n, m, k;
        inf >> n >> m >> k;

        vector<int> S(k);
        for (int i = 0; i < k; ++i) {
            inf >> S[i];
        }

        set<pair<int, int>> original_edges;
        for (int i = 0; i < m; ++i) {
            int u, v;
            inf >> u >> v;
            original_edges.insert({min(u, v), max(u, v)});
        }

        string ts_r;
        sof >> ts_r;
        if (!broj(ts_r)) return -1;
        int r = stoi(ts_r);

        string ts;
        ouf >> ts;

        if ((int)ts.length() == 0) return -1;
        if (!broj(ts)) return -1;

        int M = stoi(ts);

        if (r == -1 && M != -1) return -1; 
        if (M == -1 && r != -1) return -1; 
        if (M == -1 && r == -1) continue;  

        if (M != n - 1) return -1;

        vector<pair<int, int>> participant_edges;
        vector<int> degree(n + 1, 0);

        for (int i = 0; i < n - 1; ++i) {
            string ts_u, ts_v;
            
            ouf >> ts_u;
            if (ts_u.empty() || !broj(ts_u)) return -1;
            int u = stoi(ts_u);

            ouf >> ts_v;
            if (ts_v.empty() || !broj(ts_v)) return -1;
            int v = stoi(ts_v);

            if (u < 1 || v < 1 || u > n || v > n) return -1;

            if (original_edges.find({min(u, v), max(u, v)}) == original_edges.end()) {
                return -1;
            }

            participant_edges.push_back({u, v});
            degree[u]++;
            degree[v]++;
        }

        for (int i = 0; i < k; ++i) {
            if (degree[S[i]] != 1) return -1;
        }

        vector<vector<int>> adj(n + 1);
        for (auto e : participant_edges) {
            adj[e.first].push_back(e.second);
            adj[e.second].push_back(e.first);
        }

        int visited_count = 0;
        queue<int> q;
        vector<bool> vis(n + 1, false);
        
        q.push(1);
        vis[1] = true;
        visited_count = 1;

        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int nxt : adj[curr]) {
                if (!vis[nxt]) {
                    vis[nxt] = true;
                    visited_count++;
                    q.push(nxt);
                }
            }
        }

        if (visited_count != n) return -1;
    }

    if (has_extra_tokens(ouf))
        return -1;
        
    return 0;
}
