// ****************************************
// Program Title: Project_11
// Project File: Project_11.cpp
// Name: Atchima Klomkaew
// Course Section: CPE-112-02
// Lab Section: 3
// Due Date: 12/01/15
// ****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <climits>

using namespace std;

// typedef
typedef int IntArray[3][3];

// Function prototypes
void openFile(ifstream&, string&);
void storeInput(ifstream&, IntArray);
void findDeterminant(IntArray, int&);
void findTranspose(IntArray, IntArray);
void addTwoMatrices(IntArray, IntArray, IntArray);
void printMat(IntArray);
void taskDone();
void subtractTwoMatrices(IntArray, IntArray, IntArray);
void multiplyTwoMatrices(IntArray, IntArray, IntArray);

int main()
{
	// Declare Variables
	ifstream inFile;
	string fileName;
	IntArray matrix, matrix2, newmatrix;			// same as int matrix[3][3]
	int choice, det;
	
	cout << endl;
	
	// Call function to open the file
	openFile(inFile, fileName);
	
	// Obtain choice
	inFile >> choice;
	
	// Call function to store input
	storeInput(inFile, matrix);
	
	while(inFile && !inFile.eof())
	{
		switch(choice)
		{
			case 1:
				cout << string(47, '*') << endl
					 << string(15, '*') << " Find Determinant " << string(14, '*') << endl;
			
				// Display the input matrix
				cout << "\nInput matrix:" << endl;
				printMat(matrix);
				findDeterminant(matrix, det);
				taskDone();
				break;
			case 2:
				cout << string(47, '*') << endl
			 		 << string(15, '*') << " Find Transpose " << string(16, '*') << endl;
			 	
			 	// Display the input matrix
				cout << "\nInput matrix:" << endl;
				printMat(matrix);
				findTranspose(matrix, newmatrix);
				printMat(newmatrix);
				taskDone();
				break;
			case 3:
				storeInput(inFile, matrix2);
				cout << string(47, '*') << endl
			 		 << string(15, '*') << " Add Two Matrices " << string(14, '*') << endl;
			 	
			 	// Display the two input matrices
				// Matrix 1
				cout << "\nMatrix A:" << endl;
				printMat(matrix);
			
				// Matrix 2
				cout << "\nMatrix B:" << endl;
				printMat(matrix2);
				addTwoMatrices(matrix, matrix2, newmatrix);
			
				// New Matrix
				cout << "\nMatrix A + Matrix B:" << endl;
				printMat(newmatrix);
				taskDone();
				break;
			case 4:
				storeInput(inFile, matrix2);
				cout << string(47, '*') << endl
			 		 << string(15, '*') << " Subtract Two Matrices " << string(9, '*') << endl;
			 	
			 	// Display the two input matrices
				// Matrix 1
				cout << "\nMatrix A:" << endl;
				printMat(matrix);
			
				// Matrix 2
				cout << "\nMatrix B:" << endl;
				printMat(matrix2);
				subtractTwoMatrices(matrix, matrix2, newmatrix);
			
				// New Matrix
				cout << "\nMatrix A - Matrix B:" << endl;
				printMat(newmatrix);
				taskDone();
				break;
			case 5:
				storeInput(inFile, matrix2);
				cout << string(47, '*') << endl
			 		 << string(15, '*') << " Multiply Two Matrices " << string(9, '*') << endl;
			 	
			 	// Display the two input matrices
				// Matrix 1
				cout << "\nMatrix A:" << endl;
				printMat(matrix);
			
				// Matrix 2
				cout << "\nMatrix B:" << endl;
				printMat(matrix2);
				multiplyTwoMatrices(matrix, matrix2, newmatrix);
			
				// New Matrix
				cout << "\nMatrix A * Matrix B:" << endl;
				printMat(newmatrix);
				taskDone();
				break;
		}
		
		inFile >> choice;
		storeInput(inFile, matrix);
	}
	
	// Close file
	inFile.close();
	
	return 0;
}
// *****************************************************************************
// Functions below
void openFile(ifstream& inFile, string& fileName)
{
	// Priming read
	cout << "Enter name of input file or Control-C to quit program: ";
	cin >> fileName;
	cout << fileName << endl << endl;
	inFile.open(fileName.c_str());				// Open file
	
	while(!inFile)
	{
		cout << string(15, '*') << " File Open Error " << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n"
			 << "==> Attempted to open file: " << fileName
			 << "\n==> Please try again...\n"
			 << string(47, '*') << endl << endl;
		
		// clear inFile stream
		inFile.clear();
		
		cout << "Enter name of input file or Control-C to quit program: ";
		cin >> fileName;
		cout << fileName << endl << endl;
		inFile.open(fileName.c_str());				// Open file
	}
	
}

void storeInput(ifstream& inFile, IntArray matrix)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			inFile >> matrix[i][j];
		}
	}
}

void taskDone()
{
	cout << endl << string(15, '*') << " Task Finished " << string(17, '*') 
		 << endl << string(47, '*') << endl << endl;
}

void printMat(IntArray mat)
{
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			cout << left << setw(6) << mat[i][j];
		}
		cout << endl;
	}
}

void findDeterminant(IntArray mat, int& det)
{
	// Find Determinant
	det = ((mat[0][0])*(mat[1][1])*(mat[2][2])) 
		  + ((mat[0][1])*(mat[1][2])*(mat[2][0])) 
		  + ((mat[0][2])*(mat[1][0])*(mat[2][1]));
	
	det = det - ( ((mat[2][0])*(mat[1][1])*(mat[0][2])) 
		  + ((mat[2][1])*(mat[1][2])*(mat[0][0]))
		  + ((mat[2][2])*(mat[1][0])*(mat[0][1])));
		  
	cout << "\nThe determinant is: " << det << endl;
}

void findTranspose(IntArray mat, IntArray newMat)
{
	// Find Transpose
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			newMat[i][j] = mat[j][i];
		}
	}
	
	// Display the Transpose
	cout << endl << "The transpose is: " << endl;
}

void addTwoMatrices(IntArray mat, IntArray mat2, IntArray newMat)
{
	// Find the sum of the two
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			newMat[i][j] = mat[i][j] + mat2[i][j];
		}
	}
}

void subtractTwoMatrices(IntArray mat, IntArray mat2, IntArray newMat)
{
	// Subtraction of the two
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			newMat[i][j] = mat[i][j] - mat2[i][j];
		}
	}
}

void multiplyTwoMatrices(IntArray mat, IntArray mat2, IntArray newMat)
{
	// Multiply the two
	for(int i = 0; i < 3; i++)
	{
		for(int j = 0; j < 3; j++)
		{
			newMat[i][j] = (mat[i][0]*mat2[0][j]) 
						   + (mat[i][1]*mat2[1][j]) 
						   + (mat[i][2]*mat2[2][j]);
		}
	}
}
