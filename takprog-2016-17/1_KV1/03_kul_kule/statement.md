---
timelimit: 1
memlimit: 64
---
Kao što je većini đaka poznato, draga profesorka robotike Katarina mnogo voli da se igra lego robotima i kockicama. Ovaj put na čas je donela specijalnog robota i $n$ kula kockica. Na svakoj kuli se nalazi određen broj naslaganih kockica koje predstavljaju visinu te kule, tačnije $i$-ta kula ima visinu $A_i$ (sastavljena je od tačno $A_i$ kockica). Đaci su primetili da ne sadrže sve kule podjednak broj kockica i žele to da promene pomoću profesorkinog specijalnog robota. Naime, ovaj robot može izvršiti sledeću operaciju:

- Robot može da uzme **dve** ili **tri** kockice sa **beskonačne gomile** koja se nalazi pored datih kula (Katarina toliko voli kockice da ih ima u neograničenim količinama) i da te kockice stavi na jednu od $n$ kula. Tako se u jednoj operaciji povećava visina određene kule za $2$ ili $3$ kockice.

Kako su đaci i sama profesroka malo nestrpljivi, molimo vas pomozite im da što pre izračunaju **minimalan broj operacija** potrebnih robotu da izjednači visine svih $n$ kula.

## Opis ulaza

U prvom redu standardnog ulaza nalazi se prirodan broj $n$, broj kula koje je donela profesorka. U drugom redu nalazi se niz $A$ od $n$ prirodnih brojeva razdvojenih razmakom, gde $A_i$ predstavlja visinu $i$-te kule.

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati ceo broj koji predstavlja minimalan broj operacija navedenih u tekstu zadatka potrebnih robotu da izjednači visine svih kula.

## Primer 1

### Ulaz

```
3

7 10 5
```

### Izlaz

```
3
```

## Primer 2

### Ulaz

```
5

1 5 1 5 2
```

### Izlaz

```
5
```

## Objašnjenje primera

U prvom primeru ukupno imamo $3$ kule sa kockicama. Prva kula je visine $7$, druga kula je visine $10$, dok je treća kula visine $5$. Robot može izjednačiti visine kula u $3$ operacije :

1.  Robot dodaje $3$ kockice na prvu kulu. Sada su visine kula { $10$, $10$, $5$}.
2.  Robot dodaje $3$ kockice na treću kulu. Trenutne visine kula su { $10$, $10$, $8$}.
3.  Robot dodaje $2$ kockice na treću kulu. Konačne visine kula su { $10$, $10$, $10$}.

Pokazali smo kako robot može da izjednači visine kula u $3$ operacije, može se pokazati da je nemoguće izjednačiti pomenute kule u manje poteza. Minimalan broj potrebnih operacija je $3$.

## Ograničenja

Test primeri su podeljeni u dve disjunktne gurpe:

- U test primerima koji vrede $40$ poena važiće $1 \leq n \leq 100$ i $1 \leq A_i \leq 1000$.
- U test primerima koji vrede $60$ poena važiće $1 \leq n \leq 10^5$ i $1 \leq A_i \leq 10^9$.
