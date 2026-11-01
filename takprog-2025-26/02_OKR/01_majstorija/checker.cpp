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


int main(int argc, char** argv) {
    ifstream ouf(argv[1]); //participant solution
    ifstream sof(argv[2]); //official solution 
    ifstream inf(argv[3]); //input

    int T;
    inf >> T;

    while(T--){
        int n, m;
        inf >> n >> m;
        if (n != m){

            string ts;
            ouf >> ts;

            if ((int)ts.length() == 0){
                return -1;
            }


            if (ts == "-1")
                continue;
            return -1;
        }


        vector<vector<int>> a(n, vi(m, 0));
        vi red(n, 0), kolona(m, 0);
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < m; ++j){
                string ts;
                ouf >> ts;

                if ((int)ts.length() != 1 || !broj(ts)) return -1;

                if (ts != "1" && ts != "0") return -1;

                if (ts == "1"){
                    red[i]++;
                    kolona[j]++;
                    a[i][j] = 1;
                }
            }
        }

        for (int i = 0; i < n; ++i){
            if (red[i] % (i + 1) != 0) return -1;
            if (kolona[i] % (i + 1) != 0) return -1;
        }
    }

    if (has_extra_tokens(ouf))
        return -1;
    return 0;
}
