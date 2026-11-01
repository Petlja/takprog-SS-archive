---
timelimit: 0.6
memlimit: 64
---
Vučko je preturajući po sobi, iza jednog baštenskog rekvizita koji je dobio od drugara kao rođendanski poklon, pronašao stari špil karata. Na svakoj karti bio je ispisan jedan prirodan broj. On je odmah pozvao Kocu da igraju sledeću igru: Prvo Vučko položi sve karte licem nadole a zatim Koca bira dve karte, čita brojeve sa njih i zatim traži prirodan broj veći od $1$ koji deli oba izvučena broja. Ako se ispostavi da takav broj ne postoji, Vučko pobeđuje. U suprotnom, niko ne pobeđuje (svakako Koca ne pobeđuje). Vučko sprema ispit iz verovatnoće pa želi da kao vežbu izračuna verovatnoću da će pobediti u ovoj igri. Za to mu je potrebna vaša pomoć! Recite Vučku na koliko načina se mogu odabrati dve karte tako da on pobedi.

## Opis ulaza

U prvom redu standardnog ulaza nalazi se jedan prirodan broj $N$, broj karata u špilu. U narednih $N$ redova nalazi se po jedan prirodan broj $A_i$, broj sa $i$-te karte.

## Opis izlaza

Na standardni izlaz ispisati jedan ceo broj -- broj načina da se izvuku dve karte tako da Vučko pobeđuje.

## Primer 1

### Ulaz

```
3

2

3

6
```

### Izlaz

```
1
```

## Primer 2

### Ulaz

```
4

1

6

10

15
```

### Izlaz

```
3
```

## Objašnjenje primera

U prvom primeru, jedini način da Vučko pobedi jeste da Koca izvuče prvu i drugu kartu. U drugom primeru, postoje tri načina -- ako Koca izvuče prvu kartu i bilo koju od preostale tri.

## Ograničenja i podzadaci

- $1 \leq A_i \leq 10^8$

Postoje $4$ podzadataka, u kojima dodatno važi:

- Podzadatak 1 \[9 poena\]: $1 \leq N, A_i \leq 100$.
- Podzadatak 2 \[10 poena\]: $1 \leq N \leq 1000$
- Podzadatak 3 \[30 poena\]: $1 \leq N \leq 7000$.
- Podzadatak 4 \[51 poena\]: $1 \leq N \leq 30000$.
