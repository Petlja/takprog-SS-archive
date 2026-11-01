---
timelimit: 1
memlimit: 64
---
Jedan grad ima $n$ stanovnika i samo jednu ulicu koju možemo prestaviti $x$-osom. Za svakog stanovnika je poznata koordinata njegove kuće na $x$-osi, (moguće je da nekoliko kuća ima istu koordinatu). U ovaj grad dolazi poznati sajber-prevarant Džimi Rudar koji planira da otvori tačno dve prodavnice opreme za rudarenje bitkoina - u jednoj će prodavati pijuke a u drugoj ašove. Džimi Rudar zna da će, nakon otvaranja prodavnica, svaki stanovnik pojuriti u njemu najbližu prodavnicu da kupi opremu a ukoliko su obe prodavnice podjednako udaljene, stanovnik će slučajno odabrati jednu od njih (njima nije bitno da li im treba pijuk ili ašov, bitno da se rudare bitkoini).

Džimi želi da optimalno izgradi prodavnice i već je napravio $m$ potencijalnih planova: svaki plan je par brojeva $(A_i, B_i)$ i označava da Džimi želi da sagradi prodavnicu pijuka na koordinati $A_i$ i prodavnicu ašova na koordinati $B_i$ na $x$-osi. Džimi ima molbu za vas: za svaki od $m$ potencijalnih planova, izračunajte ukupnu razdaljinu koju bi prešli svi stanovnici ukoliko bi prodavnice bile izgrađene na koordinatama zadatim u tom planu. Ukoliko ovo odradite, dobijate 5kg bitkoina od Džimija! Podsetimo se da je rastojanje između tačaka $X$ i $Y$ na $x$-osi jednako $|X - Y|$.

## Opis ulaza

U prvom redu standardnog ulaza nalaze se dva prirodna broja $n$ i $m$, broj kuća i broj upita, redom. U narednom redu nalazi se $n$ prirodnih brojeva $X_i$ koji predstavljaju koordinate kuća. U narednih $m$ redova nalaze se po dva prirodna broja $A_i$ i $B_i$ koji predstavljaju plan za izgradnju prodavnica na tim koordinatama.

## Opis izlaza

Ispisati $m$ prirodnih brojeva, u svakom redu po jedan, koji predstavljaju odgovore na datih $m$ upita u odgovarajućem redosledu.

## Primeri

## Primer 1

### Ulaz

```
5 2
12 50 70 1 10
10 100
60 8
```

### Izlaz

```
81
33
```

## Primer 2

### Ulaz

```
3 1
1000000000 1000000000 1000000000
1 2
```

### Izlaz

```
2999999994
```

## Objašnjenje primera

U prvom test primeru, prvi plan predviđa izgradnju prodavnice pijuka i ašova na koordinatama 10 i 100, redom. U tom slučaju, prvi stanovnik (sa koordinatom 12) ide u prodavnicu pijuka i prelazi rastojanje $|10 - 12| = 2$; drugi stanovnik (koordinata 50) takođe ide u prodavnicu pijuka i prelazi rastojanje $|50 - 10| = 40$; treći stanovnik ide u prodavnicu ašova i prelazi rastojanje $|70 - 100| = 30$; četvrti stanovnik prelazi rastojanje 9 dok peti prelazi rastojanje 0. Ukupno pređeno rastojanje je $2 + 40 + 30 + 9 + 0 = 81$. U slučaju drugog plana (prodavnice na koordinatama 60 i 8) ukupno pređeno rastojanje je $4 + 10 + 10 + 7 + 2 = 33$.

## Ograničenja

- $1 \leq n \leq 10^5$
- $1 \leq n \leq 10^5$
- $1 \leq X_i \leq 10^9$
- $1 \leq A_i, B_i \leq 10^9$

Test primeri su podeljeni u pet disjunktnih grupa:

- U test primerima koji vrede $20$ poena važiće $1 \leq N, M \leq 1000$.
- U test primerima koji vrede $15$ poena važiće $A_i = B_i$ za svako $i$.
- U test primerima koji vrede $15$ poena važiće $A_i \leq min X$ i $max X \leq B_i$ za svako $i$.
- U test primerima koji vrede $20$ poena važiće $1 \leq A_i, B_i, X_i \leq 10^6$.
- U test primerima koji vrede $30$ poena nema dodatnih ograničenja.
