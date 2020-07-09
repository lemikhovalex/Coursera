#include <iostream>
#include <fstream>
#include <stdexcept>
#include <vector>
// Реализуйте здесь
// * класс Matrix
using namespace std;
class Matrix {
public:
    Matrix(){
        n = 0;
        m = 0;
    }

    Matrix(int num_rows, int num_columns) {
        Reset(num_rows, num_columns);
    }

    void Reset(int num_rows, int num_columns) {
        if (num_rows < 0) {
            throw out_of_range("num_rows must be >= 0");
        }
        if (num_columns < 0) {
            throw out_of_range("num_columns must be >= 0");
        }
        if (num_rows == 0 || num_columns == 0) {
            num_rows = num_columns = 0;
        }

        n = num_rows;
        m = num_columns;
        matix.assign(num_rows, vector<int>(num_columns, 0));
    }

    int At(const int row, const int col) const{
        return matix.at(row).at(col);
    }

    int& At(int row, int col){
        return matix.at(row).at(col);
    }

    int GetNumRows() const {
        return n;
    }

    int GetNumColumns() const {
        return m;
    }

private:
    int n, m;
    vector<vector<int>> matix;

};

// * оператор ввода для класса Matrix из потока istream

istream& operator>>(istream& stream, Matrix& m){
    // 0001-01-01
    //y-m-d
    int num_cols, num_rows;
    stream >> num_rows >> num_cols;

    m = Matrix(num_rows, num_cols);

    for(int i = 0; i < num_rows; i++){
        for(int j = 0; j< num_cols; j++){
            stream >> m.At(i, j);
        }
    }
    return stream;
}
// * оператор вывода класса Matrix в поток ostream
ostream& operator<<(ostream& stream, const Matrix& m){
    stream << m.GetNumRows() << " " << m.GetNumColumns() << endl;
    for(int i = 0; i < m.GetNumRows(); i++){
        for(int j = 0; j< m.GetNumColumns(); j++){
            stream << m.At(i, j) << " ";
        }
        stream << endl;
    }
    return stream;
}
// * оператор проверки на равенство двух объектов класса Matrix
bool operator==(const Matrix& lhs, const Matrix& rhs){
    if (lhs.GetNumRows() == 0 && lhs.GetNumColumns() == 0 && rhs.GetNumColumns() == 0 && rhs.GetNumRows() == 0){
        return true;
    }

    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()){
        return false;
    }

    int rows = lhs.GetNumRows();
    int cols = rhs.GetNumColumns();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            if (lhs.At(i, j) != rhs.At(i, j)){
                return false;
            }
        }
    }
    return true;
}
// * оператор сложения двух объектов класса Matrix
Matrix operator+(const Matrix& lhs, const Matrix& rhs){
    if (lhs.GetNumRows() != rhs.GetNumRows() || lhs.GetNumColumns() != rhs.GetNumColumns()){
        throw invalid_argument("lol sum for matrixes with eq dimensions");
    }
    Matrix out(lhs.GetNumRows(), lhs.GetNumColumns());
    for(int i = 0; i < out.GetNumRows(); i ++){
        for(int j = 0; j < out.GetNumColumns(); j++){
            out.At(i, j) = lhs.At(i, j) + rhs.At(i, j);
        }
    }
    return out;
}

int main() {
  Matrix one;
  Matrix two;

  cin >> one >> two;
  cout << one + two << endl;
  return 0;
}
