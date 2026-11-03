#! /usr/bin/env python3


def Resi(N):
    # neka pitanja
    x = Skener(2, 5, 'A'))
    y = Skener(1, 3, 'A'))

    # vracamo resenje: obrnuti od treceg do sestog karaktera
    return (3, 6)


# NE MENJATI NISTA ISPOD OVE LINIJE (i ne pristupati promenljivama
# koje koristi)

def Skener(L, R, C):
    if not 1 <= L <= R <= len(Skener.s):
        return 0
    Skener.nq += 1
    if Skener.nq > Skener.q:
        exit(1)

    i = 'AUCG'.index(C)
    return Skener.prefix[R-1][i] - (Skener.prefix[L-1][i] if L > 1 else 0)


def main():
    n, q = map(int, input().split())
    s = input()
    Skener.s = s
    Skener.q = q
    Skener.nq = 0

    Skener.prefix = [[] for _ in s]
    for i, c in enumerate(s):
        Skener.prefix[i] = Skener.prefix[i - 1].copy() if i > 0 else [0,0,0,0]
        Skener.prefix[i]['AUCG'.index(c)] += 1

    L, R = Resi(n)
    print(L, R)
    print(Skener.nq)


if __name__ == '__main__':
    main()
