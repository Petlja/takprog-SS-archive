#include <bits/stdc++.h>
using namespace std;

bool has_extra_tokens(ifstream &ifs) {
    string s;
    if (!(ifs >> s)) return false;
    return true;
}

string upper_str(string s) {
    for (char &c : s) if (c >= 'a' && c <= 'z') c -= 'a' - 'A';
    return s;
}

// Read an answer from stream `in`.
// Returns:
//  - 1 if stream contains "DA" and the provided sequence is valid,
//  - 0 if stream contains "NE",
//  - -1 on format/validation error.
//
// If t == 0 and the stream says "DA", this function will immediately
// exit with success (same behavior as polygon quitf(_ok, ...)).
int readAns(ifstream &in, int n, int k, const vector<int> &A, int t) {
    string possible;
    if (!(in >> possible)) {
        // Couldn't read token
        return -1;
    }
    possible = upper_str(possible);

    if (possible != "DA" && possible != "NE") {
        // invalid token
        return -1;
    }

    if (possible == "NE") return 0;

    // possible == "DA"
    if(t==0)
        return 1;
    // read n integers in range [-n, n]
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) {
        int x;
        if (!(in >> x)) return -1;
        if (x < -n || x > n) return -1;
        v.push_back(x);
    }

    // compute final rating process
    int w = 0;
    for (int x : v) {
        if (x >= w) w++;
        else w--;
    }
    if (w != k) return -1;

    // check permutation of original A
    vector<int> v1 = v;
    vector<int> a1 = A;
    sort(v1.begin(), v1.end());
    sort(a1.begin(), a1.end());
    if (v1 != a1) return -1;

    return 1;
}

int main(int argc, char **argv) {
    ifstream ouf(argv[1]); // participant
    ifstream sof(argv[2]); // official / jury
    ifstream inf(argv[3]); // input

    // Read input file: t, n, k, then array A (n integers)
    int t, n, k;
    inf>>t>>n>>k;

    vector<int> A;
    A.resize(n);
    for (int i = 0; i < n; ++i) {
        inf>>A[i];
    }

    int aj = readAns(sof, n, k, A, t);
    if (aj == -1) {
        // jury output malformed -> treat as error
        return -1;
    }
    // Note: readAns may exit(0) already if jury said DA and t==0

    int ap = readAns(ouf, n, k, A, t);
    if (ap == -1) {
        // participant output malformed -> WA
        return -1;
    }

    // Interpret results (matching original checker logic)
    if (ap == 1 && aj == 0) {
        // Jury says NE (no solution), but participant provided a solution -> This shall never happen
        exit(-100);
    }
    if (ap == 0 && aj == 1) {
        // Jury found a solution but participant says NE -> fail (treat as WA)
        return -1;
    }

    // If both say NE -> OK, or both say DA and participant solution validated -> OK
    return 0;
}
