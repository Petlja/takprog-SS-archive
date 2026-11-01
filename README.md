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
| `scoring.yaml` | The competition's scoring: subtasks, points, public tests. `score_total: null` means each test is worth the points its checker gives |
| `grader/` | Functional tasks only (the contestant writes functions, not a program): the competition's grader, per language, as Petlja serves it. `cpp/main.cpp` and `cpp/code.h` are compiled together with the contestant's file; `pas/` is the Pascal version from the same contest |

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

In 2017-18 the statements are the commission's Markdown originals, in Cyrillic, as Petlja stores them (Kvalifikacije 1
has only Petlja's HTML, converted the same way as 2016-17). Petlja moved every test file in November 2018, so all
versions carry that date; the contest's set is the version the problem still serves, unless that one was uploaded
after the move. Every task was also compared with a second copy that Petlja kept separately, an early collection
of the same tasks; where the two differ, the note says which one the contest used and why.

From 2018-19 on, Petlja kept every test version with the time it was uploaded, and the competition's scoring file. The
contest's set is the last version uploaded before the contest ended, with any tests uploaded separately before it
ended. Where the commission corrected tests during a contest and graded every submission again, the set is the
corrected one.

In 2019-20 and 2020-21 the statements come from the collection, except SIO, which it doesn't have (those are
Petlja's Markdown originals). For four 2020-21 tasks Petlja's storage no longer has every test the contest graded
(the grader of the time kept tests from earlier uploads). Where an earlier upload on Petlja still has them, they come
from there; otherwise from the collection, which matches every test Petlja does have. Submissions accepted at the
contest pass the completed sets. The task's note says which tests these are.

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
| 2016-17 | Kvalifikacije | [Trotoar](takprog-2016-17/1_KV1/01_trotoar) | 1 s | 64 MB | 22 | default | — |
| 2016-17 | Kvalifikacije | [Papir, kamen, makaze](takprog-2016-17/1_KV1/02_papir_kamen_makaze) | 1 s | 64 MB | 22 | default | — |
| 2016-17 | Kvalifikacije | [Kul kule](takprog-2016-17/1_KV1/03_kul_kule) | 1 s | 64 MB | 22 | default | — |
| 2016-17 | Kvalifikacije | [Filozof](takprog-2016-17/1_KV1/04_filozof) | 0.5 s | 256 MB | 12 | default | — |
| 2016-17 | Kvalifikacije | [Sportski centar](takprog-2016-17/1_KV1/05_sportski_centar) | 0.2 s | 64 MB | 12 | default | The statement's picture `img_sportski_centar.png` is lost |
| 2016-17 | Kvalifikacije | [Kružna škola](takprog-2016-17/1_KV1/06_kruzna_skola) | 1 s | 256 MB | 27 | default | The statement's picture `img_kruzna_skola.png` is lost |
| 2016-17 | Okružno | [Krompir](takprog-2016-17/2_OKR/01_krompir) | 0.5 s | 256 MB | 22 | default | The statement's picture `Krompir_Example1.png` is lost |
| 2016-17 | Okružno | [Raketa](takprog-2016-17/2_OKR/02_raketa) | 0.1 s | 256 MB | 27 | default | — |
| 2016-17 | Okružno | [Marsovci](takprog-2016-17/2_OKR/03_marsovci) | 0.5 s | 256 MB | 22 | default | — |
| 2016-17 | Okružno | [Baza](takprog-2016-17/2_OKR/04_baza) | 1 s | 256 MB | 22 | `checker.cpp` (custom, rewritten) | Any placement with exactly M safe sectors is correct. The statement's picture `Baza_Example1.png` is lost |
| 2016-17 | Okružno | [Kosmodrom](takprog-2016-17/2_OKR/05_kosmodrom) | 0.3 s | 256 MB | 12 | default | — |
| 2016-17 | Okružno | [Mingo](takprog-2016-17/2_OKR/06_mingo) | 1.5 s | 256 MB | 22 | default | The contest's copy on Petlja shows Kosmodrom's statement; this one is from the round's testing copy, which has the same tests |
| 2016-17 | Državno | [Bond](takprog-2016-17/3_DRZ/01_bond) | 1 s | 256 MB | 20 | default | The contest's copy on Petlja shows Karte's statement; this one is from the round's testing copy, which has the same tests |
| 2016-17 | Državno | [Hari](takprog-2016-17/3_DRZ/02_hari) | 0.4 s | 64 MB | 26 | default | An earlier testing copy had a different test 26 and a test 27; the contest ran on these 26 |
| 2016-17 | Državno | [Kladionica](takprog-2016-17/3_DRZ/03_kladionica) | 0.7 s | 256 MB | 26 | default | — |
| 2016-17 | Državno | [Karibi](takprog-2016-17/3_DRZ/04_karibi) | 1.5 s | 256 MB | 27 | default | — |
| 2016-17 | Državno | [Prorok](takprog-2016-17/3_DRZ/05_prorok) | 0.3 s | 64 MB | 19 | default | — |
| 2016-17 | Državno | [Karte](takprog-2016-17/3_DRZ/06_karte) | 0.6 s | 64 MB | 23 | default | — |
| 2016-17 | SIO | [Klikeri](takprog-2016-17/4_SIO/01_klikeri) | 1.5 s | 64 MB | 41 | default | — |
| 2016-17 | SIO | [Zaduženja](takprog-2016-17/4_SIO/02_zaduzenja) | 1.5 s | 64 MB | 30 | default | — |
| 2016-17 | SIO | [Tetke](takprog-2016-17/4_SIO/03_tetke) | 3 s | 192 MB | 22 | default | — |
| 2016-17 | SIO | [Neonke](takprog-2016-17/4_SIO/04_neonke) | — | — | 4 | `checker.cpp` (custom, rewritten) | Output-only: contestants submit the outputs, so there are no limits (the header says 0). Each `.out` holds the statement's constants A and B, and the checker gives 0–25 points per test. Re-scoring the 236 outputs submitted in 2017 gives the recorded points for all but one file (one contestant, test 1): it scored 24 then, but under the statement's rule it goes over the budget, so the original checker counted manual switch-ons more leniently. The `Neonke.jar` visualizer the statement mentions is not on Petlja |
| 2016-17 | SIO | [Virus](takprog-2016-17/4_SIO/05_virus) | 1 s | 64 MB | 50 | `checker.cpp` (custom, rewritten) | The expected outputs are empty: the checker computes the minimum number of paths itself. Petlja's statement has a placeholder instead of the output description; the example shows the format (the count, then one pair per line). The statement's example is not one of the tests |
| 2016-17 | SIO | [Pogled](takprog-2016-17/4_SIO/06_pogled) | 1 s | 64 MB | 26 | default | The statement's examples are not among the tests |
| 2017-18 | Kvalifikacije 1 | [Prva cifra](takprog-2017-18/1_KV1/01_prva_cifra) | 0.1 s | 64 MB | 12 | default | Petlja's contest copy has no statement; this one is from its early collection copy, which has the same tests |
| 2017-18 | Kvalifikacije 1 | [Transformacija matrice](takprog-2017-18/1_KV1/02_transformacija_matrice) | 4 s | 128 MB | 22 | default | — |
| 2017-18 | Kvalifikacije 1 | [Prodavnice](takprog-2017-18/1_KV1/03_prodavnice) | 1 s | 64 MB | 22 | default | The statement's example 1 writes one query as `60 8`; test 1 has `8 60`, with the same answer |
| 2017-18 | Kvalifikacije 1 | [Okrnjen trougao](takprog-2017-18/1_KV1/04_okrnjen_trougao) | 1 s | 128 MB | 22 | `checker.cpp` (custom) | — |
| 2017-18 | Kvalifikacije 1 | [Nagrade](takprog-2017-18/1_KV1/05_nagrade) | 1 s | 128 MB | 22 | `checker.cpp` (custom) | — |
| 2017-18 | Kvalifikacije 2 | [Mala matrica](takprog-2017-18/2_KV2/01_mala_matrica) | 1 s | 256 MB | 22 | `checker.cpp` (custom) | — |
| 2017-18 | Kvalifikacije 2 | [Trivijalan broj](takprog-2017-18/2_KV2/02_trivijalan_broj) | 2 s | 256 MB | 11 | default | — |
| 2017-18 | Kvalifikacije 2 | [Topla voda](takprog-2017-18/2_KV2/03_topla_voda) | 2 s | 128 MB | 22 | default | — |
| 2017-18 | Kvalifikacije 2 | [Džokeri](takprog-2017-18/2_KV2/04_dzokeri) | 1 s | 256 MB | 22 | default | — |
| 2017-18 | Kvalifikacije 2 | [Kiosci](takprog-2017-18/2_KV2/05_kiosci) | 2.5 s | 512 MB | 22 | default | — |
| 2017-18 | Kvalifikacije 3 | [Zečevi](takprog-2017-18/3_KV3/01_zecevi) | 0.2 s | 64 MB | 54 | `checker.cpp` (custom) | — |
| 2017-18 | Kvalifikacije 3 | [Najbliži neopadajući](takprog-2017-18/3_KV3/02_najblizi_neopadajuci) | 0.3 s | 64 MB | 44 | default | — |
| 2017-18 | Kvalifikacije 3 | [Struja](takprog-2017-18/3_KV3/03_struja) | 2 s | 128 MB | 22 | `checker.cpp` (custom) | — |
| 2017-18 | Kvalifikacije 3 | [Plus-minus](takprog-2017-18/3_KV3/04_plus_minus) | 1 s | 128 MB | 22 | `checker.cpp` (custom) | — |
| 2017-18 | Kvalifikacije 3 | [Prepisivanje](takprog-2017-18/3_KV3/05_prepisivanje) | 2.5 s | 512 MB | 22 | default | An early copy on Petlja has only tests 1–12; the contest ran all 22 |
| 2017-18 | Okružno | [Pangram](takprog-2017-18/4_OKR/01_pangram) | 1 s | 512 MB | 22 | `checker.cpp` (custom) | Petlja also has an earlier version of test 18 with some letters in other places; both are impossible to reconstruct, so the answer `SAN` is the same |
| 2017-18 | Okružno | [Matriks](takprog-2017-18/4_OKR/02_matriks) | 1 s | 64 MB | 11 | default | — |
| 2017-18 | Okružno | [Žalbe](takprog-2017-18/4_OKR/03_zalbe) | 0.5 s | 64 MB | 22 | `checker.cpp` (custom, converted) | The original checker returned 5 for the lexicographically smallest valid permutation starting with k, 3 (60%) for another valid one, and −1 otherwise |
| 2017-18 | Okružno | [Cik-cak](takprog-2017-18/4_OKR/04_cik_cak) | 1 s | 128 MB | 22 | `checker.cpp` (custom, converted) | The original checker returned 5 for a correct answer, 3 for a partly correct one, and −1 otherwise. An early copy on Petlja has a different test 2; the contest's problem only ever had this one |
| 2017-18 | Okružno | [Velika matrica](takprog-2017-18/4_OKR/05_velika_matrica) | 2 s | 64 MB | 11 | default | — |
| 2017-18 | Okružno | [Formula](takprog-2017-18/4_OKR/06_formula) | 1 s | 64 MB | 22 | `checker.cpp` (custom) | — |
| 2017-18 | Državno | [Pola-pola](takprog-2017-18/5_DRZ/01_polapola) | 0.5 s | 256 MB | 28 | default | — |
| 2017-18 | Državno | [Trik](takprog-2017-18/5_DRZ/02_trik) | 0.3 s | 256 MB | 33 | `checker.cpp` (custom) | — |
| 2017-18 | Državno | [Esikez](takprog-2017-18/5_DRZ/03_esikez) | 1 s | 256 MB | 43 | default | — |
| 2017-18 | Državno | [Super velika matrica](takprog-2017-18/5_DRZ/04_super_velika) | 3 s | 64 MB | 23 | default | — |
| 2017-18 | Državno | [Sort na stablu](takprog-2017-18/5_DRZ/05_sort_na_stablu) | 2 s | 256 MB | 24 | default | The statement's picture `sortnastablu_ex1.png` is lost |
| 2017-18 | Državno | [Obaranje](takprog-2017-18/5_DRZ/06_obaranje) | 0.5 s | 64 MB | 25 | default | Test 8 exists in two versions on Petlja with the same answer (0): this one, with large coordinates, is current; which one the contest used is unknown. The statement's picture `obaranje_example1.png` is lost |
| 2017-18 | SIO | [Pacovi](takprog-2017-18/6_SIO/01_pacovi) | 0.3 s | 256 MB | 38 | default, `grader/` | Functional |
| 2017-18 | SIO | [Imanje](takprog-2017-18/6_SIO/02_imanje) | — | — | 5 | `checker.cpp` (custom, converted) | Output-only: contestants submit the five outputs, so the limits (Petlja's row says 1 s, 64 MB) don't apply. The checker gives 0–10, 0–20, 0–20, 0–25 and 0–25 points against the commission's result; the original returned them as its exit code. Its flood fill needs a large stack (the grader gives checkers an unlimited one) |
| 2017-18 | SIO | [Popis](takprog-2017-18/6_SIO/03_popis) | 2 s | 512 MB | 21 | default, `grader/` | Functional |
| 2017-18 | SIO | [Bombonice](takprog-2017-18/6_SIO/04_bombonice) | 1.5 s | 128 MB | 26 | default, `grader/` | Functional. Petlja's two earlier versions have wrong expected outputs from test 12 or 13 on; these agree with a solution written from the statement, and the 26 full scores at the contest show it ran on them |
| 2017-18 | SIO | [Voćnjak](takprog-2017-18/6_SIO/05_vocnjak) | 1 s | 128 MB | 41 | `checker.cpp` (custom), `grader/` | Functional. The checker compares the cell (the first two numbers of `.out`) and rejects more queries than allowed |
| 2017-18 | SIO | [Taman](takprog-2017-18/6_SIO/06_taman) | 1 s | 128 MB | 25 | default, `grader/` | Functional |
| 2018-19 | Kvalifikacije 1 | [Pileća krilca](takprog-2018-19/01_KV1/01_krilca) | 1 s | 64 MB | 12 | `checker.cpp` (custom) | — |
| 2018-19 | Kvalifikacije 1 | [Lep niz](takprog-2018-19/01_KV1/02_lep_niz) | 1 s | 64 MB | 52 | default | — |
| 2018-19 | Kvalifikacije 1 | [Deljenje niza](takprog-2018-19/01_KV1/03_deljenje_niza) | 0.498 s | 64 MB | 22 | `checker.cpp` (custom) | — |
| 2018-19 | Kvalifikacije 1 | [Poštar](takprog-2018-19/01_KV1/04_postar) | 2 s | 128 MB | 21 | `checker.cpp` (custom) | The expected outputs of tests 2–21 were corrected 4 minutes into the contest; every submission was graded again with them |
| 2018-19 | Kvalifikacije 1 | [Dodela vrednosti](takprog-2018-19/01_KV1/05_dodela) | 2 s | 512 MB | 11 | default | — |
| 2018-19 | Kvalifikacije 2 | [Nadovezivanje](takprog-2018-19/02_KV2/01_nadovezivanje) | 0.5 s | 128 MB | 12 | default | — |
| 2018-19 | Kvalifikacije 2 | [Dobri pravougaonici](takprog-2018-19/02_KV2/02_dobri_pravougaonici) | 1.5 s | 256 MB | 26 | default | — |
| 2018-19 | Kvalifikacije 2 | [Rokada](takprog-2018-19/02_KV2/03_rokada) | 1 s | 64 MB | 52 | `checker.cpp` (custom) | Test 3 was replaced during the contest; every submission was graded again with it |
| 2018-19 | Kvalifikacije 2 | [Bojenje](takprog-2018-19/02_KV2/04_bojenje) | 1 s | 64 MB | 27 | `checker.cpp` (custom, rewritten) | Petlja's checker has an empty source (it worked until 2025), so this one was written in 2026: it compares the single integer answer, as the round's other checkers do. All tests were uploaded separately before the contest; they are included |
| 2018-19 | Kvalifikacije 2 | [Vrednost dodele](takprog-2018-19/02_KV2/05_vrednost_dodele) | 1.6 s | 1024 MB | 46 | `checker.cpp` (custom) | — |
| 2018-19 | Kvalifikacije 3 | [Vorp Spejs](takprog-2018-19/03_KV3/01_vorpspejs) | 0.4 s | 64 MB | 102 | default | The statement's example 1 places the ship and the exit one column to the left of test 1; the answer is the same |
| 2018-19 | Kvalifikacije 3 | [Moć niza](takprog-2018-19/03_KV3/02_moc_niza) | 0.5 s | 64 MB | 12 | default | — |
| 2018-19 | Kvalifikacije 3 | [Pakovanje](takprog-2018-19/03_KV3/03_pakovanje) | 1.6 s | 64 MB | 12 | default | — |
| 2018-19 | Kvalifikacije 3 | [Požar](takprog-2018-19/03_KV3/04_pozar) | 1 s | 64 MB | 21 | default | — |
| 2018-19 | Kvalifikacije 3 | [Sveska](takprog-2018-19/03_KV3/05_sveska) | 1 s | 256 MB | 26 | default | — |
| 2018-19 | Okružno | [Piramida](takprog-2018-19/04_OKR/01_piramida) | 1 s | 128 MB | 22 | default | — |
| 2018-19 | Okružno | [Fotografisanje](takprog-2018-19/04_OKR/02_fotografisanje) | 1 s | 128 MB | 28 | `checker.cpp` (custom) | — |
| 2018-19 | Okružno | [Grupe](takprog-2018-19/04_OKR/03_grupe) | 1 s | 128 MB | 22 | default | — |
| 2018-19 | Okružno | [Izgubljeni niz](takprog-2018-19/04_OKR/04_izgubljeni_niz) | 1 s | 64 MB | 21 | `checker.cpp` (custom) | — |
| 2018-19 | Okružno | [Slepi brojevi](takprog-2018-19/04_OKR/05_slepi_brojevi) | 0.5 s | 128 MB | 22 | default | — |
| 2018-19 | Okružno | [Žetoni](takprog-2018-19/04_OKR/06_zetoni) | 2 s | 256 MB | 52 | `checker.cpp` (custom) | — |
| 2018-19 | Državno | [Hakerisanje](takprog-2018-19/05_DRZ/01_hakerisanje) | 1 s | 64 MB | 20 | default | — |
| 2018-19 | Državno | [Poljoprivrednik](takprog-2018-19/05_DRZ/02_poljoprivrednik) | 0.5 s | 64 MB | 24 | `checker.cpp` (custom) | The `.out` files are placeholders (−1): the checker counts the pairs in the contestant's array. Every test has a solution, so −1 is never accepted |
| 2018-19 | Državno | [Miniranje](takprog-2018-19/05_DRZ/03_miniranje) | 2 s | 128 MB | 29 | default | — |
| 2018-19 | Državno | [Nz](takprog-2018-19/05_DRZ/04_nz) | 1 s | 512 MB | 67 | default | — |
| 2018-19 | Državno | [Vizaard](takprog-2018-19/05_DRZ/05_vizaard) | 1.5 s | 256 MB | 27 | default | — |
| 2018-19 | Državno | [Pariz](takprog-2018-19/05_DRZ/06_pariz) | 1.5 s | 256 MB | 29 | default | — |
| 2018-19 | SIO | [Kombinovanje](takprog-2018-19/06_SIO/01_kombinovanje) | — | — | 4 | `checker.cpp` (custom, converted) | Output-only, so the limits don't apply. The `.out` files are empty: the checker scores the answer between the bounds P and Q in the input (0–25 per file), and the original returned the points as its exit code. Its inputs were replaced 51 minutes into the day, before anyone had submitted |
| 2018-19 | SIO | [Crno-bela zvezda](takprog-2018-19/06_SIO/02_zvezda) | 0.4 s | 64 MB | 57 | default, `grader/` | Functional |
| 2018-19 | SIO | [Kamera](takprog-2018-19/06_SIO/03_kamera) | 5 s | 512 MB | 45 | default, `grader/` | Functional |
| 2018-19 | SIO | [Skladište](takprog-2018-19/06_SIO/04_skladiste) | 0.3 s | 128 MB | 20 | default, `grader/` | Functional |
| 2018-19 | SIO | [Planine](takprog-2018-19/06_SIO/05_planine) | 1 s | 64 MB | 61 | `checker.cpp` (custom), `grader/` | Functional. The checker compares the peak (the two numbers in `.out`) and rejects more queries than allowed. Test 1 was replaced separately before the contest; this is the replaced version |
| 2018-19 | SIO | [Film](takprog-2018-19/06_SIO/06_film) | 1 s | 256 MB | 58 | `checker.cpp` (custom), `grader/` | Functional |
| 2019-20 | Kvalifikacije 1 | [Isplata](takprog-2019-20/01_KV1/01_isplata) | 0.1 s | 64 MB | 22 | `checker.cpp` (exact tokens) | — |
| 2019-20 | Kvalifikacije 1 | [Odbojka](takprog-2019-20/01_KV1/02_odbojka) | 1 s | 64 MB | 23 | `checker.cpp` (custom) | Tests 6–7 were replaced separately before the contest; this is the replaced version |
| 2019-20 | Kvalifikacije 1 | [Vodopad](takprog-2019-20/01_KV1/03_vodopad) | 1 s | 256 MB | 25 | `checker.cpp` (exact tokens) | — |
| 2019-20 | Kvalifikacije 1 | [Šahovska trka](takprog-2019-20/01_KV1/04_sahovska_trka) | 1 s | 1024 MB | 53 | `checker.cpp` (exact tokens) | — |
| 2019-20 | Kvalifikacije 1 | [Luxor](takprog-2019-20/01_KV1/05_luxor) | 2 s | 64 MB | 21 | `checker.cpp` (custom) | — |
| 2019-20 | Kvalifikacije 2 | [Pikado](takprog-2019-20/02_KV2/01_pikado) | 2 s | 512 MB | 22 | `checker.cpp` (custom) | — |
| 2019-20 | Kvalifikacije 2 | [Polica](takprog-2019-20/02_KV2/02_polica) | 1 s | 512 MB | 22 | `checker.cpp` (exact tokens) | — |
| 2019-20 | Kvalifikacije 2 | [Zlatnici](takprog-2019-20/02_KV2/03_zlatnici) | 1 s | 512 MB | 22 | `checker.cpp` (exact tokens) | — |
| 2019-20 | Kvalifikacije 2 | [JAG](takprog-2019-20/02_KV2/04_jag) | 1 s | 128 MB | 22 | `checker.cpp` (exact tokens) | — |
| 2019-20 | Kvalifikacije 2 | [Gric](takprog-2019-20/02_KV2/05_gric) | 1 s | 512 MB | 21 | `checker.cpp` (custom) | — |
| 2019-20 | Kvalifikacije 3 | [Upoznavanje](takprog-2019-20/03_KV3/01_upoznavanje) | 2 s | 256 MB | 22 | default | — |
| 2019-20 | Kvalifikacije 3 | [Lubenice](takprog-2019-20/03_KV3/02_lubenice) | 0.5 s | 256 MB | 22 | default | — |
| 2019-20 | Kvalifikacije 3 | [Sazvežđa](takprog-2019-20/03_KV3/03_sazvezdja) | 0.5 s | 64 MB | 28 | `checker.cpp` (custom) | — |
| 2019-20 | Kvalifikacije 3 | [Boje](takprog-2019-20/03_KV3/04_boje) | 1 s | 512 MB | 12 | default | — |
| 2019-20 | Kvalifikacije 3 | [K-tačne sekvence zagrada](takprog-2019-20/03_KV3/05_k-tacne_sekvence_zagrada) | 5 s | 64 MB | 11 | `checker.cpp` (custom) | Test 1 was replaced separately before the contest; this is the replaced version |
| 2019-20 | Okružno | [Premeštanja](takprog-2019-20/04_OKR/01_premestanja) | 2.5 s | 512 MB | 22 | default | Tests 7–10, 15, 17–18, 20–21 were replaced separately before the contest; this is the replaced version |
| 2019-20 | Okružno | [Zaboravljena partija](takprog-2019-20/04_OKR/02_zaboravljena) | 1 s | 512 MB | 22 | `checker.cpp` (custom) | The `.out` files say only whether a position exists; the checker verifies the contestant's position itself |
| 2019-20 | Okružno | [Čarobnjak iz voza](takprog-2019-20/04_OKR/03_carobnjak_iz_voza) | 1 s | 512 MB | 22 | default | — |
| 2019-20 | Okružno | [Dobitni listić](takprog-2019-20/04_OKR/04_dobitni_listic) | 0.5 s | 512 MB | 22 | `checker.cpp` (custom) | — |
| 2019-20 | Okružno | [Bezbedna podmatrica](takprog-2019-20/04_OKR/05_bezbedna_podmatrica) | 1 s | 512 MB | 22 | `checker.cpp` (exact tokens) | — |
| 2019-20 | Okružno | [Moj broj](takprog-2019-20/04_OKR/06_moj_broj) | 0.3 s | 512 MB | 11 | `checker.cpp` (custom, converted) | The original checker returned the points (10–100, `divisor: 100`) as its exit code |
| 2019-20 | Državno | [Lek](takprog-2019-20/05_DRZ/01_lek) | 2 s | 256 MB | 42 | `checker.cpp` (custom, one include added) | One `#include <vector>` was added to the checker: today's g++ needs it, and without it nothing has been accepted since 2025 |
| 2019-20 | Državno | [Veštica](takprog-2019-20/05_DRZ/02_vestica) | 1 s | 256 MB | 33 | default | — |
| 2019-20 | Državno | [Trookrugao](takprog-2019-20/05_DRZ/03_trookrugao) | 2.5 s | 512 MB | 32 | default | — |
| 2019-20 | Državno | [Statistika](takprog-2019-20/05_DRZ/04_statistika) | 1.5 s | 256 MB | 16 | default | — |
| 2019-20 | Državno | [Spec zadatak](takprog-2019-20/05_DRZ/05_spec) | 1.5 s | 256 MB | 28 | default | Tests 2, 3, 14, 23 and 28 were corrected in the first 25 minutes of the contest, before any contestant had submitted; this is the corrected set |
| 2019-20 | Državno | [Festival](takprog-2019-20/05_DRZ/06_festival) | 2.5 s | 256 MB | 24 | `checker.cpp` (exact tokens) | Test 16 was replaced separately before the contest; this is the replaced version |
| 2019-20 | SIO | [Brojorb](takprog-2019-20/06_SIO/01_brojorb) | — | — | 16 | default | Output-only, so the limits don't apply. Output 1 is the contestant's source code: it is worth 0 points, and the default checker marks it wrong, as at the contest |
| 2019-20 | SIO | [Šašavo odelo](takprog-2019-20/06_SIO/02_sasavo_odelo) | 1.5 s | 512 MB | 29 | `checker.cpp` (custom), `grader/` | Functional. Test 27 was replaced separately before the contest; this is the replaced version. The `.out` files say only whether a coloring exists; the checker verifies the contestant's coloring itself |
| 2019-20 | SIO | [Smeštaj](takprog-2019-20/06_SIO/03_smestaj) | 1.5 s | 512 MB | 52 | default, `grader/` | Functional |
| 2019-20 | SIO | [Dido](takprog-2019-20/06_SIO/04_dido) | 1 s | 512 MB | 30 | `checker.cpp` (custom), `grader/` | Functional |
| 2019-20 | SIO | [Mračna soba](takprog-2019-20/06_SIO/05_mracna_soba) | 1.5 s | 64 MB | 42 | `checker.cpp` (exact tokens), `grader/` | Functional |
| 2019-20 | SIO | [Metro](takprog-2019-20/06_SIO/06_metro) | 1 s | 512 MB | 18 | default, `grader/` | Functional |
| 2020-21 | Kvalifikacije 1 | [Minimalan trud](takprog-2020-21/01_KV1/01_trud) | 1 s | 256 MB | 12 | default | — |
| 2020-21 | Kvalifikacije 1 | [Prijatelji](takprog-2020-21/01_KV1/02_prijatelji) | 1 s | 256 MB | 22 | default | — |
| 2020-21 | Kvalifikacije 1 | [Žalbe](takprog-2020-21/01_KV1/03_zalbe) | 2 s | 256 MB | 21 | `checker.cpp` (exact tokens) | Tests 11 and 17–21 are from Petlja's version 3: the contest's version 4 has only tests 1–10, and the grader of the time kept the rest from version 3. Tests 12–16 were replaced separately before the contest; this is the replaced version |
| 2020-21 | Kvalifikacije 1 | [Čvrsti brojevi](takprog-2020-21/01_KV1/04_cvrsti_brojevi) | 1 s | 512 MB | 22 | `checker.cpp` (exact tokens) | — |
| 2020-21 | Kvalifikacije 1 | [SIO stablo](takprog-2020-21/01_KV1/05_sio_stablo) | 3 s | 256 MB | 26 | default | — |
| 2020-21 | Kvalifikacije 2 | [Kvadrati](takprog-2020-21/02_KV2/01_kvadrati) | 1 s | 256 MB | 22 | `checker.cpp` (exact tokens) | — |
| 2020-21 | Kvalifikacije 2 | [Uzgajivači jabuka](takprog-2020-21/02_KV2/02_jabuke) | 2 s | 256 MB | 11 | `checker.cpp` (custom) | — |
| 2020-21 | Kvalifikacije 2 | [Slova](takprog-2020-21/02_KV2/03_slova) | 1 s | 256 MB | 12 | default | — |
| 2020-21 | Kvalifikacije 2 | [BUG](takprog-2020-21/02_KV2/04_BUG) | 1 s | 256 MB | 22 | default | — |
| 2020-21 | Kvalifikacije 2 | [01 niz](takprog-2020-21/02_KV2/05_01_niz) | 2 s | 256 MB | 52 | default | Petlja lost tests 12–21, 27, 29, 30, 32–35, 37–40 and 42–51 (the contest graded 52); they are from the 2024 collection, which matches every test Petlja still has. Tests 1–4, 6–8, 22–26, 28, 31, 36, 41 and 52 come from patches uploaded before the contest |
| 2020-21 | Kvalifikacije 3 | [Šampion](takprog-2020-21/03_KV3/01_sampion) | 1 s | 256 MB | 23 | `checker.cpp` (exact tokens) | — |
| 2020-21 | Kvalifikacije 3 | [Gejm šou](takprog-2020-21/03_KV3/02_gejm_sou) | 1 s | 256 MB | 21 | default | — |
| 2020-21 | Kvalifikacije 3 | [Karte 2](takprog-2020-21/03_KV3/03_karte2) | 2.5 s | 256 MB | 12 | `checker.cpp` (custom) | — |
| 2020-21 | Kvalifikacije 3 | [Pitanja](takprog-2020-21/03_KV3/04_pitanja) | 1.5 s | 1024 MB | 27 | default | Petlja lost tests 19–27 (the contest graded 27); they are from the 2024 collection, which matches tests 1–18 |
| 2020-21 | Kvalifikacije 3 | [Novogodišnje stablo](takprog-2020-21/03_KV3/05_novogodisnje_stablo) | 2 s | 256 MB | 21 | `checker.cpp` (custom) | Petlja lost tests 13–21 (the contest graded 21); they are from the 2024 collection, which matches tests 1–12 |
| 2020-21 | Okružno | [Takmičar](takprog-2020-21/04_OKR/01_takmicar) | 1.5 s | 256 MB | 22 | `checker.cpp` (exact tokens) | — |
| 2020-21 | Okružno | [Lepa matrica](takprog-2020-21/04_OKR/02_lepa_matrica) | 2 s | 256 MB | 21 | default | Tests 2–21 were replaced separately before the contest; this is the replaced version |
| 2020-21 | Okružno | [Zlatnici 2: Električni bugalu](takprog-2020-21/04_OKR/03_zlatnici_2_elektricni_bugalu) | 1.5 s | 256 MB | 21 | default | — |
| 2020-21 | Okružno | [Standardan zadatak](takprog-2020-21/04_OKR/04_standardan_zadatak) | 1 s | 256 MB | 22 | default | — |
| 2020-21 | Okružno | [Velika trka](takprog-2020-21/04_OKR/05_velika_trka) | 3 s | 256 MB | 21 | default | — |
| 2020-21 | Okružno | [Altruizam](takprog-2020-21/04_OKR/06_altruizam) | 1 s | 256 MB | 22 | default | The 2024 collection has different tests 4–21 (of 22); these are the ones the contest ran |
| 2020-21 | Državno | [Kvadrati uzvraćaju udarac](takprog-2020-21/05_DRZ/01_kvadrati_uzvracaju_udarac) | 0.5 s | 256 MB | 25 | default | — |
| 2020-21 | Državno | [Preduzeće](takprog-2020-21/05_DRZ/02_preduzece) | 1 s | 256 MB | 22 | default | — |
| 2020-21 | Državno | [Proslava rođendana](takprog-2020-21/05_DRZ/03_proslava_rodjendana) | 2 s | 256 MB | 29 | default | — |
| 2020-21 | Državno | [Žice](takprog-2020-21/05_DRZ/04_zice) | 1 s | 256 MB | 16 | `checker.cpp` (exact tokens) | — |
| 2020-21 | Državno | [Jakuze](takprog-2020-21/05_DRZ/05_jakuze) | 2 s | 256 MB | 25 | default | All tests were uploaded separately before the contest; they are included |
| 2020-21 | Državno | [NZD permutacije](takprog-2020-21/05_DRZ/06_nzd_permutacije) | 2 s | 256 MB | 25 | default | — |
| 2020-21 | SIO | [RNK](takprog-2020-21/06_SIO/01_rnk) | 1 s | 256 MB | 20 | `checker.cpp` (custom), `grader/` | Functional. The `.out` files are placeholders: the checker verifies the contestant's answer itself |
| 2020-21 | SIO | [Marsko](takprog-2020-21/06_SIO/02_marsko) | 1 s | 256 MB | 23 | default, `grader/` | Functional. All tests were uploaded separately before the contest; they are included |
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
