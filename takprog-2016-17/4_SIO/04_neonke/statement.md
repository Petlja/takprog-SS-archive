---
timelimit: 0
memlimit: 0
---
Kao što ste već videli, za uspešno održavanje drugog dana SIO bilo je potrebno otići u Komisijski tajni podrum i precizno aktivirati mašinu koja će zameniti zadatke između dva dana. Pošto ste prethodnog dana uspešno odredili način na koji je ovo potrebno uraditi, članovi Komisije su uspeli da aktiviraju mašinu, i drugi dan SIO može biti održan.

Međutim, ova aktivacija mašine nije bila bez posledica. Naime, Komisijski podrum je izuzetno loše osvetljen, tako da je navigacija bila jako teška, i određeni članovi Komisije su bili povređeni. Kako se uskoro očekuje poseta IZS (Inspekcije za održavanje Zdravlja i Sigurnosti™), Komisija je odlučila da prikladno osvetli podrum neonskim sijalicama (*"neonkama"*).

Podrum je predstavljen kao matrica od $N \times M$ polja. Neonka postavljena na poziciji $(x_n, y_n)$ je u mogućnosti da osvetli polja $(x, y)$ za koja važi $x_n - R \leq x \leq x_n + R$ i $y_n - R \leq y \leq y_n + R$, gde je $R$ jačina svetlosti neonke. Za ovo polje takođe mora važiti da unutar pravougaonika određenog koordinatama $(x, y)$ i $(x_n, y_n)$ **nema ni jednog zida**!

Na primer, ako je $R = 3$, polja označena sa `'S'` bi bila osvetljena neonkom postavljenom na poziciju označenu sa `'N'`:

```
.#...SSS........
.#...SSS#.......
.####SSS#.......
....#SSNSSS.....
....#SSSSSS.....
....#SSS#.......
....#SSS#.......
```

Zbog umanjenja brojnosti Komisije, angažovana je pomoć malog Perice, koji je bio odsutan jureći naučne konferencije tokom celog ovogodišnjeg ciklusa takmičenja. Kako Perica nema vremena da se angažuje, čak ni kada je to najpotrebnije, odlučio je da naplati postavljanje svake neonke sa $C$ dinara, i ručno paljenje svake neonke sa $P$ dinara. Na sreću, nije neophodno ručno upaliti svaku neonku -- ukoliko svetlost od jedne neonke zahvati drugu, ona se onda sama pali. Možete smatrati da će Perica paliti neonke tako da je broj ručnih paljenja minimalan.

Na vama je da odredite na koje pozicije u podrumu treba postaviti neonke, tako da se osvetli što više njegovih polja. Komisija je odvojila ograničen budžet za malog Pericu -- ovaj budžet ne sme da se premaši!

## Napomena

Ovo je zadatak sa poznatim ulazom (*output-only* zadatak). Vama su dati ulazni fajlovi (`case-01.in`, `case-02.in`, `case-03.in`, `case-04.in`), dok vi treba da pošaljete samo odgovarajuće izlazne fajlove za njih (`case-01.out`, `case-02.out`, `case-03.out`, `case-04.out`).

## Opis ulaza

U prvom redu ulaznih fajlova nalaze se tri prirodna broja $N$, $M$ i $R$ - visina i širina plana podruma, i jačina svetlosti svake neonke, redom. U drugom redu nalaze se tri prirodna broja $C$, $P$ i $B$: cena jedne neonke, cena ručnog paljenja jedne neonke, i ukupan budžet dostupan Komisiji, redom. U preostalih $N$ redova nalazi se po $M$ karaktera, koji predstavljaju plan podruma, ${\bf Z}$, jedan po jedan red, redom. Svaki karakter može biti `'.'`, `'#'` ili `'-'`, tako da `'.'` predstavlja slobodno polje, dok preostala dva karaktera predstavljaju zidove.

## Opis izlaza

Vaši izlazni fajlovi treba da sadrže pozicije svih neonki koje Komisija treba da kupi: za svaku neonku, potrebno je u zasebnom redu izlaza priložiti dva cela broja $X_i$ i $Y_i$, koji predstavljaju poziciju $i$-te neonke koju Komisija treba da kupi. Obavezno mora da važi $1 \leq X_i \leq N$, $1 \leq Y_i \leq M$, i ${\bf Z}_{X_i, Y_i} = \text{'.'}$.

## Primer 1

### Ulaz

```
8 22 3
1 100 220
--########--########--
-#########--#########-
-#......######......#-
-#..................#-
-#..................#-
-#..................#-
-####################-
--##################--
```

### Izlaz

```
4 7 
4 10
```

### Objašnjenje primera

Ukoliko postavimo neonke na date dve pozicije, onda će osvetljenost podruma biti sledeća (sa `'N'` obeležavamo pozicije neonki, a sa `'S'` pozicije koje su osvetljene):

```
--########--########--
-#########--#########-
-#.SSSSS######......#-
-#.SSSNSSNSSS.......#-
-#.SSSSSSSSSS.......#-
-#.SSSSSSSSSS.......#-
-####################-
--##################--
```

Dovoljno je ručno upaliti samo jednu od ove dve neonke da bi se obe upalile. Stoga je ukupna utrošena cena za ovo rešenje $2 \times C + 1 \times P = 102$, što je unutar našeg budžeta, tako da je rešenje korektno. Ovo rešenje ukupno osvetljava $35$ polja (i **ne predstavlja** optimalno rešenje!).

## Bodovanje

Vaše rešenje za neki od ulaza će se smatrati nevažećim ukoliko je ispunjen bar jedan od sledećih uslova:

- izlazni fajl sadrži neparan broj celih brojeva;
- izlazni fajl sadrži poziciju koja je izvan ograničenja datog plana;
- izlazni fajl sadrži poziciju na kojoj se nalazi zid;
- izlazni fajl sadrži dve iste pozicije;
- ukupna cena postavljanja i ručnog paljenja neonki premašuje zadati budžet.

U suprotnom, neka je $k$ ukupan broj polja koje vaše rešenje osvetljava. Za svaki ulaz definisane su konstante $A$ i $B$ tako da:

- Ukoliko važi $k \geq B$, osvajate 25 poena za taj ulaz;
- Ukoliko važi $k \leq A$, osvajate 0 poena za taj ulaz;
- Inače, osvajate $\lfloor 25 \times \frac{k - A}{B - A}\rfloor$ poena za taj ulaz.

## Testiranje i eksperimentisanje

Na korišćenje vam je dat program sa kojim možete lakše da testirate svoje rešenje (`neonke.html`).

Otvorite ga u veb pregledaču i izaberite odgovarajuće `case-??.in` i `case-??.out` fajlove: moći ćete da vizuelizujete vaše rešenje za date ulaze, kao i informacije poput količine polja koje ste osvetlili i ukupne cene koju ste potrošili.

Sve neonke koje se upale kao posledica jednog ručnog paljenja će unutar programa biti prikazane istom bojom.
