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

// 0 za ok
// -1 za wa
#define all(a_) a_.begin(),a_.end()

int getnxt(string &s){
    string cu;
    while(s.size()&&s.back()!=' '){
        cu+=s.back();
        s.pop_back();
        if(cu.size()>7) return -1;
    }
    if(s.size()&&s.back()==' ') s.pop_back();
    reverse(all(cu));
    return stoi(cu);
}
bool okniz(string s){
    for(char c : s){
        if(c<'0'||c>'9'){
            if(c!=' ') return 0;
        }
    }
    return 1;
}
#define ll long long
#define ld long double
const int maxn = 2005;
long long n,S;
long long w[maxn];
long long v[maxn];
bool vis[maxn];
int main(int argc, char** argv) {
    ifstream ouf(argv[1]); //participant solution
    ifstream sof(argv[2]); //official solution
    ifstream inf(argv[3]); //input
    ld eps;
    inf >> n >> S >> eps;
    for(int i = 1;i<=n;i++) inf >> w[i] >> v[i];
    long long oficijel;
    sof >> oficijel;
    string sin;
    int m;
    if(getline(ouf,sin)){
        if(!broj(sin)) return -1;
        if(sin.size()>7) return -1;
        m = stoi(sin);
    }else return -1;
    if(m>n||m<0) return -1;
    if(getline(ouf,sin)){
        if(!okniz(sin)) return -1;
        while(!sin.empty()&&sin.back()==' ') sin.pop_back();
        if(count(all(sin),' ')!=m-1) return -1;
    }else{
        if(m!=0) return -1;
    }
    long long ucenik_weight = 0;
    long long ucenik_value = 0;
    for(int j = 0;j<m;j++){
        int i = getnxt(sin);
        if(i<1||i>n) return -1;
        if(vis[i]) return -1;
        vis[i] = 1;
        ucenik_weight+=w[i];
        ucenik_value+=v[i];
    }
    if(ucenik_weight>S) return -1;
    if(ucenik_value>=oficijel*(1-eps)-(1e-6)) return 0;
    return -1;
}
