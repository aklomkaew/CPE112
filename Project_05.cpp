// ****************************************
// Program Title: Project_05
// Project File: Project_05.cpp
// Name: Atchima Klomkaew
// Course Section: CPE-112-02
// Lab Section: 3
// Due Date: 09/18/15
// program description: Description of
// What the program does.
// ****************************************
#include <iostream>
#include <string>
#include <iomanip>
#include <climits>
using namespace std;

int main()
{
	// Declare variables for first line
	string first;				// first line
	string unique;				// unique character
	string firstPart;			// Part 1 of line 1
	string secondPart;			// Part 2 of line 1
	string::size_type pos;		// Position of the unique character
	double percent;				// Percent of characters
	
	// Declare variables for second line
	string second; 				// second line
	string divide;				// dividing character
	string firstLine2;			// Part 1 of line 2
	string secondLine2;			// Part 2 of line 2
	string thirdLine2;			// Part 3 of line 2
	string split1;				// Split parts
	
	// Prompting input for the first line
	cout << "\nEnter the first line for processing:" << endl;
	getline(cin, first, '\n');
	// Echoing
	cout << first << endl;
	
	cout << "Enter the unique character for the line: ";
	getline(cin, unique, '\n');
	// Echoing
	cout << unique << endl << endl;
	
	// Prompting input for the second line
	cout << "Enter the second line for processing:" << endl;
	getline(cin, second, '\n');
	// Echoing
	cout << second << endl;
	
	cout << "Enter the dividing character for the line: ";
	getline(cin, divide, '\n');
	// Echoing
	cout << divide << endl << endl;

// ****************************************************************************
// Line One Section

	// Find the position of the unique character in line 1
	pos = first.find(unique);
	// Split line 1
	firstPart = first.substr(0,pos);
	secondPart = first.substr(pos+1);
	//Find Percentage
	percent = ((double)firstPart.length())/(first.length()) * 100.0;
	
	cout << setprecision(2) << fixed;
	// Output First line Information
	cout << string(20, '*') << " First Line Information " << string(20, '*') << endl;
	cout << setw(15) << "Line read: " << first << "[" << first.length() << "]" << endl;
	cout << setw(15) << "Part 1: " << firstPart << "[" << firstPart.length() << "]" << endl;
	cout << setw(15) << "Part 2: " << secondPart << "[" << secondPart.length() << "]" << endl;
	cout << percent << "% of the characters are in the first part of the line" << endl;
	
	// Output 64 '*'
	cout << string(64, '*') << endl << endl;

// ****************************************************************************
// Line Two Section
	
	// Find the position of the dividing character of line 2
	pos = second.find(divide);
	
	// Split line 2
	split1 = second.substr(pos+1, INT_MAX);

	// Get first and second parts for line 2
	firstLine2 = second.substr(0, pos);
	secondLine2 = split1.substr(0, split1.find(divide));
	thirdLine2 = split1.substr(split1.find(divide)+1);
	
	// Output Second Line Information
	cout << string(10, '*') << " Second Line Information " << string(10, '*') << endl;
	cout << setw((firstLine2.length() + 45)/2) << firstLine2 << endl;
	cout << setw((secondLine2.length() + 45)/2) << secondLine2 << endl;
	cout << setw((thirdLine2.length() + 45)/2) << thirdLine2 << endl;
	cout << string(45, '*') << endl;
	
	return 0;
}
