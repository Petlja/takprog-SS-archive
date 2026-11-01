from student_code import ProceniSumu

_MAXA = 100000000000000
_a = []
_qt = 0
_n = 0
_m = 0
_adap = False


def Pitaj(i, j):
    global _qt
    _qt -= 1
    assert 1 <= i <= _n
    assert 1 <= j <= _m
    assert _qt >= 0
    i -= 1
    j -= 1

    if _adap:
        k = 0
        l = 0
        ty = 0
        leq = _MAXA
        geq = 1

        for x in range(i, -1, -1):
            for y in range(j, ty - 1, -1):
                if _a[x][y]:
                    leq = min(leq, _a[x][y])
                    ty = y + 1
                else:
                    k += 1

        ty = _m
        for x in range(i, _n):
            for y in range(j, ty):
                if _a[x][y]:
                    geq = max(geq, _a[x][y])
                    ty = y
                else:
                    l += 1

        _a[i][j] = _MAXA if k <= 10 * l else 1
        _a[i][j] = min(_a[i][j], leq)
        _a[i][j] = max(_a[i][j], geq)

    return _a[i][j]


n, m, q, adap = map(int, input().split())
_n = n
_m = m
_adap = bool(adap)

if not _adap:
    _a = [list(map(int, input().split())) for _ in range(n)]
else:
    _a = [[0 for _ in range(m)] for _ in range(n)]

_qt = q
result = ProceniSumu(n, m, q, Pitaj)

print("Ne_HaKuJtE_PeTlJu!!!")
print(result)

if _adap:
    for row in _a:
        print(*row)
