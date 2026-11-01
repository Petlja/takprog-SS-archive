#include <bits/stdc++.h>

using namespace std;

int Mesi(int n, int m, int x[], int y[], int a[], int b[]);

int main()
{

    int test;
    cin >> test;

    while(test--){
        int n, m;
        cin >> n >> m;
        int* x = new int[n+1];
        int* y = new int[n+1];

        int* a = new int[m+1];
        int* b = new int[m+1];

        for (int i=1; i<=n; i++){
            cin >> x[i] >> y[i];
        }


        for (int i=1; i<=m; i++){
            cin >> a[i] >> b[i];
        }


        cout << Mesi(n,m,x,y,a,b) << '\n';

        delete[] x;
        delete[] y;
        delete[] a;
        delete[] b;
    }
}