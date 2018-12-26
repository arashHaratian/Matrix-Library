
//
// Created by arashHaratian on 11/16/18.
//

#ifndef MATRIXLIBFINAL_LIBRARY_H
#define MATRIXLIBFINAL_LIBRARY_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Matrix {
private:
    //----------Field
    int column_;
    int row_;
    vector<vector<double> > matrix_;

    //-----------Methods
    void getCofactor_(Matrix matrix1, Matrix &tempMatrix, int p, int q, int n);
    void openFile_ (string address, char delim);
    double determinant_ (int n);
    void adjoint_ (Matrix &adjoint);

public:
    //----------Constructor
    Matrix (string address , char delim);
    Matrix (int row, int column);
    //---------Friends Methods-----------
    friend istream &operator >> (istream &in , Matrix &matrix1);
    friend ostream &operator << (ostream &out , const Matrix &matrix1);
    friend  Matrix operator * (int const coefficient, Matrix const matrix) ;
    //--------Public Methods------------------
    void show(char delim);
    void show();
    Matrix operator + (Matrix const &matrix);
    Matrix operator - (Matrix const matrix);
    Matrix operator * (int const coefficient);
    Matrix operator * (Matrix const &matrix);
    bool operator == (Matrix const matrix);
    Matrix transpose();
    double determinant ();
    void save (string name, char delim);
    int getRow();
    int getColumn();
    string showSize();
    Matrix inverse();
};

#endif //MATRIXLIBFINAL_LIBRARY_H