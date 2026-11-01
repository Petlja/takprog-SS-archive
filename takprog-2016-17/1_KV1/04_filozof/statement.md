---
timelimit: 0.5
memlimit: 256
---
Mali Stojan od svih predmeta najviše voli filozofiju (zapravo, pre bi se moglo reći da voli raspravljanje i filozofiranje). Nakon što je izgubio pola časa na raspravu sa Stojanom, profesor filozofije mu je postavio sledeći zadatak, u nadi da će ga to okupirati bar na neko vreme:

Stari grčki filozof Mile iz Talesa je u svojoj bašti gajio pravougaonike - svakog dana bi posadio jedan. Pravougaonici su neobične biljke i traju samo $K$ dana, tako da bi Mile svakog dana takođe uklonio pravougaonik koji je posadio pre $K$ dana. Pošto se Mile pridržavao starogrčkih načela baštovanstva, sve pravougaonike je sadio tako da su im stranice paralelne koordinatnim osama.

Da bi ih zaštitio od sunca, Mile je u bašti imao jedan pravougaoni zaklon, koji je svakog dana pomerao tako da u potpunosti prekriva sve pravougaonike. Zbog već pomenutih načela, ovaj zaklon je takođe uvek morao biti paralelan osama i okrenut na istu stranu (nije se smeo rotirati).

Iz Miletovih beležaka, poznate su pozicije i dimenzije svih pravougaonika koje je posadio tokom $N$ dana, koliko se ukupno bavio baštovanstvom. Na Stojanu je sada da pronađe dimenzije najmanjeg zaklona koji bi uvek mogao da ih zaštiti od sunca. Pomozite mu da odredi ovo, da bi se što pre vratio raspravljanju i filozofiranju.

## Opis ulaza

Pošto su test primeri potencijalno veoma veliki, da bi se izbeglo učitavanje celih primera, vaš program treba da generiše primere na sledeći način:

Na prvom i jedinom redu standardnog ulaza nalazi se šest brojeva: $N$, $K$, $M$, $A$, $B$ i $S$. Nizovi $X$, $Y$, $XX$ i $YY$, gde $(X_i, Y_i)$ i $(XX_i, YY_i)$ predstavljaju koordinate donjeg levog, odnosno gornjeg desnog pravougaonika koji je Mile zasadio i-tog dana, se generišu na sledeći način (u pseudokodu dole, nizovi su indeksirani od 1):

```
for i from 1 to N:
    if i == 1
        X[i] = (A * S + B) mod M
    else
        X[i] = (A * YY[i-1] + B) mod M
    Y[i] = (A * X[i] + B) mod M
    XX[i] = (A * Y[i] + B) mod M
    YY[i] = (A * XX[i] + B) mod M

    if X[i] == XX[i]
        XX[i] = XX[i] + 1
    if X[i] > XX[i]:
        swap(X[i], XX[i])

    if Y[i] == YY[i]
        YY[i] = YY[i] + 1
    if Y[i] > YY[i]
        swap(Y[i], YY[i])
```

Na primer, za ulaz

```
2 3 100000007 19997 31 73
```

generisane vrednosti su (svaki red odgovara vrednostima $X_i$, $Y_i$, $XX_i$, $YY_i$ redom):

```
1459812 29119072 95455781 91858558
94042061 29119072 95455781 58962213
```

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati dva cela broja - traženu minimalnu širinu i visinu zaklona.

## Primer 1

### Ulaz

```
4 2 13 2 5 2
```

### Izlaz

```
7 9
```

## Primer 2

### Ulaz

```
7 3 37 5 0 3
```

### Izlaz

```
30 32
```

## Objašnjenje primera

Prvi primer odgovara sledećim vrednostima koordinata pravougaonika (redom $X_i$, $Y_i$, $XX_i$, $YY_i$):

```
9 3 12 10
11 1 12 3
7 1 11 6
4 0 5 2
```

Prvog dana, Mile može da zakloni prvi pravougaonik tako što postavi zaklon tako da mu je donji levi ugao u $(9,3)$. Drugog dana ga pomera na $(9,1)$. Trećeg dana, Mile uklanja prvi pravougaonik, tako da zaklon tada može da stoji na primer u $(7,-2)$. Nakon što ukloni drugi i doda četvrti pravougaonik, pomera zaklon u $(4,0)$.

## Ograničenja

- $1 \leq N, K$
- $1 \leq M \lt 10^9$
- $0 \leq A, B, S \leq 10^9$

Ograničenja za $M$, $A$, $B$ i $S$ garantuju da će se sve koordinate nalaziti u intervalu $[0, 10^9]$. Međurezultati pri generisanju ulaza mogu biti izvan ovog intervala, tako da se preporučuje korišćenje 64-bitnih tipova za njih (long long u C/C++, int64 u Paskalu).

Test primeri su podeljeni u tri disjunktne grupe:

- U test primerima koji vrede 20 poena važi $N, K \leq 1000$
- U test primerima koji vrede 50 poena važi $N, K \leq 10^5$
- U test primerima koji vrede 30 poena važi $N, K \leq 2 * 10^6$
