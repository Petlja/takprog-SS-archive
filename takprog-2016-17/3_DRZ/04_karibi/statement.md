---
timelimit: 1.5
memlimit: 256
---
Nekada davno, bilo je vreme programera koji nisu testirali svoje kodove, vreme Programera sa Kariba. Ovi programeri plovili su morem i sejali strah i nekvalitetne programe duž karipskih ostrva; za sobom su ostavljali uplakane korisnike, nezavršene aplikacije i članove posade koji bi koristili *C* umesto *C++*-a. Svaki brod koji bi im se suprotstavio, dobio bi floating point eksepšn i prestao bi da float...

Popularno mesto za okupljanje Programera sa Kariba bilo je Karipsko ostrvo Tortuga. Zaliv ovog ostrva možemo predstaviti **binarnom matricom dimenzije $n \times m$ čije je svako polje kopno (označeno jedinicom) ili voda (označeno nulom)**. Programerski brodovi dolaze u raznim dužinama i ukoliko je dužina nekog broda $x$, to znači da taj brod zauzima tačno $x$ uzastopnih polja zaliva, bilo vertikalno ili horizontalno (širina broda je tačno jedno polje). Prema tome, **brod dužine $x$ se može parkirati u zaliv ako i samo ako postoji $x$ uzastopnih polja u istoj vrsti ili istoj koloni matrice zaliva pri čemu sva polja predstavljaju vodu i na nijednom od njih se ne nalazi deo nekog drugog broda.** U opštem slučaju, može postojati više načina za parkiranje.

Jednog dana, u zaliv Tortuge stigao je programer Džek Vrabac na svom brodu *Black Perl* **dužine** $a$ i rešio da ga uparkira. Džek zna da posle njega u zaliv stiže programer Barbosa na svom brodu *Blue Pascal* **dužine** $b$, kao i da Barbosa najviše na svetu mrzi tri stvari: programera Džeka, debug mod i nedovoljno mesta za parkiranje broda. **Zato je Džek odlučio da parkira svoj brod tako da posle njegovog parkiranja bude najmanje moguće načina da se u zaliv uparkira Barbosin brod.** Kako je programer Džek poznat po tome što ne zna da programira, zatražio je pomoć od vas i kao nagradu neće vam hakovati računar.

## Opis ulaza

U prvom redu standardnog ulaza nalaze se četiri prirodna broja $n$, $m$, $a$ i $b$, razdvojena razmakom, koja, redom, predstavljaju dimenzije zaliva, dužinu Džekovog broda i dužinu Barbosinog broda. Zatim sledi opis zaliva - u narednih $n$ redova nalazi se po $m$ karaktera (bez razmaka) od kojih je svaki '0' ili '1'.

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati jedan prirodan broj - najmanji mogući broj načina za parkiranje Barbosinog broda nakon parkiranja Džekovog broda.

## Primer 1

### Ulaz

```
5 6 3 3

110111

000001

000001

111101

100010
```

### Izlaz

```
2
```

## Primer 2

### Ulaz

```
2 5 2 5

00000

00000
```

### Izlaz

```
0
```

## Objašnjenje primera

U prvom test primeru su dužine Džekovog i Barbosinog broda po 3. Ukoliko Džek parkira svoj brod tako da zauzima polja (1,3)(2,3)(3,3), Barbosa će imati samo dva načina za parkiranje svog broda - (2,5)(3,5)(4,5) i (5,2)(5,3)(5,4) (vrste su numerisane odozgo nadole a kolone s leva udesno). Džek nikako ne može parkirati svoj brod tako da Barbosa ima manje od dva načina za parkiranje.

## Ograničenja i podzadaci

- $1 \leq a \leq max\{n,m\}$, $2 \leq b \leq max\{n,m\}$
- Zaliv će biti takav da će postojati bar jedan način da Džek uparkira svoj brod.

Postoje $5$ podzadataka, u kojima dodatno važi:

- Podzadatak 1 \[11 poena\]: $1 \leq n, m \leq 80$.
- Podzadatak 2 \[12 poena\]: $n = 1$ i $1 \leq m \leq 2000$.
- Podzadatak 3 \[13 poena\]: $a = 1$ i $1 \leq n, m \leq 2000$.
- Podzadatak 4 \[22 poena\]: $1 \leq n, m \leq 500$.
- Podzadatak 5 \[42 poen\]: $1 \leq n, m \leq 2000$.
