---
timelimit: 0.3
memlimit: 256
---
Nakon uspešne ekspedicije, na Marsu je izgrađen ,,Bibop'', prvi veliki kosmodrom u Sunčevom sistemu. Sa njega svakog dana poleće $N$ raketa, i za svaku raketu se zna njeno planirano vreme poletanja $T_i$ (mereno u marsovskim sekundama proteklim od ponoći).

Kada raketa treba da poleti, u nju se utovaruje teret koji treba da ponese. Pošto radnici na kosmodromu drže sve kutije sa teretom naslagane jednu na drugu, mogu da utovare samo teret iz kutije koja je na vrhu gomile. Srećom, veoma su brzi -- proces utovarivanja ne zahteva nimalo vremena. Ako se desi da kutija koju traže nije na vrhu, lansiranje rakete mora da sačeka dok se ne utovare sve kutije koje su iznad tražene.

Da bi olakšali ovaj proces lansiranja, na kosmodromu postoji uređaj koji može da uzme proizvoljan broj kutija sa vrha gomile i prevrne ih (tako da budu poređane suprotnim redosledom). Pošto je ovaj proces spor i može oštetiti teret, uređaj se može iskoristiti *samo jednom* i to *na početku dana* (pre prvog poletanja).

Radnici ,,Bibopa'' su greškom poređali kutije sa teretom po rednim brojevima raketa umesto po redu letenja (tako da je na vrhu kutija namenjena za raketu $1$, ispod nje za raketu $2$, i tako dalje). Pomozite im da odaberu broj kutija koje će okrenuti ovim uređajem, tako da najduže vreme koje neka od raketa provede čekajući na teret bude što manje.

## Opis ulaza

U prvom redu standardnog ulaza nalazi se jedan prirodan broj $N$ -- broj raketa koje poleću tokom dana. U drugom redu standardnog ulaza nalazi se $N$ prirodnih brojeva, $T_1, T_2, \dots, T_N$, gde je $i$-ti broj vreme poletanja rakete sa rednim brojem $i$.

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati jedan prirodan broj, koji predstavlja minimalno "najduže vreme čekanja", koje se dostiže za optimalan izbor prevrnutih kutija.

## Primer 1

### Ulaz

```
5
6 3 8 2 5
```

### Izlaz

```
5
```

## Primer 2

### Ulaz

```
3
2 2 1
```

### Izlaz

```
0
```

## Objašnjenje primera

U prvom primeru, prva raketa koja treba da poleti je raketa $4$, dve sekunde posle ponoći, ali ne može odmah da poleti jer njen teret nije na vrhu gomile. Sledeća po redu je raketa $2$ (tri sekunde posle ponoći), koja takođe mora da čeka, a zatim raketa $5$, koja isto čeka.

Nakon što poleti raketa $1$ (šest sekundi posle ponoći), koja ne mora da čeka na svoju kutiju, raketa $2$ odmah može da poleti, jer je njen teret sada na vrhu. Ona je, dakle, čekala $6-3=3$ sekunde. Dve sekunde kasnije (osam sekundi posle ponoći) raketa $3$ poleće bez čekanja, a odmah zatim i rakete $4$ i $5$, sa čekanjima od $6$ i $3$ sekunde redom.

Ako radnici okrenu gornje četiri kutije, tako da je redosled vremena poletanja raketa (od vrha gomile do dna) $2,8,3,6,5$, raketa koja poleće tri sekunde posle ponoći će čekati najduže -- pet sekundi. Nijedan izbor ne daje čekanja koja su sva kraća od pet sekundi, tako da je ovo optimalno rešenje.

U drugom primeru, ako se cela gomila prevrne, nijedna raketa ne mora da čeka -- pošto utovarivanje tereta ne oduzima vreme, nijedna raketa koja poleće dve sekunde posle ponoći ne mora da čeka.

## Ograničenja

- $1 \leq T_i \leq 10^9$

Test primeri su podeljeni u tri disjunktne grupe:

- U test primerima koji vrede 20 poena važi $1 \leq N \leq 100$.
- U test primerima koji vrede 30 poena važi $1 \leq N \leq 2000$.
- U test primerima koji vrede 50 poena važi $1 \leq N \leq 200000$.
