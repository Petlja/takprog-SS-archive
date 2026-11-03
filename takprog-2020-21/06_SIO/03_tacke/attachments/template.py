# Dozvoljeno vam je da koristite dodatne biblioteke i pomocne funkcije

def Resi(N, Px, Py, X, Y, Q, L, R, O):

	# Na ovaj nacin upisite odgovore u niz O
	for i in range(1, Q + 1):
		O[i]=True


# KOD ISPOD OVOG KOMENTARA NE SMETE MENJATI

def main():
	N, Px, Py = map(int, input().split())
	
	X, Y = [0 for _ in range(N + 1)], [0 for _ in range(N + 1)]
	for i in range(1, N + 1):
		X[i], Y[i] = map(int, input().split())

	Q = int(input())
	
	L, R = [0 for _ in range(Q + 1)], [0 for _ in range(Q + 1)]
	for i in range(1, Q + 1):
		L[i], R[i] = map(int, input().split())

	O = [False for _ in range(Q + 1)]

	Resi(N, Px, Py, X, Y, Q, L, R, O)

	for i in range(1, Q + 1):
		if O[i]:
			print("Da")
		else:
			print("Ne")

if __name__ == "__main__":
	main()
