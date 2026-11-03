#include <iostream>
using namespace std;

void Raspored(int N, int M, int *P, int* T, int *L, int* D, int** A, bool** B){
    // Ovako bi se upisivalo dato resenje iz primera N = 2, M = 2

    *P = 3;

    T[1] = 1, L[1] = 1; D[1] = 2;
    A[1][1] = 1, B[1][1] = 0;
    A[1][2] = 2, B[1][2] = 1;

    T[2] = 1; L[2] = 2; D[2] = 1;
    A[2][1] = 3, B[2][1] = 0;

    T[3] = 2; L[3] = 1; D[3] = 1;
    A[3][1] = 2, B[3][1] = 1;

    T[4] = 2; L[4] = 2; D[4] = 2;
    A[4][1] = 2, B[4][1] = 1;
    A[4][2] = 1, B[4][2] = 0;

    return;
}
