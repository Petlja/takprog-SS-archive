---
timelimit: 1
memlimit: 64
---
Sunce ponovo sija, Beograd je ozeleneo i rascvetao se, topli dani su se vratili i kao što se može pretpostaviti članovi komisije iznenada više nemaju vremena za SIO. Međutim, da bi olakšali sebi posao tajno su zaposlili jednog mladog člana da napravi zadatke za njih. Ono što nisu znali jeste da je on skovao podmukli plan sa ciljem da upropasti SIO i preuzme posao komisije. Nazvaćemo našeg zlikovca Nikola.

Nikola je instalirao virus na $N$ računara namenjenih takmičarima. Sasvim slučajno se desilo da je tih $N$ računara povezano pomoću $N-1$ kablova (jedan kabal spaja dva računara) tako da računari formiraju stablo.

Komisija je morala da se ponovo aktivira i sanira novonastali problem. 'Antivirus', koji su napravili u te svrhe, funkcioniše tako što komisija bira dva računara $a$ i $b$, a zatim pokreće svoj program koji sa svakog računara na putu od $a$ do $b$, uključujući i njih, briše virus ako postoji.

Pomozite komisiji da spasi sve zaražene računare i to pomoću minimalnog broja pokretanja antivirusa tako što ćete odrediti taj broj i navesti im parove računara za koje treba da pozovu program.

## Opis ulaza

U prvom redu standardnog ulaza nalazi se jedan prirodni broj $N$ - broj računara zaraženih virusom. U narednih $N-1$ redova nalaze se po dva prirodna broja $a$ i $b$ koja označavaju da su računari $a$ i $b$ povezani.

## Opis izlaza

Opis izlaznih podataka.

## Primer 1

### Ulaz

```
5
1 3
1 4
2 3
3 5
```

### Izlaz

```
2
1 4
2 5
```

## Ograničenja

Postoje $3$ podzadatka u kojima dodatno važi:

- Podzadatak 1 \[20 poena\]: $n \leq 20$.
- Podzadatak 2 \[35 poena\]: $n \leq 5000$.
- Podzadatak 3 \[45 poena\]: $n \leq 200000$.

## Napomena

Može da postoji više načina na koje se mogu povezati računari kako bi se dobilo optimalno rešenje. Potrebno je ispisati samo jedan, proizvoljan način kao rešenje zadatka.
