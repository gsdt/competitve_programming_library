#include <vector>
using namespace std;

class DSU
{
private:
    size_t size;
    vector<int> *rank, *parent;

public:
    DSU(size_t size)
    {
        this->size = size;
        rank = new vector<int>(size);
        parent = new vector<int>(size);
        for (int i = 1; i <= size; i++)
        {
            parent->at(i) = i;
        }
    }

    int findSet(int v)
    {
        if (v == parent->at(v))
            return v;
        return parent->at(v) = findSet(parent->at(v));
    }

    void unionSets(int a, int b)
    {
        a = findSet(a);
        b = findSet(b);
        if (a != b)
        {
            if (rank->at(a) < rank->at(b))
                swap(a, b);
            parent->at(b) = a;
            if (rank->at(a) == rank->at(b))
                rank->at(a) ++;
        }
    }

    bool isSameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }
};