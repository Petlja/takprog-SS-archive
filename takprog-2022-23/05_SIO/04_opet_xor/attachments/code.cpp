#include <cstring>
#include <cstdio>
using namespace std;

void Resi(int N, int *A, int Q, int *T, int *I, int *X, bool *O) {
    for(int i=1; i<=Q; i++) if(T[i]==2) O[i]=(X[i]<=2);
}
