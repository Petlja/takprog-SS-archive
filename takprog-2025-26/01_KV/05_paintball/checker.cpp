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

int adj[2000][2000];


int main(int argc, char** argv) {
    ifstream ouf(argv[1]); //participant solution
    ifstream sof(argv[2]); //official solution 
    ifstream inf(argv[3]); //input

    int n, m;
    inf >> n >> m;
    for (long i = 0; i < m; i++)
    {
        long a, b;
        inf >>  a >> b;
        adj[a][b] = true; adj[b][a] = true;
    }
    
    string ts;
    ouf >> ts;

    if ((int)ts.length() == 0 || !broj(ts)){
        return -1;
    }

    int g1 = stoi(ts);


    ouf >> ts;

    if ((int)ts.length() == 0 || !broj(ts)){
        return -1;
    }

    int g2 = stoi(ts);

    vi a;
    for (int i = 0; i < g1; ++i){
        int x;
        ouf >> ts;

        if ((int)ts.length() == 0 || !broj(ts)) return -1;
        x = stoi(ts);
        a.push_back(x);
    }

    vi b;
    for (int i = 0; i < g2; ++i){
        int x;
        ouf >> ts;

        if ((int)ts.length() == 0 || !broj(ts)) return -1;
        x = stoi(ts);
        b.push_back(x);
    }

   // if (has_extra_tokens(ouf))
     //   return -1;

    for (int i = 1; i <= n; ++i){
        int cnt = 0;

        for (int x : a)
            cnt += (x == i);

        for (int x : b)
            cnt += (x == i);
        if (cnt != 1) return -1;
    }

    if ((int)a.size() + (int)b.size() != n){
        return -1;
    }

    int cnt = 0;
    for (int x : a){
        for (int y : b){
            cnt += adj[x][y];
        }
    }

    if (cnt >= m/2){
        return 0;
    }

    return -1;
}
