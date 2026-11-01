#include<bits/stdc++.h>
#define maxa 100000000000000ll
using namespace std;

bool check(long long realSum, long long estimatedSum) {
    if (estimatedSum * 2 < realSum)
        return false;
    if (realSum * 2 < estimatedSum)
        return false;
    return true;
}

int main(int argc, char *argv[])
{
    ifstream ouf(argv[1]); //Takmicar
	ifstream sof(argv[2]); //Komisija
	ifstream inf(argv[3]); //Input
    int n, m, q;
    bool adaptive;
    inf >> n >> m >> q >> adaptive;
    string magic;
    ouf>>magic;
    if (magic != "Ne_HaKuJtE_PeTlJu!!!") {
        return -1;
    }
    long long estimatedSum;
    ouf>>estimatedSum;
    if (!adaptive) {
        long long realSum;
        sof>>realSum;
        if (!check(realSum, estimatedSum))
        {
            return -1;
        }
    }
    else {
        long long minRealSum = 0;
        long long maxRealSum = 0;
        vector<vector<long long>> a(n, vector<long long>(m));
        vector<vector<long long>> minMat(n, vector<long long>(m));
        vector<vector<long long>> maxMat(n, vector<long long>(m));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                ouf>>a[i][j];
                if(a[i][j]) {
                    minMat[i][j]=maxMat[i][j]=a[i][j];
                }
                else {
                    minMat[i][j]=1;
                    maxMat[i][j]=maxa;
                }

            }
        }
        for (int i=n-1;i>=0;i--) {
            for(int j=m-1;j>=0;j--) {
                if(i<n-1) minMat[i][j]=max(minMat[i][j],minMat[i+1][j]);
                if(j<m-1) minMat[i][j]=max(minMat[i][j],minMat[i][j+1]);
                minRealSum+=minMat[i][j];
            }
        }
        for (int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(i) maxMat[i][j]=min(maxMat[i][j],maxMat[i-1][j]);
                if(j) maxMat[i][j]=min(maxMat[i][j],maxMat[i][j-1]);
                maxRealSum+=maxMat[i][j];
            }
        }
        if(!check(minRealSum, estimatedSum) || !check(maxRealSum, estimatedSum))  {
            return -1;
        }
    }
    return 0;
}
