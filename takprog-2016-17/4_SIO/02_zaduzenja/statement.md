---
timelimit: 1.5
memlimit: 64
---
Članovi Komisije su vrlo zauzeti ljudi i uvek se pogodi da najviše obaveza (koje nemaju veze sa SIO-om) imaju neposredno pred SIO. Nažalost, neko mora i da smišlja zadatke i pravi test primere pa se uvek uoči SIO-a organizuje popularna *trka zaduženja*.

U komisiji ima $k$ članova i svi žive u jednom gradu koji ima $n$ raskrsnica numerisanih brojevima od $1$ do $n$ i $m$ **dvosmernih** ulica koje povezuju neke od raskrsnica. Za svakog člana komisije je poznato na kojoj raskrsnici živi i za svaku ulicu je poznata njena dužina u metrima. Svake godine se odabere *kružna staza* -- niz **od nekoliko (bar 3) različitih raskrsnica** $x_1, x_2, \ldots, x_l$ pri čemu **između svake dve uzastopne raskrnice na kružnoj stazi postoji neka ulica** (tj. postoje ulice između raskrsnica $x_1$ i $x_2$, $x_2$ i $x_3$, $\ldots$, $x_l$ i $x_1$). Ulice kružne staze se pokrivaju posebnim materijalom pogodnim za trčanje -- kada neko trči njima, on prelazi $1$ metar za $a$ sekundi dok na ostalim ulicama prelazi $1$ metar za $b$ sekundi (dakle, svi članovi komisije trče istom brzinom). Svaki član komisije mora trčati **od svoje raskrsnice do neke raskrsnice na kružnoj stazi (po izboru) a zatim optrčati tačno jedan krug kružne staze**. Ko prvi završi trku, ide svojim izmišljenim obavezama a ostali moraju da prave test primere.

Ispostavlja se da članovi Komisije zbog svojih obaveza nisu imali vremena da treniraju pa im je mnogo bitnije da pobednik bude odlučen što pre (jer tada ostali mogu prekinuti tu napornu aktivnost) nego da pobede u trci. Zato planiraju da urgiraju kod gradskih vlasti da se ove godine **izabere takva kružna staza za koju važi da je vreme potrebno pobedniku da završi trku -- najmanje moguće**. Pomozite članovima Komisije da odaberu takvu kružnu stazu kako bi stigli da naprave test primere za ovaj zadatak.

## Opis ulaza

U prvom redu standardnog ulaza nalaze se pet prirodnih brojeva $n$, $m$, $k$, $a$ i $b$ koji, redom, predstavljaju podatke iz teksta zadatka. U narednom redu nalazi se $k$ prirodnih brojeva $r_i$ -- redni brojevi raskrsnica na kojima žive članovi komisije. U narednih $m$ redova nalaze se po tri broja $x_i$, $y_i$ i $z_i$ koji označavaju da između raskrsnice broj $x_i$ i raskrsnice broj $y_i$ postoji ulica dužine $z_i$ metara.

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati jedan ceo broj - najmanji vreme (u sekundama) potrebno da pobednik završi trku pri optimalnom izboru kružne staze. **Uvek će postojati bar jedno rešenje.**

## Primer 1

### Ulaz

```
8 12 3 1 2
4 2 7
1 5 1
7 5 6
2 7 1
7 3 11
8 1 7
2 3 20
4 6 2
1 6 2
2 4 10
8 6 8
7 8 15
5 8 5
```

### Izlaz

```
20
```

## Primer 2

### Ulaz

```
3 3 1 10 5
2
1 2 11
2 3 12
3 1 13
```

### Izlaz

```
360
```

## Objašnjenje primera

U prvom primeru imamo ukupno 8 raskrsnica i 3 člana Komisije koji žive na raskrsnicama 4, 2 i 7. Optimalno je odabrati kružnu stazu 5-8-6-1-5. Tada pri optimalnom trčanju, član Komisije koji živi na raskrsnici broj 4 trči do staze ulicom 4-6 dužine 2 a zatim trči stazom (ulicama 6-8, 8-5, 5-1 i 1-6) dok ne obiđe celu stazu, tj. dok se ne vrati na raskrsnicu 6. Ukupno mu je trebalo $2 \cdot b + 8 \cdot a + 5 \cdot a + 1 \cdot a + 2 \cdot a$ = 20 sekundi. Članovi komisije sa raskrsnica 2 i 7 bi, redom, završili trku posle 30 i 28 sekundi; dakle, za ovaj izbor kružne staze, član sa raskrsnice 4 je pobednik i trka se prekida posle 20 sekundi. Ne postoji izbor kružne staze tako da pobednik bude odlučen za manje od 20 sekundi.

## Ograničenja i podzadaci

- $3 \leq n \leq 500$
- $n \leq m \leq n(n-1)/2$
- $1 \leq k \leq n$
- $0 \leq a, b \leq 10^6$
- $1 \leq r_i \leq n$, $r_i \neq r_j$ za $i \neq j$
- $1 \leq x_i, y_i \leq n$, $x_i \neq y_i$, $1 \leq z_i \leq 10^9$
- Između svake dve raskrsnice postoji najviše jedna ulica.
- Moguće je doći od bilo koje raskrsnice do bilo koje druge raskrsnice koristeći date ulice.

Postoji $6$ podzadataka, u kojima dodatno važi:

- Podzadatak 1 \[8 poena\]: $n \leq 10$.
- Podzadatak 2 \[15 poena\]: $n \leq 80$.
- Podzadatak 3 \[18 poena\]: $a = 0$.
- Podzadatak 4 \[20 poena\]: $b = 0$.
- Podzadatak 5 \[16 poena\]: $k = 1$.
- Podzadatak 6 \[23 poena\]: Nema dodatnih ograničenja.
