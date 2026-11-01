#include <bits/stdc++.h>
using namespace std;

const int N = 200;
const int K = 2000;

int whose[K][2];

void infect(int p, int s, int c){
    if(c == -1){
        whose[p][s] = -1;
        return;
    }
    if(c == 0){
        return;
    }
    if(whose[p][s] == 0) whose[p][s] = c;
    if(whose[p][s] != c) whose[p][s] = -1;
}

pair <int, int> dekodiraj(string s){
    char t = s.back();
    int strana;
    if(t == 'p') strana = 0;
    else if(t == 'd') strana = 1;
    else strana = -1;
    s.pop_back();
    int broj = 0;
    for(int i=0; i<s.size(); i++){
        broj = 10*broj + (s[i] - '0');
    }
    return {broj, strana};
}

map <pair <int, int>, int> postoji;
map <int, bool> postoji_peskir;

int main(int argc, char* argv[]) {

    ifstream outFile(argv[1]);
    ifstream solFile(argv[2]);
    ifstream inFile(argv[3]);

    int n, m, q1, q2;
    inFile >> n >> m;
    solFile >> q1 >> q2;

    int k;
    outFile >> k;
    if (k > 250 || k < 1)
        return -1;

    for(int t=0; t<n*m; t++){
        int b;
        outFile >> b;
        if(b < 1 || b > k) return -1;
        int tak;
        outFile >> tak;
        if(tak < 1 || tak > n) return -1;
        vector <pair <int, int>> pes;
        for(int peskiri=0; peskiri<b; peskiri++){
            string s;
            outFile >> s;
            pair <int, int> info = dekodiraj(s);
            if(info.first < 1 || info.first > k || info.second == -1) return -1; // nije validan peskir
            pes.push_back(dekodiraj(s));
        }
        for(auto c : pes){
            if(postoji_peskir[c.first]) return -1;
            postoji_peskir[c.first] = 1;
        }
        postoji_peskir.clear();
        int lez;
        outFile >> lez;
        if(lez < 1 || lez > m) return -1;
        if(postoji[{tak, lez}]) return -1;
        postoji[{tak, lez}] = 1;
        // covek-peskir
        int p = pes[0].first, s  = pes[0].second;
        if(whose[p][s] != 0 && whose[p][s] != tak){
            return -1;
        }
        infect(p, s, tak);
        // peskir-peskir
        for(int i=0; i+1<b; i++){
            int p1, s1;
            int p2, s2;
            p1 = pes[i].first, s1 = 1 ^ pes[i].second;
            p2 = pes[i+1].first, s2 = pes[i+1].second;
            infect(p1, s1, whose[p2][s2]);
            infect(p2, s2, whose[p1][s1]);
        }
        // peskir-lezaljka
        p = pes[b-1].first, s = 1 ^ pes[b-1].second;
        if(whose[p][s] != 0 && whose[p][s] != n + lez){
            return -1;
        }
        infect(p, s, n + lez);
    }
    if(k > q1) cout << 0 << endl;
    else if(k > q2) cout << 5 << endl;
    else cout << 10 << endl;
    return 0;
}
