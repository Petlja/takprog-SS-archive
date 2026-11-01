---
timelimit: 1
memlimit: 64
---
Mali Milutin mnogo voli da ide u školu, tj. da pešači od kuće do škole. Njegov omiljeni predmet je matematika, omiljeni brojevi - celi brojevi, a omiljene operacije su mu **sabiranje i množenje** jer ostale ne zna.

Jednog dana, na putu do škole, naišao je na tri cela broja $a$, $b$ i $c$, napisana jedan za drugim kredom na trotoaru. Tada mu je sinula strašna ideja: **dopisaće neku od njemu omiljenih operacija između prvog i drugog kao i između drugog i trećeg broja tako da rezultat bude najmanji mogući broj**; zatim će pobeći sa lica mesta. Odredite koji je to najmanji mogući broj uzimajući u obzir da Milutin nije mogao da menja redosled brojeva niti da dopisuje zagrade, ali da zna o prioritetu operacija.

## Opis ulaza

U prvom i jedinom redu standardnog ulaza nalaze se tri cela broja $a$, $b$ i $c$, razdvojena razmacima i u redosledu kojim su napisani na trotoaru.

## Opis izlaza

U prvom i jedinom redu standardnog izlaza ispisati jedan ceo broj - traženi najmanji mogući broj koji može dobiti Milutin.

## Primer 1

### Ulaz

```
1 2 1
```

### Izlaz

```
2
```

## Primer 2

### Ulaz

```
-2 5 -7
```

### Izlaz

```
-37
```

## Objašnjenje primera

U prvom primeru najmanji broj dobijamo dopisivanjem dve operacije množenja: $1 \cdot 2 \cdot 1 = 2$, dok je za drugi primer potrebno prvo dopisati sabiranje pa množenje : $(-2) + 5 \cdot (-7) = -37$.

## Ograničenja

Test primeri su podeljeni u dve disjunktne grupe:

- U test primerima koji vrede $40$ poena važiće $1 < a, b, c < 100$.
- U test primerima koji vrede $60$ poena važiće $-1000 < a, b, c < 1000$.
