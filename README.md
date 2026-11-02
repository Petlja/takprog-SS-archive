# Takprog archive: high school

Tasks from Serbian high-school informatics competitions (Takprog), restored from Petlja and checked, for the competition
archive. Each task has everything needed to set it again: statement with examples, testcases, checker (or grader), scoring,
and time and memory limits. The tasks are under CC BY, as the competition commission publishes them, except the six
of the 2017 training camp (`takprog-2016-17/PRI`): those are ICPC problems, and their statements are ICPC's.

## Layout

Paths follow the archive's own scheme: `takprog-{season}/{round}/{nn}_{task}/`.

| File | What |
|---|---|
| `statement.md` | The statement in Markdown, with examples. Its header gives `timelimit` (seconds) and `memlimit` (MB) |
| `*.png` | Pictures the statement shows, if any |
| `testcases/` | `NN.in` / `NN.out`: the test set the competition actually ran on. Where a custom checker verifies the answer itself, `.out` may be empty, a placeholder or the bounds it scores against |
| `checker.cpp` | The competition's checker, when it had one. Called as `checker <contestant output> <expected output> <input>`. Exit code 0 = accepted, anything else = wrong; a number on stdout is the score (divided by `divisor` when `scoring.yaml` has one). Checkers marked *converted* were written for Petlja's grader before 2025, which read the exit code as the score: their own code is unchanged, and a short `main` at the end translates the result. Checkers marked *rewritten* replace one that couldn't be retrieved (only a Windows binary or an empty source survives): they were written in 2026 from the statement. Checkers run with an unlimited stack, as on Petlja's grader |
| `scoring.yaml` | The competition's scoring: subtasks, points, public tests. `score_total: null` means each test is worth the points its checker gives |
| `grader/` | Functional tasks only (the contestant writes functions, not a program): the competition's grader, per language, as Petlja serves it. `cpp/main.cpp` and `cpp/code.h` are compiled together with the contestant's file; `pas/` is the Pascal version from the same contest |

Six missing statement illustrations (Kružna škola, Krompir, Baza, Count the Regions, Sort na stablu and Obaranje)
and vOOda’s eight input pictures were restored from the commission’s `takprog-*` repositories. The vOOda
pictures are named `1.png`–`8.png` as in the statement; their pixels match the corresponding archived input tests.

## How a task gets here

**Tests, limits, checker and scoring come from the competition on Petlja**, as the contest ran. They are taken byte
for byte from the problem's test version that was live on the contest date, after comparing every copy on Petlja: all
test versions, the competition, its testing and archive copies. The 2024 collection (`takprog-SS-zbirka-2024`) is not
used for these: it has fewer tests and different limits. Only the **statement**,
which the collection shares with the competition, comes from it.

Before a task is added, solutions are run against the chosen testcases in a copy of Petlja's grader: the collection's
author solutions where it has them, otherwise solutions submitted at the contest, which must get the verdict the contest
recorded on every test. Functional tasks run with their grader; for output-only tasks the answers submitted at the
contest are scored again with the checker. Anything
missing or not working is listed in the table below, for the authors to fill in.

**Seasons the collection doesn't cover** (it has 2019-20 to 2023-24) come from Petlja alone; their tasks were
checked with solutions submitted at the contest. In 2016-17, the statements are Petlja's own, in Latin script as the contest showed them, converted from
HTML. Petlja kept only one version of the tests, so the contest's set is the one it still has; where a round was
also set up as a separate testing competition, the two sets were compared. The scoring was kept as per-test and
per-subtask rows rather than a scoring file; `scoring.yaml` is rebuilt from them.

The 2017 training camp (PRI, two practice contests in June and July 2017) used six ICPC problems, in English, with
Petlja's section headings. They were judged as at ICPC: a submission solves the problem or doesn't, and Petlja has no
scoring for them, so `scoring.yaml` gives the 100 points only for passing every test. Most have a single test file
with many cases, so the statement's examples are not separate tests.

In 2017-18 the statements are the commission's Markdown originals, in Cyrillic, as Petlja stores them (Kvalifikacije 1
has only Petlja's HTML, converted the same way as 2016-17). Petlja moved every test file in November 2018, so all
versions carry that date; the contest's set is the version the problem still serves, unless that one was uploaded
after the move. Every task was also compared with a second copy that Petlja kept separately, an early collection
of the same tasks.

From 2018-19 on, Petlja kept every test version with the time it was uploaded, and the competition's scoring file. The
contest's set is the last version uploaded before the contest ended, with any tests uploaded separately before it
ended. Where the commission corrected tests during a contest and graded every submission again, the set is the
corrected one.

In 2019-20 and 2020-21 the statements come from the collection, except SIO, which it doesn't have (those are
Petlja's Markdown originals). For four 2020-21 tasks Petlja's storage no longer has every test the contest graded
(the grader of the time kept tests from earlier uploads). Where an earlier upload on Petlja still has them, they come
from there; otherwise from the collection, which matches every test Petlja does have. Submissions accepted at the
contest pass the completed sets. The table says which tests these are.

In 2021-22 the statements come from the collection, except SIO and the EJOI and EGOI selection rounds, which it
doesn't have: those are Petlja's Markdown originals, and their tasks were checked with solutions submitted at the
contest.

In 2022-23 and 2023-24 the statements come from the collection, SIO included, except Quaestio militaris formationis
(2023-24 SIO): the collection has another task's statement there, so it is Petlja's Markdown original. Where the
commission uploaded tests again during a contest, every earlier submission was graded again, so the set is the one
Petlja had at the end.

2024-25 and later have no collection: the statements are the commission's Markdown originals from Petlja, in
Cyrillic, and the tasks were checked with solutions submitted at the contest. From the 2024-25
selection rounds on, the contests ran on Petlja's Linux grader. In 2025-26 several checkers score each test
themselves and there is no scoring file on Petlja; there `scoring.yaml` says `score_total: null`, as at the contest.

## Limits

- **Time limit:** CPU time of the solution on one testcase, not wall-clock time.
- **Memory limit:** the solution's peak memory on one testcase. Stack may use up to 256 MB within it.
- **Where they were checked:** Petlja's grader as of 2026. That's Linux on an Intel Xeon Platinum 8272CL at
  2.6 GHz, with every run sandboxed by [isolate](https://github.com/ioi/isolate). C++ is compiled with g++ 14.2,
  `-std=gnu++17 -O2 -static`; Python is 3.13.
- The limits are the ones set for the competition, on the grader of that time (until 2025 a Windows machine with
  other compilers). Every task's solutions were re-run on today's grader and pass within the limits, except where
  the table says otherwise.

## Tasks

Limits are the competition's. *Type* is `standard` (the program reads the input and writes the output), `functional`
(the contestant writes functions; `grader/` has the main program) or `output-only` (contestants submit the output
files, so the limits don't apply). *Checker* is `default` when the task uses a plain token comparison and needs no
`checker.cpp`.

The last two columns list only what is missing or doesn't work; everything else is as the contest had it.
Please check the tasks against your own copies too.

| Season | Round | Task | Type | Time | Memory | Testcases | Checker | Task problems | Testcase problems |
|---|---|---|---|---|---|---|---|---|---|
| 2016-17 | Kvalifikacije | [Trotoar](takprog-2016-17/1_KV1/01_trotoar) | standard | 1 s | 64 MB | 22 | default | — | — |
| 2016-17 | Kvalifikacije | [Papir, kamen, makaze](takprog-2016-17/1_KV1/02_papir_kamen_makaze) | standard | 1 s | 64 MB | 22 | default | — | — |
| 2016-17 | Kvalifikacije | [Kul kule](takprog-2016-17/1_KV1/03_kul_kule) | standard | 1 s | 64 MB | 22 | default | — | — |
| 2016-17 | Kvalifikacije | [Filozof](takprog-2016-17/1_KV1/04_filozof) | standard | 0.5 s | 256 MB | 12 | default | — | — |
| 2016-17 | Kvalifikacije | [Sportski centar](takprog-2016-17/1_KV1/05_sportski_centar) | standard | 0.2 s | 64 MB | 12 | default | Picture `img_sportski_centar.png` lost | — |
| 2016-17 | Kvalifikacije | [Kružna škola](takprog-2016-17/1_KV1/06_kruzna_skola) | standard | 1 s | 256 MB | 27 | default | — | — |
| 2016-17 | Okružno | [Krompir](takprog-2016-17/2_OKR/01_krompir) | standard | 0.5 s | 256 MB | 22 | default | — | — |
| 2016-17 | Okružno | [Raketa](takprog-2016-17/2_OKR/02_raketa) | standard | 0.1 s | 256 MB | 27 | default | — | — |
| 2016-17 | Okružno | [Marsovci](takprog-2016-17/2_OKR/03_marsovci) | standard | 0.5 s | 256 MB | 22 | default | — | — |
| 2016-17 | Okružno | [Baza](takprog-2016-17/2_OKR/04_baza) | standard | 1 s | 256 MB | 22 | `checker.cpp` (custom, rewritten) | — | — |
| 2016-17 | Okružno | [Kosmodrom](takprog-2016-17/2_OKR/05_kosmodrom) | standard | 0.3 s | 256 MB | 12 | default | — | — |
| 2016-17 | Okružno | [Mingo](takprog-2016-17/2_OKR/06_mingo) | standard | 1.5 s | 256 MB | 22 | default | — | — |
| 2016-17 | Državno | [Bond](takprog-2016-17/3_DRZ/01_bond) | standard | 1 s | 256 MB | 20 | default | — | — |
| 2016-17 | Državno | [Hari](takprog-2016-17/3_DRZ/02_hari) | standard | 0.4 s | 64 MB | 26 | default | — | — |
| 2016-17 | Državno | [Kladionica](takprog-2016-17/3_DRZ/03_kladionica) | standard | 0.7 s | 256 MB | 26 | default | — | — |
| 2016-17 | Državno | [Karibi](takprog-2016-17/3_DRZ/04_karibi) | standard | 1.5 s | 256 MB | 27 | default | — | — |
| 2016-17 | Državno | [Prorok](takprog-2016-17/3_DRZ/05_prorok) | standard | 0.3 s | 64 MB | 19 | default | — | — |
| 2016-17 | Državno | [Karte](takprog-2016-17/3_DRZ/06_karte) | standard | 0.6 s | 64 MB | 23 | default | — | — |
| 2016-17 | SIO | [Klikeri](takprog-2016-17/4_SIO/01_klikeri) | standard | 1.5 s | 64 MB | 41 | default | — | — |
| 2016-17 | SIO | [Zaduženja](takprog-2016-17/4_SIO/02_zaduzenja) | standard | 1.5 s | 64 MB | 30 | default | — | — |
| 2016-17 | SIO | [Tetke](takprog-2016-17/4_SIO/03_tetke) | standard | 3 s | 192 MB | 22 | default | — | — |
| 2016-17 | SIO | [Neonke](takprog-2016-17/4_SIO/04_neonke) | output-only | — | — | 4 | `checker.cpp` (custom, rewritten) | The `Neonke.jar` visualizer the statement mentions is lost | — |
| 2016-17 | SIO | [Virus](takprog-2016-17/4_SIO/05_virus) | standard | 1 s | 64 MB | 50 | `checker.cpp` (custom, rewritten) | The output section is a placeholder (the example shows the format) | — |
| 2016-17 | SIO | [Pogled](takprog-2016-17/4_SIO/06_pogled) | standard | 1 s | 64 MB | 26 | default | — | — |
| 2016-17 | Pripreme | [Collecting Luggage](takprog-2016-17/PRI/CollectingLuggage) | standard | 10 s | 256 MB | 0 | default | The figure the statement describes is lost. The limits may be Two Circles' (see testcases) | **No testcases:** Petlja's copy has Two Circles' tests instead |
| 2016-17 | Pripreme | [CosmoCraft](takprog-2016-17/PRI/CosmoCraft) | standard | 3 s | 64 MB | 1 | default | — | — |
| 2016-17 | Pripreme | [Count the Regions](takprog-2016-17/PRI/Count) | standard | 0.3 s | 64 MB | 1 | default | — | — |
| 2016-17 | Pripreme | [Covered walkway](takprog-2016-17/PRI/CoveredWalkway) | standard | 100 s | 256 MB | 1 | default | — | — |
| 2016-17 | Pripreme | [Red/Blue Spanning Tree](takprog-2016-17/PRI/RedBlue) | standard | 3 s | 64 MB | 1 | default | — | — |
| 2016-17 | Pripreme | [Two Circles](takprog-2016-17/PRI/TwoCircles) | standard | 10 s | 256 MB | 10 | `checker.cpp` (custom, rewritten) | — | — |
| 2017-18 | Kvalifikacije 1 | [Prva cifra](takprog-2017-18/1_KV1/01_prva_cifra) | standard | 0.1 s | 64 MB | 12 | default | — | — |
| 2017-18 | Kvalifikacije 1 | [Transformacija matrice](takprog-2017-18/1_KV1/02_transformacija_matrice) | standard | 4 s | 128 MB | 22 | default | — | — |
| 2017-18 | Kvalifikacije 1 | [Prodavnice](takprog-2017-18/1_KV1/03_prodavnice) | standard | 1 s | 64 MB | 22 | default | — | — |
| 2017-18 | Kvalifikacije 1 | [Okrnjen trougao](takprog-2017-18/1_KV1/04_okrnjen_trougao) | standard | 1 s | 128 MB | 22 | `checker.cpp` (custom) | — | Test 11's answer is about 2.6·10³⁵: solutions that overflow a `double` along the way fail it today (the 2017 grader let them through) |
| 2017-18 | Kvalifikacije 1 | [Nagrade](takprog-2017-18/1_KV1/05_nagrade) | standard | 1 s | 128 MB | 22 | `checker.cpp` (custom) | — | — |
| 2017-18 | Kvalifikacije 2 | [Mala matrica](takprog-2017-18/2_KV2/01_mala_matrica) | standard | 1 s | 256 MB | 22 | `checker.cpp` (custom) | — | — |
| 2017-18 | Kvalifikacije 2 | [Trivijalan broj](takprog-2017-18/2_KV2/02_trivijalan_broj) | standard | 2 s | 256 MB | 11 | default | — | — |
| 2017-18 | Kvalifikacije 2 | [Topla voda](takprog-2017-18/2_KV2/03_topla_voda) | standard | 2 s | 128 MB | 22 | default | — | — |
| 2017-18 | Kvalifikacije 2 | [Džokeri](takprog-2017-18/2_KV2/04_dzokeri) | standard | 1 s | 256 MB | 22 | default | — | — |
| 2017-18 | Kvalifikacije 2 | [Kiosci](takprog-2017-18/2_KV2/05_kiosci) | standard | 2.5 s | 512 MB | 22 | default | — | — |
| 2017-18 | Kvalifikacije 3 | [Zečevi](takprog-2017-18/3_KV3/01_zecevi) | standard | 0.2 s | 64 MB | 54 | `checker.cpp` (custom) | — | — |
| 2017-18 | Kvalifikacije 3 | [Najbliži neopadajući](takprog-2017-18/3_KV3/02_najblizi_neopadajuci) | standard | 0.3 s | 64 MB | 44 | default | — | — |
| 2017-18 | Kvalifikacije 3 | [Struja](takprog-2017-18/3_KV3/03_struja) | standard | 2 s | 128 MB | 22 | `checker.cpp` (custom) | — | — |
| 2017-18 | Kvalifikacije 3 | [Plus-minus](takprog-2017-18/3_KV3/04_plus_minus) | standard | 1 s | 128 MB | 22 | `checker.cpp` (custom) | — | — |
| 2017-18 | Kvalifikacije 3 | [Prepisivanje](takprog-2017-18/3_KV3/05_prepisivanje) | standard | 2.5 s | 512 MB | 22 | default | — | — |
| 2017-18 | Okružno | [Pangram](takprog-2017-18/4_OKR/01_pangram) | standard | 1 s | 512 MB | 22 | `checker.cpp` (custom) | — | — |
| 2017-18 | Okružno | [Matriks](takprog-2017-18/4_OKR/02_matriks) | standard | 1 s | 64 MB | 11 | default | — | — |
| 2017-18 | Okružno | [Žalbe](takprog-2017-18/4_OKR/03_zalbe) | standard | 0.5 s | 64 MB | 22 | `checker.cpp` (custom, converted) | — | — |
| 2017-18 | Okružno | [Cik-cak](takprog-2017-18/4_OKR/04_cik_cak) | standard | 1 s | 128 MB | 22 | `checker.cpp` (custom, converted) | — | — |
| 2017-18 | Okružno | [Velika matrica](takprog-2017-18/4_OKR/05_velika_matrica) | standard | 2 s | 64 MB | 11 | default | — | — |
| 2017-18 | Okružno | [Formula](takprog-2017-18/4_OKR/06_formula) | standard | 1 s | 64 MB | 22 | `checker.cpp` (custom) | — | — |
| 2017-18 | Državno | [Pola-pola](takprog-2017-18/5_DRZ/01_polapola) | standard | 0.5 s | 256 MB | 28 | default | — | — |
| 2017-18 | Državno | [Trik](takprog-2017-18/5_DRZ/02_trik) | standard | 0.3 s | 256 MB | 33 | `checker.cpp` (custom) | — | — |
| 2017-18 | Državno | [Esikez](takprog-2017-18/5_DRZ/03_esikez) | standard | 1 s | 256 MB | 43 | default | — | — |
| 2017-18 | Državno | [Super velika matrica](takprog-2017-18/5_DRZ/04_super_velika) | standard | 3 s | 64 MB | 23 | default | — | — |
| 2017-18 | Državno | [Sort na stablu](takprog-2017-18/5_DRZ/05_sort_na_stablu) | standard | 2 s | 256 MB | 24 | default | — | — |
| 2017-18 | Državno | [Obaranje](takprog-2017-18/5_DRZ/06_obaranje) | standard | 0.5 s | 64 MB | 25 | default | — | — |
| 2017-18 | SIO | [Pacovi](takprog-2017-18/6_SIO/01_pacovi) | functional | 0.3 s | 256 MB | 38 | default | — | — |
| 2017-18 | SIO | [Imanje](takprog-2017-18/6_SIO/02_imanje) | output-only | — | — | 5 | `checker.cpp` (custom, converted) | — | — |
| 2017-18 | SIO | [Popis](takprog-2017-18/6_SIO/03_popis) | functional | 2 s | 512 MB | 21 | default | — | — |
| 2017-18 | SIO | [Bombonice](takprog-2017-18/6_SIO/04_bombonice) | functional | 1.5 s | 128 MB | 26 | default | — | — |
| 2017-18 | SIO | [Voćnjak](takprog-2017-18/6_SIO/05_vocnjak) | functional | 1 s | 128 MB | 41 | `checker.cpp` (custom) | — | — |
| 2017-18 | SIO | [Taman](takprog-2017-18/6_SIO/06_taman) | functional | 1 s | 128 MB | 25 | default | — | — |
| 2018-19 | Kvalifikacije 1 | [Pileća krilca](takprog-2018-19/01_KV1/01_krilca) | standard | 1 s | 64 MB | 12 | `checker.cpp` (custom) | — | — |
| 2018-19 | Kvalifikacije 1 | [Lep niz](takprog-2018-19/01_KV1/02_lep_niz) | standard | 1 s | 64 MB | 52 | default | — | — |
| 2018-19 | Kvalifikacije 1 | [Deljenje niza](takprog-2018-19/01_KV1/03_deljenje_niza) | standard | 0.498 s | 64 MB | 22 | `checker.cpp` (custom) | — | — |
| 2018-19 | Kvalifikacije 1 | [Poštar](takprog-2018-19/01_KV1/04_postar) | standard | 2 s | 128 MB | 21 | `checker.cpp` (custom) | — | — |
| 2018-19 | Kvalifikacije 1 | [Dodela vrednosti](takprog-2018-19/01_KV1/05_dodela) | standard | 2 s | 512 MB | 11 | default | — | — |
| 2018-19 | Kvalifikacije 2 | [Nadovezivanje](takprog-2018-19/02_KV2/01_nadovezivanje) | standard | 0.5 s | 128 MB | 12 | default | — | — |
| 2018-19 | Kvalifikacije 2 | [Dobri pravougaonici](takprog-2018-19/02_KV2/02_dobri_pravougaonici) | standard | 1.5 s | 256 MB | 26 | default | — | — |
| 2018-19 | Kvalifikacije 2 | [Rokada](takprog-2018-19/02_KV2/03_rokada) | standard | 1 s | 64 MB | 52 | `checker.cpp` (custom) | — | — |
| 2018-19 | Kvalifikacije 2 | [Bojenje](takprog-2018-19/02_KV2/04_bojenje) | standard | 1 s | 64 MB | 27 | `checker.cpp` (custom, rewritten) | — | — |
| 2018-19 | Kvalifikacije 2 | [Vrednost dodele](takprog-2018-19/02_KV2/05_vrednost_dodele) | standard | 1.6 s | 1024 MB | 46 | `checker.cpp` (custom) | — | — |
| 2018-19 | Kvalifikacije 3 | [Vorp Spejs](takprog-2018-19/03_KV3/01_vorpspejs) | standard | 0.4 s | 64 MB | 102 | default | — | — |
| 2018-19 | Kvalifikacije 3 | [Moć niza](takprog-2018-19/03_KV3/02_moc_niza) | standard | 0.5 s | 64 MB | 12 | default | — | — |
| 2018-19 | Kvalifikacije 3 | [Pakovanje](takprog-2018-19/03_KV3/03_pakovanje) | standard | 1.6 s | 64 MB | 12 | default | — | — |
| 2018-19 | Kvalifikacije 3 | [Požar](takprog-2018-19/03_KV3/04_pozar) | standard | 1 s | 64 MB | 21 | default | — | — |
| 2018-19 | Kvalifikacije 3 | [Sveska](takprog-2018-19/03_KV3/05_sveska) | standard | 1 s | 256 MB | 26 | default | — | — |
| 2018-19 | Okružno | [Piramida](takprog-2018-19/04_OKR/01_piramida) | standard | 1 s | 128 MB | 22 | default | — | — |
| 2018-19 | Okružno | [Fotografisanje](takprog-2018-19/04_OKR/02_fotografisanje) | standard | 1 s | 128 MB | 28 | `checker.cpp` (custom) | — | — |
| 2018-19 | Okružno | [Grupe](takprog-2018-19/04_OKR/03_grupe) | standard | 1 s | 128 MB | 22 | default | — | — |
| 2018-19 | Okružno | [Izgubljeni niz](takprog-2018-19/04_OKR/04_izgubljeni_niz) | standard | 1 s | 64 MB | 21 | `checker.cpp` (custom) | — | — |
| 2018-19 | Okružno | [Slepi brojevi](takprog-2018-19/04_OKR/05_slepi_brojevi) | standard | 0.5 s | 128 MB | 22 | default | — | — |
| 2018-19 | Okružno | [Žetoni](takprog-2018-19/04_OKR/06_zetoni) | standard | 2 s | 256 MB | 52 | `checker.cpp` (custom) | — | — |
| 2018-19 | Državno | [Hakerisanje](takprog-2018-19/05_DRZ/01_hakerisanje) | standard | 1 s | 64 MB | 20 | default | — | — |
| 2018-19 | Državno | [Poljoprivrednik](takprog-2018-19/05_DRZ/02_poljoprivrednik) | standard | 0.5 s | 64 MB | 24 | `checker.cpp` (custom) | — | — |
| 2018-19 | Državno | [Miniranje](takprog-2018-19/05_DRZ/03_miniranje) | standard | 2 s | 128 MB | 29 | default | — | — |
| 2018-19 | Državno | [Nz](takprog-2018-19/05_DRZ/04_nz) | standard | 1 s | 512 MB | 67 | default | — | — |
| 2018-19 | Državno | [Vizaard](takprog-2018-19/05_DRZ/05_vizaard) | standard | 1.5 s | 256 MB | 27 | default | — | — |
| 2018-19 | Državno | [Pariz](takprog-2018-19/05_DRZ/06_pariz) | standard | 1.5 s | 256 MB | 29 | default | — | — |
| 2018-19 | SIO | [Kombinovanje](takprog-2018-19/06_SIO/01_kombinovanje) | output-only | — | — | 4 | `checker.cpp` (custom, converted) | — | — |
| 2018-19 | SIO | [Crno-bela zvezda](takprog-2018-19/06_SIO/02_zvezda) | functional | 0.4 s | 64 MB | 57 | default | — | — |
| 2018-19 | SIO | [Kamera](takprog-2018-19/06_SIO/03_kamera) | functional | 5 s | 512 MB | 45 | default | — | — |
| 2018-19 | SIO | [Skladište](takprog-2018-19/06_SIO/04_skladiste) | functional | 0.3 s | 128 MB | 20 | default | — | — |
| 2018-19 | SIO | [Planine](takprog-2018-19/06_SIO/05_planine) | functional | 1 s | 64 MB | 61 | `checker.cpp` (custom) | 64 MB is too tight for today's grader, which counts memory a program declares: solutions accepted at the contest crash at start | — |
| 2018-19 | SIO | [Film](takprog-2018-19/06_SIO/06_film) | functional | 1 s | 256 MB | 58 | `checker.cpp` (custom) | — | — |
| 2019-20 | Kvalifikacije 1 | [Isplata](takprog-2019-20/01_KV1/01_isplata) | standard | 0.1 s | 64 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2019-20 | Kvalifikacije 1 | [Odbojka](takprog-2019-20/01_KV1/02_odbojka) | standard | 1 s | 64 MB | 23 | `checker.cpp` (custom) | — | — |
| 2019-20 | Kvalifikacije 1 | [Vodopad](takprog-2019-20/01_KV1/03_vodopad) | standard | 1 s | 256 MB | 25 | `checker.cpp` (exact tokens) | — | — |
| 2019-20 | Kvalifikacije 1 | [Šahovska trka](takprog-2019-20/01_KV1/04_sahovska_trka) | standard | 1 s | 1024 MB | 53 | `checker.cpp` (exact tokens) | — | — |
| 2019-20 | Kvalifikacije 1 | [Luxor](takprog-2019-20/01_KV1/05_luxor) | standard | 2 s | 64 MB | 21 | `checker.cpp` (custom) | — | — |
| 2019-20 | Kvalifikacije 2 | [Pikado](takprog-2019-20/02_KV2/01_pikado) | standard | 2 s | 512 MB | 22 | `checker.cpp` (custom) | — | — |
| 2019-20 | Kvalifikacije 2 | [Polica](takprog-2019-20/02_KV2/02_polica) | standard | 1 s | 512 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2019-20 | Kvalifikacije 2 | [Zlatnici](takprog-2019-20/02_KV2/03_zlatnici) | standard | 1 s | 512 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2019-20 | Kvalifikacije 2 | [JAG](takprog-2019-20/02_KV2/04_jag) | standard | 1 s | 128 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2019-20 | Kvalifikacije 2 | [Gric](takprog-2019-20/02_KV2/05_gric) | standard | 1 s | 512 MB | 21 | `checker.cpp` (custom) | — | — |
| 2019-20 | Kvalifikacije 3 | [Upoznavanje](takprog-2019-20/03_KV3/01_upoznavanje) | standard | 2 s | 256 MB | 22 | default | — | — |
| 2019-20 | Kvalifikacije 3 | [Lubenice](takprog-2019-20/03_KV3/02_lubenice) | standard | 0.5 s | 256 MB | 22 | default | — | — |
| 2019-20 | Kvalifikacije 3 | [Sazvežđa](takprog-2019-20/03_KV3/03_sazvezdja) | standard | 0.5 s | 64 MB | 28 | `checker.cpp` (custom) | — | — |
| 2019-20 | Kvalifikacije 3 | [Boje](takprog-2019-20/03_KV3/04_boje) | standard | 1 s | 512 MB | 12 | default | — | — |
| 2019-20 | Kvalifikacije 3 | [K-tačne sekvence zagrada](takprog-2019-20/03_KV3/05_k-tacne_sekvence_zagrada) | standard | 5 s | 64 MB | 11 | `checker.cpp` (custom) | — | — |
| 2019-20 | Okružno | [Premeštanja](takprog-2019-20/04_OKR/01_premestanja) | standard | 2.5 s | 512 MB | 22 | default | — | — |
| 2019-20 | Okružno | [Zaboravljena partija](takprog-2019-20/04_OKR/02_zaboravljena) | standard | 1 s | 512 MB | 22 | `checker.cpp` (custom) | — | — |
| 2019-20 | Okružno | [Čarobnjak iz voza](takprog-2019-20/04_OKR/03_carobnjak_iz_voza) | standard | 1 s | 512 MB | 22 | default | — | — |
| 2019-20 | Okružno | [Dobitni listić](takprog-2019-20/04_OKR/04_dobitni_listic) | standard | 0.5 s | 512 MB | 22 | `checker.cpp` (custom) | — | — |
| 2019-20 | Okružno | [Bezbedna podmatrica](takprog-2019-20/04_OKR/05_bezbedna_podmatrica) | standard | 1 s | 512 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2019-20 | Okružno | [Moj broj](takprog-2019-20/04_OKR/06_moj_broj) | standard | 0.3 s | 512 MB | 11 | `checker.cpp` (custom, converted) | — | — |
| 2019-20 | Državno | [Lek](takprog-2019-20/05_DRZ/01_lek) | standard | 2 s | 256 MB | 42 | `checker.cpp` (custom, one include added) | — | — |
| 2019-20 | Državno | [Veštica](takprog-2019-20/05_DRZ/02_vestica) | standard | 1 s | 256 MB | 33 | default | — | — |
| 2019-20 | Državno | [Trookrugao](takprog-2019-20/05_DRZ/03_trookrugao) | standard | 2.5 s | 512 MB | 32 | default | — | — |
| 2019-20 | Državno | [Statistika](takprog-2019-20/05_DRZ/04_statistika) | standard | 1.5 s | 256 MB | 16 | default | — | — |
| 2019-20 | Državno | [Spec zadatak](takprog-2019-20/05_DRZ/05_spec) | standard | 1.5 s | 256 MB | 28 | default | — | — |
| 2019-20 | Državno | [Festival](takprog-2019-20/05_DRZ/06_festival) | standard | 2.5 s | 256 MB | 24 | `checker.cpp` (exact tokens) | — | — |
| 2019-20 | SIO | [Brojorb](takprog-2019-20/06_SIO/01_brojorb) | output-only | — | — | 16 | default | — | Test 1 asks for the contestant's source code (0 points): the default checker always marks it wrong |
| 2019-20 | SIO | [Šašavo odelo](takprog-2019-20/06_SIO/02_sasavo_odelo) | functional | 1.5 s | 512 MB | 29 | `checker.cpp` (custom) | — | — |
| 2019-20 | SIO | [Smeštaj](takprog-2019-20/06_SIO/03_smestaj) | functional | 1.5 s | 512 MB | 52 | default | — | — |
| 2019-20 | SIO | [Dido](takprog-2019-20/06_SIO/04_dido) | functional | 1 s | 512 MB | 30 | `checker.cpp` (custom) | — | — |
| 2019-20 | SIO | [Mračna soba](takprog-2019-20/06_SIO/05_mracna_soba) | functional | 1.5 s | 64 MB | 42 | `checker.cpp` (exact tokens) | — | — |
| 2019-20 | SIO | [Metro](takprog-2019-20/06_SIO/06_metro) | functional | 1 s | 512 MB | 18 | default | — | — |
| 2020-21 | Kvalifikacije 1 | [Minimalan trud](takprog-2020-21/01_KV1/01_trud) | standard | 1 s | 256 MB | 12 | default | — | — |
| 2020-21 | Kvalifikacije 1 | [Prijatelji](takprog-2020-21/01_KV1/02_prijatelji) | standard | 1 s | 256 MB | 22 | default | — | — |
| 2020-21 | Kvalifikacije 1 | [Žalbe](takprog-2020-21/01_KV1/03_zalbe) | standard | 2 s | 256 MB | 21 | `checker.cpp` (exact tokens) | — | — |
| 2020-21 | Kvalifikacije 1 | [Čvrsti brojevi](takprog-2020-21/01_KV1/04_cvrsti_brojevi) | standard | 1 s | 512 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2020-21 | Kvalifikacije 1 | [SIO stablo](takprog-2020-21/01_KV1/05_sio_stablo) | standard | 3 s | 256 MB | 26 | default | — | — |
| 2020-21 | Kvalifikacije 2 | [Kvadrati](takprog-2020-21/02_KV2/01_kvadrati) | standard | 1 s | 256 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2020-21 | Kvalifikacije 2 | [Uzgajivači jabuka](takprog-2020-21/02_KV2/02_jabuke) | standard | 2 s | 256 MB | 11 | `checker.cpp` (custom) | — | — |
| 2020-21 | Kvalifikacije 2 | [Slova](takprog-2020-21/02_KV2/03_slova) | standard | 1 s | 256 MB | 12 | default | — | — |
| 2020-21 | Kvalifikacije 2 | [BUG](takprog-2020-21/02_KV2/04_BUG) | standard | 1 s | 256 MB | 22 | default | — | — |
| 2020-21 | Kvalifikacije 2 | [01 niz](takprog-2020-21/02_KV2/05_01_niz) | standard | 2 s | 256 MB | 52 | default | — | Tests 12–21, 27, 29, 30, 32–35, 37–40 and 42–51 are lost on Petlja; these are the 2024 collection's |
| 2020-21 | Kvalifikacije 3 | [Šampion](takprog-2020-21/03_KV3/01_sampion) | standard | 1 s | 256 MB | 23 | `checker.cpp` (exact tokens) | — | — |
| 2020-21 | Kvalifikacije 3 | [Gejm šou](takprog-2020-21/03_KV3/02_gejm_sou) | standard | 1 s | 256 MB | 21 | default | — | — |
| 2020-21 | Kvalifikacije 3 | [Karte 2](takprog-2020-21/03_KV3/03_karte2) | standard | 2.5 s | 256 MB | 12 | `checker.cpp` (custom) | — | — |
| 2020-21 | Kvalifikacije 3 | [Pitanja](takprog-2020-21/03_KV3/04_pitanja) | standard | 1.5 s | 1024 MB | 27 | default | — | Tests 19–27 are lost on Petlja; these are the 2024 collection's |
| 2020-21 | Kvalifikacije 3 | [Novogodišnje stablo](takprog-2020-21/03_KV3/05_novogodisnje_stablo) | standard | 2 s | 256 MB | 21 | `checker.cpp` (custom) | — | Tests 13–21 are lost on Petlja; these are the 2024 collection's |
| 2020-21 | Okružno | [Takmičar](takprog-2020-21/04_OKR/01_takmicar) | standard | 1.5 s | 256 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2020-21 | Okružno | [Lepa matrica](takprog-2020-21/04_OKR/02_lepa_matrica) | standard | 2 s | 256 MB | 21 | default | — | — |
| 2020-21 | Okružno | [Zlatnici 2: Električni bugalu](takprog-2020-21/04_OKR/03_zlatnici_2_elektricni_bugalu) | standard | 1.5 s | 256 MB | 21 | default | — | — |
| 2020-21 | Okružno | [Standardan zadatak](takprog-2020-21/04_OKR/04_standardan_zadatak) | standard | 1 s | 256 MB | 22 | default | — | — |
| 2020-21 | Okružno | [Velika trka](takprog-2020-21/04_OKR/05_velika_trka) | standard | 3 s | 256 MB | 21 | default | — | — |
| 2020-21 | Okružno | [Altruizam](takprog-2020-21/04_OKR/06_altruizam) | standard | 1 s | 256 MB | 22 | default | — | — |
| 2020-21 | Državno | [Kvadrati uzvraćaju udarac](takprog-2020-21/05_DRZ/01_kvadrati_uzvracaju_udarac) | standard | 0.5 s | 256 MB | 25 | default | — | — |
| 2020-21 | Državno | [Preduzeće](takprog-2020-21/05_DRZ/02_preduzece) | standard | 1 s | 256 MB | 22 | default | — | — |
| 2020-21 | Državno | [Proslava rođendana](takprog-2020-21/05_DRZ/03_proslava_rodjendana) | standard | 2 s | 256 MB | 29 | default | — | — |
| 2020-21 | Državno | [Žice](takprog-2020-21/05_DRZ/04_zice) | standard | 1 s | 256 MB | 16 | `checker.cpp` (exact tokens) | — | — |
| 2020-21 | Državno | [Jakuze](takprog-2020-21/05_DRZ/05_jakuze) | standard | 2 s | 256 MB | 25 | default | — | — |
| 2020-21 | Državno | [NZD permutacije](takprog-2020-21/05_DRZ/06_nzd_permutacije) | standard | 2 s | 256 MB | 25 | default | — | — |
| 2020-21 | SIO | [RNK](takprog-2020-21/06_SIO/01_rnk) | functional | 1 s | 256 MB | 20 | `checker.cpp` (custom) | No examples | — |
| 2020-21 | SIO | [Marsko](takprog-2020-21/06_SIO/02_marsko) | functional | 1 s | 256 MB | 23 | default | — | — |
| 2020-21 | SIO | [Tačke](takprog-2020-21/06_SIO/03_tacke) | functional | 2 s | 256 MB | 40 | default | — | — |
| 2020-21 | SIO | [Izvlačenje slamki](takprog-2020-21/06_SIO/04_izvlacenje_slamki) | functional | 1 s | 256 MB | 32 | `checker.cpp` (exact tokens) | — | — |
| 2020-21 | SIO | [Xorko](takprog-2020-21/06_SIO/05_xorko) | functional | 1 s | 256 MB | 35 | default | — | — |
| 2020-21 | SIO | [Dva stabla](takprog-2020-21/06_SIO/06_dva_stabla) | functional | 3 s | 256 MB | 27 | default | — | — |
| 2021-22 | Kvalifikacije 1 | [Nesusedni](takprog-2021-22/01_KV1/01_nesusedni) | standard | 0.2 s | 256 MB | 22 | `checker.cpp` (custom, converted) | — | — |
| 2021-22 | Kvalifikacije 1 | [Transfuzija krvi](takprog-2021-22/01_KV1/02_transfuzija) | standard | 0.5 s | 256 MB | 12 | `checker.cpp` (custom) | — | — |
| 2021-22 | Kvalifikacije 1 | [Prepisivači](takprog-2021-22/01_KV1/03_prepisivaci) | standard | 1 s | 256 MB | 22 | default | — | — |
| 2021-22 | Kvalifikacije 1 | [Cen\*ura](takprog-2021-22/01_KV1/04_cenzura) | standard | 1 s | 256 MB | 21 | `checker.cpp` (custom, converted) | — | — |
| 2021-22 | Kvalifikacije 1 | [Noćna vožnja](takprog-2021-22/01_KV1/05_nocnavoznja) | standard | 4 s | 256 MB | 21 | default | — | — |
| 2021-22 | Kvalifikacije 2 | [Mađioničar](takprog-2021-22/02_KV2/01_madjionicar) | standard | 1 s | 256 MB | 22 | default | — | — |
| 2021-22 | Kvalifikacije 2 | [Ekskurzija](takprog-2021-22/02_KV2/02_ekskurzija) | standard | 0.1 s | 256 MB | 11 | default | — | — |
| 2021-22 | Kvalifikacije 2 | [Palindrom šafl](takprog-2021-22/02_KV2/03_palindrom_safl) | standard | 0.5 s | 256 MB | 22 | default | — | — |
| 2021-22 | Kvalifikacije 2 | [Gušter](takprog-2021-22/02_KV2/04_guster) | standard | 0.5 s | 128 MB | 23 | default | — | — |
| 2021-22 | Kvalifikacije 2 | [Čarobnjak](takprog-2021-22/02_KV2/05_carobnjak) | standard | 1 s | 256 MB | 21 | default | — | — |
| 2021-22 | Kvalifikacije 3 | [Biodiverzitet](takprog-2021-22/03_KV3/01_biodiverzitet) | standard | 1 s | 64 MB | 21 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Kvalifikacije 3 | [Mlađioničar](takprog-2021-22/03_KV3/02_mladjionicar) | standard | 0.5 s | 256 MB | 22 | `checker.cpp` (custom) | — | — |
| 2021-22 | Kvalifikacije 3 | [Psiho](takprog-2021-22/03_KV3/03_psiho) | standard | 1 s | 256 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Kvalifikacije 3 | [Konjugacija](takprog-2021-22/03_KV3/04_konjugacija) | standard | 1 s | 256 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Kvalifikacije 3 | [Min Max Plus](takprog-2021-22/03_KV3/05_min_max_plus) | standard | 3 s | 256 MB | 27 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Okružno | [Odbijanje](takprog-2021-22/04_OKR/01_odbijanje) | standard | 0.5 s | 512 MB | 12 | default | — | — |
| 2021-22 | Okružno | [Štale](takprog-2021-22/04_OKR/02_stale) | standard | 1 s | 512 MB | 22 | default | — | — |
| 2021-22 | Okružno | [Okram](takprog-2021-22/04_OKR/03_okram) | standard | 3 s | 512 MB | 21 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Okružno | [Sličice](takprog-2021-22/04_OKR/04_slicice) | standard | 1 s | 512 MB | 11 | default | — | — |
| 2021-22 | Okružno | [Ćivas](takprog-2021-22/04_OKR/05_civas) | standard | 1 s | 512 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Okružno | [AdVenture Communist](takprog-2021-22/04_OKR/06_adventure_communist) | standard | 0.5 s | 512 MB | 21 | default | — | — |
| 2021-22 | Državno | [Jednačine](takprog-2021-22/05_DRZ/01_jednacine) | standard | 1 s | 64 MB | 26 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Državno | [Turnir](takprog-2021-22/05_DRZ/02_turnir) | standard | 2 s | 267 MB | 38 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Državno | [Burad](takprog-2021-22/05_DRZ/03_burad) | standard | 1 s | 256 MB | 31 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Državno | [Koncert](takprog-2021-22/05_DRZ/04_koncert) | standard | 0.5 s | 256 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Državno | [Šmeker](takprog-2021-22/05_DRZ/05_smeker) | standard | 1 s | 256 MB | 28 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | Državno | [Konstrukta](takprog-2021-22/05_DRZ/06_konstrukta) | standard | 1.6 s | 256 MB | 44 | `checker.cpp` (custom) | — | — |
| 2021-22 | SIO | [Laz](takprog-2021-22/06_SIO/01_laz) | functional | 1 s | 64 MB | 50 | `checker.cpp` (custom) | No examples | — |
| 2021-22 | SIO | [TSM](takprog-2021-22/06_SIO/02_tsm) | functional | 1.5 s | 256 MB | 25 | `checker.cpp` (exact tokens) | — | — |
| 2021-22 | SIO | [Igrica](takprog-2021-22/06_SIO/03_igrica) | functional | 2.5 s | 256 MB | 30 | default | — | — |
| 2021-22 | SIO | [Dugmići](takprog-2021-22/06_SIO/04_dugmici) | functional | 0.7 s | 64 MB | 32 | default | — | — |
| 2021-22 | SIO | [US Open](takprog-2021-22/06_SIO/05_us_open) | functional | 1 s | 256 MB | 43 | default | — | — |
| 2021-22 | SIO | [Metropole](takprog-2021-22/06_SIO/06_metropole) | functional | 1 s | 512 MB | 55 | default | — | — |
| 2021-22 | EJOI izborno | [Poslovan Čovek](takprog-2021-22/07_EJOI_Izborno/01_poslovan_covek) | standard | 1.3 s | 256 MB | 35 | default | — | — |
| 2021-22 | EJOI izborno | [Arhitekta](takprog-2021-22/07_EJOI_Izborno/02_arhitekta) | standard | 1.5 s | 128 MB | 35 | default | — | — |
| 2021-22 | EJOI izborno | [Zagrade](takprog-2021-22/07_EJOI_Izborno/03_zagrade) | standard | 1 s | 64 MB | 31 | default | — | — |
| 2021-22 | EGOI izborno | [Računar](takprog-2021-22/08_EGOI_Izborno/01_racunar) | standard | 1 s | 64 MB | 19 | default | — | — |
| 2021-22 | EGOI izborno | [XXL Matrica](takprog-2021-22/08_EGOI_Izborno/02_xxl_matrica) | standard | 1 s | 64 MB | 92 | default | — | — |
| 2021-22 | EGOI izborno | [Nadvlačenje konopca](takprog-2021-22/08_EGOI_Izborno/03_nadvlacenje_konopca) | standard | 1 s | 64 MB | 26 | default | — | — |
| 2021-22 | EGOI izborno | [Šestougao](takprog-2021-22/08_EGOI_Izborno/04_sestougao) | standard | 2 s | 256 MB | 37 | default | — | — |
| 2022-23 | Kvalifikacije 1 | [Sudar](takprog-2022-23/01_KV1/01_sudar) | standard | 0.1 s | 32 MB | 45 | default | — | — |
| 2022-23 | Kvalifikacije 1 | [Nameštanje glasanja](takprog-2022-23/01_KV1/02_namestanjeg) | standard | 1 s | 64 MB | 35 | `checker.cpp` (custom) | — | — |
| 2022-23 | Kvalifikacije 1 | [Sante](takprog-2022-23/01_KV1/03_sante) | standard | 1 s | 64 MB | 22 | default | — | — |
| 2022-23 | Kvalifikacije 1 | [Vage](takprog-2022-23/01_KV1/04_vage) | standard | 2 s | 256 MB | 22 | default | — | — |
| 2022-23 | Kvalifikacije 1 | [Zlatnici 3](takprog-2022-23/01_KV1/05_zlatnici3) | standard | 0.8 s | 256 MB | 22 | default | — | — |
| 2022-23 | Kvalifikacije 2 | [Spojler](takprog-2022-23/02_KV2/01_spojler) | standard | 0.1 s | 256 MB | 23 | `checker.cpp` (exact tokens) | — | — |
| 2022-23 | Kvalifikacije 2 | [Finale](takprog-2022-23/02_KV2/02_finale) | standard | 0.1 s | 32 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2022-23 | Kvalifikacije 2 | [Gužva](takprog-2022-23/02_KV2/03_guzva) | standard | 3 s | 256 MB | 21 | `checker.cpp` (exact tokens) | — | — |
| 2022-23 | Kvalifikacije 2 | [Formacija](takprog-2022-23/02_KV2/04_formacija) | standard | 1 s | 256 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2022-23 | Kvalifikacije 2 | [Opklada](takprog-2022-23/02_KV2/05_opklada) | standard | 4 s | 256 MB | 21 | `checker.cpp` (custom) | — | — |
| 2022-23 | Okružno | [Kuvar](takprog-2022-23/03_OKR/01_kuvar) | standard | 1 s | 64 MB | 12 | default | — | — |
| 2022-23 | Okružno | [Razmena znaka](takprog-2022-23/03_OKR/02_razmena_znaka) | standard | 1.5 s | 256 MB | 21 | default | — | — |
| 2022-23 | Okružno | [Jednostavni pikado](takprog-2022-23/03_OKR/03_jednostavni_pikado) | standard | 2 s | 512 MB | 22 | default | — | — |
| 2022-23 | Okružno | [Poklon](takprog-2022-23/03_OKR/04_poklon) | standard | 1 s | 128 MB | 21 | default | — | — |
| 2022-23 | Okružno | [Krompiri](takprog-2022-23/03_OKR/05_krompiri) | standard | 0.75 s | 64 MB | 22 | `checker.cpp` (custom) | — | — |
| 2022-23 | Okružno | [Sdneirf](takprog-2022-23/03_OKR/06_sdneirf) | standard | 2 s | 256 MB | 22 | default | — | — |
| 2022-23 | Državno | [Bakterijada](takprog-2022-23/04_DRZ/01_bakterijada) | standard | 1 s | 64 MB | 21 | default | — | — |
| 2022-23 | Državno | [Xor Fabrika](takprog-2022-23/04_DRZ/02_xor_fabrika) | standard | 1 s | 64 MB | 21 | default | — | — |
| 2022-23 | Državno | [Kirbi](takprog-2022-23/04_DRZ/03_kirbi) | standard | 3 s | 64 MB | 21 | default | — | — |
| 2022-23 | Državno | [Život u gradu](takprog-2022-23/04_DRZ/04_zivot_u_gradu) | standard | 1 s | 256 MB | 34 | `checker.cpp` (custom) | — | — |
| 2022-23 | Državno | [Bekstvo](takprog-2022-23/04_DRZ/05_bekstvo) | standard | 1 s | 512 MB | 95 | default | — | — |
| 2022-23 | Državno | [Turizam](takprog-2022-23/04_DRZ/06_turizam) | standard | 2.5 s | 512 MB | 44 | default | — | — |
| 2022-23 | SIO | [Operacija nad glistom](takprog-2022-23/05_SIO/01_operacija_nad_glistom) | functional | 1 s | 256 MB | 41 | default | — | — |
| 2022-23 | SIO | [Kompresovani niz](takprog-2022-23/05_SIO/02_kompresovani_niz) | functional | 0.5 s | 256 MB | 132 | default | — | — |
| 2022-23 | SIO | [Najslabija karika](takprog-2022-23/05_SIO/03_samo_najjaci_opstaju) | functional | 3.5 s | 512 MB | 50 | default | — | — |
| 2022-23 | SIO | [Opet XOR](takprog-2022-23/05_SIO/04_opet_xor) | functional | 4 s | 512 MB | 13 | default | — | — |
| 2022-23 | SIO | [vOOda](takprog-2022-23/05_SIO/05_vOOda) | output-only | — | — | 8 | `checker.cpp` (custom) | The contestants' zip and `compressor.cpp` are absent here; pictures `1.png`–`8.png` were restored from the commission repository; `compressor.cpp` is in the 2024 collection | — |
| 2022-23 | SIO | [Parovi](takprog-2022-23/05_SIO/06_parovi) | functional | 1 s | 64 MB | 61 | default | — | — |
| 2023-24 | Kvalifikacije 1 | [Tri tajna broja](takprog-2023-24/01_KV1/01_tri_tajna_broja) | standard | 1 s | 64 MB | 21 | default | — | — |
| 2023-24 | Kvalifikacije 1 | [Moramo da recikliramo](takprog-2023-24/01_KV1/02_moramo_da_recikliramo) | standard | 2 s | 64 MB | 21 | default | — | — |
| 2023-24 | Kvalifikacije 1 | [Presedanja](takprog-2023-24/01_KV1/03_presedanja) | standard | 1 s | 64 MB | 22 | default | — | — |
| 2023-24 | Kvalifikacije 1 | [Veća trka](takprog-2023-24/01_KV1/04_veca_trka) | standard | 3 s | 64 MB | 22 | `checker.cpp` (custom) | — | — |
| 2023-24 | Kvalifikacije 1 | [Fejk reklama](takprog-2023-24/01_KV1/05_fejk_reklama) | standard | 1 s | 256 MB | 23 | default | — | — |
| 2023-24 | Kvalifikacije 2 | [Nadkvadrat](takprog-2023-24/02_KV2/01_nadkvadrat) | standard | 0.1 s | 32 MB | 23 | default | — | — |
| 2023-24 | Kvalifikacije 2 | [Manja je matrica od matrice](takprog-2023-24/02_KV2/02_manja_je_matrica_od_matrice) | standard | 2 s | 256 MB | 22 | `checker.cpp` (exact tokens) | — | — |
| 2023-24 | Kvalifikacije 2 | [Školice](takprog-2023-24/02_KV2/03_skolice) | standard | 2 s | 256 MB | 21 | `checker.cpp` (exact tokens) | — | — |
| 2023-24 | Kvalifikacije 2 | [Obaranje ruku](takprog-2023-24/02_KV2/04_obaranje_ruku) | standard | 2.4 s | 768 MB | 27 | `checker.cpp` (exact tokens) | — | — |
| 2023-24 | Kvalifikacije 2 | [Pećinski zečevi](takprog-2023-24/02_KV2/05_pecinski_zecevi) | standard | 6 s | 512 MB | 29 | default | — | — |
| 2023-24 | Okružno | [Usamljenost](takprog-2023-24/03_OKR/01_usamljenost) | standard | 0.3 s | 64 MB | 22 | default | — | — |
| 2023-24 | Okružno | [Dejn](takprog-2023-24/03_OKR/02_dejn) | standard | 1 s | 64 MB | 23 | default | — | — |
| 2023-24 | Okružno | [Bitvajz oranje](takprog-2023-24/03_OKR/03_bitvajz_oranje) | standard | 2 s | 256 MB | 27 | default | — | — |
| 2023-24 | Okružno | [Xormutacije](takprog-2023-24/03_OKR/04_xormutacije) | standard | 1 s | 256 MB | 22 | `checker.cpp` (custom) | — | — |
| 2023-24 | Okružno | [Monopol](takprog-2023-24/03_OKR/05_monopol) | standard | 0.7 s | 64 MB | 22 | default | — | — |
| 2023-24 | Okružno | [Linijopolis](takprog-2023-24/03_OKR/06_linijopolis) | standard | 4 s | 128 MB | 22 | default | — | — |
| 2023-24 | Državno | [Nepodniz](takprog-2023-24/04_DRZ/01_nepodniz) | standard | 3 s | 64 MB | 33 | default | — | — |
| 2023-24 | Državno | [Domski Sletač](takprog-2023-24/04_DRZ/02_domski_sletac) | standard | 1 s | 256 MB | 30 | default | — | — |
| 2023-24 | Državno | [Starući prsten](takprog-2023-24/04_DRZ/03_staruci_prsten) | standard | 1 s | 256 MB | 59 | default | — | — |
| 2023-24 | Državno | [I/ili](takprog-2023-24/04_DRZ/04_i_ili) | standard | 1 s | 64 MB | 22 | default | — | — |
| 2023-24 | Državno | [Kiki](takprog-2023-24/04_DRZ/05_kiki) | standard | 1.5 s | 256 MB | 40 | `checker.cpp` (custom) | — | — |
| 2023-24 | Državno | [Palindromska šetnja](takprog-2023-24/04_DRZ/06_palindromska_setnja) | standard | 3 s | 256 MB | 102 | default | — | — |
| 2023-24 | SIO | [Spartacus](takprog-2023-24/05_SIO/01_spartacus) | functional | 0.1 s | 256 MB | 68 | `checker.cpp` (exact tokens) | — | — |
| 2023-24 | SIO | [Et tu, Brute?](takprog-2023-24/05_SIO/02_et_tu_brute) | functional | 1.5 s | 256 MB | 50 | default | — | — |
| 2023-24 | SIO | [E pluribus unum](takprog-2023-24/05_SIO/03_e_pluribus_unum) | functional | 3.5 s | 256 MB | 93 | default | — | — |
| 2023-24 | SIO | [Quaestio militaris formationis](takprog-2023-24/05_SIO/04_quaestio_militaris_formationis) | functional | 1 s | 256 MB | 31 | `checker.cpp` (custom) | — | — |
| 2023-24 | SIO | [Viae Romanae](takprog-2023-24/05_SIO/05_viae_romanae) | functional | 1.5 s | 256 MB | 104 | default | — | — |
| 2023-24 | SIO | [Turris inclinata](takprog-2023-24/05_SIO/06_turris_inclinata) | functional | 1.5 s | 256 MB | 80 | default | — | — |
| 2024-25 | Kvalifikacije 1 | [Pećina](takprog-2024-25/01_KV1/01_pecina) | standard | 0.2 s | 64 MB | 23 | default | — | — |
| 2024-25 | Kvalifikacije 1 | [Plazma](takprog-2024-25/01_KV1/02_plazma) | standard | 3 s | 128 MB | 52 | default | — | — |
| 2024-25 | Kvalifikacije 1 | [Požar](takprog-2024-25/01_KV1/03_pozar) | standard | 1 s | 256 MB | 24 | default | — | — |
| 2024-25 | Kvalifikacije 1 | [Konveksni skoro omotač](takprog-2024-25/01_KV1/04_konveksni_skoro_omotac) | standard | 1.5 s | 64 MB | 28 | default | — | — |
| 2024-25 | Kvalifikacije 1 | [Dva niza](takprog-2024-25/01_KV1/05_dvaniza) | standard | 1.5 s | 256 MB | 26 | default | — | — |
| 2024-25 | Kvalifikacije 2 | [Prosek i medijana](takprog-2024-25/02_KV2/01_prosek_i_medijana) | standard | 0.1 s | 64 MB | 23 | default | — | — |
| 2024-25 | Kvalifikacije 2 | [Sreća u matrici](takprog-2024-25/02_KV2/02_sreca_u_matrici) | standard | 1 s | 64 MB | 22 | default | — | — |
| 2024-25 | Kvalifikacije 2 | [Putešestvije](takprog-2024-25/02_KV2/03_putesestvije) | standard | 3 s | 256 MB | 22 | `checker.cpp` (custom) | — | — |
| 2024-25 | Kvalifikacije 2 | [Daltonizacija](takprog-2024-25/02_KV2/04_daltonizacija) | standard | 2 s | 128 MB | 27 | default | — | — |
| 2024-25 | Kvalifikacije 2 | [Zanimljivi grafovski upiti](takprog-2024-25/02_KV2/05_zanimljivi_grafovski_upiti) | standard | 8.5 s | 1024 MB | 22 | default | — | — |
| 2024-25 | Kvalifikacije za izborno | [Karte 3](takprog-2024-25/A_PIZ/01_karte_3) | standard | 1 s | 256 MB | 21 | default | — | — |
| 2024-25 | Kvalifikacije za izborno | [Najveća pojava](takprog-2024-25/A_PIZ/02_najveca_pojava) | standard | 1.5 s | 256 MB | 73 | default | — | — |
| 2024-25 | Kvalifikacije za izborno | [Radoje](takprog-2024-25/A_PIZ/03_radoje) | standard | 1 s | 256 MB | 56 | `checker.cpp` (custom) | — | — |
| 2024-25 | Kvalifikacije za izborno | [Pisma iz Sukrea](takprog-2024-25/A_PIZ/04_pisma_iz_sukrea) | standard | 2 s | 64 MB | 24 | default | — | — |
| 2024-25 | Izborno | [Uzumaki](takprog-2024-25/B_IZB/01_uzumaki) | functional | 4 s | 256 MB | 56 | default | — | — |
| 2024-25 | Izborno | [Mesi](takprog-2024-25/B_IZB/02_mesi) | functional | 0.5 s | 128 MB | 70 | default | — | — |
| 2024-25 | Izborno | [Šafler](takprog-2024-25/B_IZB/03_safler) | functional | 1.5 s | 256 MB | 25 | default | — | — |
| 2024-25 | Izborno | [Nalbandian](takprog-2024-25/B_IZB/04_nalbandian) | functional | 3 s | 256 MB | 82 | default | — | — |
| 2024-25 | Izborno | [Sabiranje razapinjućih stabala](takprog-2024-25/B_IZB/05_sabiranje_razapinjucih_stabala) | functional | 0.5 s | 256 MB | 34 | default | — | — |
| 2024-25 | Izborno | [Titikaka](takprog-2024-25/B_IZB/06_titikaka) | functional | 2 s | 512 MB | 10 | `checker.cpp` (custom) | — | — |
| 2025-26 | Kvalifikacije | [Podela jabuka](takprog-2025-26/01_KV/01_podela_jabuka) | standard | 1 s | 64 MB | 22 | default | — | — |
| 2025-26 | Kvalifikacije | [Najbliži neprijatelj](takprog-2025-26/01_KV/02_najblizi_neprijatelj) | standard | 1 s | 64 MB | 102 | default | — | — |
| 2025-26 | Kvalifikacije | [Dzek Vrabac](takprog-2025-26/01_KV/03_dzek_vrabac) | standard | 1 s | 64 MB | 51 | default | — | — |
| 2025-26 | Kvalifikacije | [Prijateljski trkači](takprog-2025-26/01_KV/04_prijateljski_trkaci) | standard | 1 s | 64 MB | 50 | default | — | — |
| 2025-26 | Kvalifikacije | [Paintball](takprog-2025-26/01_KV/05_paintball) | standard | 1 s | 64 MB | 22 | `checker.cpp` (custom) | — | — |
| 2025-26 | Kvalifikacije | [Baki i Srecko](takprog-2025-26/01_KV/06_najvektor) | standard | 1 s | 64 MB | 52 | `checker.cpp` (custom) | — | — |
| 2025-26 | Kvalifikacije | [Mst 😭](takprog-2025-26/01_KV/07_mst_😭) | standard | 1 s | 256 MB | 51 | default | — | — |
| 2025-26 | Kvalifikacije | [Igra sa Kartama](takprog-2025-26/01_KV/08_Igra_sa_kartama) | standard | 3 s | 256 MB | 23 | default | — | — |
| 2025-26 | Kvalifikacije | [Potera](takprog-2025-26/01_KV/09_potera) | standard | 5 s | 256 MB | 27 | default | — | — |
| 2025-26 | Kvalifikacije | [Perica i novogodisnje stablo](takprog-2025-26/01_KV/10_laganje) | standard | 0.5 s | 256 MB | 51 | `checker.cpp` (custom) | — | — |
| 2025-26 | Kvalifikacije | [Srecko i Ponchoi](takprog-2025-26/01_KV/11_srecko_i_poncoi) | standard | 1 s | 512 MB | 51 | `checker.cpp` (custom) | — | — |
| 2025-26 | Okružno | [Majstorija](takprog-2025-26/02_OKR/01_majstorija) | standard | 1 s | 256 MB | 21 | `checker.cpp` (custom) | — | No `.out` files: the checker doesn't use them |
| 2025-26 | Okružno | [Hari Poter](takprog-2025-26/02_OKR/02_hari_poter) | standard | 1 s | 128 MB | 22 | `checker.cpp` (custom) | — | — |
| 2025-26 | Okružno | [Abakus 2](takprog-2025-26/02_OKR/03_abakus) | standard | 2 s | 256 MB | 22 | default | — | — |
| 2025-26 | Okružno | [Xormutacije 2](takprog-2025-26/02_OKR/04_xormutacije) | standard | 1.5 s | 256 MB | 21 | default | — | — |
| 2025-26 | Okružno | [Vasa, skupljač aure](takprog-2025-26/02_OKR/05_vasa_skupljac) | standard | 1 s | 128 MB | 22 | default | — | — |
| 2025-26 | Okružno | [Xorovanje delilaca](takprog-2025-26/02_OKR/06_xorovanje_delilaca) | standard | 1 s | 256 MB | 22 | default | — | — |
| 2025-26 | Državno | [Nameštaljka](takprog-2025-26/03_DRZ/01_cikcak) | standard | 1 s | 64 MB | 39 | `checker.cpp` (custom) | — | — |
| 2025-26 | Državno | [Aralski Mornar](takprog-2025-26/03_DRZ/02_aralski_mornar) | standard | 1 s | 512 MB | 44 | default | — | — |
| 2025-26 | Državno | [Sub67ce](takprog-2025-26/03_DRZ/03_sub67ce) | standard | 2 s | 512 MB | 29 | default | — | — |
| 2025-26 | Državno | [Ekskluzivni Kamp](takprog-2025-26/03_DRZ/04_fini_cvorovi) | standard | 1 s | 256 MB | 45 | `checker.cpp` (custom) | — | — |
| 2025-26 | Državno | [Kodforses blog](takprog-2025-26/03_DRZ/05_codeforces_blogovi) | standard | 0.25 s | 256 MB | 137 | `checker.cpp` (custom) | — | — |
| 2025-26 | Državno | [A3 - Intergalaktički sukob](takprog-2025-26/03_DRZ/06_buenas_tackas) | standard | 1.5 s | 256 MB | 72 | `checker.cpp` (custom) | — | — |
| 2025-26 | EGOI izborno | [Raspored](takprog-2025-26/04_EGOI_IZB/01_raspored) | standard | 2.5 s | 256 MB | 87 | `checker.cpp` (custom) | — | — |
| 2025-26 | EGOI izborno | [Dva Tornja](takprog-2025-26/04_EGOI_IZB/02_dva_tornja) | standard | 2 s | 256 MB | 64 | default | — | — |
| 2025-26 | EGOI izborno | [Takmičenje](takprog-2025-26/04_EGOI_IZB/03_takmicenje) | standard | 1 s | 256 MB | 85 | default | — | — |
| 2025-26 | EGOI izborno | [Tajna Matrica](takprog-2025-26/04_EGOI_IZB/04_tajna_matrica) | functional | 1 s | 256 MB | 74 | `checker.cpp` (custom) | — | — |
| 2025-26 | SIO | [Prodaja](takprog-2025-26/05_SIO/01_prodaja) | functional | 1 s | 64 MB | 158 | default | — | — |
| 2025-26 | SIO | [Gradovi](takprog-2025-26/05_SIO/02_gradovi) | functional | 1 s | 256 MB | 67 | `checker.cpp` (custom) | — | — |
| 2025-26 | SIO | [Minecraft kOOfa](takprog-2025-26/05_SIO/03_koofa) | output-only | — | — | 10 | `checker.cpp` (custom) | — | — |
| 2025-26 | SIO | [Vasilije mrzi geometriju](takprog-2025-26/05_SIO/04_vasa_mrzi_geometriju) | functional | 0.5 s | 64 MB | 99 | default | — | — |
| 2025-26 | SIO | [Intergalakticki konflikt dva](takprog-2025-26/05_SIO/05_intergalakticki_konflikt_dva) | functional | 2 s | 64 MB | 116 | `checker.cpp` (custom) | — | — |
| 2025-26 | SIO | [Gajbiša](takprog-2025-26/05_SIO/06_gajbisa) | functional | 5 s | 512 MB | 60 | default | — | — |

## Summary

All 311 tasks have their statement, limits, scoring and checker (or the default one); the 50 functional tasks have
their grader. Five checkers couldn't be retrieved and were rewritten from the statement: Baza, Neonke, Virus
(2016-17), Two Circles (2016-17 PRI) and Bojenje (2018-19). **14 tasks have a problem**, listed below (Collecting
Luggage is in both lists).

**Task problems (8 tasks)**

- **Lost pictures (2):** [Sportski centar](takprog-2016-17/1_KV1/05_sportski_centar) and
  [Collecting Luggage](takprog-2016-17/PRI/CollectingLuggage) (2016-17).
- **Lost attachments for contestants (2):** [Neonke](takprog-2016-17/4_SIO/04_neonke) (2016-17, the visualizer),
  [vOOda](takprog-2022-23/05_SIO/05_vOOda) (2022-23, the zip and `compressor.cpp`; its eight pictures have been restored).
- **Placeholder section (1):** [Virus](takprog-2016-17/4_SIO/05_virus) (2016-17), the output description.
- **No examples (2):** [RNK](takprog-2020-21/06_SIO/01_rnk) (2020-21), [Laz](takprog-2021-22/06_SIO/01_laz) (2021-22).
- **Limits (2):** [Planine](takprog-2018-19/06_SIO/05_planine) (2018-19): 64 MB is too tight for today's grader;
  [Collecting Luggage](takprog-2016-17/PRI/CollectingLuggage) (2016-17 PRI): the limits may be wrong.

**Testcase problems (7 tasks)**

- **No testcases (1):** [Collecting Luggage](takprog-2016-17/PRI/CollectingLuggage) (2016-17 PRI).
- **Some tests from the 2024 collection, lost on Petlja (3):** [01 niz](takprog-2020-21/02_KV2/05_01_niz),
  [Pitanja](takprog-2020-21/03_KV3/04_pitanja), [Novogodišnje stablo](takprog-2020-21/03_KV3/05_novogodisnje_stablo)
  (2020-21).
- **A test that fails today (1):** [Okrnjen trougao](takprog-2017-18/1_KV1/04_okrnjen_trougao) (2017-18): test 11
  fails solutions that overflow a `double`.
- **A test that can't be checked (1):** [Brojorb](takprog-2019-20/06_SIO/01_brojorb) (2019-20): test 1 always counts
  as wrong.
- **No `.out` files (1):** [Majstorija](takprog-2025-26/02_OKR/01_majstorija) (2025-26); the checker doesn't need them.
