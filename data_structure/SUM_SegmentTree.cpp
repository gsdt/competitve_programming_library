#include <bits/stdc++.h>
using namespace std;

/*
* Complexity: O(logN)
*/
template<class T> 
class SegmenTree {
    private:
        size_t size;
        vector<T> st;
        vector<T> lz;

        void pushdown(int p, int L, int R) {
            if (lz[p]) {
                st[p] += (R - L + 1) * lz[p];
                if (L < R) {
                    lz[p << 1] += lz[p];
                    lz[p << 1 | 1] += lz[p];
                }
                lz[p] = 0;
            }
        }

        void upd(int p, int l, int r, int L, int R, T val) {
            pushdown(p, L, R);
            if (l > R || r < L) return;
            if (l <= L && r >= R) {
                lz[p] = val;
                pushdown(p, L, R);
                return;
            }
            upd(p << 1, l, r, L, L + R >> 1, val);
            upd(p << 1 | 1, l, r, (L + R >> 1) + 1, R, val);
            st[p] = st[p << 1] + st[p << 1 | 1];
        }
        T qry(int p, int l, int r, int L, int R) {
            pushdown(p, L, R);
            if (l > R || r < L) return 0;
            if (l <= L && r >= R) return st[p];
            return qry(p << 1, l, r, L, L + R >> 1) + qry(p << 1 | 1, l, r, (L + R >> 1) + 1, R);
        }
    public:
        SegmenTree(size_t n) {
            size = n;
            st.resize(n << 2 + 10);
            lz.resize(n << 2 + 10);
        }
        T query(int l, int r) {
            return qry(1, l, r, 0, size-1);
        }

        void update(int l, int r, T value) {
            upd(1, l, r, 0, size-1, value);
        }
};

const int maxn = 1e5 + 5;
int n;
int a[maxn];

int sum(int a, int b) {
    return a + b;
}

int main() {
    srand(time(NULL));
    n = 1000;
    

    SegmenTree<int> seg(1000);

    for (int it = 0; it < 1000; it++) {
        int l = rand() % n;
        int r = rand() % n;
        if (l > r) swap(l, r);
        int v = rand() % 1000;
        for (int i = l; i <= r; i++) {
            a[i] += v;
        }
        seg.update(l, r, v);
        l = rand() % n;
        r = rand() % n;
        if (l > r) swap(l, r);
        int ans = 0;
        for (int i = l; i <= r; i++) {
            ans += a[i];
        }
        int d = seg.query(l, r);
        cout << ans << " " << d<<endl;
        assert(ans == d);    
    }
    cout << "Correct!\n";
    return 0;
}