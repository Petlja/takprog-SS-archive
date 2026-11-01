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

const int maxn = 3e5+10;

bool broj(string s){
    for (char c : s)
        if (c < '0' || c > '9') return 0;
    return 1;
}


int n,k;
long long x[maxn];
long long y[maxn];
__int128_t  participant_ans,ofc_ans;
bool vis[maxn];
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
int main(int argc, char** argv) {
    ifstream ouf(argv[1]); //participant solution
    ifstream sof(argv[2]); //official solution 
    ifstream inf(argv[3]); //input
    inf >> n;
    for (int i = 1; i <= n; ++i){
        inf >> x[i] >> y[i];
        vis[i] = 0;
    }
    string soff;
    sof >> soff;
    ofc_ans = 0;
    for(char c : soff){
        ofc_ans*=10;
        ofc_ans+=c-'0';
    }
    string sin;
    if(getline(ouf,sin)){
        while(sin.back()==' ') sin.pop_back();
        if(!broj(sin)) return -1;
        if(sin.size()>7) return -1;
        k = stoi(sin);
    }else return -1;
    if(k<0||k>n) return -1;
    __int128_t  X = 0,Y = 0;
    if(getline(ouf,sin)){
        if(!okniz(sin)) return -1;
        while(sin.back()==' ') sin.pop_back();
        if(count(all(sin),' ')!=k-1) return -1;
    }else{
        if(ofc_ans==0) return 0;
        return -1;
    }
    for(int j = 1;j<=k;j++){
        int i = getnxt(sin);
        if(i<1&&i>n) return -1;
        if(vis[i]) return -1;
        vis[i] = 1;
        X+=(long long)x[i];
        Y+=(long long)y[i];
    }
    if(has_extra_tokens(ouf)) return -1;
    participant_ans = X*X+Y*Y;
    if(participant_ans==ofc_ans) return 0;
    return -1;
}
