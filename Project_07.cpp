// ****************************************
// Program Title: Project_07
// Project File: Project_07.cpp
// Name: Atchima Klomkaew
// Course Section: CPE-112-02
// Lab Section: 3
// Due Date: 10/06/15
// program description: Description of
// What the program does.
// ****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <climits>
#include <iomanip>

using namespace std;

int main()
{
	ifstream inFile;								// stream for inFile
	string fileName;								// name of input file
	double judge1, judge2, judge3, judge4;			// Scores from each judge
	double overAll;									// Average score
	
	cout << "Input file containing the judges' scores: ";
	cin >> fileName;
	cout << fileName << endl;			// Echo
	
	// Open file
	inFile.open(fileName.c_str());
	
	// Check the file's existence
	if(!inFile)
	{
		cout << string(15, '*') << " File Open Error "
			 << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << fileName << endl;
		cout << "==> Terminating program!!!\n";
		cout << string(47, '*') << endl;
		return 1;
	}
	
	cout << fixed << setprecision(1);	// Set precision to 1
	
	// Read scores from the file
	inFile.ignore(INT_MAX, ':');		// Ignore until ':' is reached
	inFile >> judge1;					// score from judge 1
	// Check for invalid score 
	if((judge1 < 0) || (judge1 > 5))
		cout << "WARNING: Judge1 has an invalid score of " << judge1 << endl;
		
	inFile.ignore(INT_MAX, ':');		// Ignore
	inFile >> judge2;					// score from judge 2
	if((judge2 < 0) || (judge2 > 5))
		cout << "WARNING: Judge2 has an invalid score of " << judge2 << endl;
		
	inFile.ignore(INT_MAX, ':');		// Ignore
	inFile >> judge3;					// score from judge 3
	if((judge3 < 0) || (judge3 > 5))
		cout << "WARNING: Judge3 has an invalid score of " << judge3 << endl;
	
	inFile.ignore(INT_MAX, ':');		// Ignore
	inFile >> judge4;					// score from judge 4
	if((judge4 < 0) || (judge4 > 5))
		cout << "WARNING: Judge4 has an invalid score of " << judge4 << endl;
		
	// Check status of the input
	if(!inFile.good())
	{
		cout << string(15, '*') << " File Read Error "
			 << string(15, '*') << endl;
		cout << "==> Reading of one or more scores failed" << endl;
		cout << "==> Terminating program!!!" << endl;
		cout << string(47, '*') << endl;
		return 1;
	}
	
// ***************************************************************************
	// Output receiving scores from judges
	cout << left << setw(10) << "Judge1"
		 << setw(10) << "Judge2"
		 << setw(10) << "Judge3"
		 << setw(10) << "Judge4"
		 << setw(10) << "Overall" << endl;
		 
	cout << setw(10) << "------"
		 << setw(10) << "------"
		 << setw(10) << "------"
		 << setw(10) << "------"
		 << setw(10) << "-------" << endl;
		 
	cout << setw(10) << judge1
		 << setw(10) << judge2
		 << setw(10) << judge3
		 << setw(10) << judge4;
	
	cout << setprecision(2) << fixed;
	
	// Determine which is the smallest score
	if((judge1 <= judge2) && (judge1 <= judge3) && (judge1 <= judge4))
	{
		overAll = (judge2 + judge3 + judge4)/3.00;		// Calculate average score
		cout << setw(10) << overAll << endl << endl;
		cout << "Dropping lowest score of " << setprecision(1) << judge1 << " by Judge1" << endl;
	}
	else if((judge2 <= judge1) && (judge2 <= judge3) && (judge2 <= judge4))
	{
		overAll = (judge1 + judge3 + judge4)/3.00;		// Calculate average score
		cout << setw(10) << overAll << endl << endl;
		cout << "Dropping lowest score of " << setprecision(1) << judge2 << " by Judge2" << endl;
	}
	else if((judge3 <= judge2) && (judge3 <= judge1) && (judge3 <= judge4))
	{
		overAll = (judge2 + judge1 + judge4)/3.00;		// Calculate average score
		cout << setw(10) << overAll << endl << endl;
		cout << "Dropping lowest score of " << setprecision(1) << judge3 << " by Judge3" << endl;
	}
	else if((judge4 <= judge2) && (judge4 <= judge3) && (judge4 <= judge1))
	{
		overAll = (judge2 + judge3 + judge1)/3.00;		// Calculate average score
		cout << setw(10) << overAll << endl << endl;
		cout << "Dropping lowest score of " << setprecision(1) << judge4 << " by Judge4" << endl;
	}
	
	// Check performance level
	if(0.0 <= overAll && overAll < 1.0)
		cout << "Performance Level = Division IV" << endl;
	else if(1.0 <= overAll && overAll < 2.0)
		cout << "Performance Level = Division III" << endl;
	else if(2.0 <= overAll && overAll < 3.0)
		cout << "Performance Level = Division II" << endl;
	else if(3.0 <= overAll && overAll < 4.0)
		cout << "Performance Level = Division I" << endl;
	else if(4.0 <= overAll && overAll < 5.0)
		cout << "Performance Level = Masters Division" << endl;
	else
		cout << "Performance Level = Invalid Score" << endl;
	
	return 0;
}
