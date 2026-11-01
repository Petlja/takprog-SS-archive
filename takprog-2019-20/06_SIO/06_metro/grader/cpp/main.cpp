#include <cstdio>

using namespace std;

void Resi(int N, int M, int *U, int *V, int *C, int Q, int *A, int *B, long long *R);

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int *eu = new int[m+1], *ev = new int[m+1], *ew = new int[m+1];
    for(int i = 1; i <= m; i++) {
        scanf("%d %d %d", &eu[i], &ev[i], &ew[i]);
    }
    
    int q;
    scanf("%d", &q);
    int *op = new int[q+1], *val = new int[q+1];
    bool *has_out = new bool[q+1];
    for(int i = 1; i <= q; i++) {
        scanf("%d %d", &op[i], &val[i]);
        has_out[i] = op[i] < 0;
    }

    long long *ans = new long long[q+1];
    Resi(n, m, eu, ev, ew, q, op, val, ans);

    for(int i = 1; i <= q; i++) {
        if(has_out[i]) {
            printf("%lld\n", ans[i]);
        }
    }

    delete[] eu, ev, ew, op, val, has_out, ans;

    return 0;
}
