#include <bits/stdc++.h>
using namespace std;

// accepted at https://codeforces.com/contest/1167/submission/54340666

class DSU
{
private:
    size_t size;
    vector<int> *rank, *parent, *cnt;

public:
    DSU(size_t size)
    {
        this->size = size;
        rank = new vector<int>(size + 9);
        parent = new vector<int>(size + 9);
		cnt = new vector<int>(size + 9);
        for (int i = 1; i <= size; i++)
        {
            parent->at(i) = i;
			cnt->at(i) = 1;
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
			cnt->at(a) += cnt->at(b);
        }
    }

    bool isSameSet(int a, int b) {
        return findSet(a) == findSet(b);
    }

	size_t getSetSize(int u) {
		u = findSet(u);
		return cnt->at(u);
	}
};



int main() {
	int n, m; cin>>n>>m;
	DSU djs(n);

	for(int i=0; i<m; i++) {
		int N; cin>>N;
		if(N<1) continue;
		int first = -1;
		for(int i=0; i<N; i++) {
			if(i == 0) cin>>first;
			else {
				int x; cin>>x;
				djs.unionSets(first, x);
			}
		}
	}

	for(int i=1; i<=n; i++) {
		cout << djs.getSetSize(i) << " ";
	}

	return 0;
}
