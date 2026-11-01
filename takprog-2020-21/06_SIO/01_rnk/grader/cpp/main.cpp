#include "code.h"
#include <cstdio>
#include <cstring>
#include <cstdlib>

static const int N = 100005;
static char rna[N]; static int n;
static int TAJNI_prefix[N][4];

int toidx(char c) {
    if(c >= 'a' && c <= 'z') c += 'A' - 'a';
    return
        (c == 'A') ? 0 :
        (c == 'U') ? 1 :
        (c == 'C') ? 2 :
        (c == 'G') ? 3 : -1;
}

static int q, nq;
int Skener(int L, int R, char C) {
    if(++nq > q) exit(1);

    static int check = 0;
    if(nq != ++check) exit(1);

    int i = toidx(C);
    L--; R--;
    if(L < 0 || L >= n || R < 0 || R >= n || R < L || i == -1) {
        return 0;
    }

    return (TAJNI_prefix[R][i] ^ 0xDEAD) - (L ? (TAJNI_prefix[L - 1][i] ^ 0xDEAD) : 0);
}

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &q);
    scanf(" %s", &rna);
 
    fclose(stdin);

    for(int i = 0; i < n; i++) {
        for(int c = 0; c < 4; c++) {
            TAJNI_prefix[i][c] = i ? TAJNI_prefix[i - 1][c] : 0;
        }
        TAJNI_prefix[i][toidx(rna[i])]++;
    }

    for(int i = 0; i < n; i++) rna[i] = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < 4; j++)
            TAJNI_prefix[i][j] ^= 0xDEAD;

    int L, R;
    Resi(n, &L, &R);
    printf("%d %d\n", L, R);
    printf("%d\n", nq);

    return 0;
}
