#include <bits/stdc++.h>
#include "code.h"
#define maxa 100000000000000ll
using namespace std;

namespace {
    static vector<vector<long long>> a;
    static vector<vector<bool>> qv;
    static int n;
    static int m;
    static int qt;
    static bool adap;
}
long long ProceniSumu(int n, int m, int q);

long long Pitaj(int i, int j) {
    qt--;
    assert(1<=i && i<=n);
    assert(1<=j && j<=m);
    assert(qt >= 0);
    i--;
    j--;
    if(adap) {
        int k=0,l=0;
        int ty=0;
        long long leq=maxa;
        long long geq=1;
        for(int x=i;x>=0;x--) {
            for(int y=j;y>=ty;y--) {
                if(a[x][y]) {
                    leq=min(leq,a[x][y]);
                    ty=y+1;
                }
                else {
                    k++;
                }
            }
        }
        ty=m;
        for(int x=i;x<n;x++) {
            for(int y=j;y<ty;y++) {
                if(a[x][y]) {
                    geq=max(geq,a[x][y]);
                    ty=y;
                }
                else {
                    l++;
                }
            }
        }
        if(k<=10*l) a[i][j]=maxa;
        else a[i][j]=1;
        a[i][j]=min(a[i][j],leq);
        a[i][j]=max(a[i][j],geq);
    }
    return a[i][j];
}

int main() {
    int q;
    cin >> n >> m >> q >> adap;
    a.resize(n, vector<long long>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!adap) cin >> a[i][j];
            else a[i][j]=0;
        }
    }
    qt = q;
    long long result = ProceniSumu(n, m, q);
    cout << "Ne_HaKuJtE_PeTlJu!!!" << endl;
    cout << result << endl;
    if (adap) {
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                cout<<a[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
