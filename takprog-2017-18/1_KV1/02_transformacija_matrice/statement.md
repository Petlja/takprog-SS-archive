---
timelimit: 4
memlimit: 128
---
Nakon duge igre sa brojevima, Mabu i Džo su rešili da promene temu njihove zabave. Sada su na red došle matrice! Mabu je napisao na papiru kvadratnu matricu $A$, dok je Džo napisao kvadratnu matricu $B$. Obe kvadratne matrice su iste dimenzije i ona iznosi $n$ ( svaka matrica ima tačno $n$ vrsta i $n$ kolona ).

Kada su napisali matrice na papiru, Mabu je odjednom poželeo da promeni svoju matricu u onu koju je Džo napisao ( želeo je da transformiše matricu $A$ u matricu $B$ ). Za ovaj poduhvat Mabu sme da koristi sledeće dve operacije proizvoljan broj puta u proizvoljnom redosledu:

$1.$ Promena vrednosti jednog elementa u matrici $A$ - element može da se zameni proizvoljnom vrednošću

$2.$ Rotacija matrice $A$ za $90$ stepeni u desno.

Mabua interesuje minimalan broj operacija koje mora da izvrši na matrici $A$ kako bi dobio matricu $B$.

## Opis ulaza

Prva linija standardnog ulaza sadrži prirodan broj $n$ , dimenziju kvadratnih matrice koje su napisali Mabu i Džo.

Sledećih $n$ linija standarnog ulaza sadrži po $n$ prirodnih brojeva koji predstaljaju matricu $A$.

Poslednjih $n$ linija standarnog ulaza sadrži po $n$ prirodnih brojeva koji predstaljaju matricu $B$.

## Opis izlaza

U jedinoj liniji standardnog izlaza ispisati minimalan broj operacija potrebnih da se matrica $A$ transformiše u matricu $B$.

## Primer $1$

### Ulaz

```
2
1 2
3 8
6 1
8 5
```

### Izlaz

```
3
```

## Primer $2$

### Ulaz

```
1
5
5
```

### Izlaz

```
0
```

## Objašnjenje primera

U prvom primeru matricu $A$ možemo transformisati u matricu $B$ sa najmanje $3$ koraka.

$1.$ Promena vrednosti polja ($2$, $1$) , $A_{2,1} = 6$

$2.$ Rotacija matrice za $90$ stepeni u desno

$3.$ Promena vrednosti polja ($2$, $2$) , $A_{2,2} = 5$

U drugom primeru matrice $A$ i $B$ imaju samo po jedan element i on ima vrednost $5$ u obe matrice. Nije potrebno izvršiti neku operaciju, tako da je rešenje $0$

## Ograničenja

$1 \leq n \leq 1000$

$1 \leq A_{i,j}, B_{i,j} \leq 10^9$

Test primeri su podeljeni u $4$ disjunktne grupe :

U test primerima vrednim $20$ poena važiće ograničenje $n = 2$.

U test primerima vrednim $20$ poena za optimalno rešenje biće potrebne samo operacije prvog tipa.

U test primerima vrednim $30$ poena važiće ograničenje $1 \leq n \leq 50$.

U test primerima vrednim $30$ poena nema dodatnih ograničenja.
