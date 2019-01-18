# Matrix-library

Matrix-library is a C++ library for dealing with matrices.
## Getting Started

### Prerequisites
To use cmake, make sure **[cmake](https://cmake.org/)** is installed.
If it not installed use these commands to install that:
```bash
sudo apt-get install cmake
``` 
### Make a static library
To make a static library you need to cmake the [CMakeLists.txt](https://github.com/arashHaratian/Matrix-library/blob/master/CMakeLists.txt) and then change directory to **CMakeFiles** and make the **Makefile**.

```bash
cmake CMakeLists
cd CMakeFiles
make
```
Now **".a"** file made.
To use this **".a"** file you can link this file with your mian file with **"g++ -L(location of header file) -l(.a name)"** .

### Make a shared library
To make a shared library you need to change **CMakeFiles** to this:
```gedit
cmake_minimum_required(VERSION 3.5)
project(Matrixlib)

set(CMAKE_CXX_STANDARD 14)

add_library(Matrixlib SHARED matrixLib.cpp matrixLib.h)
```
Now **".so"** file made.

To use this **".so"** file you can check [this](https://www.cprogramming.com/tutorial/shared-libraries-linux-gcc.html) link.

## Usage
A simple code to check my library:
```cpp
#include "matrixLib.h"
using namespace std;

int main()
{
    Matrix matrix1(2,3);                     //Make a 2,3 matrix
    cin >> matrix1;                          //Get the elements of matrix from user
    cout << "your matrix is:\n" << matrix1;   // print the matrix1
    return 0;
```
### The functions you can use are:

#### **[Matrix (string address , char delim)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L30) :**
This **constructor** will take the address of your matrix text file and then make a that matrix.
#### **[Matrix (int row, int column)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L31) :**
This **constructor** will get row and column of your matirx and make that matrix.
#### **[friend istream &operator >> (istream &in , Matrix &matrix1)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L33) :**
Overloading ">>" to **take** elements of matrix from input.
#### **[friend ostream &operator << (ostream &out , const Matrix &matrix1)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L34) :**
Overloading "<<" to **print** the matrix.
#### **[friend Matrix operator * (int const coefficient, Matrix const matrix)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L35)** and **[Matrix operator * (int const coefficient)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L41) :**
These funtions Multiply the matrix in the coefficient return a **"Matrix" object**.
#### **[void show(char delim)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L37)** and **[void show()](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L38) :**
These function **print** the matrix **with/without a specific delimiter**.
#### **[Matrix operator + (Matrix const &matrix)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L39) :**
This function sum the matrices return a **"Matrix" object**.
#### **[Matrix operator - (Matrix const matrix)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L40) :**
This function subtract the matrices return a **"Matrix" object**.
#### **[Matrix operator * (Matrix const &matrix)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L42) :**
This function multiply the matrices and return a **"Matrix" object**.
#### **[bool operator == (Matrix const matrix)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L43) :**
This function compares matrices and return a **"bool" value**.
#### **[Matrix transpose()](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L44) :**
This function transpose the matrices and return a **"Matrix" object**.
#### **[double determinant ()](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L45) :**
This function compute the determinant of the matrices and return a **"double" value**.
#### **[void save (string name, char delim)](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L46) :**
This function save the matrices in a **textfile** with a specific delimiter.
#### **[int getRow()](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L47)** and **[int getColumn()](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L48) :**
These functions show the **row/column** of matrices and return a **"int" value**.
#### **[string showSize()](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L49) :**
This function return a **"string"** that show the row and column of matrices.
#### **[Matrix inverse()](https://github.com/arashHaratian/Matrix-library/blob/f5c10c4564e77546e6f0b6ca1f481a06a239a035/matrixLib.h#L50) :**
This function compute the inverse of the matrices and return a **"Matrix" object**.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.

## License
[MIT](https://choosealicense.com/licenses/mit/)
