#include "code.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

const int N = 100005;
char rna[N]; int n;
int prefix[N][4];

int toidx(char c) {
    if(c >= 'a' && c <= 'z') c += 'A' - 'a';
    return
        (c == 'A') ? 0 :
        (c == 'U') ? 1 :
        (c == 'C') ? 2 :
        (c == 'G') ? 3 : -1;
}

int q, nq;
int Skener(int L, int R, char C) {
    if(++nq > q) exit(1);

    int i = toidx(C);
    L--; R--;
    if(L < 0 || L >= n || R < 0 || R >= n || R < L || i == -1) {
        return 0;
    }

    return prefix[R][i] - (L ? prefix[L - 1][i] : 0);
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &q);
    scanf(" %s", &rna);
 
    for(int i = 0; i < n; i++) {
        for(int c = 0; c < 4; c++) {
            prefix[i][c] = i ? prefix[i - 1][c] : 0;
        }
        prefix[i][toidx(rna[i])]++;
    }

    int L, R;
    Resi(n, &L, &R);
    printf("%d %d\n", L, R);
    printf("%d\n", nq);

    return 0;
}
