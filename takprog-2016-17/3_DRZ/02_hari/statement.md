---
timelimit: 0.4
memlimit: 64
---
Hogvorts, škola magije i čarobnjaštva, priprema se za uskršnji raspust kada svi učenici idu kući na zasluženi odmor. Kako je magija zabranjena u svetu običnih ljudi, čarobnjaci ne nose svoje čarobne štapove, već ih ostavljaju Hagridu na čuvanje. Čarobni štapovi se čuvaju u posebnim magičnim kutijama. Hagrid je vrlo senilan, pa je zaboravio gde je ostavio magične kutije, te mora da napravi nove.

Da se štapovi ne bi pomešali, pa da nakon raspusta čarobnjaci ne mogu da nađu svoj štap, postoji posebna procedura. Najpre svi čarobnjaci, njih $N$, ostave svoje štapove na dugačkom stolu, a onda ih Hagrid redom pakuje u kutije. Hagrid mora da ih pakuje redom, tj svaka kutija treba sadržati **samo uzastopne štapove**.

Mora se voditi računa i o stabilnosti kutija. U svakoj kutiji mora biti **isti broj štapova**. Takođe, štapovi imaju starost, izraženu u godinama. Ukoliko se u jednoj kutiji nađe više od $K$ čarobnih štapova iste starosti, može doći do velike magične eksplozije.

Hagrida zanima na koliko načina može da upakuje štapove u kutije, a da ispoštuje sva pravila.

## Opis ulaza

U prvom redu standardnog ulaza nalaze se dva prirodna broja, $N$ - broj čarobnjaka i $K$ - najveći dozvoljeni broj štapova iste starosti koji se mogu naći u jednoj kutiji. U sledećem redu nalazi se N celih brojeva, $A_1, A_2, ..., A_N$ koji predstavljaju starosti štapova.

## Opis izlaza

Na standardni izlaz potrebno je ispisati jedan broj, koji predstavlja broj načina na koji Hagrid može podeliti štapove u kutije.

## Primer 1

### Ulaz

```
6 1

1 5 3 3 7 4
```

### Izlaz

```
2
```

## Primer 2

### Ulaz

```
12 2

1 2 3 4 2 3 4 2 1 2 3 4
```

### Izlaz

```
5
```

## Objašnjenje primera

U prvom primeru K je 1, što znači da svi štapovi u jednoj kutiji moraju imati različitu starost. Moguće je staviti svaki štap u posebnu kutiju, ili prva tri u jednu kutiju, a sledeća tri u drugu. Ako se stavljaju po dva, druga kutija će sadržati štapove starosti 3 i 3, što nije stabilno. U drugom primeru validne su podele na po 1, 2, 3, 4 i 6 štapova po kutiji.

## Ograničenja i podzadaci

- $1 \leq K \leq 200000$
- $1 \leq A_i \leq 10^9$

Postoje 4 podzadatka, u kojima dodatno važi:

- Podzadatak 1 \[16 poena\]: $1 \leq N \leq 100$.
- Podzadatak 2 \[24 poena\]: $1 \leq N \leq 20000$.
- Podzadatak 3 \[29 poena\]: $1 \leq N \leq 200000$ i $1 \leq A_i \leq 10^6$.
- Podzadatak 4 \[31 poena\]: $1 \leq N \leq 200000$.

## Napomena

Dozvoljeno je staviti i sve štapove u jednu kutiju, ukoliko su ispunjni sva pravila.
