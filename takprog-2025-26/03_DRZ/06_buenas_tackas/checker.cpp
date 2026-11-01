#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_set>
#include <cstdint>
#include <set>

#define x first
#define y second
using namespace std;

typedef vector<int> vi;

using ll = long long;
using pll = pair<ll,ll>;

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

const ll maxn = 1000005;
pll a[maxn];
pll b[maxn];
ll n,m,k;
ll dist(ll i,ll j){
    ll dx = a[i].x-b[j].x; dx*=dx;
    ll dy = a[i].y-b[j].y; dy*=dy;
    return dx+dy;
}
bool visa[maxn];
bool visb[maxn];
int main(int argc, char** argv) {

    ifstream ouf(argv[1]); // participant solutioFn
    ifstream sof(argv[2]); // official solution 
    ifstream inf(argv[3]); // input

    ll dis_off; sof >> dis_off;
    ll dis_participant;
    if(!(ouf >> dis_participant)) return -1;
    if(!broj(to_string(dis_participant))) return -1;

    if(dis_participant!=dis_off) return -1;

    inf >> n >> m >> k;
    for(ll i = 1;i<=n;i++) inf >> a[i].x >> a[i].y;
    for(ll i = 1;i<=m;i++) inf >> b[i].x >> b[i].y;
    for(ll i = 1;i<=k;i++){
        ll ia,ib;
        if(!(ouf >> ia)) return -1;
        if(!(ouf >> ib)) return -1;
        if(!broj(to_string(ia))||!broj(to_string(ib))) return -1;
        if(visa[ia]||visb[ib]) return -1;
        visa[ia] = visb[ib] = 1;
        if(dist(ia,ib)>dis_participant) return -1;
    }
    if (has_extra_tokens(ouf)) return -1;
    ll sta = -1,stb = -1;
    ll ena = -1,enb = -1;
    for(ll i = 1;i<=n;i++){
        if(visa[i]){
            if(sta==-1) sta = i;
            ena = i;
        }
    }
    for(ll i = 1;i<=m;i++){
        if(visb[i]){
            if(stb==-1) stb = i;
            enb = i;
        }
    }
    if(sta==-1||stb==-1) return -1;
    if(ena-sta+1!=k||enb-stb+1!=k) return -1;
    return 0;
}
