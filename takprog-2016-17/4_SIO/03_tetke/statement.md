---
timelimit: 3
memlimit: 192
---
U ključnom momentu, kada je trebalo da se pripreme zadaci za SIO, $N$ članova Komisije je shvatilo da moraju pod hitno da odnesu lek svojim tetkama. Poznato je da se kuća svake tetke nalazi na nekom od polja matrice $A \times B$, kao i da ne postoji polje na kome su dve kuće.

Kako bi ubedili Potpredsednika Komisije da je njihovo odsustvo opravdano, svi članovi su redom javno objavili na kom polju se nalazi kuća njihove tetke, kao i na kojoj je nadmorskoj visini. Potpredsednik nije od juče, i pažljivo beleži sve što čuje. Pored toga, iako ne zna nadmorske visine svih polja u matrici, on zna da je apsolutna razlika nadmorske visine svaka dva susedna polja u matrici **tačno 1** (polja su susedna ako dele stranicu). Imajući to u vidu, on nakon objave svakog člana proba da rekonstruiše celu matricu, tj. da dodeli **svakom** polju neku nadmorsku visinu, kako bi se uverio da su sve objave bile istinite (ova rekonstrukcija ne mora nužno biti jedinstvena).

Ako nakon objave nekog člana, Potpredsenik po prvi put ne može da odredi visinu svakog polja tako da bude u skladu sa svim dosadašnjim objavama (tj. ne postoji matrica konzistentna sa svim dosadašnjim objavama), jasno je da je taj član lupio glupost. Vaš zadatak je da pronađete prvog člana Komisije koji je lupio glupost.

## Opis ulaza

U prvom redu standardnog ulaza nalaze se tri prirodna broja $N$, $A$ i $B$ -- broj članova komisije tj. broj kuća, broj redova matrice i broj kolona matrice. U svakom od narednih $N$ redova nalaze se tri prirodna broja $R_i$, $C_i$ i $H_i$ koji označavaju red, kolonu i nadmorsku visinu kuće u kojoj živi tetka $i$-tog člana Komisije.

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati jedan prirodan broj koji predstavlja indeks člana Komisije koji je lupio glupost (članovi su indeksirani počevši od broja $1$). Ukoliko takav član ne postoji, ispisati "bravo komisijo" (bez navodnika).

## Primer 1

### Ulaz

```
4 3 5
1 2 1
2 1 3
2 5 21
2 2 8
```

### Izlaz

```
3
```

## Primer 2

### Ulaz

```
5 6 5
1 1 5
4 2 3
4 5 6
5 2 2
1 3 5
```

### Izlaz

```
bravo komisijo
```

## Objašnjenje primera

U prvom primeru, nakon prve dve objave moguće je odrediti visinu za svako polje tako da se ispoštuju uslovi, npr:

```
2 1 2 3 4
3 2 3 4 3
4 3 4 5 4
```

Nakon treće objave, ne postoji način da se to uradi, pa je treći član Komisije lupio glupost.

U drugom primeru, postoji raspored visina koji se uklapa sa svih pet objava, npr:

```
5 4 5 6 7 8
4 5 6 7 6 7
3 4 5 6 5 6
4 3 4 5 6 5
3 2 3 4 5 4
```

## Ograničenja i podzadaci

- $1 \leq A, B \leq 10^9$
- $1 \leq N \leq 10^5$
- Za svako $H_i$ važi $1 \leq H_i \leq 10^8$

Postoji $5$ podzadataka, u kojima dodatno važi:

- Podzadatak 1 \[11 poena\]: $B = 1$.
- Podzadatak 2 \[11 poena\]: $N \leq 1000$.
- Podzadatak 3 \[16 poena\]: Za svako $H_i$ važi $1 \leq H_i \leq 10$.
- Podzadatak 4 \[28 poena\]: $A, B \leq 800$.
- Podzadatak 5 \[34 poena\]: Bez dodatnih ograničenja.
