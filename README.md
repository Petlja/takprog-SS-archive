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
