#include <bits/stdc++.h>

using namespace std;

int Safler(int n, int a[]);

int main() {
    int n;
    cin >> n;

    int* a = new int[n+1];

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    cout << Safler(n, a) << '\n';

    delete[] a;
}