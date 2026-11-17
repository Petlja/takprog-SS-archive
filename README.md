# Takprog archive: high school

The tasks of the Serbian high-school informatics competitions, seasons 2016-17 to 2025-26: 311 tasks from
the qualifying rounds, Okružno, Državno, SIO and the selections for international olympiads. Each task folder holds
what you need to set the task again: the statement with examples, the tests, the checker, the scoring and the limits.

## Layout

`takprog-{season}/{round}/{nn}_{task}/`, where `nn` is the task's place in the round. A task folder has:

| File | What |
|---|---|
| `statement.md` | The statement in Markdown, formulas in LaTeX between `$`. Its header gives `timelimit` (seconds) and `memlimit` (MB). In Cyrillic, except 2016-17's and Kvalifikacije 1 2017-18's (Latin script) and the training camp's (English) |
| `*.png`, `*.svg` | Pictures the statement links |
| `testcases/` | `NN.in` and `NN.out`. When a custom checker verifies the answer itself, `.out` can be empty or hold only what the checker needs; Majstorija (2025-26) has no `.out` files |
| `checker.cpp` | The task's checker, if it has its own (see [Checkers](#checkers)) |
| `scoring.yaml` | Points per test or subtask, and which results contestants saw during the contest (see [Scoring](#scoring)) |
| `grader/` | Functional tasks only: the main program, per language (`cpp/`, and for a few tasks `pas/` or `py3/`) |
| `attachments/` | Files contestants were given with the task, if any: starting code and a local grader for functional tasks, inputs and tools for output-only tasks |

## Task types

- **standard:** the program reads the test's input on stdin and writes its answer to stdout.
- **functional:** the contestant writes the functions the statement names. Compile their file together with
  `grader/cpp/main.cpp` (and `grader/cpp/code.h`, where there is one), for example
  `g++ -std=gnu++17 -O2 -static grader/cpp/main.cpp code.cpp`. `main.cpp` reads the input and writes the output.
- **output-only:** the contestant submits an output file per test, made from the inputs in `testcases/` (also in
  `attachments/`). Nothing runs except the checker, so there are no limits.

## Checkers

`default` in the table means that outputs are compared as tokens, ignoring whitespace, and accept a real number within
the precision the expected answer is written to.

A `checker.cpp` is called as `checker <contestant output> <expected output> <input>`. Exit code 0 means accepted,
anything else wrong. A checker that gives partial points prints them on stdout, out of the `divisor` in
`scoring.yaml`. 
In the table, `exact tokens` is a checker that compares tokens exactly

## Scoring

`scoring.yaml` has a `type`:

- **`testcase`:** `score_total` points shared equally among the tests, except those in `score_overrides` (usually
  the statement's examples, worth 0). `public` lists the tests whose results contestants saw during the contest.
  `score_total: null` means each test is worth what its checker prints.
- **`subtask`:** each of the `groups` gives its `score` only when all its `testcases` pass. `public` lists group ids.


## Limits

- **Time:** CPU time on one test, not wall-clock time.
- **Memory:** peak memory on one test.

## Tasks

| Season | Round | Task | Type | Time | Memory | Tests | Checker |
|---|---|---|---|---|---|---|---|
| 2016-17 | Kvalifikacije | [Trotoar](takprog-2016-17/1_KV1/01_trotoar) | standard | 1 s | 64 MB | 22 | default |
| 2016-17 | Kvalifikacije | [Papir, kamen, makaze](takprog-2016-17/1_KV1/02_papir_kamen_makaze) | standard | 1 s | 64 MB | 22 | default |
| 2016-17 | Kvalifikacije | [Kul kule](takprog-2016-17/1_KV1/03_kul_kule) | standard | 1 s | 64 MB | 22 | default |
| 2016-17 | Kvalifikacije | [Filozof](takprog-2016-17/1_KV1/04_filozof) | standard | 0.5 s | 256 MB | 12 | default |
| 2016-17 | Kvalifikacije | [Sportski centar](takprog-2016-17/1_KV1/05_sportski_centar) | standard | 0.2 s | 64 MB | 12 | default |
| 2016-17 | Kvalifikacije | [Kružna škola](takprog-2016-17/1_KV1/06_kruzna_skola) | standard | 1 s | 256 MB | 27 | default |
| 2016-17 | Okružno | [Krompir](takprog-2016-17/2_OKR/01_krompir) | standard | 0.5 s | 256 MB | 22 | default |
| 2016-17 | Okružno | [Raketa](takprog-2016-17/2_OKR/02_raketa) | standard | 0.1 s | 256 MB | 27 | default |
| 2016-17 | Okružno | [Marsovci](takprog-2016-17/2_OKR/03_marsovci) | standard | 0.5 s | 256 MB | 22 | default |
| 2016-17 | Okružno | [Baza](takprog-2016-17/2_OKR/04_baza) | standard | 1 s | 256 MB | 22 | rewritten |
| 2016-17 | Okružno | [Kosmodrom](takprog-2016-17/2_OKR/05_kosmodrom) | standard | 0.3 s | 256 MB | 12 | default |
| 2016-17 | Okružno | [Mingo](takprog-2016-17/2_OKR/06_mingo) | standard | 1.5 s | 256 MB | 22 | default |
| 2016-17 | Državno | [Bond](takprog-2016-17/3_DRZ/01_bond) | standard | 1 s | 256 MB | 20 | default |
| 2016-17 | Državno | [Hari](takprog-2016-17/3_DRZ/02_hari) | standard | 0.4 s | 64 MB | 26 | default |
| 2016-17 | Državno | [Kladionica](takprog-2016-17/3_DRZ/03_kladionica) | standard | 0.7 s | 256 MB | 26 | default |
| 2016-17 | Državno | [Karibi](takprog-2016-17/3_DRZ/04_karibi) | standard | 1.5 s | 256 MB | 27 | default |
| 2016-17 | Državno | [Prorok](takprog-2016-17/3_DRZ/05_prorok) | standard | 0.3 s | 64 MB | 19 | default |
| 2016-17 | Državno | [Karte](takprog-2016-17/3_DRZ/06_karte) | standard | 0.6 s | 64 MB | 23 | default |
| 2016-17 | SIO | [Klikeri](takprog-2016-17/4_SIO/01_klikeri) | standard | 1.5 s | 64 MB | 41 | default |
| 2016-17 | SIO | [Zaduženja](takprog-2016-17/4_SIO/02_zaduzenja) | standard | 1.5 s | 64 MB | 30 | default |
| 2016-17 | SIO | [Tetke](takprog-2016-17/4_SIO/03_tetke) | standard | 3 s | 192 MB | 22 | default |
| 2016-17 | SIO | [Neonke](takprog-2016-17/4_SIO/04_neonke) | output-only | — | — | 4 | rewritten |
| 2016-17 | SIO | [Virus](takprog-2016-17/4_SIO/05_virus) | standard | 1 s | 64 MB | 50 | rewritten |
| 2016-17 | SIO | [Pogled](takprog-2016-17/4_SIO/06_pogled) | standard | 1 s | 64 MB | 26 | default |
| 2016-17 | Pripreme | [Collecting Luggage](takprog-2016-17/PRI/CollectingLuggage) | standard | 2 s | 256 MB | 10 | default |
| 2016-17 | Pripreme | [CosmoCraft](takprog-2016-17/PRI/CosmoCraft) | standard | 3 s | 64 MB | 1 | default |
| 2016-17 | Pripreme | [Count the Regions](takprog-2016-17/PRI/Count) | standard | 0.3 s | 64 MB | 1 | default |
| 2016-17 | Pripreme | [Covered walkway](takprog-2016-17/PRI/CoveredWalkway) | standard | 10 s | 256 MB | 1 | default |
| 2016-17 | Pripreme | [Red/Blue Spanning Tree](takprog-2016-17/PRI/RedBlue) | standard | 3 s | 64 MB | 1 | default |
| 2016-17 | Pripreme | [Two Circles](takprog-2016-17/PRI/TwoCircles) | standard | 10 s | 256 MB | 10 | rewritten |
| 2017-18 | Kvalifikacije 1 | [Prva cifra](takprog-2017-18/1_KV1/01_prva_cifra) | standard | 0.1 s | 64 MB | 12 | default |
| 2017-18 | Kvalifikacije 1 | [Transformacija matrice](takprog-2017-18/1_KV1/02_transformacija_matrice) | standard | 4 s | 128 MB | 22 | default |
| 2017-18 | Kvalifikacije 1 | [Prodavnice](takprog-2017-18/1_KV1/03_prodavnice) | standard | 1 s | 64 MB | 22 | default |
| 2017-18 | Kvalifikacije 1 | [Okrnjen trougao](takprog-2017-18/1_KV1/04_okrnjen_trougao) | standard | 1 s | 128 MB | 22 | custom |
| 2017-18 | Kvalifikacije 1 | [Nagrade](takprog-2017-18/1_KV1/05_nagrade) | standard | 1 s | 128 MB | 22 | custom |
| 2017-18 | Kvalifikacije 2 | [Mala matrica](takprog-2017-18/2_KV2/01_mala_matrica) | standard | 1 s | 256 MB | 22 | custom |
| 2017-18 | Kvalifikacije 2 | [Trivijalan broj](takprog-2017-18/2_KV2/02_trivijalan_broj) | standard | 2 s | 256 MB | 11 | default |
| 2017-18 | Kvalifikacije 2 | [Topla voda](takprog-2017-18/2_KV2/03_topla_voda) | standard | 2 s | 128 MB | 22 | default |
| 2017-18 | Kvalifikacije 2 | [Džokeri](takprog-2017-18/2_KV2/04_dzokeri) | standard | 1 s | 256 MB | 22 | default |
| 2017-18 | Kvalifikacije 2 | [Kiosci](takprog-2017-18/2_KV2/05_kiosci) | standard | 2.5 s | 512 MB | 22 | default |
| 2017-18 | Kvalifikacije 3 | [Zečevi](takprog-2017-18/3_KV3/01_zecevi) | standard | 0.2 s | 64 MB | 54 | custom |
| 2017-18 | Kvalifikacije 3 | [Najbliži neopadajući](takprog-2017-18/3_KV3/02_najblizi_neopadajuci) | standard | 0.3 s | 64 MB | 44 | default |
| 2017-18 | Kvalifikacije 3 | [Struja](takprog-2017-18/3_KV3/03_struja) | standard | 2 s | 128 MB | 22 | custom |
| 2017-18 | Kvalifikacije 3 | [Plus-minus](takprog-2017-18/3_KV3/04_plus_minus) | standard | 1 s | 128 MB | 22 | custom |
| 2017-18 | Kvalifikacije 3 | [Prepisivanje](takprog-2017-18/3_KV3/05_prepisivanje) | standard | 2.5 s | 512 MB | 22 | default |
| 2017-18 | Okružno | [Pangram](takprog-2017-18/4_OKR/01_pangram) | standard | 1 s | 512 MB | 22 | custom |
| 2017-18 | Okružno | [Matriks](takprog-2017-18/4_OKR/02_matriks) | standard | 1 s | 64 MB | 11 | default |
| 2017-18 | Okružno | [Žalbe](takprog-2017-18/4_OKR/03_zalbe) | standard | 0.5 s | 64 MB | 22 | custom |
| 2017-18 | Okružno | [Cik-cak](takprog-2017-18/4_OKR/04_cik_cak) | standard | 1 s | 128 MB | 22 | custom |
| 2017-18 | Okružno | [Velika matrica](takprog-2017-18/4_OKR/05_velika_matrica) | standard | 2 s | 64 MB | 11 | default |
| 2017-18 | Okružno | [Formula](takprog-2017-18/4_OKR/06_formula) | standard | 1 s | 64 MB | 22 | custom |
| 2017-18 | Državno | [Pola-pola](takprog-2017-18/5_DRZ/01_polapola) | standard | 0.5 s | 256 MB | 28 | default |
| 2017-18 | Državno | [Trik](takprog-2017-18/5_DRZ/02_trik) | standard | 0.3 s | 256 MB | 33 | custom |
| 2017-18 | Državno | [Esikez](takprog-2017-18/5_DRZ/03_esikez) | standard | 1 s | 256 MB | 43 | default |
| 2017-18 | Državno | [Super velika matrica](takprog-2017-18/5_DRZ/04_super_velika) | standard | 3 s | 64 MB | 23 | default |
| 2017-18 | Državno | [Sort na stablu](takprog-2017-18/5_DRZ/05_sort_na_stablu) | standard | 2 s | 256 MB | 24 | default |
| 2017-18 | Državno | [Obaranje](takprog-2017-18/5_DRZ/06_obaranje) | standard | 0.5 s | 64 MB | 25 | default |
| 2017-18 | SIO | [Pacovi](takprog-2017-18/6_SIO/01_pacovi) | functional | 0.3 s | 256 MB | 38 | default |
| 2017-18 | SIO | [Imanje](takprog-2017-18/6_SIO/02_imanje) | output-only | — | — | 5 | custom |
| 2017-18 | SIO | [Popis](takprog-2017-18/6_SIO/03_popis) | functional | 2 s | 512 MB | 21 | default |
| 2017-18 | SIO | [Bombonice](takprog-2017-18/6_SIO/04_bombonice) | functional | 1.5 s | 128 MB | 26 | default |
| 2017-18 | SIO | [Voćnjak](takprog-2017-18/6_SIO/05_vocnjak) | functional | 1 s | 128 MB | 41 | custom |
| 2017-18 | SIO | [Taman](takprog-2017-18/6_SIO/06_taman) | functional | 1 s | 128 MB | 25 | default |
| 2018-19 | Kvalifikacije 1 | [Pileća krilca](takprog-2018-19/01_KV1/01_krilca) | standard | 1 s | 64 MB | 12 | custom |
| 2018-19 | Kvalifikacije 1 | [Lep niz](takprog-2018-19/01_KV1/02_lep_niz) | standard | 1 s | 64 MB | 52 | default |
| 2018-19 | Kvalifikacije 1 | [Deljenje niza](takprog-2018-19/01_KV1/03_deljenje_niza) | standard | 0.498 s | 64 MB | 22 | custom |
| 2018-19 | Kvalifikacije 1 | [Poštar](takprog-2018-19/01_KV1/04_postar) | standard | 2 s | 128 MB | 21 | custom |
| 2018-19 | Kvalifikacije 1 | [Dodela vrednosti](takprog-2018-19/01_KV1/05_dodela) | standard | 2 s | 512 MB | 11 | default |
| 2018-19 | Kvalifikacije 2 | [Nadovezivanje](takprog-2018-19/02_KV2/01_nadovezivanje) | standard | 0.5 s | 128 MB | 12 | default |
| 2018-19 | Kvalifikacije 2 | [Dobri pravougaonici](takprog-2018-19/02_KV2/02_dobri_pravougaonici) | standard | 1.5 s | 256 MB | 26 | default |
| 2018-19 | Kvalifikacije 2 | [Rokada](takprog-2018-19/02_KV2/03_rokada) | standard | 1 s | 64 MB | 52 | custom |
| 2018-19 | Kvalifikacije 2 | [Bojenje](takprog-2018-19/02_KV2/04_bojenje) | standard | 1 s | 64 MB | 27 | rewritten |
| 2018-19 | Kvalifikacije 2 | [Vrednost dodele](takprog-2018-19/02_KV2/05_vrednost_dodele) | standard | 1.6 s | 1024 MB | 46 | custom |
| 2018-19 | Kvalifikacije 3 | [Vorp Spejs](takprog-2018-19/03_KV3/01_vorpspejs) | standard | 0.4 s | 64 MB | 102 | default |
| 2018-19 | Kvalifikacije 3 | [Moć niza](takprog-2018-19/03_KV3/02_moc_niza) | standard | 0.5 s | 64 MB | 12 | default |
| 2018-19 | Kvalifikacije 3 | [Pakovanje](takprog-2018-19/03_KV3/03_pakovanje) | standard | 1.6 s | 64 MB | 12 | default |
| 2018-19 | Kvalifikacije 3 | [Požar](takprog-2018-19/03_KV3/04_pozar) | standard | 1 s | 64 MB | 21 | default |
| 2018-19 | Kvalifikacije 3 | [Sveska](takprog-2018-19/03_KV3/05_sveska) | standard | 1 s | 256 MB | 26 | default |
| 2018-19 | Okružno | [Piramida](takprog-2018-19/04_OKR/01_piramida) | standard | 1 s | 128 MB | 22 | default |
| 2018-19 | Okružno | [Fotografisanje](takprog-2018-19/04_OKR/02_fotografisanje) | standard | 1 s | 128 MB | 28 | custom |
| 2018-19 | Okružno | [Grupe](takprog-2018-19/04_OKR/03_grupe) | standard | 1 s | 128 MB | 22 | default |
| 2018-19 | Okružno | [Izgubljeni niz](takprog-2018-19/04_OKR/04_izgubljeni_niz) | standard | 1 s | 64 MB | 21 | custom |
| 2018-19 | Okružno | [Slepi brojevi](takprog-2018-19/04_OKR/05_slepi_brojevi) | standard | 0.5 s | 128 MB | 22 | default |
| 2018-19 | Okružno | [Žetoni](takprog-2018-19/04_OKR/06_zetoni) | standard | 2 s | 256 MB | 52 | custom |
| 2018-19 | Državno | [Hakerisanje](takprog-2018-19/05_DRZ/01_hakerisanje) | standard | 1 s | 64 MB | 20 | default |
| 2018-19 | Državno | [Poljoprivrednik](takprog-2018-19/05_DRZ/02_poljoprivrednik) | standard | 0.5 s | 64 MB | 24 | custom |
| 2018-19 | Državno | [Miniranje](takprog-2018-19/05_DRZ/03_miniranje) | standard | 2 s | 128 MB | 29 | default |
| 2018-19 | Državno | [Nz](takprog-2018-19/05_DRZ/04_nz) | standard | 1 s | 512 MB | 67 | default |
| 2018-19 | Državno | [Vizaard](takprog-2018-19/05_DRZ/05_vizaard) | standard | 1.5 s | 256 MB | 27 | default |
| 2018-19 | Državno | [Pariz](takprog-2018-19/05_DRZ/06_pariz) | standard | 1.5 s | 256 MB | 29 | default |
| 2018-19 | SIO | [Kombinovanje](takprog-2018-19/06_SIO/01_kombinovanje) | output-only | — | — | 4 | custom |
| 2018-19 | SIO | [Crno-bela zvezda](takprog-2018-19/06_SIO/02_zvezda) | functional | 0.4 s | 64 MB | 57 | default |
| 2018-19 | SIO | [Kamera](takprog-2018-19/06_SIO/03_kamera) | functional | 5 s | 512 MB | 45 | default |
| 2018-19 | SIO | [Skladište](takprog-2018-19/06_SIO/04_skladiste) | functional | 0.3 s | 128 MB | 20 | default |
| 2018-19 | SIO | [Planine](takprog-2018-19/06_SIO/05_planine) | functional | 1 s | 128 MB | 61 | custom |
| 2018-19 | SIO | [Film](takprog-2018-19/06_SIO/06_film) | functional | 1 s | 256 MB | 58 | custom |
| 2019-20 | Kvalifikacije 1 | [Isplata](takprog-2019-20/01_KV1/01_isplata) | standard | 0.1 s | 64 MB | 22 | exact tokens |
| 2019-20 | Kvalifikacije 1 | [Odbojka](takprog-2019-20/01_KV1/02_odbojka) | standard | 1 s | 64 MB | 23 | custom |
| 2019-20 | Kvalifikacije 1 | [Vodopad](takprog-2019-20/01_KV1/03_vodopad) | standard | 1 s | 256 MB | 25 | exact tokens |
| 2019-20 | Kvalifikacije 1 | [Šahovska trka](takprog-2019-20/01_KV1/04_sahovska_trka) | standard | 1 s | 1024 MB | 53 | exact tokens |
| 2019-20 | Kvalifikacije 1 | [Luxor](takprog-2019-20/01_KV1/05_luxor) | standard | 2 s | 64 MB | 21 | custom |
| 2019-20 | Kvalifikacije 2 | [Pikado](takprog-2019-20/02_KV2/01_pikado) | standard | 2 s | 512 MB | 22 | custom |
| 2019-20 | Kvalifikacije 2 | [Polica](takprog-2019-20/02_KV2/02_polica) | standard | 1 s | 512 MB | 22 | exact tokens |
| 2019-20 | Kvalifikacije 2 | [Zlatnici](takprog-2019-20/02_KV2/03_zlatnici) | standard | 1 s | 512 MB | 22 | exact tokens |
| 2019-20 | Kvalifikacije 2 | [JAG](takprog-2019-20/02_KV2/04_jag) | standard | 1 s | 128 MB | 22 | exact tokens |
| 2019-20 | Kvalifikacije 2 | [Gric](takprog-2019-20/02_KV2/05_gric) | standard | 1 s | 512 MB | 21 | custom |
| 2019-20 | Kvalifikacije 3 | [Upoznavanje](takprog-2019-20/03_KV3/01_upoznavanje) | standard | 2 s | 256 MB | 22 | default |
| 2019-20 | Kvalifikacije 3 | [Lubenice](takprog-2019-20/03_KV3/02_lubenice) | standard | 0.5 s | 256 MB | 22 | default |
| 2019-20 | Kvalifikacije 3 | [Sazvežđa](takprog-2019-20/03_KV3/03_sazvezdja) | standard | 0.5 s | 64 MB | 28 | custom |
| 2019-20 | Kvalifikacije 3 | [Boje](takprog-2019-20/03_KV3/04_boje) | standard | 1 s | 512 MB | 12 | default |
| 2019-20 | Kvalifikacije 3 | [K-tačne sekvence zagrada](takprog-2019-20/03_KV3/05_k-tacne_sekvence_zagrada) | standard | 5 s | 64 MB | 11 | custom |
| 2019-20 | Okružno | [Premeštanja](takprog-2019-20/04_OKR/01_premestanja) | standard | 2.5 s | 512 MB | 22 | default |
| 2019-20 | Okružno | [Zaboravljena partija](takprog-2019-20/04_OKR/02_zaboravljena) | standard | 1 s | 512 MB | 22 | custom |
| 2019-20 | Okružno | [Čarobnjak iz voza](takprog-2019-20/04_OKR/03_carobnjak_iz_voza) | standard | 1 s | 512 MB | 22 | default |
| 2019-20 | Okružno | [Dobitni listić](takprog-2019-20/04_OKR/04_dobitni_listic) | standard | 0.5 s | 512 MB | 22 | custom |
| 2019-20 | Okružno | [Bezbedna podmatrica](takprog-2019-20/04_OKR/05_bezbedna_podmatrica) | standard | 1 s | 512 MB | 22 | exact tokens |
| 2019-20 | Okružno | [Moj broj](takprog-2019-20/04_OKR/06_moj_broj) | standard | 0.3 s | 512 MB | 11 | custom |
| 2019-20 | Državno | [Lek](takprog-2019-20/05_DRZ/01_lek) | standard | 2 s | 256 MB | 42 | custom |
| 2019-20 | Državno | [Veštica](takprog-2019-20/05_DRZ/02_vestica) | standard | 1 s | 256 MB | 33 | default |
| 2019-20 | Državno | [Trookrugao](takprog-2019-20/05_DRZ/03_trookrugao) | standard | 2.5 s | 512 MB | 32 | default |
| 2019-20 | Državno | [Statistika](takprog-2019-20/05_DRZ/04_statistika) | standard | 1.5 s | 256 MB | 16 | default |
| 2019-20 | Državno | [Spec zadatak](takprog-2019-20/05_DRZ/05_spec) | standard | 1.5 s | 256 MB | 28 | default |
| 2019-20 | Državno | [Festival](takprog-2019-20/05_DRZ/06_festival) | standard | 2.5 s | 256 MB | 24 | exact tokens |
| 2019-20 | SIO | [Brojorb](takprog-2019-20/06_SIO/01_brojorb) | output-only | — | — | 15 | default |
| 2019-20 | SIO | [Šašavo odelo](takprog-2019-20/06_SIO/02_sasavo_odelo) | functional | 1.5 s | 512 MB | 29 | custom |
| 2019-20 | SIO | [Smeštaj](takprog-2019-20/06_SIO/03_smestaj) | functional | 1.5 s | 1100 MB | 52 | default |
| 2019-20 | SIO | [Dido](takprog-2019-20/06_SIO/04_dido) | functional | 1 s | 512 MB | 30 | custom |
| 2019-20 | SIO | [Mračna soba](takprog-2019-20/06_SIO/05_mracna_soba) | functional | 1.5 s | 64 MB | 42 | exact tokens |
| 2019-20 | SIO | [Metro](takprog-2019-20/06_SIO/06_metro) | functional | 1 s | 512 MB | 18 | default |
| 2020-21 | Kvalifikacije 1 | [Minimalan trud](takprog-2020-21/01_KV1/01_trud) | standard | 1 s | 256 MB | 12 | default |
| 2020-21 | Kvalifikacije 1 | [Prijatelji](takprog-2020-21/01_KV1/02_prijatelji) | standard | 1 s | 256 MB | 22 | default |
| 2020-21 | Kvalifikacije 1 | [Žalbe](takprog-2020-21/01_KV1/03_zalbe) | standard | 2 s | 256 MB | 21 | exact tokens |
| 2020-21 | Kvalifikacije 1 | [Čvrsti brojevi](takprog-2020-21/01_KV1/04_cvrsti_brojevi) | standard | 1 s | 512 MB | 22 | exact tokens |
| 2020-21 | Kvalifikacije 1 | [SIO stablo](takprog-2020-21/01_KV1/05_sio_stablo) | standard | 3 s | 256 MB | 26 | default |
| 2020-21 | Kvalifikacije 2 | [Kvadrati](takprog-2020-21/02_KV2/01_kvadrati) | standard | 1 s | 256 MB | 22 | exact tokens |
| 2020-21 | Kvalifikacije 2 | [Uzgajivači jabuka](takprog-2020-21/02_KV2/02_jabuke) | standard | 2 s | 256 MB | 11 | custom |
| 2020-21 | Kvalifikacije 2 | [Slova](takprog-2020-21/02_KV2/03_slova) | standard | 1 s | 256 MB | 12 | default |
| 2020-21 | Kvalifikacije 2 | [BUG](takprog-2020-21/02_KV2/04_BUG) | standard | 1 s | 256 MB | 22 | default |
| 2020-21 | Kvalifikacije 2 | [01 niz](takprog-2020-21/02_KV2/05_01_niz) | standard | 2 s | 256 MB | 52 | default |
| 2020-21 | Kvalifikacije 3 | [Šampion](takprog-2020-21/03_KV3/01_sampion) | standard | 1 s | 256 MB | 23 | exact tokens |
| 2020-21 | Kvalifikacije 3 | [Gejm šou](takprog-2020-21/03_KV3/02_gejm_sou) | standard | 1 s | 256 MB | 21 | default |
| 2020-21 | Kvalifikacije 3 | [Karte 2](takprog-2020-21/03_KV3/03_karte2) | standard | 2.5 s | 256 MB | 12 | custom |
| 2020-21 | Kvalifikacije 3 | [Pitanja](takprog-2020-21/03_KV3/04_pitanja) | standard | 1.5 s | 1024 MB | 27 | default |
| 2020-21 | Kvalifikacije 3 | [Novogodišnje stablo](takprog-2020-21/03_KV3/05_novogodisnje_stablo) | standard | 2 s | 256 MB | 21 | custom |
| 2020-21 | Okružno | [Takmičar](takprog-2020-21/04_OKR/01_takmicar) | standard | 1.5 s | 256 MB | 22 | exact tokens |
| 2020-21 | Okružno | [Lepa matrica](takprog-2020-21/04_OKR/02_lepa_matrica) | standard | 2 s | 256 MB | 21 | default |
| 2020-21 | Okružno | [Zlatnici 2: Električni bugalu](takprog-2020-21/04_OKR/03_zlatnici_2_elektricni_bugalu) | standard | 1.5 s | 256 MB | 21 | default |
| 2020-21 | Okružno | [Standardan zadatak](takprog-2020-21/04_OKR/04_standardan_zadatak) | standard | 1 s | 256 MB | 22 | default |
| 2020-21 | Okružno | [Velika trka](takprog-2020-21/04_OKR/05_velika_trka) | standard | 3 s | 256 MB | 21 | default |
| 2020-21 | Okružno | [Altruizam](takprog-2020-21/04_OKR/06_altruizam) | standard | 1 s | 256 MB | 22 | default |
| 2020-21 | Državno | [Kvadrati uzvraćaju udarac](takprog-2020-21/05_DRZ/01_kvadrati_uzvracaju_udarac) | standard | 0.5 s | 256 MB | 25 | default |
| 2020-21 | Državno | [Preduzeće](takprog-2020-21/05_DRZ/02_preduzece) | standard | 1 s | 256 MB | 22 | default |
| 2020-21 | Državno | [Proslava rođendana](takprog-2020-21/05_DRZ/03_proslava_rodjendana) | standard | 2 s | 256 MB | 29 | default |
| 2020-21 | Državno | [Žice](takprog-2020-21/05_DRZ/04_zice) | standard | 1 s | 256 MB | 16 | exact tokens |
| 2020-21 | Državno | [Jakuze](takprog-2020-21/05_DRZ/05_jakuze) | standard | 2 s | 256 MB | 25 | default |
| 2020-21 | Državno | [NZD permutacije](takprog-2020-21/05_DRZ/06_nzd_permutacije) | standard | 2 s | 256 MB | 25 | default |
| 2020-21 | SIO | [RNK](takprog-2020-21/06_SIO/01_rnk) | functional | 1 s | 256 MB | 20 | custom |
| 2020-21 | SIO | [Marsko](takprog-2020-21/06_SIO/02_marsko) | functional | 1 s | 256 MB | 23 | default |
| 2020-21 | SIO | [Tačke](takprog-2020-21/06_SIO/03_tacke) | functional | 2 s | 256 MB | 40 | default |
| 2020-21 | SIO | [Izvlačenje slamki](takprog-2020-21/06_SIO/04_izvlacenje_slamki) | functional | 1 s | 256 MB | 32 | exact tokens |
| 2020-21 | SIO | [Xorko](takprog-2020-21/06_SIO/05_xorko) | functional | 1 s | 256 MB | 35 | default |
| 2020-21 | SIO | [Dva stabla](takprog-2020-21/06_SIO/06_dva_stabla) | functional | 3 s | 256 MB | 27 | default |
| 2021-22 | Kvalifikacije 1 | [Nesusedni](takprog-2021-22/01_KV1/01_nesusedni) | standard | 0.2 s | 256 MB | 22 | custom |
| 2021-22 | Kvalifikacije 1 | [Transfuzija krvi](takprog-2021-22/01_KV1/02_transfuzija) | standard | 0.5 s | 256 MB | 12 | custom |
| 2021-22 | Kvalifikacije 1 | [Prepisivači](takprog-2021-22/01_KV1/03_prepisivaci) | standard | 1 s | 256 MB | 22 | default |
| 2021-22 | Kvalifikacije 1 | [Cen\*ura](takprog-2021-22/01_KV1/04_cenzura) | standard | 1 s | 256 MB | 21 | custom |
| 2021-22 | Kvalifikacije 1 | [Noćna vožnja](takprog-2021-22/01_KV1/05_nocnavoznja) | standard | 4 s | 256 MB | 21 | default |
| 2021-22 | Kvalifikacije 2 | [Mađioničar](takprog-2021-22/02_KV2/01_madjionicar) | standard | 1 s | 256 MB | 22 | default |
| 2021-22 | Kvalifikacije 2 | [Ekskurzija](takprog-2021-22/02_KV2/02_ekskurzija) | standard | 0.1 s | 256 MB | 11 | default |
| 2021-22 | Kvalifikacije 2 | [Palindrom šafl](takprog-2021-22/02_KV2/03_palindrom_safl) | standard | 0.5 s | 256 MB | 22 | default |
| 2021-22 | Kvalifikacije 2 | [Gušter](takprog-2021-22/02_KV2/04_guster) | standard | 0.5 s | 128 MB | 23 | default |
| 2021-22 | Kvalifikacije 2 | [Čarobnjak](takprog-2021-22/02_KV2/05_carobnjak) | standard | 1 s | 256 MB | 21 | default |
| 2021-22 | Kvalifikacije 3 | [Biodiverzitet](takprog-2021-22/03_KV3/01_biodiverzitet) | standard | 1 s | 64 MB | 21 | exact tokens |
| 2021-22 | Kvalifikacije 3 | [Mlađioničar](takprog-2021-22/03_KV3/02_mladjionicar) | standard | 0.5 s | 256 MB | 22 | custom |
| 2021-22 | Kvalifikacije 3 | [Psiho](takprog-2021-22/03_KV3/03_psiho) | standard | 1 s | 256 MB | 22 | exact tokens |
| 2021-22 | Kvalifikacije 3 | [Konjugacija](takprog-2021-22/03_KV3/04_konjugacija) | standard | 1 s | 256 MB | 22 | exact tokens |
| 2021-22 | Kvalifikacije 3 | [Min Max Plus](takprog-2021-22/03_KV3/05_min_max_plus) | standard | 3 s | 256 MB | 27 | exact tokens |
| 2021-22 | Okružno | [Odbijanje](takprog-2021-22/04_OKR/01_odbijanje) | standard | 0.5 s | 512 MB | 12 | default |
| 2021-22 | Okružno | [Štale](takprog-2021-22/04_OKR/02_stale) | standard | 1 s | 512 MB | 22 | default |
| 2021-22 | Okružno | [Okram](takprog-2021-22/04_OKR/03_okram) | standard | 3 s | 512 MB | 21 | exact tokens |
| 2021-22 | Okružno | [Sličice](takprog-2021-22/04_OKR/04_slicice) | standard | 1 s | 512 MB | 11 | default |
| 2021-22 | Okružno | [Ćivas](takprog-2021-22/04_OKR/05_civas) | standard | 1 s | 512 MB | 22 | exact tokens |
| 2021-22 | Okružno | [AdVenture Communist](takprog-2021-22/04_OKR/06_adventure_communist) | standard | 0.5 s | 512 MB | 21 | default |
| 2021-22 | Državno | [Jednačine](takprog-2021-22/05_DRZ/01_jednacine) | standard | 1 s | 64 MB | 26 | exact tokens |
| 2021-22 | Državno | [Turnir](takprog-2021-22/05_DRZ/02_turnir) | standard | 2 s | 267 MB | 38 | exact tokens |
| 2021-22 | Državno | [Burad](takprog-2021-22/05_DRZ/03_burad) | standard | 1 s | 256 MB | 31 | exact tokens |
| 2021-22 | Državno | [Koncert](takprog-2021-22/05_DRZ/04_koncert) | standard | 0.5 s | 256 MB | 22 | exact tokens |
| 2021-22 | Državno | [Šmeker](takprog-2021-22/05_DRZ/05_smeker) | standard | 1 s | 256 MB | 28 | exact tokens |
| 2021-22 | Državno | [Konstrukta](takprog-2021-22/05_DRZ/06_konstrukta) | standard | 1.6 s | 256 MB | 44 | custom |
| 2021-22 | SIO | [Laz](takprog-2021-22/06_SIO/01_laz) | functional | 1 s | 64 MB | 50 | custom |
| 2021-22 | SIO | [TSM](takprog-2021-22/06_SIO/02_tsm) | functional | 1.5 s | 256 MB | 25 | exact tokens |
| 2021-22 | SIO | [Igrica](takprog-2021-22/06_SIO/03_igrica) | functional | 2.5 s | 256 MB | 30 | default |
| 2021-22 | SIO | [Dugmići](takprog-2021-22/06_SIO/04_dugmici) | functional | 0.7 s | 64 MB | 32 | default |
| 2021-22 | SIO | [US Open](takprog-2021-22/06_SIO/05_us_open) | functional | 1 s | 256 MB | 43 | default |
| 2021-22 | SIO | [Metropole](takprog-2021-22/06_SIO/06_metropole) | functional | 1 s | 512 MB | 55 | default |
| 2021-22 | EJOI izborno | [Poslovan Čovek](takprog-2021-22/07_EJOI_Izborno/01_poslovan_covek) | standard | 1.3 s | 256 MB | 35 | default |
| 2021-22 | EJOI izborno | [Arhitekta](takprog-2021-22/07_EJOI_Izborno/02_arhitekta) | standard | 1.5 s | 128 MB | 35 | default |
| 2021-22 | EJOI izborno | [Zagrade](takprog-2021-22/07_EJOI_Izborno/03_zagrade) | standard | 1 s | 64 MB | 31 | default |
| 2021-22 | EGOI izborno | [Računar](takprog-2021-22/08_EGOI_Izborno/01_racunar) | standard | 1 s | 64 MB | 19 | default |
| 2021-22 | EGOI izborno | [XXL Matrica](takprog-2021-22/08_EGOI_Izborno/02_xxl_matrica) | standard | 1 s | 64 MB | 92 | default |
| 2021-22 | EGOI izborno | [Nadvlačenje konopca](takprog-2021-22/08_EGOI_Izborno/03_nadvlacenje_konopca) | standard | 1 s | 64 MB | 26 | default |
| 2021-22 | EGOI izborno | [Šestougao](takprog-2021-22/08_EGOI_Izborno/04_sestougao) | standard | 2 s | 256 MB | 37 | default |
| 2022-23 | Kvalifikacije 1 | [Sudar](takprog-2022-23/01_KV1/01_sudar) | standard | 0.1 s | 32 MB | 45 | default |
| 2022-23 | Kvalifikacije 1 | [Nameštanje glasanja](takprog-2022-23/01_KV1/02_namestanjeg) | standard | 1 s | 64 MB | 35 | custom |
| 2022-23 | Kvalifikacije 1 | [Sante](takprog-2022-23/01_KV1/03_sante) | standard | 1 s | 64 MB | 22 | default |
| 2022-23 | Kvalifikacije 1 | [Vage](takprog-2022-23/01_KV1/04_vage) | standard | 2 s | 256 MB | 22 | default |
| 2022-23 | Kvalifikacije 1 | [Zlatnici 3](takprog-2022-23/01_KV1/05_zlatnici3) | standard | 0.8 s | 256 MB | 22 | default |
| 2022-23 | Kvalifikacije 2 | [Spojler](takprog-2022-23/02_KV2/01_spojler) | standard | 0.1 s | 256 MB | 23 | exact tokens |
| 2022-23 | Kvalifikacije 2 | [Finale](takprog-2022-23/02_KV2/02_finale) | standard | 0.1 s | 32 MB | 22 | exact tokens |
| 2022-23 | Kvalifikacije 2 | [Gužva](takprog-2022-23/02_KV2/03_guzva) | standard | 3 s | 256 MB | 21 | exact tokens |
| 2022-23 | Kvalifikacije 2 | [Formacija](takprog-2022-23/02_KV2/04_formacija) | standard | 1 s | 256 MB | 22 | exact tokens |
| 2022-23 | Kvalifikacije 2 | [Opklada](takprog-2022-23/02_KV2/05_opklada) | standard | 4 s | 256 MB | 21 | custom |
| 2022-23 | Okružno | [Kuvar](takprog-2022-23/03_OKR/01_kuvar) | standard | 1 s | 64 MB | 12 | default |
| 2022-23 | Okružno | [Razmena znaka](takprog-2022-23/03_OKR/02_razmena_znaka) | standard | 1.5 s | 256 MB | 21 | default |
| 2022-23 | Okružno | [Jednostavni pikado](takprog-2022-23/03_OKR/03_jednostavni_pikado) | standard | 2 s | 512 MB | 22 | default |
| 2022-23 | Okružno | [Poklon](takprog-2022-23/03_OKR/04_poklon) | standard | 1 s | 128 MB | 21 | default |
| 2022-23 | Okružno | [Krompiri](takprog-2022-23/03_OKR/05_krompiri) | standard | 0.75 s | 64 MB | 22 | custom |
| 2022-23 | Okružno | [Sdneirf](takprog-2022-23/03_OKR/06_sdneirf) | standard | 2 s | 256 MB | 22 | default |
| 2022-23 | Državno | [Bakterijada](takprog-2022-23/04_DRZ/01_bakterijada) | standard | 1 s | 64 MB | 21 | default |
| 2022-23 | Državno | [Xor Fabrika](takprog-2022-23/04_DRZ/02_xor_fabrika) | standard | 1 s | 64 MB | 21 | default |
| 2022-23 | Državno | [Kirbi](takprog-2022-23/04_DRZ/03_kirbi) | standard | 3 s | 64 MB | 21 | default |
| 2022-23 | Državno | [Život u gradu](takprog-2022-23/04_DRZ/04_zivot_u_gradu) | standard | 1 s | 256 MB | 34 | custom |
| 2022-23 | Državno | [Bekstvo](takprog-2022-23/04_DRZ/05_bekstvo) | standard | 1 s | 512 MB | 95 | default |
| 2022-23 | Državno | [Turizam](takprog-2022-23/04_DRZ/06_turizam) | standard | 2.5 s | 512 MB | 44 | default |
| 2022-23 | SIO | [Operacija nad glistom](takprog-2022-23/05_SIO/01_operacija_nad_glistom) | functional | 1 s | 256 MB | 41 | default |
| 2022-23 | SIO | [Kompresovani niz](takprog-2022-23/05_SIO/02_kompresovani_niz) | functional | 0.5 s | 256 MB | 132 | default |
| 2022-23 | SIO | [Najslabija karika](takprog-2022-23/05_SIO/03_samo_najjaci_opstaju) | functional | 3.5 s | 512 MB | 50 | default |
| 2022-23 | SIO | [Opet XOR](takprog-2022-23/05_SIO/04_opet_xor) | functional | 4 s | 512 MB | 13 | default |
| 2022-23 | SIO | [vOOda](takprog-2022-23/05_SIO/05_vOOda) | output-only | — | — | 8 | custom |
| 2022-23 | SIO | [Parovi](takprog-2022-23/05_SIO/06_parovi) | functional | 1 s | 64 MB | 61 | default |
| 2023-24 | Kvalifikacije 1 | [Tri tajna broja](takprog-2023-24/01_KV1/01_tri_tajna_broja) | standard | 1 s | 64 MB | 21 | default |
| 2023-24 | Kvalifikacije 1 | [Moramo da recikliramo](takprog-2023-24/01_KV1/02_moramo_da_recikliramo) | standard | 2 s | 64 MB | 21 | default |
| 2023-24 | Kvalifikacije 1 | [Presedanja](takprog-2023-24/01_KV1/03_presedanja) | standard | 1 s | 64 MB | 22 | default |
| 2023-24 | Kvalifikacije 1 | [Veća trka](takprog-2023-24/01_KV1/04_veca_trka) | standard | 3 s | 64 MB | 22 | custom |
| 2023-24 | Kvalifikacije 1 | [Fejk reklama](takprog-2023-24/01_KV1/05_fejk_reklama) | standard | 1 s | 256 MB | 23 | default |
| 2023-24 | Kvalifikacije 2 | [Nadkvadrat](takprog-2023-24/02_KV2/01_nadkvadrat) | standard | 0.1 s | 32 MB | 23 | default |
| 2023-24 | Kvalifikacije 2 | [Manja je matrica od matrice](takprog-2023-24/02_KV2/02_manja_je_matrica_od_matrice) | standard | 2 s | 256 MB | 22 | exact tokens |
| 2023-24 | Kvalifikacije 2 | [Školice](takprog-2023-24/02_KV2/03_skolice) | standard | 2 s | 256 MB | 21 | exact tokens |
| 2023-24 | Kvalifikacije 2 | [Obaranje ruku](takprog-2023-24/02_KV2/04_obaranje_ruku) | standard | 2.4 s | 768 MB | 27 | exact tokens |
| 2023-24 | Kvalifikacije 2 | [Pećinski zečevi](takprog-2023-24/02_KV2/05_pecinski_zecevi) | standard | 6 s | 512 MB | 29 | default |
| 2023-24 | Okružno | [Usamljenost](takprog-2023-24/03_OKR/01_usamljenost) | standard | 0.3 s | 64 MB | 22 | default |
| 2023-24 | Okružno | [Dejn](takprog-2023-24/03_OKR/02_dejn) | standard | 1 s | 64 MB | 23 | default |
| 2023-24 | Okružno | [Bitvajz oranje](takprog-2023-24/03_OKR/03_bitvajz_oranje) | standard | 2 s | 256 MB | 27 | default |
| 2023-24 | Okružno | [Xormutacije](takprog-2023-24/03_OKR/04_xormutacije) | standard | 1 s | 256 MB | 22 | custom |
| 2023-24 | Okružno | [Monopol](takprog-2023-24/03_OKR/05_monopol) | standard | 0.7 s | 64 MB | 22 | default |
| 2023-24 | Okružno | [Linijopolis](takprog-2023-24/03_OKR/06_linijopolis) | standard | 4 s | 128 MB | 22 | default |
| 2023-24 | Državno | [Nepodniz](takprog-2023-24/04_DRZ/01_nepodniz) | standard | 3 s | 64 MB | 33 | default |
| 2023-24 | Državno | [Domski Sletač](takprog-2023-24/04_DRZ/02_domski_sletac) | standard | 1 s | 256 MB | 30 | default |
| 2023-24 | Državno | [Starući prsten](takprog-2023-24/04_DRZ/03_staruci_prsten) | standard | 1 s | 256 MB | 59 | default |
| 2023-24 | Državno | [I/ili](takprog-2023-24/04_DRZ/04_i_ili) | standard | 1 s | 64 MB | 22 | default |
| 2023-24 | Državno | [Kiki](takprog-2023-24/04_DRZ/05_kiki) | standard | 1.5 s | 256 MB | 40 | custom |
| 2023-24 | Državno | [Palindromska šetnja](takprog-2023-24/04_DRZ/06_palindromska_setnja) | standard | 3 s | 256 MB | 102 | default |
| 2023-24 | SIO | [Spartacus](takprog-2023-24/05_SIO/01_spartacus) | functional | 0.1 s | 256 MB | 68 | exact tokens |
| 2023-24 | SIO | [Et tu, Brute?](takprog-2023-24/05_SIO/02_et_tu_brute) | functional | 1.5 s | 256 MB | 50 | default |
| 2023-24 | SIO | [E pluribus unum](takprog-2023-24/05_SIO/03_e_pluribus_unum) | functional | 3.5 s | 256 MB | 93 | default |
| 2023-24 | SIO | [Quaestio militaris formationis](takprog-2023-24/05_SIO/04_quaestio_militaris_formationis) | functional | 1 s | 256 MB | 31 | custom |
| 2023-24 | SIO | [Viae Romanae](takprog-2023-24/05_SIO/05_viae_romanae) | functional | 1.5 s | 256 MB | 104 | default |
| 2023-24 | SIO | [Turris inclinata](takprog-2023-24/05_SIO/06_turris_inclinata) | functional | 1.5 s | 256 MB | 80 | default |
| 2024-25 | Kvalifikacije 1 | [Pećina](takprog-2024-25/01_KV1/01_pecina) | standard | 0.2 s | 64 MB | 23 | default |
| 2024-25 | Kvalifikacije 1 | [Plazma](takprog-2024-25/01_KV1/02_plazma) | standard | 3 s | 128 MB | 52 | default |
| 2024-25 | Kvalifikacije 1 | [Požar](takprog-2024-25/01_KV1/03_pozar) | standard | 1 s | 256 MB | 24 | default |
| 2024-25 | Kvalifikacije 1 | [Konveksni skoro omotač](takprog-2024-25/01_KV1/04_konveksni_skoro_omotac) | standard | 1.5 s | 64 MB | 28 | default |
| 2024-25 | Kvalifikacije 1 | [Dva niza](takprog-2024-25/01_KV1/05_dvaniza) | standard | 1.5 s | 256 MB | 26 | default |
| 2024-25 | Kvalifikacije 2 | [Prosek i medijana](takprog-2024-25/02_KV2/01_prosek_i_medijana) | standard | 0.1 s | 64 MB | 23 | default |
| 2024-25 | Kvalifikacije 2 | [Sreća u matrici](takprog-2024-25/02_KV2/02_sreca_u_matrici) | standard | 1 s | 64 MB | 22 | default |
| 2024-25 | Kvalifikacije 2 | [Putešestvije](takprog-2024-25/02_KV2/03_putesestvije) | standard | 3 s | 256 MB | 22 | custom |
| 2024-25 | Kvalifikacije 2 | [Daltonizacija](takprog-2024-25/02_KV2/04_daltonizacija) | standard | 2 s | 128 MB | 27 | default |
| 2024-25 | Kvalifikacije 2 | [Zanimljivi grafovski upiti](takprog-2024-25/02_KV2/05_zanimljivi_grafovski_upiti) | standard | 8.5 s | 1024 MB | 22 | default |
| 2024-25 | Kvalifikacije za izborno | [Karte 3](takprog-2024-25/A_PIZ/01_karte_3) | standard | 1 s | 256 MB | 21 | default |
| 2024-25 | Kvalifikacije za izborno | [Najveća pojava](takprog-2024-25/A_PIZ/02_najveca_pojava) | standard | 1.5 s | 256 MB | 73 | default |
| 2024-25 | Kvalifikacije za izborno | [Radoje](takprog-2024-25/A_PIZ/03_radoje) | standard | 1 s | 256 MB | 56 | custom |
| 2024-25 | Kvalifikacije za izborno | [Pisma iz Sukrea](takprog-2024-25/A_PIZ/04_pisma_iz_sukrea) | standard | 2 s | 64 MB | 24 | default |
| 2024-25 | Izborno | [Uzumaki](takprog-2024-25/B_IZB/01_uzumaki) | functional | 4 s | 256 MB | 56 | default |
| 2024-25 | Izborno | [Mesi](takprog-2024-25/B_IZB/02_mesi) | functional | 0.5 s | 128 MB | 70 | default |
| 2024-25 | Izborno | [Šafler](takprog-2024-25/B_IZB/03_safler) | functional | 1.5 s | 256 MB | 25 | default |
| 2024-25 | Izborno | [Nalbandian](takprog-2024-25/B_IZB/04_nalbandian) | functional | 3 s | 256 MB | 82 | default |
| 2024-25 | Izborno | [Sabiranje razapinjućih stabala](takprog-2024-25/B_IZB/05_sabiranje_razapinjucih_stabala) | functional | 0.5 s | 256 MB | 34 | default |
| 2024-25 | Izborno | [Titikaka](takprog-2024-25/B_IZB/06_titikaka) | functional | 2 s | 512 MB | 10 | custom |
| 2025-26 | Kvalifikacije | [Podela jabuka](takprog-2025-26/01_KV/01_podela_jabuka) | standard | 1 s | 64 MB | 22 | default |
| 2025-26 | Kvalifikacije | [Najbliži neprijatelj](takprog-2025-26/01_KV/02_najblizi_neprijatelj) | standard | 1 s | 64 MB | 102 | default |
| 2025-26 | Kvalifikacije | [Dzek Vrabac](takprog-2025-26/01_KV/03_dzek_vrabac) | standard | 1 s | 64 MB | 51 | default |
| 2025-26 | Kvalifikacije | [Prijateljski trkači](takprog-2025-26/01_KV/04_prijateljski_trkaci) | standard | 1 s | 64 MB | 50 | default |
| 2025-26 | Kvalifikacije | [Paintball](takprog-2025-26/01_KV/05_paintball) | standard | 1 s | 64 MB | 22 | custom |
| 2025-26 | Kvalifikacije | [Baki i Srecko](takprog-2025-26/01_KV/06_najvektor) | standard | 1 s | 64 MB | 52 | custom |
| 2025-26 | Kvalifikacije | [Mst 😭](takprog-2025-26/01_KV/07_mst_😭) | standard | 1 s | 256 MB | 51 | default |
| 2025-26 | Kvalifikacije | [Igra sa Kartama](takprog-2025-26/01_KV/08_Igra_sa_kartama) | standard | 3 s | 256 MB | 23 | default |
| 2025-26 | Kvalifikacije | [Potera](takprog-2025-26/01_KV/09_potera) | standard | 5 s | 256 MB | 27 | default |
| 2025-26 | Kvalifikacije | [Perica i novogodisnje stablo](takprog-2025-26/01_KV/10_laganje) | standard | 0.5 s | 256 MB | 51 | custom |
| 2025-26 | Kvalifikacije | [Srecko i Ponchoi](takprog-2025-26/01_KV/11_srecko_i_poncoi) | standard | 1 s | 512 MB | 51 | custom |
| 2025-26 | Okružno | [Majstorija](takprog-2025-26/02_OKR/01_majstorija) | standard | 1 s | 256 MB | 21 | custom |
| 2025-26 | Okružno | [Hari Poter](takprog-2025-26/02_OKR/02_hari_poter) | standard | 1 s | 128 MB | 22 | custom |
| 2025-26 | Okružno | [Abakus 2](takprog-2025-26/02_OKR/03_abakus) | standard | 2 s | 256 MB | 22 | default |
| 2025-26 | Okružno | [Xormutacije 2](takprog-2025-26/02_OKR/04_xormutacije) | standard | 1.5 s | 256 MB | 21 | default |
| 2025-26 | Okružno | [Vasa, skupljač aure](takprog-2025-26/02_OKR/05_vasa_skupljac) | standard | 1 s | 128 MB | 22 | default |
| 2025-26 | Okružno | [Xorovanje delilaca](takprog-2025-26/02_OKR/06_xorovanje_delilaca) | standard | 1 s | 256 MB | 22 | default |
| 2025-26 | Državno | [Nameštaljka](takprog-2025-26/03_DRZ/01_cikcak) | standard | 1 s | 64 MB | 39 | custom |
| 2025-26 | Državno | [Aralski Mornar](takprog-2025-26/03_DRZ/02_aralski_mornar) | standard | 1 s | 512 MB | 44 | default |
| 2025-26 | Državno | [Sub67ce](takprog-2025-26/03_DRZ/03_sub67ce) | standard | 2 s | 512 MB | 29 | default |
| 2025-26 | Državno | [Ekskluzivni Kamp](takprog-2025-26/03_DRZ/04_fini_cvorovi) | standard | 1 s | 256 MB | 45 | custom |
| 2025-26 | Državno | [Kodforses blog](takprog-2025-26/03_DRZ/05_codeforces_blogovi) | standard | 0.25 s | 256 MB | 137 | custom |
| 2025-26 | Državno | [A3 - Intergalaktički sukob](takprog-2025-26/03_DRZ/06_buenas_tackas) | standard | 1.5 s | 256 MB | 72 | custom |
| 2025-26 | EGOI izborno | [Raspored](takprog-2025-26/04_EGOI_IZB/01_raspored) | standard | 2.5 s | 256 MB | 87 | custom |
| 2025-26 | EGOI izborno | [Dva Tornja](takprog-2025-26/04_EGOI_IZB/02_dva_tornja) | standard | 2 s | 256 MB | 64 | default |
| 2025-26 | EGOI izborno | [Takmičenje](takprog-2025-26/04_EGOI_IZB/03_takmicenje) | standard | 1 s | 256 MB | 85 | default |
| 2025-26 | EGOI izborno | [Tajna Matrica](takprog-2025-26/04_EGOI_IZB/04_tajna_matrica) | functional | 1 s | 256 MB | 74 | custom |
| 2025-26 | SIO | [Prodaja](takprog-2025-26/05_SIO/01_prodaja) | functional | 1 s | 64 MB | 158 | default |
| 2025-26 | SIO | [Gradovi](takprog-2025-26/05_SIO/02_gradovi) | functional | 1 s | 256 MB | 67 | custom |
| 2025-26 | SIO | [Minecraft kOOfa](takprog-2025-26/05_SIO/03_koofa) | output-only | — | — | 10 | custom |
| 2025-26 | SIO | [Vasilije mrzi geometriju](takprog-2025-26/05_SIO/04_vasa_mrzi_geometriju) | functional | 0.5 s | 64 MB | 99 | default |
| 2025-26 | SIO | [Intergalakticki konflikt dva](takprog-2025-26/05_SIO/05_intergalakticki_konflikt_dva) | functional | 2 s | 64 MB | 116 | custom |
| 2025-26 | SIO | [Gajbiša](takprog-2025-26/05_SIO/06_gajbisa) | functional | 5 s | 512 MB | 60 | default |
