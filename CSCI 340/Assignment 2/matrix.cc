/* 	Thomas Dela Pena
	z120111
	CSCI 340 Section 1
	
	I certify that this is my own work and where appropriate an extension 
	of the starter code provided for the assignment.
*/

#include <iostream>
#include <iomanip>
#include "matrix.h"


/* 
*	Initializes the matrix class
*
*	@param rows Value representing the number of rows in the matrix
*	@param cols Value representing the number of columns in the matrix
*/
matrix::matrix(unsigned int rows, unsigned int cols)
{
	//initialize the matrix vector
	std::vector<std::vector<int>> mat(rows, std::vector<int>(cols));
	
	//resize matrix using rows and cols
	mat.resize(rows,std::vector<int>(cols));
}

/*
*	Resize the matrix vector to have row elements, then resize each
*	of those elements(which are also vectors) to have cols elements
*	
*	@param rows Value representing the number of rows in the matrix
*       @param cols Value representing the number of columns in the matrix
*
*/
void matrix::resize(unsigned int rows, unsigned int cols)
{
	mat.resize(rows,std::vector<int>(cols));
}
/*
*	Read the input values from the given input stream and store
*	them into the 2-D matrix 'mat'
*	
*	@param is reference to a set of input values from the input
*	stream
*
*/
void matrix::load(std::istream &is)
{
	int mrows, mcols;
	int value;

	is >> mrows;
	is >> mcols;

	resize(mrows,mcols);			//resize the mat matrix
	
	for(int i = 0; i < mrows; i++)		//fill in the mat matrix with the input values
	{	
		for(int j = 0; j < mcols; j++)
		{
			is >> value;
			mat.at(i).push_back(value);
			
		}
	}	
}

/*
*	Prints out the values of the matrix elements with vertical lines, and a properly sized footer line. 
*
*	@param colWidth Value that represents the width of the columns
*/
void matrix::print(int colWidth) const
{
	std::cout<< getRows() << " x " << getCols() << std::endl;	//Print out the dimensions of matrix (row x column)
	
	for(unsigned int i = 0; i < getCols() * (colWidth + 1); i++)
	{
		std::cout << "--------------";		//print a proper sized header line
	}
	
	std::cout << std::endl;  

	//Print the elements of the matrix
	for(auto i : mat)
	{
		for(auto j : i)
		{		
			std::cout << "|" << std::setw(colWidth + 1) << std::right << mat.at(i,j) << "|";
		}
		
		std::cout << std::endl;
	}


}







	
