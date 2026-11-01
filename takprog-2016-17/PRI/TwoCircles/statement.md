---
timelimit: 10
memlimit: 256
---
We will consider a convex polygon with N vertices. We wish to find the maximum radius R such that two circles of radius R can be placed entirely inside the polygon without overlapping.

## Opis ulaza

The first line of input contains the number N (3 ≤ n ≤ 50000). Each of the next N lines contains a pair of integers xi and yi (−10^7 ≤ xi, yi ≤ 10^7) - representing the coordinates of the i-th point, separated by space. Points are given in anti-clockwise order.

## Opis izlaza

You should output a single number R - the desired radius. Output R with absolute or relative error of 10^(−3).

## Primer 1

### Ulaz

```
4
0 0
1 0
1 1
0 1
```

### Izlaz

```
0.293
```
