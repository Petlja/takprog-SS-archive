---
timelimit: 0.5
memlimit: 256
---
Nakon mnogo godina istraživanja i rada, kao i bezbroj bezuspešnih pokušaja prouzrokovanih nepažljivim programerima koji u kodu koji pokreće svemirski brod greškom ostave komandu `system("PAUSE")`, a neretko i `readln()`, prva ljudska ekspedicija je uspešno sletela na Mars! Čim su sleteli, mala Marina, vođa ekspedicije, je primetila da se ispred njih nalazi nepomična kolona u kojoj stoji $n$ Marsovaca. Na njeno veliko iznenađenje, Marsovci nisu bili zeleni, već metalik roze boje.

Nakon nekoliko dana proteklih u zbunjujućim pokušajima komunikacije, Marina je saznala visine svih Marsovaca ($H_1 \dots H_N$) i konačno je shvatila da oni nepomično stoje jer testiraju inteligenciju novih posetilaca i žele da provere da li će Zemljani uspeti da naću **podniz uzastopnih Marsovaca iz kolone, takav da je razlika najvišeg i najnižeg Marsovca najveća moguća**.

Kako je ovaj problem Marini previše jednostavan, odlučila je da dodatno impresionira nove poznanike tako što će im reći **koliko takvih podnizova postoji**. Pomozite Marini da obori Marsovce s nogu i započne jedno novo prijateljstvo.

## Opis ulaza

U prvoj liniji standardnog ulaza nalazi se jedan prirodan broj $N$ - broj Marsovaca u koloni. U drugoj liniji standardnog ulaza nalazi se $N$ prirodnih brojeva, $H_1 \dots H_N$ - visine Marsovaca (u metrima) redom, od prvog do poslednjeg u koloni.

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati jedan nenegativan ceo broj koji predstavlja broj načina da se odabere podniz uzastopnih Marsovaca takav da je razlika najvišeg i najnižeg među njima najveća moguća.

## Primer 1

### Ulaz

```
5

3 5 2 1 4
```

### Izlaz

```
4
```

## Primer 2

### Ulaz

```
2

21 8
```

### Izlaz

```
1
```

## Objašnjenje primera

U prvom primeru najveća moguća razlika između najvišeg i najnižeg Marsovca u nekom podnizu je 4 metra i može se dobiti na 4 različita načina, i to ako odaberemo neki od narednih podnizova:

- od prvog do četvrtog Marsovca, tj. $[3, 5, 2, 1]$
- od drugog do petog Marsovca, tj. $[5, 2, 1, 4]$
- od prvog do petog Marsovca, tj. $[3, 5, 2, 1, 4]$
- od drugog do četvrtog Marsovca, tj. $[5, 2, 1]$

U drugom primeru najveća moguća razlika je 13 metara i može se dobiti samo ako u podniz uključimo oba Marsovca.

## Ograničenja

- $1 \leq Hi \leq 10^9$.

Test primeri su podeljeni u četiri disjunktne grupe:

- U test primerima koji vrede 15 poena važi $1 \leq N \leq 100$.
- U test primerima koji vrede 20 poena važi $1 \leq N \leq 3000$.
- U test primerima koji vrede 15 poena ne postoje dva Marsovca iste visine i važi $1 \leq N \leq 10^5$.
- U test primerima koji vrede 50 poena važi $1 \leq N \leq 10^5$.

## Napomena

Obratite pažnju da je za rešenje potrebno koristiti $64$-bitni tip podataka.
