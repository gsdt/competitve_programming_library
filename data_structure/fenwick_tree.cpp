#include <bits/stdc++.h>
using namespace std;

template <class T>
class FenwickTree {
    private:
        size_t _size;
        vector<T>* _tree, *_data;
    public:
        FenwickTree(const size_t numberOfElement) {
            _size = numberOfElement;
            _tree = new vector<T>(_size + 2);
            _data = new vector<T>(_size + 1);
        }

        size_t size() {
            return _size;
        }

        void add(const size_t pos, const T value) {
            if(pos > _size) {
                throw std::out_of_range("index out of range.");
            }
            size_t index = pos + 1;
            while(index <= _size + 1) {
                _tree->at(index) += value;
                index += index & (-index);
            }
            _data->at(pos) += value;
        }

        T sumToPosition(const size_t pos) const {
            if(pos > _size) {
                throw std::out_of_range("index out of range.");
            }
            size_t index = pos + 1;
            T sum = 0;
            while(index >= 1) {
                sum += _tree->at(index);
                index -= index & (-index);
            }
            return sum;
        }

        T sumOfRange(const size_t start_pos, const size_t end_pos) const {
            if(start_pos > _size || end_pos > _size) {
                throw std::out_of_range("index out of range.");
            }
            if(start_pos > end_pos) {
                throw std::invalid_argument("start position must not be greater than end position.");
            }
            if(start_pos == 0) return sumToPosition(end_pos);
            return sumToPosition(end_pos) - sumToPosition(start_pos-1);
        }

        void set(const size_t pos, const T newValue) {
            if(pos > _size) {
                throw std::range_error("index out of range.");
            }
            T delta = newValue - _data->at(pos);
            add(pos, delta);
        }

        T operator[] (const size_t pos) const {
            if(pos > _size) {
                throw std::out_of_range("index out of range.");
            }
            return _data->at(pos);
        }

        void clear() {
            free(_tree);
            free(_data);
            _size = 0;
        }
        
        void debug() {
            cout << "info: Size: " << _data->size() << endl;
            cout << "data: ";
            for(int i=0; i<_data->size(); i++) cout << _data->at(i) << " ";
            cout << endl << "tree: ";
            for(int i=0; i<_tree->size(); i++) cout << _tree->at(i) << " ";
            cout << endl;
        }
};

int main() {
    FenwickTree<int> t(10);
    for(int i=1; i<=10; i++) {
        cout << "I ->" << i << endl;
        t.set(i, i);
        t.debug();
        cout << endl;
    }

    cout << t.sumToPosition(10) << endl;;
    
    t.set(10,-1);

    cout << t.sumToPosition(10) << endl;

    cout << t[10] << endl;

    cout << t.sumOfRange(1, 5) << endl;

    t.clear();

    cout << t.size() << endl;

    cout << t[4] << endl;
    
    return 0;
}