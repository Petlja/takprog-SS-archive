---
timelimit: 100
memlimit: 256
---
Your university wants to build a new walkway, and they want at least part of it to be covered. There are certain points which must be covered. It doesn’t matter if other points along the walkway are covered or not. The building contractor has an interesting pricing scheme. To cover the walkway from a point at x to a point at y, they will charge c+(x-y)^2, where c is a constant. Note that it is possible for x=y. If so, then the contractor would simply charge c. Given the points along the walkway and the constant c, what is the minimum cost to cover the walkway?

## Opis ulaza

There will be several test cases in the input. Each test case will begin with a line with two integers, n (1≤n≤1,000,000) and c (1≤c≤10^9), where n is the number of points which must be covered, and c is the contractor’s constant. Each of the following n lines will contain a single integer, representing a point along the walkway that must be covered. The points will be in order, from smallest to largest. All of the points will be in the range from 1 to 10^9, inclusive. The input will end with a line with two 0s.

## Opis izlaza

For each test case, output a single integer, representing the minimum cost to cover all of the specified points. Output each integer on its own line, with no spaces, and do not print any blank lines between answers. All possible inputs yield answers which will fit in a signed 64-bit integer.

## Primer 1

### Ulaz

```
10 5000
1
23
45
67
101
124
560
789
990
1019
0 0
```

### Izlaz

```
30726
```
