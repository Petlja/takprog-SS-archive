#include<bits/stdc++.h>

using namespace std;

const int maxN=1268;
int a[maxN],c[maxN];
int n;

int main(int argc, char *argv[])
{
    FILE* fout = fopen(argv[1], "r");
	FILE* fsol = fopen(argv[2], "r");
	FILE* fin  = fopen(argv[3], "r");

	fscanf(fin, "%d", &n);

	for (int i=0;i<n;i++)
        fscanf(fsol, "%d",&a[i]);

    for (int i=0;i<n;i++)
        fscanf(fout, "%d",&c[i]);

    fclose(fin);
	fclose(fsol);
	fclose(fout);

    sort(a, a+n);
    sort(c, c+n);

    for (int i=0;i<n;i++)
        if (c[i]!=a[i]) return -1;

    return 0;
}
