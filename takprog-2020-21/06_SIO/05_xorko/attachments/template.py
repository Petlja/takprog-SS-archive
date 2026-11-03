# Dozvoljeno vam je da koristite dodatne biblioteke i pomocne funkcije

def LexMax(N,A,B):
    # Na ovaj nacin upisite odgovore u niz B
    for i in range(1, N + 1):
        B[i] = A[i]

# NE MENJATI NISTA ISPOD OVE LINIJE (i ne pristupati promenljivama
# koje koristi)

def main():
    N = int(input())
    A = [0 for x in range(N + 1)]
    A = [0]+list(map(int, input().split()))
    B = [0 for x in range(N + 1)]
    LexMax(N,A,B)
    for i in range(1, N + 1):
        print(B[i], end=' ')
    print()

if __name__ == '__main__':
    main()
