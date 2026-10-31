# Takprog archive

Tasks from Serbian informatics competitions (Takprog), restored from Petlja and checked, for the competition
archive. Each task has everything needed to set it again: statement with examples, testcases, checker (or grader), scoring,
and time and memory limits. The tasks are under CC BY, as the competition commission publishes them.

## Layout

Paths follow the archive's own scheme: `takprog-{season}/{round}/{nn}_{task}/`.

| File | What |
|---|---|
| `statement.md` | The statement in petljapub format, with examples |
| `testcases/` | `NN.in` / `NN.out`: the test set the competition actually ran on |
| `checker.cpp` | The competition's checker, when it had one. Called as `checker <contestant output> <expected output> <input>`; exit code 0 = accepted |
| `scoring.yaml` | The competition's scoring: subtasks, points, public tests |

## How a task gets here

**Tests, limits, checker and scoring come from the competition on Petlja**, as the contest ran. They are taken byte
for byte from the problem's test version that was live on the contest date, after comparing every copy on Petlja: all
test versions, the competition, its testing and archive copies. The 2024 collection (`takprog-SS-zbirka-2024`) is not
used for these: it has fewer tests and different limits. Only the **statement**,
which the collection shares with the competition, comes from it.

The collection's author solutions are run against the chosen testcases in a copy of Petlja's grader before the task is added. Anything
that couldn't be found is noted in the table below, for the authors to fill in.

## Limits

- **Time limit:** CPU time of the solution on one testcase, not wall-clock time.
- **Memory limit:** the solution's peak memory on one testcase. Stack may use up to 256 MB within it.
- **Where they were checked:** Petlja's grader as of 2026. That's Linux on an Intel Xeon Platinum 8272CL at
  2.6 GHz, with every run sandboxed by [isolate](https://github.com/ioi/isolate). C++ is compiled with g++ 14.2,
  `-std=gnu++17 -O2 -static`; Python is 3.13.
- The limits are the ones set for the competition, on the grader of that time (until 2025 a Windows machine with
  other compilers). Every task's solutions were re-run on today's grader: they pass within the limits.

## Tasks

Limits are the competition's. *Checker* is `default` when the task uses a plain token comparison and needs no
`checker.cpp`.

| Season | Round | Task | Time | Memory | Testcases | Checker | Notes |
|---|---|---|---|---|---|---|---|
| 2021-22 | Državno | [Jednačine](takprog-2021-22/05_DRZ/01_jednacine) | 1 s | 64 MB | 26 | `checker.cpp` (exact tokens) | Testcases are the set the contest ran on; earlier copies (Petlja's version 4, the 2024 collection) had wrong outputs for tests 8 and 18 |
