#include <iostream>
#include <cstdlib>
#include <matrix_header.h>
using namespace std;
int main()
{
int r1,c1,r2,c2;
cout << "Enter number of Rows for matrix 1" << endl;
cin >> r1;
cout << "Enter number of Columns for matrix 1" << endl;
cin >> c1;
cout << "Enter number of Rows for matrix 2" << endl;
cin >> r2;
cout << "Enter number of Columns for matrix 2" << endl;
cin >> c2;
if (c1!=r2)
   	{
        cout << "Error! column of first matrix not equal to row of second." << endl;
	exit(0);
	}

MatrixI M1(r1,c1), M2(r2,c2), Multiplication(r1,c2), Transpose(c1,r1);
cout << "Enter First Matrix M1" << endl;;
M1 = M1.input(r1,c1);
cout << "Enter Second Matrix M2" << endl;
M2 = M2.input(r2,c2);
cout << "Multiplication of both matrix" << endl;
//Multiplication = M1.mul(M1,M2);
//Multiplication.mul_print(M1,M2);
MatrixI::mul_print(M1,M2);
cout << "Transpose of the first matrix" << endl;
//Transpose = Transpose.transpose(M1);
//Transpose.print(Transpose);
MatrixI::transpose_print(M1);
return 0;
}
