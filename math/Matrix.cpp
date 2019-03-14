#include <bits/stdc++.h>
using namespace std;

template <class T>
class Matrix {
    private:
        static const int MAX_MN = 109;
        size_t __rows;
        size_t __cols;
        size_t __MOD = 1e9 + 7;
        T __cell[MAX_MN][MAX_MN];
    public:
        Matrix(size_t rows, size_t cols) {
            this->__rows = rows;
            this->__cols = cols;
            for(size_t i=1; i<=rows; i++) {
                for(size_t j=1; j<=rows; j++) {
                    __cell[i][j] = 0;
                }
            }
        }

        Matrix(const Matrix &matrix) {
            this->__rows = matrix.__rows;
            this->__cols = matrix.__cols;
            for(size_t i=1; i<=this->__rows; i++) {
                for(size_t j=1; j<=this->__cols; j++) {
                    __cell[i][j] = matrix(i,j);
                }
            }
        }

        T& operator()(size_t row, size_t col)
        {
            return __cell[row][col];
        }
        
        const T& operator()(size_t row, size_t col) const
        {
            return __cell[row][col];
        }

        static Matrix Identity(size_t size) {
            Matrix I(size, size);
            for(size_t i=1; i<=size; i++) {
                I(i,i) = 1;
            }
            return I;
        }

        const Matrix operator+(Matrix rhs){
            Matrix sum(this->__rows, this->__cols);
            for(size_t i=1; i<=this->__rows; i++) {
                for(size_t j=1; j<=this->__cols; j++) {
                    sum(i,j) = this->__cell[i][j] + rhs(i,j);
                }
            }
            return sum;
        }

        const Matrix operator-(Matrix rhs){
            Matrix sum(this->__rows, this->__cols);
            for(size_t i=1; i<=this->__rows; i++) {
                for(size_t j=1; j<=this->__cols; j++) {
                    sum(i,j) = this->__cell[i][j] - rhs(i,j);
                }
            }
            return sum;
        }

        const Matrix operator*(Matrix rhs){
            Matrix sum(this->__rows, rhs.__cols);
            for (size_t i = 1; i <= this->__rows; i++) {
                for (size_t k = 1; k <= this->__cols; k++) { 
                    for (size_t j = 1; j <= rhs.__cols; j++) {
                        sum(i,j) += this->__cell[i][k] * rhs(k,j);
                        if(sum(i,j) >= (T)this->__MOD) {
                            sum(i,j) %= this->__MOD;
                        }
                    }
                }
            }
            return sum;
        }

        // pow function
        const Matrix operator^(int power){
            assert(this->__rows == this->__cols);
            if (power == 0)
                return Matrix::Identity(this->__rows);
            if (power % 2)
            {
                Matrix m = (*this)^(power - 1);
                return (*this)*m;
            }

            Matrix half = (*this)^(power / 2);
            return half*half;
        }

        Matrix& operator=(const Matrix& rhs)
        {
            Matrix temp(rhs); // Copy-constructor -- RAII
            swap(*this, *temp);
            return *this;
        }

        void show() {
            for(size_t i=1; i<=this->__rows; i++) {
                for(size_t j=1; j<=this->__cols; j++) {
                    cout << __cell[i][j] << " ";
                }
                cout <<endl;
            }
        }

};

int main() {
    freopen("input.txt","r", stdin);
    size_t r, c; cin>>r>>c;
    Matrix<int> A(r,c);
    for(size_t i=1; i<=r; i++) {
        for(size_t j=1; j<=c; j++) {
            cin >> A(i,j);
        }
    }

    cin>>r>>c;
    Matrix<int> B(r,c);
    for(size_t i=1; i<=r; i++) {
        for(size_t j=1; j<=c; j++) {
            cin >> B(i,j);
        }
    }

    Matrix<int> C = A^3;
    C.show();

    return 0;
}