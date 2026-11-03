# Dozvoljeno vam je da koristite dodatne biblioteke i pomocne funkcije

def Resi(N, A, M, U, V, W, R):
	
	# Na ovaj nacin upisite odgovore u niz R
	for i in range(1, N+1):
		R[i]=1


# KOD ISPOD OVOG KOMENTARA NE SMETE MENJATI

def main():
	N, M = map(int, input().split())
	
	A = [0 for _ in range(N + 1)];
	A = [0] + list(map(int, input().split()))

	U, V, W = [0 for _ in range(M + 1)], [0 for _ in range(M + 1)], [0 for _ in range(M + 1)]
	for i in range(1, M + 1):
		U[i], V[i], W[i] = map(int, input().split())

	R = [0 for _ in range(N + 1)]
	Resi(N, A, M, U, V, W, R);

	for i in range(1, N + 1):
		print(R[i], end=' ')
	print()

if __name__ == "__main__":
	main()
