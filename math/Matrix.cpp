#include <bits/stdc++.h>
using namespace std;

template <class T>
class Matrix {
    private:
        static const int MAX_MN = 109;
        T __cell[MAX_MN][MAX_MN];

        inline void init(size_t rows, size_t cols) {
            this->rows = rows;
            this->columns = cols;
            for(size_t i=1; i<=rows; i++) {
                for(size_t j=1; j<=rows; j++) {
                    __cell[i][j] = 0;
                }
            }
        }

    public:
        size_t rows;
        size_t columns;
        
        inline Matrix(size_t rows, size_t cols) {
            init(rows, cols);
        }

        inline Matrix(const Matrix &matrix) {
            this->rows = matrix.rows;
            this->columns = matrix.columns;
            for(size_t i=1; i<=this->rows; i++) {
                for(size_t j=1; j<=this->columns; j++) {
                    __cell[i][j] = matrix(i,j);
                }
            }
        }

        inline  T& operator()(size_t row, size_t col)
        {
            return __cell[row][col];
        }
        
        inline const T& operator()(size_t row, size_t col) const
        {
            return __cell[row][col];
        }

        Matrix & operator = (Matrix const & rhs)
        {
            if ( this == &rhs )
            return *this;

            
            rows    = rhs.rows;
            columns    = rhs.columns;
            
            for(size_t i=1; i<=this->rows; i++) {
                for(size_t j=1; j<=this->columns; j++) {
                    this->__cell[i][j] = rhs(i,j);
                }
            }

            return *this;
        }

        inline const Matrix getCopy() {
            Matrix result(this->rows, this->columns);
            for(size_t i=1; i<=this->rows; i++) {
                for(size_t j=1; j<=this->columns; j++) {
                    result(i,j) = this->__cell[i][j];
                }
            }
            return result;
        }

        inline static Matrix getIdentity(size_t size) {
            Matrix I(size, size);
            for(size_t i=1; i<=size; i++) {
                I(i,i) = 1;
            }
            return I;
        }

        inline const Matrix operator+(const Matrix rhs){
            Matrix sum(this->rows, this->columns);
            for(size_t i=1; i<=this->rows; i++) {
                for(size_t j=1; j<=this->columns; j++) {
                    sum(i,j) = this->__cell[i][j] + rhs(i,j);
					if(sum(i,j) >= MOD) {
						sum(i,j) %= MOD;
					}
                }
            }
            return sum;
        }

        inline const Matrix operator-(const Matrix rhs){
            Matrix sum(this->rows, this->columns);
            for(size_t i=1; i<=this->rows; i++) {
                for(size_t j=1; j<=this->columns; j++) {
                    sum(i,j) = this->__cell[i][j] - rhs(i,j);
					if(sum(i,j) < 0) {
						sum(i,j) += MOD;
					}
                }
            }
            return sum;
        }

        inline const Matrix operator*(const Matrix rhs){
            Matrix sum(this->rows, rhs.columns);
            for (size_t i = 1; i <= this->rows; i++) {
                for (size_t j = 1; j <= this->columns; j++) { 
                    for (size_t k = 1; k <= rhs.columns; k++) {
                        sum(i,j) += 1LL*this->__cell[i][k] * rhs(k,j) % MOD;
                        if(sum(i,j) > MOD) {
                            sum(i,j) -= MOD;
                        }
                    }
                }
            }
            return sum;
        }

        // pow function
        inline const Matrix operator^(int64_t power){
            assert(this->rows == this->columns);
            Matrix<T> result = Matrix::getIdentity(this->rows);
            Matrix<T> a = this->getCopy();
            while(power) {
                if(power % 2) {
                    result = result*a;
                    power --;
                }
                else {
                    a = a*a;
                    power/=2;
                }
            }
            return result;
        }

        inline void show() {
            for(size_t i=1; i<=this->rows; i++) {
                for(size_t j=1; j<=this->columns; j++) {
                    cout << this->__cell[i][j] << " ";
                }
                cout <<endl;
            }
        }

};

int main() {
    // this code passed codechef: https://www.codechef.com/submit/complete/23591451
    // more application: https://www.hackerearth.com/practice/notes/matrix-exponentiation-1/

}