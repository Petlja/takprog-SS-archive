#include<bits/stdc++.h>

using namespace std;

const int MAXN=int(2e5+50);

bool has_extra_tokens(ifstream& ifs) {
	string s;
	ifs >> s;
	return s.size() != 0;
}

int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

    ifstream fout(argv[1]);
	ifstream fsol(argv[2]);
	ifstream fin(argv[3]);

	int n,a[MAXN],b[MAXN];

	fin >> n;

	for(int i=1;i<=n;i++)
	{
        fin >> a[i];
        b[i]=a[i];
	}

	int iK,xK,iT,xT;

	fsol >> iK >> xK;

	fout >> iT >> xT;

	if (has_extra_tokens(fout))
		return -1;

	if (xT>int(1e9) || xT<1 || iT<1 || iT>n)
        return -1;

    if (iK==iT && xK==xT)
        return 0;

    a[iK]=xK;
    b[iT]=xT;

    sort(a+1,a+n+1);
    sort(b+1,b+n+1);

    int mxK=a[2]-a[1];
    int mxT=b[2]-b[1];

    for (int i=3; i<=n; i++)
    {
        if (a[i]-a[i-1]>mxK)
            mxK=a[i]-a[i-1];
        if (b[i]-b[i-1]>mxT)
            mxT=b[i]-b[i-1];
    }

	if (mxK!=mxT)
        return -1;
    else
        return 0;
}
