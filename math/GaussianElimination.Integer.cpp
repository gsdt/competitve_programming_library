#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e6+3;

int norm(int a) {
	while(a >= MOD) a -= MOD;
	while(a < 0) a += MOD;
	return a;
}

int mul(int a, int b) {
	return int(a * 1ll * b % MOD);
}

int pow(int a, int k) {
	int ans = 1;
	while(k > 0) {
		if(k & 1)
			ans = mul(ans, a);
		a = mul(a, a);
		k >>= 1;
	}
	return ans;
}

int inv(int a) {
	return pow(a, MOD - 2);
}

class GaussianElimination {
    private:
        const int MOD = 1e6+3;
        size_t size;
        vector<vector<int> > a;
        
    public:
        GaussianElimination(vector<vector<int>> inputMatrix) {
            swap(a, inputMatrix);
            size = a.size();
        }

        vector<int> solve() {
            for(int j=0; j<size; j++) {
                int nid = -1;
                for(int i=j; i < size; i++) {
                    if(a[i][j] != 0) {
                        nid = i;
                        break;
                    }
                }

                if(nid == -1) {
                    continue;
                }
                
                swap(a[j], a[nid]);
                for(int i=0; i<size; i++) {
                    if(i == j) continue;
                    int cf = mul(a[i][j], inv(a[j][j]));
                    
                    for(int cj=j; cj<=size; cj++) {
                        a[i][cj] = norm(a[i][cj] - mul(cf, a[j][cj]));
                    }
                }
            }
            
            vector<int> result(size, 0);

            for(int i=0; i<size; i++) {
                if(a[i][i] == 0)
                    continue;
                result[i] = mul(a[i][size], inv(a[i][i]));
            }
            return result;
        }
};



int main()
{
    vector<vector<int> > input = {
        {1, 2, 3, 20},
        {4, 1, 0, 11},
        {5, 2, 2, 24}
    };

    GaussianElimination g(input);
    vector<int> res = g.solve();
    for(int e: res) {
        cout << e << " ";
    }
}
