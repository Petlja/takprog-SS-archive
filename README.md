# Takprog archive

Tasks from Serbian informatics competitions (Takprog), restored from Petlja and checked, for the competition
archive. Each task has everything needed to set it again: statement with examples, testcases, checker (or grader), scoring,
and time and memory limits. The tasks are under CC BY, as the competition commission publishes them.

## Layout

Paths follow the archive's own scheme: `takprog-{season}/{round}/{nn}_{task}/`.

| File | What |
|---|---|
| `statement.md` | The statement in Markdown, with examples. Its header gives `timelimit` (seconds) and `memlimit` (MB) |
| `*.png` | Pictures the statement shows, if any |
| `testcases/` | `NN.in` / `NN.out`: the test set the competition actually ran on |
| `checker.cpp` | The competition's checker, when it had one. Called as `checker <contestant output> <expected output> <input>`. Exit code 0 = accepted, anything else = wrong; a number on stdout is the score (divided by `divisor` when `scoring.yaml` has one). Checkers marked *converted* were written for Petlja's grader before 2025, which read the exit code as the score: their own code is unchanged, and a short `main` at the end translates the result. Checkers marked *rewritten* replace one that survives only as a Windows binary: they were written in 2026 from the statement |
| `scoring.yaml` | The competition's scoring: subtasks, points, public tests |

## How a task gets here

**Tests, limits, checker and scoring come from the competition on Petlja**, as the contest ran. They are taken byte
for byte from the problem's test version that was live on the contest date, after comparing every copy on Petlja: all
test versions, the competition, its testing and archive copies. The 2024 collection (`takprog-SS-zbirka-2024`) is not
used for these: it has fewer tests and different limits. Only the **statement**,
which the collection shares with the competition, comes from it.

The collection's author solutions are run against the chosen testcases in a copy of Petlja's grader before the task is added. Anything
that couldn't be found is noted in the table below, for the authors to fill in.

**Seasons the collection doesn't cover** (it has 2019-20 to 2023-24) come from Petlja alone, and their tasks were
not re-run. In 2016-17, the statements are Petlja's own, in Latin script as the contest showed them, converted from
HTML. Petlja kept only one version of the tests, so the contest's set is the one it still has; where a round was
also set up as a separate testing competition, the two sets were compared. The scoring was kept as per-test and
per-subtask rows rather than a scoring file; `scoring.yaml` is rebuilt from them.

## Limits

- **Time limit:** CPU time of the solution on one testcase, not wall-clock time.
- **Memory limit:** the solution's peak memory on one testcase. Stack may use up to 256 MB within it.
- **Where they were checked:** Petlja's grader as of 2026. That's Linux on an Intel Xeon Platinum 8272CL at
  2.6 GHz, with every run sandboxed by [isolate](https://github.com/ioi/isolate). C++ is compiled with g++ 14.2,
  `-std=gnu++17 -O2 -static`; Python is 3.13.
- The limits are the ones set for the competition, on the grader of that time (until 2025 a Windows machine with
  other compilers). For the seasons the collection covers, every task's solutions were re-run on today's grader:
  they pass within the limits.

## Tasks

Limits are the competition's. *Checker* is `default` when the task uses a plain token comparison and needs no
`checker.cpp`.

| Season | Round | Task | Time | Memory | Testcases | Checker | Notes |
|---|---|---|---|---|---|---|---|
| 2021-22 | Kvalifikacije 1 | [Nesusedni](takprog-2021-22/01_KV1/01_nesusedni) | 0.2 s | 256 MB | 22 | `checker.cpp` (custom, converted) | The original checker returned 5 for a correct answer and −1 otherwise |
| 2021-22 | Kvalifikacije 1 | [Transfuzija krvi](takprog-2021-22/01_KV1/02_transfuzija) | 0.5 s | 256 MB | 12 | `checker.cpp` (custom) | — |
| 2021-22 | Kvalifikacije 1 | [Prepisivači](takprog-2021-22/01_KV1/03_prepisivaci) | 1 s | 256 MB | 22 | default | Example 2 (test 2, 0 points) was replaced during the contest, in the statement too; this is the replaced version |
| 2021-22 | Kvalifikacije 1 | [Cen\*ura](takprog-2021-22/01_KV1/04_cenzura) | 1 s | 256 MB | 21 | `checker.cpp` (custom, converted) | The checker scores 100 for a correct answer and 80 when only the count is right. Test 13 was replaced before the contest; this is the replaced version |
| 2021-22 | Kvalifikacije 1 | [Noćna vožnja](takprog-2021-22/01_KV1/05_nocnavoznja) | 4 s | 256 MB | 21 | default | All tests were uploaded separately before the contest; they are included |
| 2021-22 | Kvalifikacije 2 | [Mađioničar](takprog-2021-22/02_KV2/01_madjionicar) | 1 s | 256 MB | 22 | default | — |
| 2021-22 | Kvalifikacije 2 | [Ekskurzija](takprog-2021-22/02_KV2/02_ekskurzija) | 0.1 s | 256 MB | 11 | default | — |
| 2021-22 | Kvalifikacije 2 | [Palindrom šafl](takprog-2021-22/02_KV2/03_palindrom_safl) | 0.5 s | 256 MB | 22 | default | — |
| 2021-22 | Kvalifikacije 2 | [Gušter](takprog-2021-22/02_KV2/04_guster) | 0.5 s | 128 MB | 23 | default | Test 13 was replaced before the contest; this is the replaced version |
| 2021-22 | Kvalifikacije 2 | [Čarobnjak](takprog-2021-22/02_KV2/05_carobnjak) | 1 s | 256 MB | 21 | default | — |
| 2021-22 | Kvalifikacije 3 | [Biodiverzitet](takprog-2021-22/03_KV3/01_biodiverzitet) | 1 s | 64 MB | 21 | `checker.cpp` (exact tokens) | — |
| 2021-22 | Kvalifikacije 3 | [Mlađioničar](takprog-2021-22/03_KV3/02_mladjionicar) | 0.5 s | 256 MB | 22 | `checker.cpp` (custom) | Testcases are the set the contest ran on; earlier copies (Petlja's version 2, the 2024 collection) differ in tests 15, 16 and 18 |
| 2021-22 | Kvalifikacije 3 | [Psiho](takprog-2021-22/03_KV3/03_psiho) | 1 s | 256 MB | 22 | `checker.cpp` (exact tokens) | Testcases are the set the contest ran on; earlier copies (Petlja's version 3, the 2024 collection) had different tests 3–22 |
| 2021-22 | Kvalifikacije 3 | [Konjugacija](takprog-2021-22/03_KV3/04_konjugacija) | 1 s | 256 MB | 22 | `checker.cpp` (exact tokens) | Test 8 was replaced before the contest; this is the replaced version |
| 2021-22 | Kvalifikacije 3 | [Min Max Plus](takprog-2021-22/03_KV3/05_min_max_plus) | 3 s | 256 MB | 27 | `checker.cpp` (exact tokens) | All tests were uploaded separately before the contest; they are included |
| 2021-22 | Okružno | [Odbijanje](takprog-2021-22/04_OKR/01_odbijanje) | 0.5 s | 512 MB | 12 | default | — |
| 2021-22 | Okružno | [Štale](takprog-2021-22/04_OKR/02_stale) | 1 s | 512 MB | 22 | default | Test 15 was replaced the day before the contest; this is the replaced version |
| 2021-22 | Okružno | [Okram](takprog-2021-22/04_OKR/03_okram) | 3 s | 512 MB | 21 | `checker.cpp` (exact tokens) | All tests were uploaded separately before the contest; they are included |
| 2021-22 | Okružno | [Sličice](takprog-2021-22/04_OKR/04_slicice) | 1 s | 512 MB | 11 | default | — |
| 2021-22 | Okružno | [Ćivas](takprog-2021-22/04_OKR/05_civas) | 1 s | 512 MB | 22 | `checker.cpp` (exact tokens) | All tests were uploaded separately before the contest; they are included |
| 2021-22 | Okružno | [AdVenture Communist](takprog-2021-22/04_OKR/06_adventure_communist) | 0.5 s | 512 MB | 21 | default | — |
| 2021-22 | Državno | [Jednačine](takprog-2021-22/05_DRZ/01_jednacine) | 1 s | 64 MB | 26 | `checker.cpp` (exact tokens) | Testcases are the set the contest ran on; earlier copies (Petlja's version 4, the 2024 collection) had wrong outputs for tests 8 and 18 |
| 2021-22 | Državno | [Turnir](takprog-2021-22/05_DRZ/02_turnir) | 2 s | 267 MB | 38 | `checker.cpp` (exact tokens) | — |
| 2021-22 | Državno | [Burad](takprog-2021-22/05_DRZ/03_burad) | 1 s | 256 MB | 31 | `checker.cpp` (exact tokens) | Tests 27–31 were uploaded separately just before the contest; they are included |
| 2021-22 | Državno | [Koncert](takprog-2021-22/05_DRZ/04_koncert) | 0.5 s | 256 MB | 22 | `checker.cpp` (exact tokens) | Test 10 was replaced just before the contest; this is the replaced version |
| 2021-22 | Državno | [Šmeker](takprog-2021-22/05_DRZ/05_smeker) | 1 s | 256 MB | 28 | `checker.cpp` (exact tokens) | All tests were uploaded separately just before the contest; they are included |
| 2021-22 | Državno | [Konstrukta](takprog-2021-22/05_DRZ/06_konstrukta) | 1.6 s | 256 MB | 44 | `checker.cpp` (custom) | — |
