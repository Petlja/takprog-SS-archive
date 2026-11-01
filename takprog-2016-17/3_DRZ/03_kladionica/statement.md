---
timelimit: 0.7
memlimit: 256
---
Pametni koder Aki je sinoć gledao film *”Ocean's eleven” (Igraj svoju igru)*. Kako mu je film bio dosadan, negde na polovini se uspavao i počeo da sanja o tome kako može prevariti kladionicu kao akteri filma. Sanjao je da ima pristup bazi podataka kladionice i da može namestiti rezultat bilo koje utakmice.

Odlučio je da se kladi na fudbalske mečeve. Postoji $N$ različitih fudbalskih liga, a u svakoj ligi po $M$ utakmica za koje je moguće uložiti opkladu. Za svaku utakmicu koju je odabrao je poznata **kvota** - prirodan broj koji predstavlja koeficijent dobitka koji nosi ta utakmica ukoliko je rezultat pogođen.

Aki će **iz svake lige** izabrati bar jednu utakmicu (moguće i više), i tako sastaviti **tiket**. Za svaku ligu je poznat broj utakmica koje je moguće izabrati iz te lige na istom tiketu - npr. postoji slučaj gde je za neku ligu moguće izabrati tačno 2 ili 4 utakmice, ali nije moguće izabrati 3.

Dobitak tiketa se određuje tako što se **pomnože kvote** svih odabranih utakmica, a zatim se dobijeni proizvod **pomnoži sa bonusom** koji zavisi od broja odigranih utakmica. Bonusi za svaki mogući broj odigranih utakmica su dati od strane kladionice.

Kako Aki u svom snu može namestiti rezultate svih utakmica, i želi da zaradi što više para, on će **sastaviti sve moguće tikete**. Dva tiketa se razlikuju ukoliko bar jedna utakmica postoji na jednom tiketu, a ne postoji na drugom. Na kraju, Aki će zaraditi onoliko para koliko je zbir dobitaka sa svih tiketa.

Izračunajte i ispišite koliko će para Aki zaraditi u svom snu (računajući po modulu $10^9 + 7 = 1000000007$).

## Opis ulaza

U prvom redu se nalaze dva prirodna broja: $N$ - broj liga, i $M$ - broj utakmica u svakoj ligi. U narednih $N$ redova se nalazi po $M$ prirodnih brojeva koji predstavljaju kvote za svaku utakmicu.

U sledećih $N$ redova se nalazi po $M$ brojeva koji predstavljaju matricu $C$. Elementi te matrice mogu imati vrednost nula ili jedan. Ako je $j$-ti broj u $i$-tom od tih redova jednak jedan ($C[i][j]=1$), onda to znači da se iz $i$-te lige može izabrati $j$ utakmica, a ako je jednak nuli, onda se iz $i$-te lige ne može izabrati $j$ utakmica.

U poslednjem redu ulaza ima ukupno $N \times M$ prirodnih brojeva gde $i$-ti broj u nizu predstalja bonus za ukupno odigranih $i$ utakmica.

## Opis izlaza

U prvom redu izlaza ispisati koliko će para Aki zaraditi, računajući po modulu $10^9 + 7 = 1000000007$.

## Primer 1

### Ulaz

```
2 3

2 3 4

5 6 7

1 0 1

0 1 1

10 20 30 40 50 60
```

### Izlaz

```
535290
```

## Objašnjenje primera

Postoje dve lige sa po tri utakmice. Kvote utakmica u prvoj ligi su $2$, $3$ i $4$, dok u drugoj ligi postoje utakmice sa kvotama $5$, $6$ i $7$. Iz prve lige je moguće izabrati tačno jednu ili tačno tri utakmice, dok nije moguće izabrati dve utakmice iz prve lige. Iz druge lige je moguće izabrati dve ili tri utakmice. Neki od mogućih tiketa su:

- Iz prve lige biramo prvu utakmicu (kvota $2$), iz druge lige biramo prvu i drugu utakmicu (kvote $5$ i $6$). Ukupna kvota je $2 \cdot 5 \cdot 6 = 60$. Pošto smo izabrali 3 utakmice, kvota se množi sa bonusom za 3 utakmice ($30$), i tako dobijamo ukupan dobitak za ovaj tiket: $60 \cdot 30 = 2400$
- Iz prve lige biramo sve tri utakmice (kvote $2$, $3$ i $4$), iz druge lige biramo prvu i treću utakmicu (kvote $5$ i $7$). Ukupna kvota je $2 \cdot 3 \cdot 4 \cdot 5 \cdot 7 = 840$. Kako smo izabrali ukupno 5 utakmica, kvota se množi sa bonusom ѕa 5 utakmica ($50$) i tako dobijamo ukupan dobitak: $840 \cdot 50 = 42000$

Kombinovanjem svih mogućih tiketa, a onda sabiranjem njihovih dobitaka, dobijamo ukupnu zaradu od $535290$.

## Ograničenja i podzadaci

- Kvote tiketa i bonusi su prirodni brojevi između 1 i 1000

Postoje $5$ podzadataka, u kojima dodatno važi:

- Podzadatak 1 \[7 poena\]: $N \cdot M \leq 20$.
- Podzadatak 2 \[25 poena\]: $N=1$, i $M \leq 100$.
- Podzadatak 3 \[12 poena\]: $N,M \leq 100$ i **iz svake lige se može igrati tačno jedna utakmica** ($C[i][1]=1$, $C[i][j]=0$ ako je $j>1$).
- Podzadatak 4 \[25 poena\]: $N,M \leq 100$ i **svi bonsi su tačno 1**.
- Podzadatak 5 \[31 poen\]: $N,M \leq 100$.
