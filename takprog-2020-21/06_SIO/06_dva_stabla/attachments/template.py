# Dozvoljeno vam je da koristite dodatne biblioteke i pomocne funkcije

def Resi(N, Q, P, U1, V1, U2, V2, A1, B1, C1, D1, R):

	# Na ovaj nacin upisite odgovore u niz R
	for i in range(1, Q + 1):
		R[i]=0

# KOD ISPOD OVOG KOMENTARA NE SMETE MENJATI

def main():
	N, Q, P = map(int, input().split())
	
	U1, V1 = [0 for _ in range(N)], [0 for _ in range(N)]
	for i in range(1, N):
		U1[i], V1[i] = map(int, input().split())
	
	U2, V2 = [0 for _ in range(N)], [0 for _ in range(N)]
	for i in range(1, N):
		U2[i], V2[i] = map(int, input().split())

	A1, B1, C1, D1 = [0 for _ in range(Q + 1)], [0 for _ in range(Q + 1)], [0 for _ in range(Q + 1)], [0 for _ in range(Q + 1)]
	for i in range(1, Q + 1):
		A1[i], B1[i], C1[i], D1[i] = map(int, input().split())

	R = [0 for _ in range(Q + 1)]
	Resi(N, Q, P, U1, V1, U2, V2, A1, B1, C1, D1, R)

	for i in range(1, Q + 1):
		print(R[i])

if __name__ == "__main__":
	main()