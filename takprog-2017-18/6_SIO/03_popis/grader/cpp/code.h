#ifndef __CODE_H__
#define __CODE_H__

/*
	N i M su dimenzije matrice, Q je broj upita,
	V je broj razlicitih brojeva u matrici.

	Svaki upit ima ili 4 broja x1, y1, x2, y2 >= 0,
	ili u slucaju apdejta ima x1, y1 = koordinate, x2 = nova
	vrednost, y2 = -1
*/

void Resi(int N, int M, int Q, int V, int** A, int* B,
	int* X1, int* Y1, int* X2, int* Y2, int* O);

#endif /* __CODE_H__ */

