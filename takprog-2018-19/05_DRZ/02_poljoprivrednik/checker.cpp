#include<bits/stdc++.h>

using namespace std;

const int maxN=1000;
int d[maxN*maxN], c[maxN];
int n, k, x;

int main(int argc, char *argv[])
{
    FILE* fout = fopen(argv[1], "r");
	FILE* fsol = fopen(argv[2], "r");
	FILE* fin  = fopen(argv[3], "r");

	fscanf(fin, "%d%d%d", &n,&k,&x);

    bool bad = false;

    for (int i=0;i<n;i++){
        fscanf(fout, "%d",&c[i]);

        if (c[i]>0 && c[i]<1000000)
            d[c[i]]++;
        else
            bad = true;
    }

    fclose(fin);
	fclose(fsol);
	fclose(fout);


    if (bad) return -1;

    int pairs = 0;

    for (int i=1;i<1000000;i++){
       if (i>x)
            pairs+=d[i]*d[i-x];

       d[i]+=d[i-1];
    }

    if (pairs!=k) return -1;

    return 0;
}
