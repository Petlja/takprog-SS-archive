# Jednačine (Државно 2021-22)

Everything needed to set this task again: [statement](statement.md) (with examples), [editorial](editorial.md),
[tests](tests/) (26), [checker](checker.cpp), [scoring](scoring.yaml), [solutions](solutions/), and the limits and
provenance in [task.yaml](task.yaml).

**Limits:** 1 s, 64 MB.

**Tests** are Petlja's version 5 of problem 134275, the set the 2021-22 state competition ran on. Earlier copies
(Petlja's version 4, and the 2024 collection) had wrong expected outputs for tests 8 and 18.

**Checker:** an exact comparison of whitespace-separated tokens. The statement allows any valid `n` when there are
several, but the tests are built so the answer is unique.

**Scoring:** five subtasks (0/10/20/35/35); tests 1–5 are public.
