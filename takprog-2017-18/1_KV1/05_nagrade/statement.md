---
timelimit: 1
memlimit: 128
---
Kao što se inače često dešava u takmičarskim zadacima, našli ste se u čudnoj situaciji: dato vam je $N$ gomila novčića ($i$-ta gomila sadrži $A_i$ novčića). Planirate da organizujete $N$ takmičenja, gde ćete za svako od njih iskoristiti jednu gomilu kao nagradni fond ($A_1$ ѕa prvo, $A_2$ ѕa drugo, i tako dalje).

Za svako takmičenje treba da odaberete koliko će učesnika biti nagrađeno (obeležićemo broj nagrađenih na $i$-tom takmičenju sa $B_i$). Sve nagrade na jednom takmičenju su iste, tako da $A_i$ mora biti deljivo sa $B_i$. Dodatno, sve vrednosti $B_i$ moraju biti prosti brojevi (niste sigurni zašto, ali neko vam je rekao da je to dobra ideja).

Da bi ciklus takmičenja bio interesantniji, planirate da odaberete vrednosti $B_i$ tako da su nagrade na svim takmičenjima različite, tj. da za svaki par vrednosti $(i,j)$ važi $\frac{A_i}{B_i} \neq
\frac{A_j}{B_j}$. Vaš zadatak je da napišete program koji će pronaći ovakvu podelu ili utvrditi da to nije moguće.

## Opis ulaza

U prvom redu standardnog ulaza nalazi se jedan ceo broj $N$ -- broj takmičenja koja organizujete. U drugom redu nalazi se $N$ brojeva $A_1,
A_2, \ldots, A_N$, koji predstavljaju broj novčića u nagradnim fondovima pojedinačnih takmičenja.

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati $N$ brojeva $B_1,
B_2, \ldots, B_N$ -- broj nagrađenih takmičara na svakom takmičenju, tako da su uslovi iz teksta zadatka zadovoljeni. Ukoliko to nije moguće, ispisati -1.

Ukoliko postoji više rešenja, ispisati bilo koje.

## Primer 1

### Ulaz

```
4
10 8 15 7
```

### Izlaz

```
2 2 5 7
```

## Primer 2

### Ulaz

```
2
2 7
```

### Izlaz

```
-1
```

## Objašnjenje primera

U prvom primeru, jedno moguće rešenje je da se na prvom takmičenju dodele dve nagrade od po $5$ novčića, na drugom dve od po $4$, na trećem pet od po $3$ i na četvrtom sedam nagrada od po jednog novčića. Pošto su sve nagrade različite, i na svakom takmičenju je nagrađen prost broj takmičara, ova podela zadovoljava date uslove. Moguća su i druga rešenja, na primer da se na prvom takmičenju nagradi pet, a na trećem tri takmičara.

U drugom primeru, jedino rešenje gde je nagrađen prost broj takmičara je `2 7` (jer $1$ nije prost broj). Kako su na njemu nagrade na oba takmičenja iste (po jedan novčić), ono ne zadovoljava sve uslove, tako da ne postoji rešenje.

## Ograničenja

- $1 \leq N$
- $1 \leq A_i$

Test primeri su podeljeni u tri disjunktne grupe:

- U test primerima koji vrede $20$ poena važi $N \leq 8, A_i \leq 1000$
- U test primerima koji vrede $20$ poena važi $N \leq 1000, A_i \leq 3000$
- U test primerima koji vrede $60$ poena važi $N \leq 1000, A_i \leq 200000$
