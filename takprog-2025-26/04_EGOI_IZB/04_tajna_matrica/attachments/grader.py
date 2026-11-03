from student_code import ProceniSumu

_a = []
_qt = 0


def Pitaj(i, j):
    global _qt
    _qt -= 1
    assert _qt >= 0
    return _a[i - 1][j - 1]


n, m, q = map(int, input().split())
_a = [list(map(int, input().split())) for _ in range(n)]

_qt = q
result = ProceniSumu(n, m, q, Pitaj)

print(result)
