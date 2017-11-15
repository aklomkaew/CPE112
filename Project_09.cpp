// ****************************************
// Program Title: Project_09
// Project File: Project_09.cpp
// Name: Atchima Klomkaew
// Course Section: CPE-112-02
// Lab Section: 3
// Due Date: 10/19/15
// program description: Description of
// What the program does.
// ****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <cctype>
#include <iomanip>

using namespace std;

// Functions
void printMenu();
void obtainChoice(int&);
bool checkFile(ifstream&, string&);
void printErrorFile(string&);
void findVowels(ifstream&);
void findConsonants(ifstream&);
void printErrorSelection();

int main()
{
	// Declare variables
	int choice;
	ifstream inFile;
	string fileName;
	bool isFile;
	
	cout << endl;
	
	// Print menu
	printMenu();
	
	// Priming read
	obtainChoice(choice);
	
	while(!(choice == 0))
	{
		isFile = checkFile(inFile, fileName);
		
		if(!isFile)
			printErrorFile(fileName);
			
		else if(isFile && choice == 1)
			findVowels(inFile);
			
		else if(isFile && choice == 2)
			findConsonants(inFile);
			
		else
			printErrorSelection();
		
		// Reset stream
		inFile.clear();
		inFile.close();
		
		// Start over
		printMenu();
		obtainChoice(choice);
	}
	
	cout << "\nQuit selected.  Terminating program now..." << endl << endl;
	
	return 0;
}

void printMenu()
{
	// Show options
	cout << string(19, '*') << " Options " << string(19, '*') << endl;
	cout << "0. Exit Program" << endl
		 << "1. Count number of vowels" << endl
		 << "2. Count number of consonants" << endl;
	cout << string(47, '*') << endl << endl;
}

void obtainChoice(int& choice)
{
	// Priming read
	cout << "Input your selection: ";
	cin >> choice;
	cout << choice << endl;					// Echo
	cin.ignore(INT_MAX, '\n');
	
	while(cin.fail())
	{
		cin.clear();
		
		// Error message
		cout << string(14, '*') << " Invalid Selection " << string(14, '*')
		 	 << "\n==> Invalid character entered!!"
		 	 << "\n==> Please enter 0, 1 or 2" << endl;
		cout << string(47, '*') << endl << endl;
		
		// Reprint the menu
		printMenu();
		
		cout << "Input your selection: ";
		cin >> choice;
		cout << choice << endl;					// Echo
		cin.ignore(INT_MAX, '\n');
	}
}

bool checkFile(ifstream& inFile, string& fileName)
{
	cout << "Enter the name of the input file now: ";
	cin >> fileName;
	cout << fileName << endl; 				// Echo
	cin.ignore(INT_MAX, '\n');
	
	inFile.open(fileName.c_str());
	
	return inFile.good();
}

void printErrorFile(string& fileName)
{
	cout << endl << string(15, '*') << " File Open Error " << string(15, '*') << endl;
	cout << "==> Input file failed to open properly!!"
		 << "\n==> Attempted to open file: " << fileName
		 << "\n==> Selected operation has been canceled" << endl;
	cout << string(47, '*') << endl << endl;
}

void findVowels(ifstream& inFile)
{
	// Declare character
	char ch;
	int vowel = 0;
	int line = 0;
	float average;
	
	// Priming read 
	inFile.get(ch);
	
	if(inFile.fail())
	{
		// Error message for empty file
		cout << endl << string(16, '*') << " File Is Empty " << string(16, '*') << endl;
		cout << "==> Input file is empty"
			 << "\n==> No information to process" << endl;
		cout << string(47, '*') << endl << endl;
		
		//exit(1);			// Return
	}
	while(inFile)
	{
		while(inFile)
		{
			if(isalpha(ch) && (tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' 
								|| tolower(ch) == 'o' || tolower(ch) == 'u'))
			{
				vowel++;
			}
			else if(ch == '\n')
			{
				line++;
			}
		
			inFile.get(ch);
		}
		// Find average
		average = (float)vowel/line;
	
		// Print out info
		cout << "\nCounting Number of Vowels" << endl;
		cout << string(25, '-') << endl
			 << "There are " << vowel << " vowels in the file" << endl
			 << "There are " << line << " lines in the file" << endl
			 << "This is an average of " << setprecision(3) << fixed << average << " vowels per line" << endl
			 << string(25, '-') << endl << endl;
	}
}

void findConsonants(ifstream& inFile)
{
	// Declare character
	char ch;
	int consonants = 0;
	int line = 0;
	float average;
	
	// Priming read 
	inFile.get(ch);
	
	if(inFile.fail())
	{
		// Error message for empty file
		cout << string(16, '*') << " File Is Empty " << string(16, '*') << endl;
		cout << "==> Input file is empty"
			 << "\n==> No information to process" << endl;
		cout << string(47, '*') << endl << endl;
	}
	while(inFile)
	{
		while(inFile)
		{
			if(isalpha(ch) && !(tolower(ch) == 'a' || tolower(ch) == 'e' || tolower(ch) == 'i' 
								|| tolower(ch) == 'o' || tolower(ch) == 'u'))
			{
				consonants++;
			}
			else if(ch == '\n')
			{
				line++;
			}
	
			inFile.get(ch);
		}
		// Find average
		average = (float)consonants/line;
	
		// Print out info
		cout << "\nCounting Number of Consonants" << endl;
		cout << string(29, '-') << endl
			 << "There are " << consonants << " consonants in the file" << endl
			 << "There are " << line << " lines in the file" << endl
			 << "This is an average of " << setprecision(3) << fixed << average << " consonants per line" << endl
			 << string(29, '-') << endl << endl;
	}
}

void printErrorSelection()
{
	cout << string(14, '*') << " Invalid Selection " << string(14, '*')
		 << "\n==> Invalid integer value entered"
		 << "\n==> Please enter 0, 1 or 2" << endl;
	cout << string(47, '*') << endl << endl;
}
