Author: __DHRUVIL__ANIL__DARJI__
Date: 4/4/2018
Matrix Multiplication and Transpose High Performance portable linear algebra library.

Steps To Install:

step 1) Unzip Darji-Dhruvil in the folder
step 2) go to Darji-Dhruvil folder - 
cd Darji-Dhruvil
cd build
cmake ..
sudo make install

It will install matrix_header.h library in "/usr/local/include/matrix_header.h" path.
Now, we are free to use matrix_header.h library in any file as a header file.

Compile source(.cpp) file:
	cd Darji-Dhruvil
	cd src
	g++ -std=c++11 -o matrix matrix.cpp
	./matrix

User Instructions:

MatrixI M(3,4) ==> M is a matrix with 3 rows and 4 columns with integer values.
MatrixF M(3,4) ==> M is a matrix with 3 rows and 4 columns with float values.
MatrixD M(3,4) ==> M is a matrix with 3 rows and 4 columns with double values.


Two ways to enter values of the matrices:
==> We can add the values of the matrices in the script using the indexing of the matrices.
1.) M.add(raw_index,column_index) = value 
	Example:
		MatrixI M(2,2);
		M.add(0,0) = 1;
		M.add(0,1) = 2;
		M.add(1,0) = 3;
		M.add(1,1) = 4;	
		M.print(M);
	Output:

		1	2
		3	4

==> We can ask user to input the values of the matrices. 
2.) M = M.input(raw, col) ==> It will ask for elements of the matrixes	
	Example:
		MatrixI M(2,2);
		M = M.input(2,2);
		M.print(M);
	Output:
		Enter Input Matrix Element 00: 1
		Enter Input Matrix Element 00: 2
		Enter Input Matrix Element 00: 3
		Enter Input Matrix Element 00: 4
		1	2
		3	4

==> Multiplication:
==> We can return the multiplied value of the matrix and print it seperately.
1.) Multiplied = Multiplied.mul(matrix1, matrix2)
	Example: 
		MatrixI M(2,2), N(2,2), Multiplication(2,2);
		M.add(0,0) = 1;
		M.add(0,1) = 2;
		M.add(1,0) = 3;
		M.add(1,1) = 4;	
		N.add(0,0) = 1;
		N.add(0,1) = 2;
		N.add(1,0) = 3;
		N.add(1,1) = 4;	
		M.print(M);
		N.print(N);
		Multiplication = Multiplication.mul(M,N);
		Multiplication.print(Multiplication);
	Output:
		1	2
		3	4
		1	2
		3	4
		7	10
		15	22
		
	==> Here, 7, 10, 15 and 22 is a multiplication matrix of M and N.

==> multiply and print the matrices together. It doen't return any value.
2.) MatrixI::mul_print(matrix1,matrix2)

	Example:
		MatrixI M(2,2), N(2,2);
		M = M.input(2,2);
		N = N.input(2,2);		
		MatrixI::mul_print(M,N);
	Output:
		Enter Input Matrix Element 00: 1
		Enter Input Matrix Element 01: 2
		Enter Input Matrix Element 10: 3
		Enter Input Matrix Element 11: 4
		Enter Input Matrix Element 00: 1
		Enter Input Matrix Element 01: 2
		Enter Input Matrix Element 10: 3
		Enter Input Matrix Element 11: 4
		7	10
		15	22
	==> Here, 7, 10, 15 and 22 is a multiplication matrix of M and N.


==> Transpose:
==> Return the value of transpose and print it seperately.
1.) T = T.transpose(matrix)
	Example:
		MatrixI M(2,3), T(3,2);
		M = M.input(2,3);
		cout << "M"<<endl;
		M.print(M);
		T = T.transpose(M)
		cout << "T" << endl;
		T.print(T);
	output 1:
		Enter Input Matrix Element 00: 1
		Enter Input Matrix Element 01: 2
		Enter Input Matrix Element 02: 3
		Enter Input Matrix Element 10: 4
		Enter Input Matrix Element 11: 5		
		Enter Input Matrix Element 12: 6
		M
		1	2	3
		4	5	6
		T
		1	4
		2	5	
		3	6
	==> Here M is a input matrix and T is transpose matrix.
==> It will transpose and print the transpose matrix. It doesn't return anything.
2.) MatrixI::transpose_print(matrix)
	Example:
		MatrixI M(2,3);
		M.add(0,0) = 1;
		M.add(0,1) = 2;
		M.add(0,2) = 3;
		M.add(1,0) = 4;	
		M.add(1,1) = 5;
		M.add(1,2) = 6;
		M.print(M);
		MatrixI::transpose_print(M);
	output:
		1	2	3
		4	5	6
		1	4
		2	5
		3	6



