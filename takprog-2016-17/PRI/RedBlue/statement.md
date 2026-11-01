---
timelimit: 3
memlimit: 64
---
Given an undirected, unweighted, connected graph, where each edge is colored either blue or red, determine whether a spanning tree with exactly k blue edges exists.

## Opis ulaza

There will be several test cases in the input. Each test case will begin with a line with three integers: n m k Where n (2≤n≤1,000) is the number of nodes in the graph, m (limited by the structure of the graph) is the number of edges in the graph, and k (0≤k\<n) is the number of blue edges desired in the spanning tree. Each of the next m lines will contain three elements, describing the edges: c f t Where c is a character, either capital ‘R’ or capital ‘B’, indicating the color of the edge, and f and t are integers (1≤f,t≤n, t≠f) indicating the nodes that edge goes from and to. The graph is guaranteed to be connected, and there is guaranteed to be at most one edge between any pair of nodes. The input will end with a line with three 0s

## Opis izlaza

For each test case, output single line, containing 1 if it is possible to build a spanning tree with exactly k blue edges, and 0 if it is not possible. Output no extra spaces, and do not separate answers with blank lines.

## Primer 1

### Ulaz

```
3 3 2
B 1 2
B 2 3
R 3 1
2 1 1
R 1 2
0 0 0
```

### Izlaz

```
1
0
```
