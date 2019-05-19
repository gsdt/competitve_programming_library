#include <bits/stdc++.h>
using namespace std;

class GaussianElimination {
    private:
        size_t size;
        vector<vector<double> > a;
    public:
        GaussianElimination(vector<vector<double>> inputMatrix) {
            swap(a, inputMatrix);
            size = a.size();
        }

        vector<double> solve() {
            for(int i=size-1; i>0; i--) {
                if(a[i-1][0]<a[i][0]) {
                    for(int j=0; j<=size; j++) {
                        swap(a[i][j], a[i-1][j]);
                    }
                }
            }

            for(int k=0; k<size-1; k++) {
                for(int i=k; i<size-1; i++) {
                    double c = (a[i+1][k] / a[k][k]) ;
                    
                    for(int j=0; j<=size; j++) {
                        a[i+1][j] -= c*a[k][j];
                    }
                }
            }

            vector<double> result(size);
            for(int i=size-1; i>=0; i--)
            {
                double c=0;
                for(int j=i; j<=size-1; j++) {
                    c = c + a[i][j] * result[j];
                }
                result[i]=(a[i][size] - c) / a[i][i];
            }

            return result;
        }
};



int main()
{
    vector<vector<double> > input = {
        {1, 1, -1, 9},
        {0, 1, 3, 3},
        {-1, 0, -2, 2}
    };

    GaussianElimination g(input);
    vector<double> res = g.solve();
    for(double e: res) {
        cout << e << " ";
    }
}
