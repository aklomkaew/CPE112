// ****************************************
// Program Title: Project_06
// Project File: Project_06.cpp
// Name: Atchima Klomkaew
// Course Section: CPE-112-02
// Lab Section: 3
// Due Date: 09/25/15
// program description: Description of
// What the program does.
// ****************************************
#include <iostream>
#include <fstream>
#include <climits>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inFile;			// Declare input file
	ofstream outFile;			// Declare output file
	string inputFile;			// Declare name for input file
	string outputFile;			// Declare name for output file
	string name;				// Name of a student
	string major;				// Student's major
	int courseHr;				// Course hours
	int grade;					// Grade
	int hours = 0;				// Hours
	float GPA;					// GPA
	int creditHr = 0;			// Credit Hours
	
	// Prompt for user to input the name of the input file
	cout << "Enter the name of the input file: ";
	cin >> inputFile;
	cout << inputFile << endl << endl; 		// Echo
	
	// Open the input file
	inFile.open(inputFile.c_str());
	
	
	// if input file does not exist and cannot be successfully open
	if(!inFile)
	{
		cout << string(15, '*') << " File Open Error "
			 << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << inputFile << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47, '*') << endl;
		return 1;
	}

// *********************************************************************	
	// Prompt user to enter in the name of output file
	cout << "Please enter in the name of the output file: ";
	cin >> outputFile;
	cout << outputFile << endl << endl;		// Echo
	
	// Open the output file
	outFile.open(outputFile.c_str());
	
	
	// if output file does not exist and cannot be successfully open
	if(!outFile)
	{
		cout << string(15, '*') << " File Open Error "
			 << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << outputFile << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47, '*') << endl;
		return 1;
	}
	
// *********************************************************************
	// Reading the name of a student
	inFile.ignore(INT_MAX, ':');		// ignore until reaches a colon ':'
	getline(inFile, name, '\n');
	name = name.substr(0, 17);			// Ensuring the output is at most 18 characters (0 to 17 is 18 char)
	
	// Reading the major for the student
	inFile.ignore(INT_MAX, ':');
	getline(inFile, major, '\n');
	major = major.substr(0, 17);
	
	// Reading the course hours and the numerical grade
	inFile.ignore(INT_MAX, ':');		// For class 1
	inFile >> courseHr >> grade;
	creditHr = creditHr + (courseHr * grade);		// Calculate credit hours
	hours = hours + courseHr;			// Calculate hours
	
	inFile.ignore(INT_MAX, ':');		// For class 2
	inFile >> courseHr >> grade;
	creditHr = creditHr + (courseHr * grade);
	hours = hours + courseHr;
	
	inFile.ignore(INT_MAX, ':');		// For class 3
	inFile >> courseHr >> grade;
	creditHr = creditHr + (courseHr * grade);
	hours = hours + courseHr;
	
	inFile.ignore(INT_MAX, ':');		// For class 4
	inFile >> courseHr >> grade;
	creditHr = creditHr + (courseHr * grade);
	hours = hours + courseHr;
	
	// Calculating GPA
	GPA = creditHr/hours;
	
// *********************************************************************
	outFile << fixed << setprecision(3);			// Three decimal places
	outFile << left << setw(20) << "Name" << setw(20) << "Major"
			<< setw(8) << "Hours" << setw(15) << "Credit Hours" << setw(5) << "GPA" << endl;
	outFile << setw(20) << "----" << setw(20) << "-----"
			<< setw(8) << "-----" << setw(15) << "------------" << setw(5) << "---" << endl;
	outFile << setw(20) << name << setw(20) << major
			<< setw(8) << hours << setw(15) << creditHr << setw(5) << GPA << endl;

	return 0;
}
