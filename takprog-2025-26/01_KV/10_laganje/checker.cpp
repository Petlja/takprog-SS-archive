#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

bool has_extra_tokens(ifstream& ifs) {
    string s;
    ifs >> s;
    return s.size() != 0;
}


bool broj(string s){
    if(s.size()>6) return 0;
    for (char c : s)
        if (c < '0' || c > '9') return 0;
    return 1;
}
#define fi first
#define sc second
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
#define pll pair<ll,ll>
struct Point{
    ld x,y;
    ll id;
};

struct Fenwick {
    const ld INF = 1e9;
    vector<pair<ld,int>> t;
    int n;

    Fenwick(int n) : n(n), t(n+1, {INF, -1}) {}

    void update(int i, pair<ld,int> v) {
        for (; i <= n; i += i & -i)
            t[i] = min(t[i], v);
    }

    pair<ld,int> query(int i) {
        pair<ld,int> res = {INF, -1};
        for (; i > 0; i -= i & -i)
            res = min(res, t[i]);
        return res;
    }
};
#define pb push_back
ld eps;
ld malo = 1e-18;
bool check_ok(vector<Point> A,vector<Point> B) {
    vector<Point> p;
    for(ll i = 0;i<A.size();i++){
        auto it = A[i];
        p.pb({it.x,it.y,i+1});
    }
    for(ll i = 0;i<B.size();i++){
        auto it = B[i];
        p.pb({it.x,it.y,-i-1});
    }
    int n = p.size();
    vector<pll> edges;
    vector<ld> ans(A.size(),1e9);
    for (int rep = 0; rep < 4; rep++) {
        sort(p.begin(), p.end(), [](auto &a, auto &b) {
            if(abs(a.y-b.y)<(long double)1e-20) return a.id>b.id;
            return a.y<b.y;
        });
        vector<ll> ys(n);
        for (int i = 0; i < n; i++) ys[i] = floor(10000000000000000LL*p[i].x);
        vector<ll> cp = ys;
        sort(cp.begin(), cp.end());
        cp.erase(unique(cp.begin(), cp.end()), cp.end());
        for (int i = 0; i < n; i++) ys[i] = lower_bound(cp.begin(), cp.end(), ys[i]) - cp.begin() + 1;
        Fenwick fw(n + 5);
        for (int i = n-1; i >= 0; i--) {
            int key = ys[i];
            if(p[i].id>0){
                auto best = fw.query(key);
                if (best.first != 1e9) {
                    ld dist = best.first - p[i].x - p[i].y;
                    ans[p[i].id-1] = min(ans[p[i].id-1],dist);
                }
            }else fw.update(key, {p[i].x + p[i].y,i});
        }
        for (auto &pt : p) {
            ld tx = pt.x;
            pt.x = pt.y;
            pt.y = tx;
        }
        if (rep == 1) {
            for (auto &pt : p) pt.x = -pt.x;
        }
    }
    for(ld x : ans) if(x>eps){
        // cerr<<"losi: "<<x<<endl;
        // cerr<<A[2].x<< " "<<A[2].y<<endl;
        // cerr<<B[2].x<< " "<<B[2].y<<endl;
        // cer(ans);
        return 0;
    }
    return 1;
}
const int maxn = 200005;
int n;
Point a[maxn];
vector<pair<long long,int> > skoring;
vector<pll> mst;
vector<pll> ans;
bool in[maxn];
int main(int argc, char** argv) {
    ifstream ouf(argv[1]); //participant solution
    ifstream sof(argv[2]); //official solution
    ifstream inf(argv[3]); //input
    inf >> n >> eps;
    for(int i = 1;i<=n;i++) inf >> a[i].x >> a[i].y,a[i].id = i;
    for(int i = 0;i<n-1;i++){
        ll x,y; sof >> x >> y;
        mst.push_back({x,y});
    }
    ll klk = floor(18.0/(eps*eps));
    int k;
    string sin;
    // getline(ouf,sin);
    if(getline(ouf,sin)){
        if(!broj(sin)) return -1;
        k = stoi(sin);
    }else return -1;
    if(k>klk) return -1;
    if(k<0) return -1;
    vector<bool> tu(n+1,0);
    vector<bool> prij(n+1,0);
    if(getline(ouf,sin)){
        if(!okniz(sin)) return -1;
        while(!sin.empty()&&sin.back()==' ') sin.pop_back();
        if(count(all(sin),' ')!=k-1) return -1;
        while(!sin.empty()){
            ll x = getnxt(sin);
            if(x<0||x>n) return -1;
            prij[x] = 1;
        }
    }else return -1;
    for(ll i = 0;i<k-1;i++){
        if(getline(ouf,sin)){
            while(!sin.empty()&&sin.back()==' ') sin.pop_back();
            if(!okniz(sin)) return -1;
            ll x = getnxt(sin);
            ll y = getnxt(sin);
            if(x<1||x>n||y<1||y>n) return -1;
            if(x==y) return -1;
            ans.push_back({x,y});
            in[x] = in[y] = 1;
        }else return -1;
    }
    if(getline(ouf,sin)) return -1;
    for(ll i = 1;i<=n;i++){
        if(in[i]!=prij[i]) return -1;
    }
    ll cnt = 0;
    for(ll i = 1;i<=n;i++){
        if(in[i]) cnt++;
    }
    if(cnt!=k) return -1;
    vector<Point> A,B;
    for(ll i = 1;i<=n;i++) A.pb({a[i].x,a[i].y,0});
    for(pll p: mst){
        ll i = p.fi,j = p.sc;
        ld X1 = a[i].x,Y1 = a[i].y;
        ld X2 = a[j].x,Y2 = a[j].y;
        ld koef = (Y2-Y1)/(X2-X1);
        ld D = X2-X1;
        ld delovi = 20;
        for(ld e = 1;e<delovi;e++){
            ld nx = X1+D*e/delovi;
            ld ny = Y1+D*e*koef/delovi;
            A.pb({nx,ny,0});
        }
    }
    for(ll i = 1;i<=n;i++) if(in[i]) B.pb({a[i].x,a[i].y,0});
    for(pll p: ans){
        ll i = p.fi,j = p.sc;
        ld X1 = a[i].x,Y1 = a[i].y;
        ld X2 = a[j].x,Y2 = a[j].y;
        ld koef = (Y2-Y1)/(X2-X1);
        ld D = X2-X1;
        ld delovi = 20;
        for(ld e = 1;e<delovi;e++){
            ld nx = X1+D*e/delovi;
            ld ny = Y1+D*e*koef/delovi;
            B.pb({nx,ny,0});
        }
    }
    if(check_ok(A,B)&&check_ok(B,A)) return 0;
    return -1;
}
