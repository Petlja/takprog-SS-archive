
void Resi(int N, int* A, int Q, int* T, int* L, int* R, int* S, int* O) {
	for (int i = 1; i <= Q; ++i) {
		if (T[i] == 1) {
			O[i] = 7;
		} else {
			A[L[i]] = R[i];
		}
	}
}
