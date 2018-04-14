#include <iostream>
#include <cstdlib>
using namespace std;

class MatrixI {
public:
    MatrixI(int r, int c) {
        _arrayofarrays = new int*[r];
        for(int i = 0; i < r; ++i)
            _arrayofarrays[i] = new int[c];
	row = r;
	col = c;	
   }
   MatrixI input(int x,int y);
   int& add(int x,int y);
   static MatrixI mul(MatrixI a,MatrixI b);
   static MatrixI transpose(MatrixI a);
   static MatrixI print(MatrixI a);
   static MatrixI mul_print(MatrixI a,MatrixI b);
   static MatrixI transpose_print(MatrixI a);
    class Proxy {
    public:
        Proxy(int* _array) : _array(_array) { }

        int operator[](int index) {
            return _array[index];
        }

    private:
        int* _array;
    }; 
    Proxy operator[](int index) {
        return Proxy(_arrayofarrays[index]);
    }
private:
    int** _arrayofarrays;
   	int row;
	int col;	
};

int& MatrixI::add(int x,int y)
{
return _arrayofarrays[x][y];
}


MatrixI MatrixI::transpose_print(MatrixI a){

	MatrixI c(a.col,a.row);
	c = a.transpose(a);
	c.print(c);
}

MatrixI MatrixI::mul_print(MatrixI a,MatrixI b){
	if (a.col != b.row)
	{
		cout << "Error! column of first matrix not equal to row of second." << endl;
		exit(0);
	}
	
	MatrixI c(a.row,b.col);
	c = a.mul(a,b);
	c.print(c);
}

MatrixI MatrixI::input(int x,int y)
{
	MatrixI c(x,y);
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			{
			cout << "Enter input matrix element " << i << j << " : ";
			cin >> c.add(i,j);
			}
	return c;
}

MatrixI MatrixI::print(MatrixI a)
{
	int r,c;
	r = a.row;
	c = a.col;
	for(int i =0; i<r; i++)
		for(int j =0; j<c; j++)
		{
		 cout << " " << a[i][j];
      		  if(j == c-1)
       		     cout << endl;
		}

}

MatrixI MatrixI::mul(MatrixI a,MatrixI b)
{	
	if (a.col != b.row)
	{
		cout << "Error! column of first matrix not equal to row of second." << endl;
		exit(0);
	}
	int i,j,k,r1,c1,r2,c2, temp;
	temp = 0;
	r1 = a.row;
	c1 = a.col;
	r2 = b.row;
	c2 = b.col; 
	MatrixI c(r1,c2);

    // Initializing elements of matrix mult to 0.
    for(i =0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            c.add(i,j) = 0;
        }

    // Multiplying matrix a and b and storing in array mult.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
		
		c.add(i,j) += a[i][k] * b[k][j];
	
            }
	
	return c;
}

MatrixI MatrixI::transpose(MatrixI a)
{	
	int i,j,k,r1,c1,r2,c2, temp;
	r1 = a.row;
	c1 = a.col; 
	MatrixI c(c1,r1);

    // Initializing elements of matrix mult to 0.
    for(i =0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            c.add(j,i) = a[i][j];
        }
	
	return c;
}


class MatrixF {
public:
    MatrixF(int r, int c) {
        _arrayofarrays = new float*[r];
        for(int i = 0; i < r; ++i)
            _arrayofarrays[i] = new float[c];
	row = r;
	col = c;	
   }
   MatrixF input(int x,int y);
   float& add(int x,int y);
   static MatrixF mul(MatrixF a,MatrixF b);
   static MatrixF transpose(MatrixF a);
   static MatrixF print(MatrixF a);
   static MatrixF mul_print(MatrixF a,MatrixF b);
   static MatrixF transpose_print(MatrixF a);
    class Proxy {
    public:
        Proxy(float* _array) : _array(_array) { }

        float operator[](int index) {
            return _array[index];
        }

    private:
        float* _array;
    }; 
    Proxy operator[](int index) {
        return Proxy(_arrayofarrays[index]);
    }
private:
    float** _arrayofarrays;
   	int row;
	int col;	
};


MatrixF MatrixF::transpose_print(MatrixF a){

	MatrixF c(a.col,a.row);
	c = a.transpose(a);
	c.print(c);
}

MatrixF MatrixF::mul_print(MatrixF a,MatrixF b){
	if (a.col != b.row)
	{
		cout << "Error! column of first matrix not equal to row of second." << endl;
		exit(0);
	}

	MatrixF c(a.row,b.col);
	c = a.mul(a,b);
	c.print(c);
}


float& MatrixF::add(int x,int y)
{
	return _arrayofarrays[x][y];
}

MatrixF MatrixF::input(int x,int y)
{
	MatrixF c(x,y);
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			{
			cout << "Enter input matrix element " << i << j << " : ";
			cin >> c.add(i,j);
			}
	return c;
}


MatrixF MatrixF::print(MatrixF a)
{
	int r,c;
	r = a.row;
	c = a.col;
	for(int i =0; i<r; i++)
		for(int j =0; j<c; j++)
		{
		 cout << " " << a[i][j];
      		  if(j == c)
       		     cout << endl;
		}

}

MatrixF MatrixF::mul(MatrixF a,MatrixF b)
{

	if (a.col != b.row)
	{
		cout << "Error! column of first matrix not equal to row of second." << endl;
		exit(0);
	}	
	int i,j,k,r1,c1,r2,c2, temp;
	r1 = a.row;
	c1 = a.col;
	r2 = b.row;
	c2 = b.col; 
	MatrixF c(r1,c2);

    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            c.add(i,j) = 0;
        }

    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
		c.add(i,j) += a[i][k] * b[k][j];
	
            }
	
	return c;
}

MatrixF MatrixF::transpose(MatrixF a)
{	
	int i,j,k,r1,c1,r2,c2, temp;
	r1 = a.row;
	c1 = a.col; 
	MatrixF c(c1,r1);

    // Initializing elements of matrix mult to 0.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            c.add(j,i) = a[i][j];
        }
	
	return c;
}


class MatrixD {
public:
    MatrixD(int r, int c) {
        _arrayofarrays = new double*[r];
        for(int i = 0; i < r; ++i)
            _arrayofarrays[i] = new double[c];
	row = r;
	col = c;	
   }
   MatrixD input(int x,int y);
   double& add(int x,int y);
   static MatrixD mul(MatrixD a,MatrixD b);
   static MatrixD transpose(MatrixD a);
   static MatrixD print(MatrixD a);
   static MatrixD mul_print(MatrixD a,MatrixD b);
   static MatrixD transpose_print(MatrixD a);
    class Proxy {
    public:
        Proxy(double* _array) : _array(_array) { }

        double operator[](int index) {
            return _array[index];
        }

    private:
        double* _array;
    }; 
    Proxy operator[](int index) {
        return Proxy(_arrayofarrays[index]);
    }
private:
    double** _arrayofarrays;
   	int row;
	int col;	
};


MatrixD MatrixD::transpose_print(MatrixD a){

	MatrixD c(a.col,a.row);
	c = a.transpose(a);
	c.print(c);
}

MatrixD MatrixD::mul_print(MatrixD a,MatrixD b){
	if (a.col != b.row)
	{
		cout << "Error! column of first matrix not equal to row of second." << endl;
		exit(0);
	}

	MatrixD c(a.row,b.col);
	c = a.mul(a,b);
	c.print(c);
}


double& MatrixD::add(int x,int y)
{
	return _arrayofarrays[x][y];
}

MatrixD MatrixD::input(int x,int y)
{
	MatrixD c(x,y);
	for(int i=0;i<x;i++)
		for(int j=0;j<y;j++)
			{
			cout << "Enter input matrix element " << i << j << " : ";
			cin >> c.add(i,j);
			}
	return c;
}


MatrixD MatrixD::print(MatrixD a)
{
	int r,c;
	r = a.row;
	c = a.col;
	for(int i =0; i<r; i++)
		for(int j =0; j<c; j++)
		{
		 cout << " " << a[i][j];
      		  if(j == c)
       		     cout << endl;
		}

}

MatrixD MatrixD::mul(MatrixD a,MatrixD b)
{

	if (a.col != b.row)
	{
		cout << "Error! column of first matrix not equal to row of second." << endl;
		exit(0);
	}	
	int i,j,k,r1,c1,r2,c2, temp;
	r1 = a.row;
	c1 = a.col;
	r2 = b.row;
	c2 = b.col; 
	MatrixD c(r1,c2);

    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
        {
            c.add(i,j) = 0;
        }

    for(i = 0; i < r1; ++i)
        for(j = 0; j < c2; ++j)
            for(k = 0; k < c1; ++k)
            {
		c.add(i,j) += a[i][k] * b[k][j];
	
            }
	
	return c;
}

MatrixD MatrixD::transpose(MatrixD a)
{	
	int i,j,k,r1,c1,r2,c2, temp;
	r1 = a.row;
	c1 = a.col; 
	MatrixD c(c1,r1);

    // Initializing elements of matrix mult to 0.
    for(i = 0; i < r1; ++i)
        for(j = 0; j < c1; ++j)
        {
            c.add(j,i) = a[i][j];
        }
	
	return c;
}


