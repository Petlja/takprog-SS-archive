---
timelimit: 1.5
memlimit: 256
---
Sada, kada je odradio takmičenje, Miroslav je shvatio koliko je programiranje naporno, te je odlučio da pobegne na Mars. On je na internetu naišao na nagradnu igru Mingo u kojoj je glavna nagrada put na Mars.

Nagradna igra se sastoji u tome da svaki takmičar na listiću izabere tačno $K$ različitih prirodnih brojeva, gde je svaki broj iz skupa ${1, 2, 3, ..., M}$. Nakon toga se vrši $Q$ izvlačenja, gde svako izvlačenje podrazumeva nasumičan odabir tačno $K$ različitih brojeva iz prethodno pomenutog skupa. Svaki listić važi za svih $Q$ izvlačenja, i takmičar koji ima listić sa svim izvučenim brojevima u bilo kom od $Q$ izvlačenja dobija put na Mars.

Kako bi povećao svoje šanse, Miroslav je popunio $N$ listića. Kako je sada teško pratiti sve te listiće, on je zamolio vas da mu pomognete.

On želi da za svako izvlačenje u svakom trenutku zna koliko listića ima svaki do tada izvučen broj, tj. za svako izvlačenje posebno, nakon izvučenog $i$-tog broja on želi da zna koliko njegovih listića sadrži svaki od izvučenih $i$ brojeva u tom izvlačenju.

## Opis ulaza

U prvoj liniji standardnog ulaza se nalaze brojevi $N, K$ i $M$, koji redom označavaju broj listića koje je Miroslav popunio, broj razlitih brojeva koje je potrebno obeležiti na listiću i najveći broj koji je moguće obeležiti. Sledećih $N$ redova opisije listiće koje je popunio Miroslav, gde se u $i$-tom redu nalazi $K$ brojeva koji označavaju izabrane brojeve na $i$-tom listiću. Nakon toga se nalazi jedan red sa brojem $Q$ koji predstavlja broj izvlačenja. U narednih $Q$ redova se nalazi opis svih izvlačenja. U $i$-tom redu se nalazi $K$ brojeva koji predstavljaju brojeve u redosledu u kojem su bili izvlačeni.

## Opis izlaza

Na standarni izlaz je potrebno ispisati $Q$ redova, gde $i$-ti red odgovara rešenju za $i$-to izvlačenje, tj. $j$-ti broj u $i$-tom redu predstavlja broj listića koji sadrže svaki od izvučenih $j$ brojeva u $i$-tom izvlačenju.

## Primer 1

### Ulaz

```
3 3 15
2 1 3
1 10 4
4 11 1
2
1 4 11 
4 3 11
```

### Izlaz

```
3 2 1
2 0 0
```

## Primer 2

### Ulaz

```
2 7 39
7 6 5 4 3 2 1
1 2 3 4 5 6 8
2
4 3 5 1 2 6 7
6 5 4 3 2 8 39
```

### Izlaz

```
2 2 2 2 2 2 1
2 2 2 2 2 1 0
```

## Objašnjenje primera

U prvom test primeru kod prvog izvlačenja rešenje je "3 2 1" zato što broj 1 Miroslav ima na sva 3 listića. Nakon drugog izvučenog broja imamo kombinaciju "1 4" koja se pojavljuje na 2 listića. Na kraju trećeg izvlačenja imamo kombinaciju brojeva "1 4 11" i jedini listić koji ima sva 3 broja iz kombinacije jeste treći listić te je odgovor 1. U drugom izvlačenju prvog test primera, broj 4 sadrže listići 2 i 3. Dok ne postoje listići koji sadrže sve brojeve iz kombinacija "4 3" i "4 3 13".

## Ograničenja

- $1 \leq N \leq 10000$
- $1 \leq K \leq 8$
- $K \leq M \leq 500$
- $1 \leq Q \leq 20000$

Test primeri su podeljeni u četiri disjunktne grupe:

- U test primerima koji vrede 15 poena važi $Q \leq 10$.
- U test primerima koji vrede 15 poena važi $K = 3, M < 100$.
- U test primerima koji vrede 30 poena važi $K \leq 5, M < 100$.
- U test primerima koji vrede 40 poena nema dodatnih ograničenja.
