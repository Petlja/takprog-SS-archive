---
timelimit: 1
memlimit: 64
---
Članovi Komisije su u periodima dokolice došli na zanimljivu ideju da na zgradama jednog mesta naprave vidikovce. Zgrade su poređane na nekoj zamišljenoj liniji. Na svakoj od njih mogu biti postavljena najviše dva uređaja za posmatranje od kojih je jedan usmeren prema početku tog niza zgrada (na levu stranu), a drugi prema kraju niza zgrada (na desnu stranu). Međutim, postavljanje uređaja koji je okrenut prema početku se može izvesti samo ako između zgrade na koji se uređaj postavlja i početka niza ne postoji zgrada veće visine. Slično postavljanje uređaja koji je okrenut prema kraju se može izvesti samo ako između te zgrade i kraja niza ne postoji zgrada veće visine. Dozvoljeno je srušiti neke zgrade, ako se time dobija mogućnost postavljanja uređaja za posmatranje na nekim zgradama. Za svaku zgradu je poznata cena rušenja. Postavljanje svakog uređaja donosi određenu zaradu i za svaku zgradu su poznate zarada ako je postavljen uređaj koji je okrenut na levo i zarada od uređaja koji je okrenut na desno. Ukupna zarada od postavljenih uređaja je jednaka razlici zbira zarada od postavljenih uređaja i troškova rušenja zgrada koje treba srušiti. Zbog zauzetosti nekim drugim aktivnostima, oni ne mogu da odvoje vreme i da odrede koje zgrade treba srušiti i gde postaviti uređaje tako da zarada bude što veća. Pomozite im da izračunaju najveću moguću zaradu koja se može dostići postavljanjem uređaja (uz neophodna rušenja).

## Opis ulaza

U prvom redu se nalazi jedan prirodan broj: $n$ - broj zgrada. U narednih $n$ redova se nalazi po $4$ broja i oni predstavljaju podatke za odgovarajuću zgradu: visina zgrade, cena rušenja zgrade, zarada ako na njoj postoji uređaj okrenut ulevo (pri čemu levo nema niti jedna zgrada veće visine, tj. sve zgrade koje su bile veće visine su srušene) i zarada ako je na zgradi postavljen uređaj koji je okrenut udesno (pri čemu su zgrade veće visine desno od te zgrade srušene). Visine zgrada su različiti brojevi, tj. ne postoje dve zgrade iste visine.

## Opis izlaza

U prvom redu izlaza ispisati maksimalnu moguću zaradu koja predstavlja razliku zbira svih zarada od uređaja raspoređenih na zgradama i zbira troškova rušenja zgrada koje su morale da budu srušene.

## Primer 1

### Ulaz

```
10
1041 18 23 27
1169 29 16 29
1962 14 23 23
1281 27 29 28
1995 21 29 26
1391 14 22 13
1815 19 26 29
1718 18 20 13
1771 25 29 18
1837 15 14 26
```

### Izlaz

```
149
```

## Objašnjenje primera

Ako se rasporede uređaji na zgradama 1, 2, 3 i 5 (zgrade su numerisane brojevima od 1 do $n$, sleva nadesno) tako da su okrenuti levo, zbir zarada će biti $23+16+23+29 = 91$. Ako se na zgradama 5, 7, 9 rasporede uređaji tako da gledaju desno, mora se srušiti zgrada broj 10. Zbir zarada od postavljenih uređaja je $26+29+18 = 73$. Rušenje zgrade 10 košta 15. Tako je ukupna zarada $91 + 73 - 15 = 149$.

## Primer 2

### Ulaz

```
8
1771 25 14 13
1270 21 24 16
1018 19 23 24
1729 26 25 16
1817 18 26 22
1861 26 13 18
1541 19 20 23
1645 25 14 17
```

### Izlaz

```
98
```

## Ograničenja i podzadaci

- Ukupan broj zgrada nije veći od $100.000$ ($n\leq 100.000$).
- Visine zgrada su celi brojevi između $1$ i $1.000.000.000$.
- Cene rušenja zgrada su celi brojevi između $0$ i $2.000.000$.
- Zarade od uređaja su celi brojevi između $1$ i $20.000$.

Postoje $4$ podzadatka u kojima dodatno važi:

- Podzadatak 1 \[$16$ poena\]: $n \leq 1000$.
- Podzadatak 2 \[$12$ poena\]: cene rušenja zgrada su između $1.000.000$ i $2.000.000$, a zarade od postavljanja uređaja za posmatranje između $5$ i $10$.
- Podzadatak 3 \[$25$ poena\]: cene rušenja zgrada su jednake nuli (za svaku od zgrada).
- Podzadatak 4 \[$47$ poena\]: nema dodatnih ograničenja.
