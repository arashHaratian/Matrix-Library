#include "matrixLib.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>

using namespace std;
//------------------------------Public Matrix(row,column) Constructor----------------
Matrix::Matrix (int row, int column) : matrix_( vector<vector<double >>(row,vector<double >(column)) )
{
    try {
        if (row <= 0)
            throw bad_alloc();
    }
    catch(bad_alloc& row)
    {
        cout<<"\nERROR! Your matrix 'row' must be bigger than 0.\n";
        throw ;
    }
    try {
        if (column  <= 0)
            throw bad_alloc();
    }
    catch(bad_alloc& column)
    {
        cout<<"\nERROR! Your matrix 'column' must be bigger than 0.\n";
        throw ;
    }
    this->column_=column;
    this->row_=row;
}
//------------------------------Public Matrix(File) Constructor------------
Matrix::Matrix (string address, char delim)
{
    ifstream matrixfile;
    matrixfile.open (address);
    try {
        if ( !matrixfile.is_open() )
            throw runtime_error("\nCould not open file.\n");
    }
    catch (exception & file)
    {
        cout << "\nYour address or txt file name is wrong.\n";
        throw ;
    }

    this->row_ = this->column_ = 0;
    size_t thisDelim = 0;
    string line = "";
    while (getline(matrixfile, line) && line != "")
    {
        while (line.find(delim, thisDelim + 1) && row_ == 0)
        {
            thisDelim = line.find(delim, thisDelim + 1);
            if (thisDelim == string::npos)
            {
                column_++;
                break;
            }
            column_++;
        }
        row_++;
    }
    this->matrix_ = vector<vector<double > > (row_,vector<double >(column_));
    this->openFile_(address, delim);
    matrixfile.close();
}
//------------------------------Overloading CIN---------------------------------
istream& operator >> (istream &in, Matrix &matrix1)
{
    for(int it = 0 ; it < matrix1.row_ ; it++)
    {
        cout<< it+1 <<"  row:\n" ;
        for ( int innerIt = 0 ; innerIt < matrix1.column_ ; innerIt++ )
            in >> matrix1.matrix_.at(it).at(innerIt);
    }
}
//------------------------------show the this->matrix WITH delim---------------------------
void Matrix::show(char delim)
{
    for (int it = 0; it < this->row_; it++)
    {
        for(int innerIt = 0; innerIt < this->column_; innerIt++)
        {
            if (innerIt == this->column_ -1)
                cout << this->matrix_.at(it).at(innerIt);
            else
                cout << this->matrix_.at(it).at(innerIt) << delim;
        }
        cout << '\n';
    }
}
//------------------------------show the this->matrix WITHOUT delim---------------------------
void Matrix::show()
{
    for (int it = 0; it < this->row_; it++)
    {
        for(int innerIt = 0; innerIt < this->column_; innerIt++)
        {
            if (innerIt == this->column_ -1)
                cout << this->matrix_.at(it).at(innerIt);
            else
                cout << this->matrix_.at(it).at(innerIt) << '\t';
        }
        cout << '\n';
    }
}
//---------------------------Overloading SUM------------------------
Matrix Matrix::operator+ (Matrix const &matrix)
{
    try
    {
        if (this->column_ != matrix.column_ || this->row_ != matrix.row_)
            throw logic_error("\nSummation error: These matrices are not in a same shape.\n");
    }
    catch(exception & logicError)
    {
        cout<<"\nAn logic error thrown.\n";
        throw ;
    }

    Matrix totalMartix (this->row_, this->column_);
    for (int it = 0; it < this->row_; it++)
        for (int innerIt = 0; innerIt < this->column_; innerIt++)
            totalMartix.matrix_.at(it).at(innerIt) = this->matrix_.at(it).at(innerIt) + matrix.matrix_.at(it).at(innerIt);
    return totalMartix;

}
//-------------------------Overloading Multiply With Another Matrix -----------------------
Matrix Matrix::operator * (Matrix const &matrix)
{
    try
    {
        if (this->column_ != matrix.row_)
            throw logic_error("\nMultiplication error: Column of first matrix is not equal to row of second matrix.\n");
    }
    catch (exception & logicError)
    {
        cout << "\nAn logic error thrown.\n";
        throw ;
    }
    Matrix productMatrix(this->row_, matrix.column_);
    for (int it = 0; it < this->row_; it++)
        for(int firstInnerIt = 0; firstInnerIt < matrix.column_; firstInnerIt++)
            for (int secondInnerIt = 0; secondInnerIt < this->column_; secondInnerIt++)
            {
                productMatrix.matrix_.at(it).at(firstInnerIt) += this->matrix_.at(it).at(secondInnerIt) * matrix.matrix_.at(secondInnerIt).at(firstInnerIt);
            }
    return productMatrix;

}
//-------------------------Overloading Multiply With Number----------------------
Matrix Matrix::operator * (int const coefficient)
{
    Matrix productMatrix(this->row_, this->column_);
    for (int it = 0; it < this->row_; it++)
        for (int innerIt = 0; innerIt < this->column_; innerIt++)
            productMatrix.matrix_.at(it).at(innerIt) = this->matrix_.at(it).at(innerIt) * coefficient;
    return productMatrix;
}
//--------------------------- int * matrix---------------------------
Matrix operator * (int const coefficient, Matrix const matrix)
{
    Matrix productMatrix(matrix.row_, matrix.column_);
    for (int it = 0; it < matrix.row_; it++)
        for (int innerIt = 0; innerIt < matrix.column_; innerIt++)
            productMatrix.matrix_.at(it).at(innerIt) = matrix.matrix_.at(it).at(innerIt) * coefficient;
    return productMatrix;
}
//----------------------------Overloading Minus----------------------
Matrix Matrix::operator - (Matrix const matrix)
{
    try
    {
        if (this->column_ != matrix.column_ || this->row_ != matrix.row_)
            throw logic_error("\nSubtraction error: These matrices are not in a same shape.\n");
    }
    catch(exception & logicError)
    {
        cout<<"\nAn logic error thrown.\n";
        throw ;
    }
    Matrix minusMatrix (this->row_, this->column_);
    for (int it = 0; it < this->row_; it++)
        for (int innerIt = 0; innerIt < this->column_; innerIt++)
            minusMatrix.matrix_.at(it).at(innerIt) = this->matrix_.at(it).at(innerIt) - matrix.matrix_.at(it).at(innerIt);
    return minusMatrix;

}
//----------------------------- overloading == -----------------------
bool Matrix ::operator == (Matrix const matrix)
{
    if(this->row_ == matrix.row_ && this->column_ == matrix.column_)
    {
        for (int it = 0; it < this->row_; it++)
            for (int innerIt = 0; innerIt < this->column_; innerIt++)
                if (this->matrix_.at (it).at (innerIt) != matrix.matrix_.at (it).at (innerIt))
                    return false;
        return true;
    }
    else
        return false;
}
//----------------------------Transposing----------------------------
Matrix Matrix::transpose()
{
    Matrix transposeMatrix (this->column_, this->row_);
    for (int it = 0; it < this->row_; it++)
        for (int innerIt = 0; innerIt < this->column_; innerIt++)
            transposeMatrix.matrix_.at(innerIt).at(it) = this->matrix_.at(it).at(innerIt);
    return transposeMatrix;
}
//-------------------------Cofactor_-----------------------------
void Matrix::getCofactor_(Matrix matrix1, Matrix &tempMatrix, int p, int q, int n)
{
    int i = 0, j = 0;
    for (int row = 0; row < n; row++)
    {
        for (int column = 0; column < n; column++)
        {
            if (row != p && column != q)
            {
                tempMatrix.matrix_.at(i).at(j++) = matrix1.matrix_.at(row).at(column);
                if (j == n - 1)
                {
                    j = 0;
                    i++;
                }
            }
        }
    }
}
//----------------------private determinant_ -----------------------------
double Matrix::determinant_ (int n)
{
    double determ = 0;
    if (n == 1)
        return this->matrix_.at(0).at(0);

    Matrix tempMatrix (this->row_, this->row_);

    int sign = 1;
    for (int f = 0; f < n; f++)
    {
        getCofactor_(*this, tempMatrix, 0, f, n);
        determ += sign * this->matrix_.at(0).at(f) * tempMatrix.determinant_ (n-1);
        sign = -sign;
    }
    return determ;
}
//-------------------Public determinant------------------------------------
double Matrix::determinant()
{
    try
    {
        if (this->row_ != this->column_)
            throw logic_error("\nDeterminants are only used for square matrices.\n");
    }
    catch(exception & logicError)
    {
        cout << "\nAn logic error thrown.\n";
        throw ;
    }

    return this->determinant_(this->row_);
}
//-----------------Elements Textfile To Matrix----------------------
void Matrix::openFile_(string address, char delim)
{
    ifstream elementFile (address);
    try
    {
        if( !elementFile.is_open() )
        {
            elementFile.open(address);
            if ( !elementFile.is_open() )
                throw runtime_error("\nThe address is passed wrong to private 'Matrix::openFile_(string address, char delim)' function.\n");
        }
    }
    catch (exception & address)
    {
        cout << "\nInternal error: The address is not passed right.\n";
        throw ;
    }
    size_t previousDelim = -1;
    size_t thisDelim = 0;
    string line = "";
    int it = 0;
    while (getline (elementFile, line) && line != "")
    {
        int innerIt = 0;
        while (line.find (delim, thisDelim + 1))
        {
            thisDelim = line.find(delim, thisDelim + 1);
            if (thisDelim == string::npos)
            {
                thisDelim = line.find('\n');
                if (line [previousDelim + 1] == '-')
                    this->matrix_.at(it).at(innerIt) = -stod (line.substr (previousDelim + 2, thisDelim));
                else
                    this->matrix_.at(it).at(innerIt) = stod (line.substr (previousDelim + 1, thisDelim - 1));
                break;
            }
            if (line[previousDelim + 1] == '-')
            {
                this->matrix_.at(it).at(innerIt) = -stod (line.substr (previousDelim + 2, thisDelim));
                innerIt++;
            }
            else {
                this->matrix_.at(it).at(innerIt) = stod (line.substr (previousDelim + 1, thisDelim));
                innerIt++;
            }
            previousDelim = thisDelim;
        }
        it++;
        previousDelim = -1;
        thisDelim = 0;
    }
}
//------------------------Saving Matrix To TextFile----------------------------------
void Matrix::save(string name , char delim)
{
    ofstream outputFile (name);
    for (int it = 0; it < this->row_; it++)
    {
        for (int innerIt = 0; innerIt < this->column_; innerIt++)
        {
            if (innerIt == this->column_ -1)
                outputFile << this->matrix_.at(it).at(innerIt);
            else
                outputFile << this->matrix_.at(it).at(innerIt) << delim ;
        }
        outputFile << '\n';
    }
}
//-------------------------Get Row-------------------------------------
int Matrix::getRow()
{
    return this->row_;
}
//---------------------Get column-------------------------------------
int Matrix::getColumn()
{
    return this->column_;
}//------------------- show matrixSize-------------------------------------
string Matrix::showSize()
{
    string size = "";
    size = to_string(this->row_) + " , " + to_string(this->column_);
    return  size;
}
//------------------private adjoint_ ------------------------------------------
void Matrix::adjoint_(Matrix &adjoint)
{
    if (this->column_ == 1)
    {
        adjoint.matrix_.at(0).at(0) = 1;
        return;
    }
    int sign = 1;
    Matrix tempMatrix(this->row_, this->column_);

    for (int  it= 0; it <this->row_; it++)
        for (int innerIt = 0; innerIt< this->column_; innerIt++)
        {
            getCofactor_(*this, tempMatrix, it, innerIt, this->row_);
            sign = ((it+innerIt)%2==0)? 1: -1;
            int n = this->row_;
            adjoint.matrix_.at(innerIt).at(it)= (sign) * (tempMatrix.determinant_(n-1));
        }
}
//--------------------Public inverse ----------------------------------------
Matrix Matrix::inverse()
{
    double determ = this->determinant_(this->column_);
    try
    {
        if (determ != 0)
            throw logic_error ("\nSingular matrix, can't find its inverse.\n");
    }
    catch (exception & logicError)
    {
        cout << "\nAn logic error thrown.\n";
        throw ;
    }
    Matrix inverse(this->row_, this->column_);
    Matrix adjoint(this->row_, this->column_);
    this->adjoint_ (adjoint);
    for (int it = 0; it < this->row_; it++)
        for (int innerIt = 0; innerIt < this->column_; innerIt++)
            inverse.matrix_.at(it).at(innerIt) = adjoint.matrix_.at(it).at(innerIt) / int(determ);
    return inverse;
}