#include <cstdio>

#define OK 0
#define WA -1

const int N = 100005;
char rna[N];
int n, q;

int toidx(char c) {
    if(c >= 'a' && c <= 'z') c += 'A' - 'a';
    return
        (c == 'A') ? 0 :
        (c == 'U') ? 1 :
        (c == 'C') ? 2 :
        (c == 'G') ? 3 : -1;
}

bool solvable() {
    bool au = false, cg = false;
    for(int i = 0; i < n; i++) {
        au = au || rna[i] == 'A' || rna[i] == 'U';
        cg = cg || rna[i] == 'C' || rna[i] == 'G';
    }
    return n % 2 == 0 || (au && cg);
}

int max(int a, int b) { return a > b ? a : b; }

int main(int argc, char *argv[]) {
    FILE *out = fopen(argv[1], "r");
    FILE *in = fopen(argv[3], "r");

    if(in == NULL || out == NULL) return WA;

    fscanf(in, "%d %d", &n, &q);
    fscanf(in, " %s", &rna);

    int l, r;
    if(fscanf(out, "%d %d", &l, &r) != 2) return WA;

    if(l == -1 && r == -1) {
        return !solvable() ? OK : WA;
    } else if(l < 1 || r < 1 || l > n || r > n) {
        return WA;
    } else {
        l--; r--;  // 0-indexed
        
        int cnt[4] = {0, 0, 0, 0};
        for(int i = 0; i < n; i++) {
            cnt[toidx(rna[i]) ^ (i >= l && i <= r)]++;
        }

        return max(max(cnt[0], cnt[1]), max(cnt[2], cnt[3])) <= n / 2 ? OK : WA;
    }
}
