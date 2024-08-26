#include <iostream>
#include <vector>
#include "matrix.hpp"

using namespace std;




int main(){
    vector<vector<double>> MatA = {{1,2,3},{4,5,6}};
    Matrix<double> A = MatA;

    vector<vector<double>> MatB = {{7,8},{9,10},{11,12}};
    Matrix<double> B = MatB;

    Matrix<double>D ({{1,2,3},{4,5,6}});

    Matrix<double> C = A*B;

    Matrix<double> E(4,4,0);

    E.DisplayMatrix();

    D.DisplayMatrix();

    C.DisplayMatrix();


    return 0;
}