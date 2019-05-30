#include <bits/stdc++.h>
using namespace std;
#ifdef gsdt
const int maxK = 40;
const int maxN =  1*1e3+9;
const int MOD = 1e9+7;
#else
const int maxK = 40;
const int maxN =  2*1e5+9;
const int MOD = 1e9+7  ;
#endif
 
struct TreeNode {
    int sum;
    TreeNode(int s) {
        sum = s;
    }
};
 
class SegmentTree {
    private:
        size_t size;
        vector<TreeNode> tree;
        string input;
 
        void build(int node, int l, int r) {
            if(l == r) {
                // tree[node].sum = input[l-1];
            }
 
            int mid = (l+r)/2;
            build(node << 1, l, mid);
            build(node << 1 | 1, mid+1, r);
            
            // int t = min(tree[node << 1].open, tree[node << 1 | 1].close);
            // tree[node].ans = tree[node<<1].ans + tree[node<<1 | 1].ans + t;
            // tree[node].open = tree[node<<1].open + tree[node<<1 | 1].open - t;
            // tree[node].close = tree[node<<1].close + tree[node<<1 | 1].close - t;
        }
        
        TreeNode inner_query(int node, int l, int r, int L, int R) {
            if(r<L) return TreeNode(0);
            if(l>R) return TreeNode(0);
            if(l<=L && R<=r) return tree[node];
 
            int mid = (L+R)/2;
            TreeNode a = inner_query(node << 1, l , r, L, mid);
            TreeNode b = inner_query(node << 1 | 1, l, r, mid+1, R);
            // int t = min(a.open, b.close);
            // return TreeNode(a.ans + b.ans + t, a.open + b.open - t, a.close + b.close - t);
            return TreeNode(a.sum+b.sum);
        }
 
        void inner_update(int node, int l, int r, int L, int R, int value) {
            if(r<L) return;
            if(l>R) return;
            if(l<=L && R<=r) {
                tree[node].sum += value;
                return ;
            }
 
            int mid = (L+R)/2;
            inner_update(node << 1, l , r, L, mid, value);
            inner_update(node << 1 | 1, l, r, mid+1, R, value);
 
            tree[node].sum = tree[node << 1].sum + tree[node << 1 | 1].sum;
        }
 
    public:
        SegmentTree(size_t size) {
            this->size = size;
            tree.resize(size << 2, TreeNode(0));
        }
        void build(string input) {
            // this->input = input;
            // build(1, 1, size);
        }
 
        int query(int l, int r) {
            TreeNode ans = inner_query(1, l, r, 1, size);
            return ans.sum;
        }
 
        void update(int l, int r, int value) {
            inner_update(1, l, r, 1, size, value);
        }
};
 
struct Question {
    int id;
    int l, r, x;
    Question() {};
    Question(int id, int l ,int r, int x) {
        this->id = id;
        this->l = l;
        this->r = r;
        this->x = x;
    }
    bool operator < (Question obj) {
        return x < obj.x;
    }
};
 
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	#ifdef gsdt
	freopen("input.txt","r", stdin);
	// freopen("output.txt","w", stdout);
	#endif
 
    int n, q; scanf("%d", &n);
    vector<pair<int,int> > ls;
    vector<Question> questions;
    SegmentTree tree(n);
 
    for(int i=1; i<=n; i++) {
        int x; scanf("%d", &x);
        ls.emplace_back(x, i);
    }
    scanf("%d", &q);
    vector<int> answer(q+1);
    for(int i=1; i<=q; i++) {
        int l, r, x; scanf("%d%d%d", &l, &r, &x);
        questions.emplace_back(i, l, r, x);
    }
 
    sort(ls.rbegin(), ls.rend());
    sort(questions.rbegin(), questions.rend());
 
    int id = 0;
    for(auto e: questions) {
        if(id<n) {
            while(ls[id].first > e.x) {
                tree.update(ls[id].second, ls[id].second, 1);
                id ++;
                if(id == n) break;
            }
        }
 
        answer[e.id] = tree.query(e.l, e.r);
    }
 
    for(int i=1; i<=q; i++) {
        printf("%d\n", answer[i]);
    }
 
	return 0;
} 