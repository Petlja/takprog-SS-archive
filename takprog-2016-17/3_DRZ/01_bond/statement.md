---
timelimit: 1
memlimit: 256
---
Pošto je dobio dozvolu za ubijanje, dobro poznati agent Bond, Džejms Bond, se uputio u, nama susednu, Crnu Goru kako bi spasio svet. On je saznao da se ozloglašeni Le Šifr uputio u kazino kako bi učestvovao u turniru sa velikim ulogom u igri Rojal. Kako bi osujetili planove Le Šifra i naterali ga da se preda, MI6 planira da ubaci Bonda u turnir, verujući da baš on može da pobedi. Kao što to obično biva, do finala su stigli baš Bond i Le Šifr.

Rojal je veoma jednostavna igra. Na početku igre se odredi broj $k$. Potom prvi igrač baca šestostranu kockicu (svaka strana kockice ima urezan broj od 1 do 6) $k$ puta i zabeleže se brojevi na kojima kockica stane prilikom svakog bacanja. Označimo dobijene brojeve sa $A = [a_1, a_2, ..., a_k]$. Zatim drugi igrač baca istu kockicu $k$ puta i zabeleži brojeve koje dobije. Označimo dobijene brojeve sa $B = [b_1, b_2, ..., b_k]$. Posle bacanja kockica sledi upoređivanje nizova $A$ i $B$ i to se radi na sledeći način:

- Najpre se brojevi u nizu $A$ sortiraju u neopadajući poredak i tako se dobije novi niz $A' = [a'_1, a'_2, ..., a'_k]$.
- Slično se brojevi u nizu $B$ sortiraju u neopadajući poredak kako bi se dobio novi niz $B' = [b'_1, b'_2, ..., b'_k]$.
- Na kraju se brojevi u nizovima upoređuju jedan po jedan, tj. broj $a'_i$ se upoređuje sa $b'_i$ (gde $1 <= i <= k$). Sa $R_1$ označimo broj puta gde je $a'_i > b'_i$, a sa $R_2$ broj puta gde je $a'_i < b'_i$. Broj poena koje prvi igrač osvoji je baš $R_1$, a $R_2$ predstavlja broj poena drugog igrača.

Npr. pretpostavimo da je $k = 5$ i da prvi igrač prilikom bacanja kockice dobija brojeve $A = [6, 4, 1, 4, 3]$, a drugi igrač dobija brojeve $B = [1, 5, 3, 2, 5]$. Po sortiranju ovih nizova dobijamo nizove $A' = [1, 3, 4, 4, 6]$ i $B' = [1, 2, 3, 5, 5]$. Upoređivanjem brojeva ova dva niza imamo: $1 = 1$, $3 > 2$, $4 > 3$, $4 < 5$ i $6 > 5$, tj. $R_1 = 3$ i $R_2 = 1$.

Bond je saznao da će u finalu da se koristi specijalna kockica za koju može da predvidi na kojim brojevima će da stane za prvih $2 \cdot N$ bacanja, tj. u prvih $2 \cdot N$ bacanja, kockica će da padne na brojeve $X = [x_1, x_2, ..., x_{2 \cdot N}]$ redom. Zna se da će Bond da bude prvi igrač i još ima pravo da odabere broj $k$ koji predstavlja broj bacanja kockice svakog igrača u igri. Međutim, mora da važi da ukupan broj bacanja kockice ne sme biti veći od $2 \cdot N$, tj. $1 <= k <= N$.

Vaš zadatak je da pomognete Bondu da odabere njemu najpovoljnije $k$, tj. takvo $k$ gde će osvojiti najviše poena.

## Opis ulaza

U prvoj liniji standardnog ulaza se nalazi prirodan broj $N$ koji označava maksimalan broj bacanja kockice. U sledećem redu se nalazi $2 \cdot N$ celih brojeva $x_1, x_2, ..., x_{2 \cdot N}$ koji predstavljaju vrednosti na koje će kockica da padne u prvih $2 \cdot N$ bacanja, redom (u prvom bacanju kockica će da padne na broj $x_1$, u drugom na $x_2$, itd.).

## Opis izlaza

Na standarni izlaz je potrebno ispisati jedan ceo broj, $R_1$, koji predstavlja maksimalan broj poena koje Bond može da osvoji.

## Primer 1

### Ulaz

```
4

2 4 6 1 5 3 5 2
```

### Izlaz

```
3
```

## Primer 2

### Ulaz

```
2

1 1 2 2
```

### Izlaz

```
0
```

## Objašnjenje primera

U ovom test primeru, moguće vrednosti za $k$ su 1, 2, 3 i 4.

- Ukoliko je $k = 1$, onda imamo $A = [x_1] = [2], B = [x_2] = [4]$, tj. $A' = [2], B' = [4]$ i ovde imamo da je $R_1 = 0$.
- Ukoliko je $k = 2$, onda imamo $A = [x_1, x_2] = [2, 4], B = [x_3, x_4] = [6, 1]$, tj. $A' = [2, 4], B' = [1, 6]$ i ovde imamo da je $R_1 = 1$.
- Ukoliko je $k = 3$, onda imamo $A = [x_1, x_2, x_3] = [2, 4, 6], B = [x_4, x_5, x_6] = [1, 5, 3]$, tj. $A' = [2, 4, 6], B' = [1, 3, 5]$ i ovde imamo da je $R_1 = 3$.
- Ukoliko je $k = 4$, onda imamo $A = [x_1, x_2, x_3, x_4] = [2, 4, 6, 1], B = [x_5, x_6, x_7, x_8] = [5, 3, 5, 2]$, tj. $A' = [1, 2, 4, 6], B' = [2, 3, 5, 5]$ i ovde imamo da je $R_1 = 1$.

Dakle, najveći broj poena koje Bond može da osvoji je 3.

U drugom test primeru, koje god $k$ Bond da odabere, imaće 0 poena.

## Ograničenja i podzadaci

- $1 \leq x_1, x_2, ..., x_{2 \cdot N} \leq 6$

Postoje 3 podzadatka, u kojima dodatno važi:

- Podzadatak 1 \[21 poen\]: $1 \leq N \leq 100$.
- Podzadatak 2 \[31 poen\]: $1 \leq N \leq 5000$.
- Podzadatak 3 \[48 poen\]: $1 \leq N \leq 1000000$
