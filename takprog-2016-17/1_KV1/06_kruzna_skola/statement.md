---
timelimit: 1
memlimit: 256
---
Škola se sastoji od $n$ učionica raspoređenih u krug. U nekim učionicama nalaze se profesori koji drže čas, tako da je u svakoj učionici ili jedan ili nijedan profesor. Profesori su poznati po tome da ih mrzi da mnogo hodaju i da umeju da hodaju samo u smeru kazaljke na satu. Nakon što zvono označi kraj časa, svaki profesor pogleda da li se u sledećoj učionici (u smeru kazaljke na satu) nalazi profesor koji je upravo završio čas. Ako se ne nalazi, on će sledeći čas održati u toj sledećoj učionici, dok ako je nekog bilo tamo on odlučuje da ostane u istoj učionici u kojoj je malopre održao čas, i ponovi čas istim đacima (jadni oni).

Na slici je dat primer kako se menja raspored profesora pri prelasku iz jednog školskog časa u naredni. Crna polja označavaju učionice sa profesorom, bela polja su učionice bez profesora.

![](img_kruzna_skola.png)

Ako je poznat raspored profesora po učionicama na prvom času, odrediti raspored na $k$-tom času.

## Opis ulaza

U prvoj liniji ulaza nalaze se prirodni brojevi $n$, broj učionica u školi, i $k$, redni broj časa za koji treba odrediti raspored. U drugoj liniji ulaza nalazi se opis učionica na prvom času dat kao $n$ karaktera. Učionice su navedene u smeru kazaljke na satu, i za svaku učionicu zapisan je karakter $1$ ako se u učionici nalazi profesor, odnosno $0$ ako se ne nalazi.

## Opis izlaza

Neka je $S$ niz od $n$ elemenata koji predstavlja stanja učionica na $k$-tom času. $S[i] = 0$ ako je $i$-ta učionica na času $k$ prazna, odnosno $S[i] = 1$ ako je u njoj profesor.

U jedinu liniju izlaza ispisati opis učionica na $k$-tom času, na sledeći način. Ako je $n \leq 10^5$, ispisati niz $S$ (bez razmaka). Ako je $n > 10^5$, ispisati $10^5$ brojeva, svaki ili $0$ ili $1$, gde $i$-ti broj predstavlja XOR svih brojeva niza $S$ na pozicijama čiji je indeks kongruentan sa $i$ po modulu $10^5$.

Ovakav način ispisivanja se traži da bi se uštedelo vreme potrebno za ispis, i ne menja suštinu zadatka. Ukoliko već imate izračunat niz $S$, možete iskoristiti sledeći C++ kod za ispis.

```
  int M = 100000;
    int l = min(n, M);
    for (int i = 0; i < l; i++) {
        int a = 0;
        for (int j = i; j < n; j += M) {
            a ^= S[j];
        }
        printf("%i", a);
    }
```

U programskom jeziku Pascal, pod pretpostavkom da ste deklarisali ove promenljive,

```
    l, i, j, a : Longint;
    S : array[1..n] of Integer;
```

za ispis možete koristiti sledeći kod.

```
  l := Min(n, M);
    for i := 1 to l do
    begin
        a := 0;
        j := i;
        while (j <= n) do
        begin
            a := a xor S[j];
            j := j + M;
        end;
        Write(a);
    end;
```

## Primer 1

### Ulaz

```
16 2

1011101100110100
```

### Izlaz

```
0111011010101010
```

## Primer 2

### Ulaz

```
10 4

1110010110
```

### Izlaz

```
0101010111
```

## Objašnjenje primera

Prvi test primer je prikazan na slici u zadatku. U drugom test primeru raspored po časovima je:

1.  1110010110
2.  1101001101
3.  1010101011
4.  0101010111

## Ograničenja

Test primeri su podeljeni u četiri disjunktne grupe:

- U test primerima koji vrede 20 poena važiće $1 \leq n \leq 10^5$ i $1 \leq k \leq 10^5$.
- U test primerima koji vrede 12 poena važiće $1 \leq n \leq 10^5$ i $10^5 < k \leq 10^9$.
- U test primerima koji vrede 8 poena važiće $10^5 < n \leq 10^7$, $1 \leq k \leq 10^5$ i broj profesora nije veći od $10^5$.
- U test primerima koji vrede 60 poena važiće $10^5 < n \leq 10^7$, $10^5 < k \leq 10^9$.
