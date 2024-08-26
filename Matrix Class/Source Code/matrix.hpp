#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
#include <stdint.h>



template <typename T> class Matrix{
public:
    Matrix(std::vector<std::vector<T>> matrix);
    Matrix(const uint32_t InputRowCount, const uint32_t InputColumnCount, T Value);

    // ___________________________________________________

    ~Matrix();

    // ___________________________________________________

    void DisplayMatrix(void) const noexcept;
    std::pair<uint32_t, uint32_t> GetDimensions(void);

    double Det(void);
    void Transpose(void);


    // ___________________________________________________

    
    friend bool operator==(Matrix<T> const& A, Matrix<T> const& B){ 
        return (A.matrix == B.matrix);
    }

    friend Matrix<T> operator+( Matrix<T> const& A, Matrix<T> const& B){
    Matrix<T> newMatrix(A.rowCount, A.columnCount, 0);

    for(int i = 0; i < A.rowCount; ++i)
       for(int j = 0; j < A.columnCount; ++j)
           newMatrix.matrix[i][j] += A.matrix[i][j] + B.matrix[i][j];

    return newMatrix;
    }

    friend Matrix<T> operator-(Matrix<T> const& A, Matrix<T> const& B){
        Matrix<T> newMatrix = A + (-1) * B;
        return newMatrix;
    }

    friend Matrix<T> operator*(T constValue, Matrix<T> const& A){
        Matrix<T> newMatrix = A;
        for(int i = 0; i < A.rowCount; ++i)
            for(int j = 0; j < A.columnCount; ++j)
                newMatrix.matrix[i][j] *= constValue;

        return newMatrix;
    }

    friend Matrix<T> operator*(Matrix<T> const& A, Matrix<T> const& B){
        if(A.columnCount != B.rowCount){
            std::cerr << "Error: wrong matrices dimensions \n" ;
            exit(1);
        }
        
        Matrix<T> newMatrix(A.rowCount, B.columnCount, 0);

        for(int i = 0; i < A.rowCount; ++i){
            for(int j = 0; j < B.columnCount; ++j){
                for(int k = 0; k < A.columnCount; ++k)
                    newMatrix.matrix[i][j] +=  A.matrix[i][k] * B.matrix[k][j];
            }
        }

        return newMatrix;
    }


private:
    std::vector<std::vector<T>> matrix;
    uint32_t rowCount;
    uint32_t columnCount;
};



//__________________________________________________________________________________________________________


template <typename T> Matrix<T>::Matrix(std::vector<std::vector<T>> matrix){
    this->matrix = matrix;
    rowCount = matrix.size();
    columnCount = matrix[0].size();
}


template <typename T> Matrix<T>::Matrix(const uint32_t rowCount, const uint32_t columnCount, T value){
    matrix.resize(rowCount);
    for(int i = 0; i < rowCount; ++i){
        matrix[i].resize(columnCount);
        for(int j = 0; j < columnCount; ++j)
            matrix[i][j] = value;
    }

    this->rowCount = rowCount;
    this->columnCount = columnCount;
}



template<typename T> Matrix<T>::~Matrix(){
    matrix.clear();
}



//__________________________________________________________________________________________________________


template <typename T> void Matrix<T>::DisplayMatrix(void) const noexcept{
    for(int i = 0; i < rowCount; ++i){
        for(int j = 0; j < columnCount; ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << '\n';
    }
}


template<typename T> std::pair<uint32_t, uint32_t> Matrix<T>::GetDimensions(void){
    return {rowCount, columnCount};
}


//__________________________________________________________________________________________________________


template <typename T> void Matrix<T>::Transpose(void) {
    std::vector<std::vector<T>> transposedMatrix(columnCount, std::vector<T> (rowCount,0 ) );

    for(int j = 0; j < columnCount; ++j)
        for(int i = 0; i < rowCount; ++i)
            transposedMatrix[j][i] = matrix[i][j];

    matrix = transposedMatrix;
    std::swap(rowCount,columnCount);
}


template<typename T> double Matrix<T>::Det(void){

    if(columnCount != rowCount){
        std::cerr << "Error: Not square matrix \n";
        exit(1);
    }

    const double EPS = 1E-9;
    int n = columnCount;

    std::vector<std::vector<T>> A = matrix;

    double det = 1;

    for(int i = 0; i < n; ++i){
        int k = i;
        for(int j = i + 1; j < n; ++j)
            if(abs(A[j][i]) > abs(A[k][i]))
                k = j;

        if(abs (A[k][i]) < EPS)
            return 0.0;

        swap(A[i], A[k]);
        if(i != k)
            det = -det;
        
        det *= A[i][i];
        for(int j = i + 1; j < n; ++j)
            A[i][j] /= A[i][i];
        
        for(int j = 0; j < n; ++j)
            if(j != i && abs(A[j][i]) > EPS)
                for(int k = i + 1; k < n; ++k)
                    A[j][k] -= A[i][k] * A[j][i];
    }

    return det;
}




#endif