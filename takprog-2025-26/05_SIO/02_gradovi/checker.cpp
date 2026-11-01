#include <bits/stdc++.h>
#define maxn 200005
using namespace std;

vector<int> comp[maxn];
int me[maxn];
int nd[maxn];
int cc[maxn];
int sl[maxn];

int n,m,k,q;
int u[maxn];
int v[maxn];
int g[maxn];
int t[maxn];

set<int> ex;

int Gradovi()
{
    int cur = 0;
    int cnt = n - k;
    for(int i=1;i<=n;i++){
        comp[i].push_back(i);
        me[i]=0;
        cc[i]=i;
        nd[i]=i;
    }
    for(int i=1;i<=k;i++){
        sl[g[i]]=1;
    }
    for(int i=1;i<=m && cnt>q;i++) {
        int x=u[i];
        int y=v[i];
        if(cc[x] == cc[y]) continue;
        int a=cc[x];
        int b=cc[y];
        if(comp[b].size() > comp[a].size()) {
            swap(a,b);
            swap(x,y);
        }
        if(sl[a] == 0 || sl[b] == 0) cnt--;
        for(auto z:comp[b]){
            comp[a].push_back(z);
            cc[z]=a;
        }
        if(me[b] > me[a]) {
            nd[a] = y;
        }
        else {
            if(me[b] < me[a]) {
                nd[a] = x;
            }
            else
            {
                nd[a] = 0;
            }
        }
        me[a]=i;
        sl[a]+=sl[b];
        comp[b].clear();
        if(cnt == q) {
            if(sl[a] == 0) {
                cur = nd[a];
            }
            else {
                cur = 0;
            }
            break;
        }
    }
    bool ok = true;
    bool fn = false;
    for(int i=1;i<=q;i++) {
        if(t[i]<1 || t[i]>n) {
            ok = false;
            break;
        }
        ex.insert(cc[t[i]]);
        if (t[i] == cur)
        {
            fn = true;
        }
        if (sl[cc[t[i]]] != 0)
        {
            ok = false;
        }
    }
    if(ex.size() != q)
    {
        ok = false;
    }
    if (cur != 0 && !fn)
    {
        ok = false;
    }
    if (ok)
    {
        return 0;
    }
    else
    {
        return -1;
    }
}

int main(int argc, char *argv[])
{
    ifstream ouf(argv[1]); //Takmicar
	ifstream sof(argv[2]); //Komisija
	ifstream inf(argv[3]); //Input
    inf >> n >> m >> k >> q;

    for (int i=1; i<=m; i++) inf >> u[i] >> v[i];

    for (int i=1; i<=k; i++) inf >> g[i];

    for (int i=1; i<=q; i++) ouf >> t[i];

    int ret = Gradovi();

    return ret;
}
