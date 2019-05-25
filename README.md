# competitve_programming_library
Author: Nguyen Anh Tuan (gsdt)
[MIT License](https://github.com/gsdt/competitve_programming_library/blob/master/LICENSE)

## Math
### [Matrix](https://github.com/gsdt/competitve_programming_library/blob/master/math/Matrix.cpp)
- Supported: add, subtract, multiply, power  _(updated: 14/03/2019)_
- Operator () overloaded, ex: M(1,2) = 12  _(updated: 14/03/2019)_
### [Geomatrix](https://github.com/gsdt/competitve_programming_library/blob/master/math/Geometric.cpp)
#### Point
- Get distance to another point
#### Circle
- Create new circle from three points
- Get center and radius
### Gaussian Elimitation
There are two version:
 - [Double data type](https://github.com/gsdt/competitve_programming_library/blob/master/math/GaussianElimination.cpp)
 - [Integer data type](https://github.com/gsdt/competitve_programming_library/blob/master/math/GaussianElimination.Integer.cpp)
 [**Passed Codeforce**](https://codeforces.com/problemset/submission/1155/54401704)

Usage:
 - Contructor: input an matrix to solve.
 - `solve()`: Solve equation

### [FFT - multiplying two polynomials](https://github.com/gsdt/competitve_programming_library/blob/master/math/FFT.cpp)


## Data structure 
### [Fenwick Tree](https://github.com/gsdt/competitve_programming_library/blob/master/data_structure/fenwick_tree.cpp) (updated: 04:14PM 12/05/2019)
- `add(pos, value)`: add some value to position **`pos`**.
- `set(pos, value)`: set a value to position **`pos`**.
- `sumToPosition(pos)`: get sum from first position to **`pos`**.
- `sumOfRage(start_pos, end_pos)`: get sum from **`start_pos`** to **`end_pos`**.
- operator `[]`: for get data, **not for set** data.
- `clear()`: remove all data from tree.
- `size()`: get number of element in tree.
### [Disjoin Set Union](https://github.com/gsdt/competitve_programming_library/blob/master/data_structure/dsu.cpp) (updated: 09:22AM 18/05/2019)
- `unionSets(a, b)`: join two set has element **`a`** and **`b`**.
- `findSet(a)`: find root of set **`a`**.
- `isSameSet(a, b)`: test if set **`a`** and set **`b`** is same.
- `getSetSize(a)`: number of element in set **`a`**.

## Graph
### [Adjacency List Graph](https://github.com/gsdt/competitve_programming_library/blob/master/graph/AdjacencyListGraph.cpp)
- `AdjacencyListGraph(n)`: create graph with n+1 vertex: from 0 to n.
- `addDirectedEdge(startVertex, endVertex, weight = 1)`: add an weighted directed edge.
- `addUndirectedEdge(firstVertex, secondVertex, weight = 1)`: add an weighted undirected edge.
- `showGraph()`: show current graph.
- `shortest(startVertex, endVertext)`: using Dijkstra alogrithm find shortest path between to vertex. Return shorted path and direction. This implementation passed [SPOJ](https://www.spoj.com/problems/SHPATH/)

