#include<bits/stdc++.h>
#define maxn 1000007
using namespace std;
int val;
int opt;
int n;
int a[maxn];
int x[maxn];
char s[maxn];
set<int> pos;
set<int> neg;
int m;
const double partial=0.4;

bool has_extra_tokens(ifstream& ifs) {
    string s;
    ifs >> s;
    return s.size() != 0;
}

int simulate() {
    int ret = 0;
    int off = 0;
    int p = 0;
    pos.clear();
    neg.clear();
    for(int i = 1; i <= n; i++) {
        if(x[i] > 0) pos.insert(x[i]);
        else neg.insert(-x[i]);
    }
    off = 0;
    p = 0;
    bool caught=false;
    while(off<m && (!pos.empty() || !neg.empty())) {
        if(!pos.empty()) {
            int v=(*pos.begin())-off;
            if(v<=p) {
                caught=true;
                break;
            }
        }
        if(!neg.empty()) {
            int v=-(*neg.begin())+off;
            if(v>=p) {
                caught=true;
                break;
            }
        }
        if(s[off] == '1') {
            if(!pos.empty()) {
                pos.erase(pos.begin());
                ret++;
            }
        }
        else if(s[off] == '2') {
            if(!neg.empty()) {
                neg.erase(neg.begin());
                ret++;
            }
        }
        else p++;
        off++;
    }
    if(off<m && caught) {
        return -1;
    }
    return ret;
}

int main(int argc, char *argv[])
{
    ifstream ouf(argv[1]); //Takmicar
	ifstream sof(argv[2]); //Komisija
	ifstream inf(argv[3]); //Input
    inf>>n;
    for(int i=1;i<=n;i++) {
        inf>>x[i];
    }
    int points;
    sof>>points;
	sof>>opt;
    ouf>>val;
	if(opt!=val)
    {
        cout<<0<<endl;
        return -1;
    }
    ouf>>s;
    m=strlen(s);
    if(m>1000000) {
        cout<<round(partial*points)<<endl;
        return 0;
    }
    for(int i=0;i<m;i++) {
        if(s[i]!='1' && s[i]!='2' && s[i]!='3') {
            cout<<round(partial*points)<<endl;
            return 0;
        }
    }
    for(int i=1;i<m;i++) {
        if(s[i]==s[i-1]) {
            cout<<round(partial*points)<<endl;
            return 0;
        }
    }
    if(simulate()!=val) {
        cout<<round(partial*points)<<endl;
        return 0;
    }
    if (has_extra_tokens(ouf))
    {
        cout<<round(partial*points)<<endl;
        return 0;
    }
    cout<<points<<endl;
    return 0;
}
