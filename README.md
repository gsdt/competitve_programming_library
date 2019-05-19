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
### [Gaussian Elimitation]
There are two version:
 - [Double data type](https://github.com/gsdt/competitve_programming_library/blob/master/math/GaussianElimination.cpp)
 - [Integer data type](https://github.com/gsdt/competitve_programming_library/blob/master/math/GaussianElimination.Integer.cpp)
Usage:
 - Contructor: input an matrix to solve.
 - `solve()`: Solve equation

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
