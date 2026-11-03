# Dozvoljeno vam je da koristite dodatne biblioteke i pomocne funkcije

def Slamke(N,A,M,T,X,Y):
    res=0

    #vaš kod za ovaj zadatak

    #funkcija treba da vrati koliko će najviše puta Pavle izvući najkraću slamku
    return res

# NE MENJATI NISTA ISPOD OVE LINIJE (i ne pristupati promenljivama
# koje koristi)

def main():
    N = int(input())
    A = [0 for x in range(N + 1)]
    A = [0]+list(map(int, input().split()))
    M = int(input())
    T, X, Y = [0 for i in range(M + 1)], [0 for x in range(M + 1)], [0 for x in range(M + 1)]
    for i in range(1, M + 1):
        T[i], X[i], Y[i] = map(int, input().split())
    print(Slamke(N,A,M,T,X,Y))

if __name__ == '__main__':
    main()
