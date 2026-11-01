#include <bits/stdc++.h>

using namespace std;

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

    ifstream ouf(argv[1]); // participant solutioFn
    ifstream sof(argv[2]); // official solution 
    ifstream inf(argv[3]); // input

    long long dist_official; sof >> dist_official;
    string s;
    if(!(ouf >> s)) return -1;
    if(!broj(s)) return -1;
    if(has_extra_tokens(ouf)) return -1;
    long long dist_participant = stoll(s);
    if(dist_participant==dist_official) return 0;
    return -1;
}
