---
timelimit: 1.5
memlimit: 64
---
Malo je poznato da je za održavanje drugog dana SIO potrebno aktivirati mašinu koju Komisija drži u jednom podrumu, koja će zameniti zadatke za prvi dan sa zadacima za drugi. Ta mašina ima prilično komplikovan sistem za aktivaciju, koji čine traka dužine $L$ polja, od kojih na $N$ postoje prekidači.

Na traci se nalazi $N$ klikera (svi su na različitim poljima), i za aktivaciju je neophodno da se u istom trenutku na svakom prekidaču nalazi po kliker. Članovi Komisije ovo obično postižu tako što odjednom gurnu sve klikere, tako da se kreću levo ili desno (različiti klikeri se mogu kretati u različitim smerovima) konstantnom brzinom od jednog polja u sekundi. Klikeri se mogu sudarati sa krajevima trake ili međusobno, u kom slučaju se odbijaju i nastavljaju istom brzinom u suprotnom smeru (pogledajte objašnjenje primera za primer odbijanja).

Pošto član Komisije koji je trebalo da aktivira mašinu nema vremena da smisli kako će to uraditi, jer gleda utakmicu između Mančester Vilidža i Fejk Madrida, na vama je da odredite kako treba usmeriti klikere. Pošto do drugog dana SIO nema previše vremena, treba da pronađete rešenje koje će aktivirati mašinu u što kraćem vremenu.

## Opis ulaza

U prvom redu standardnog ulaza nalaze se dva cela broja $L$ i $N$ -- broj polja na traci i broj klikera. U drugom redu nalazi se $N$ brojeva $A_1, A_2, \dots, A_n$, koji predstavljaju trenutne pozicije svih klikera. U trećem i poslednjem redu se takođe nalazi $N$ brojeva $B_1,
B_2, \dots, B_n$, koji predstavljaju pozicije prekidača.

Pozicije su indeksirane od 1, tj. prvom polju trake odgovara $A_i = 1$, a poslednjem $A_i = L$.

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati jedan ceo broj $T$ -- najmanje vreme (u sekundama) za koje je moguće dovesti sve klikere na prekidače. Ukoliko je to nemoguće, ispisati -1.

## Primer 1

### Ulaz

```
4 2
2 4
1 4
```

### Izlaz

```
1
```

## Primer 2

### Ulaz

```
8 4
1 3 6 7
1 3 5 8
```

### Izlaz

```
2
```

## Objašnjenje primera

U prvom primeru, ako se prvi kliker kreće levo, a druga desno, posle jedne sekunde će se prva pomeriti jedno polje levo, a druga udariti u kraj trake i vratiti se na svoju početnu poziciju (trebaće joj pola sekunde da dođe do zida i pola sekunde nazad, tako da joj pozicija ostaje ista).

U drugom primeru, pravci u kojima je potrebno da se klikeri kreću da bi se doveli na prekidače za dve sekunde su redom: desno, levo, desno i levo. Prve dve kuglice će se sudariti i vratiti na početne pozicije. Druge dve će se takođe međusobno odbiti.

## Ograničenja

- $1 \leq N, L$
- $1 \leq A_i, B_i \leq L$
- Sve pozicije $A_i$ će biti međusobno različite.
- Sve pozicije $B_i$ će biti međusobno različite.

Postoji $5$ podzadataka, u kojima dodatno važi:

- Podzadatak 1 \[15 poena\]: $N, L \leq 8$.
- Podzadatak 2 \[20 poena\]: $N, L \leq 100$.
- Podzadatak 3 \[20 poena\]: $N, L \leq 3000$.
- Podzadatak 4 \[25 poena\]: $N \leq 1000$, $L \leq 10^9$.
- Podzadatak 5 \[20 poena\]: $N \leq 3000$, $L \leq 10^9$.

## Napomena
