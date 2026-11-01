#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool has_extra_tokens(ifstream& ifs)
{
    string s;
    ifs >> s;
    return s.size()!=0;
}

vector<int> lmax,rmin;
vector<vector<int> > L,R; 

int main(int argc, char *argv[])
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ifstream ouf(argv[1]); //participant
    ifstream sof(argv[2]); //official
    ifstream inf(argv[3]); //input
    vector<ll> t_correct,t_sol;
    ll N,M;
    inf >> N >> M;
    t_correct.resize(N);
    t_sol.resize(N);
    sof >> t_correct[0];
    ouf >> t_sol[0];
    if ((t_sol[0]==-1 && t_correct[0]!=-1) || (t_correct[0]==-1 && t_sol[0]!=-1))
        return -1;
    if (t_sol[0]==-1 && t_correct[0]==-1)
    {
        if (has_extra_tokens(ouf))
            return -1;
        return 0;
    }
    for (ll i=1;i<N;i++)
        ouf >> t_sol[i];
    if (has_extra_tokens(ouf))
        return -1;
    L.resize(M);
    R.resize(M);
    lmax.resize(N,1);
    rmin.resize(N,N);
    for (ll i=0;i<M;i++)
    {
        L[i].resize(N);
        for (ll j=0;j<N;j++)
            inf >> L[i][j];
    }
    bool ok=true;
    for (ll i=0;i<M;i++)
    {
        R[i].resize(N);
        for (ll j=0;j<N;j++)
        {
            inf >> R[i][j];
            if (t_sol[j]<L[i][j] || t_sol[j]>R[i][j])
            {
                ok=false;
            }
        }
    }
    set<ll> s;
    for (ll i : t_sol)
    {
        s.insert(i);
    }
    if (s.size()!=N || !ok)
        return -1;
    return 0;
}
