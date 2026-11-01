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

const int maxn = 2e5+10;
vi vis(maxn);

bool broj(string s){
    for (char c : s)
        if (c < '0' || c > '9') return 0;
    return 1;
}



int main(int argc, char** argv) {
    ifstream ouf(argv[1]); //participant solution
    ifstream sof(argv[2]); //official solution 
    ifstream inf(argv[3]); //input

    int t = 1;

    while (t--) {
        string a, b;
        
        int n;
        inf >> n;

        set<pair<int, int>> st;
        st.insert({1,2});
        st.insert({3,2});
        st.insert({3,1});
        st.insert({3,4});
        st.insert({2,4});
        st.insert({4,1});
        for (int i = 5; i <= n; ++i){
            int a, b, c;
            inf >> a >> b >> c;
            st.insert({a,i});
            st.insert({b,i});
            st.insert({c,i});
        }


        int x;
        string s;
        if (!(ouf >> s)) return -1;

        if (s.size() == 0) return -1;
        if (!broj(s)) return -1;
        x = stoi(s);
        if (x != 1) return -1;

        for (int i = 2; i <= n+1; ++i){
            ouf >> s;
            if (s.size() == 0) return -1;
            if (!broj(s)) return -1;

            int y = stoi(s);

            if (!st.count({x,y}) && !st.count({y,x})) return -1;
            if (vis[y] == 1) return -1;
            vis[y] = 1;
            x = y;
        }

        if (x != 1) return -1;

        for (int i = 1; i <= n; ++i)
            if (!vis[i]) return -1;
    }

    string a;
    if (ouf >> a)
        return -1;

    return 0;
}
