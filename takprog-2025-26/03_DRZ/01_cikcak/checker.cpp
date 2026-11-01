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


bool broj(string s){
    for (char c : s)
        if (c < '0' || c > '9') return 0;
    return 1;
}

typedef long long ll;

int main(int argc, char** argv) {
    ifstream ouf(argv[1]); //participant solution
    ifstream sof(argv[2]); //official solution 
    ifstream inf(argv[3]); //input


    int n;
    inf >> n;

    ll s;
    sof >> s;

    vi a;
    set<int> st;
    for (int i = 0; i < n; ++i){
        string ts;
        ouf >> ts;

        if ((int)ts.length() == 0){
            return -1;
        }

        if (!broj(ts)) return -1;

        int x = stoi(ts);
        if (x < 1 || x > 2 * n || st.count(x)) return -1;

        st.insert(x);
        a.push_back(x);
    }

    vi b;
    for (int i = 0; i < n; ++i){
        string ts;
        ouf >> ts;

        if ((int)ts.length() == 0){
            return -1;
        }

        if (!broj(ts)) return -1;

        int x = stoi(ts);
        if (x < 1 || x > 2 * n || st.count(x)) return -1;

        st.insert(x);
        b.push_back(x);
    }

    ll t = 0;
    for (int i = 1; i < n; ++i){
        t += abs(a[i-1] - a[i]) + abs(b[i] - b[i-1]);
    }    

    if (s != t)
        return -1;

    if (has_extra_tokens(ouf))
        return -1;
    return 0;
}
