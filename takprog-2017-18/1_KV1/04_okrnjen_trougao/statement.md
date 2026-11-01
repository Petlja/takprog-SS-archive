---
timelimit: 1
memlimit: 128
---
Dok je prenosio veliki stakleni trougao Cimi je za trenutak izgubio ravnotežu te je treće teme trougla udarilo o pod (primetiti da kako Cimi ima samo dve ruke mogao je u jedinici vremena da drži samo 2 temena velikog staklenog trougla). Od nekada velikog staklenog trougla ostao je jedan stakleni mnogougao koji je Cimiju ostao u rukama dok se ostatak stakla pri kontaktu sa tlom razbio u neupotrebljivo male komadiće. Cimiju je ovaj događaj bio izuzetno zanimljiv i želi da o njemu razgovara sa ostalim radnicima ali razmišlja da malo izmeni priču kako bi umanjio štetu koju je napravio, koja se izražava u površini stakla koja je sada neupotrebljiva. Pomozite Cimiju time što ćete mu za dati prost mnogougao (ne obavezno konveksan) reći kolika je minimalna razlika u površinama između njega i trougla koji ga sadrži a sa njim deli bar 2 temena.

## Opis ulaza

U prvoj liniji standardnog ulaza nalazi se ceo broj $n$ koji predstavlja broj temena mnogougla. U narednih $n$ linija standardnog ulaza nalaze se po dva cela broja $x_i, y_i$ koji predstavljaju koordinate temena mnogougla. (Uzastupna temena kao i prvo i poslednje dele stranicu)

## Opis izlaza

U jedinom redu standardnog izlaza napisati realan broj koji predstavlja minimalnu razliku definisanu u tekstu zadatka. Ukoliko ne postoji ni jedan trougao koji odgovara opisu ispisati $-1$.

## Primer 1

### Ulaz

```
4
2 0
0 2
0 5
5 0
```

### Izlaz

```
2
```

## Primer 2

### Ulaz

```
4
0 0
1 1
2 0
1 7
```

### Izlaz

```
1
```

## Objašnjenje primera

U 1. primeru optimalno je odabrati trougao sa koordinatama temena (0,0), (5,0) i (0,5). U 2. primeru optimalno je odabrati trougao sa koordinatama temena (0,0), (2,0) i (1,7).

## Ograničenja

- $3 \leq n \leq 10^5$.
- $-10^9 \leq x_i, y_i \leq 10^9$.
- U 50% primera važi $n \leq 1000$

## Napomena

Ukoliko ne postoji traženi trougao, vaš program mora ispisati ceo broj -1. U suprotnom, ako je vaš program ispisao broj $a$, a rešenje komisije je realan broj $b$, vaše rešenje se prihvata kao tačno pod uslovom da važi $\frac{|a-b|}{b} \leq 10^{-6}$ ili važi $|a-b| \leq 10^{-6}$.
