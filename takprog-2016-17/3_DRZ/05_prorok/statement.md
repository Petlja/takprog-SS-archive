---
timelimit: 0.3
memlimit: 64
---
Nakon što je proveo ceo dan gledajući naučnofantastične filmove, Petar je odlučio da iskoristi ideje i znanje koje je iz njih pokupio i napravi mehaničkog proroka, odnosno mašinu koja odgovara na bilo kakvo da-ne pitanje koje joj se postavi.

Nakon što je napravio proroka, Petar mu je postavio $N$ pitanja i beležio odgovore koje je dobio. Da ne bi trošio previše papira, svako pitanje je skraćeno obeležio identifikacionim brojem (tako da istim brojevima odgovara isto pitanje -- Petar je neka pitanja postavio više puta). Primetio je da su odgovori koje je dobio kontradiktorni, tj. da je na neka pitanja dobio i odgovor "da" i odgovor "ne".

Petar pretpostavlja da je problem u neispravnoj prostor-vremenskoj ferfucni, zbog koje prorok na svako $K$-to postavljeno pitanje odgovara suprotno od tačnog odgovora (gde $2 \leq K \leq N$). Da bi mogao da počne popravke odmah, umesto da čeka da sazna prave odgovore, zamolio vas je da nađete najmanje $K$ koje odgovara ovoj pretpostavci i dobijenim odgovorima.

## Opis ulaza

U prvom redu standardnog ulaza nalazi se jedan prirodan broj $N$ -- broj pitanja koja je Petar postavio. U narednih $N$ redova nalaze se identifikacioni broj $i$-tog pitanja $Q_i$ i odgovor koji je prorok dao $A_i$. Sve vrednosti $A_i$ će biti ili "da" ili "ne".

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati $K$ -- najmanju vrednost "perioda" sa kojim je moguće da prorok greši. Ukoliko takvo $K$ ne postoji, ispisati -1.

## Primer 1

### Ulaz

```
5

1 da

2 ne

1 ne

3 da

2 ne
```

### Izlaz

```
3
```

## Primer 2

### Ulaz

```
3

1 da

1 ne

1 ne
```

### Izlaz

```
-1
```

## Objašnjenje primera

U prvom primeru, ako su odgovori na pitanja sa identifikacionim brojevima $1, 2, 3$ redom "da", "ne" i "da", odgovori proroka su konzistentni ako je na treće postavljeno pitanje dao suprotan odgovor (tj. $K = 3$). Za $K = 2$ se ne slažu odgovori na prvo i treće pitanje (prorok na njih ne bi odgovorio suprotno), kao ni odgovori na drugo i peto (prorok bi na drugo pitanje odgovorio suprotno a ne peto ne bi).

## Ograničenja i podzadaci

- $1 \leq Q_i \leq 10^9$

Postoje $3$ podzadataka, u kojima dodatno važi:

- Podzadatak 1 \[20 poena\]: $1 \leq N \leq 2000$.
- Podzadatak 2 \[35 poena\]: $1 \leq N \leq 100000$, i za sve $i$ važi $Q_i \leq 200$.
- Podzadatak 3 \[45 poena\]: $1 \leq N \leq 100000$.
