// ****************************************
// Program Title: Project_08
// Project File: Project_08.cpp
// Name: Atchima Klomkaew
// Course Section: CPE-112-02
// Lab Section: 3
// Due Date: 09/16/15
// program description: Description of
// What the program does.
// ****************************************
#include <iostream>
#include <iomanip>
#include <climits>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inFile;
    ofstream outFile;
    string in_fileName;
    string out_fileName;
    
    string lastName, firstName;
    int numQuiz, numHomework, numExam;
    int quiz, homework, exam;
    int sumQuiz = 0, sumHomework = 0, sumExam = 0, totalK = 0, total = 0;
    float average = 0.0, classavg = 0.0;
    bool flag = true;
    
    // Prompt for input file name
    cout << "Enter the name of the input file: ";
    cin >> in_fileName;
    cout << in_fileName << endl;		// Echo
    
    // Open infile
    inFile.open(in_fileName.c_str());
    
    while(inFile.fail())
	{
		cout << string(15, '*') << " File Open Error "
			 << string(15, '*') << endl;
		cout << "==> Input file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << in_fileName << endl;
		cout << "==> Please try again...\n";
		cout << string(47, '*') << endl << endl;
		inFile.clear();				// clear the status of the stream
		
		cout << "Enter the name of the input file: ";
    	cin >> in_fileName;
    	cout << in_fileName << endl;		// Echo
    	inFile.open(in_fileName.c_str());
	}
	
	// Prompt for output file name
	cout << "Enter the name of the output file: ";
    cin >> out_fileName;
    cout << out_fileName << endl;		// Echo
    
	// Open outfile
	outFile.open(out_fileName.c_str());
	
	while(!outFile)
	{
		cout << string(15, '*') << " File Open Error "
			 << string(15, '*') << endl;
		cout << "==> Output file failed to open properly!!\n";
		cout << "==> Attempted to open file: " << out_fileName << endl;
		cout << "==> Please try again...\n";
		cout << string(47, '*') << endl << endl;
		outFile.clear();				// clear the status of the stream
		
		cout << "Enter the name of the output file: ";
    	cin >> out_fileName;
    	cout << out_fileName << endl;		// Echo
    	outFile.open(out_fileName.c_str());
	}
	
// ****************************************************************************
	// Priming read
	inFile >> numQuiz >> numHomework >> numExam;
	// Check file emptiness
	if(inFile.fail())
	{
		cout << string(13, '*') << " Input File Is Empty "
			 << string(13, '*') << endl;
		cout << "==> The input file is empty.\n";
		cout << "==> Terminating the program." << endl;
		cout << string(47, '*') << endl << endl;
		
		outFile << "Input file " << in_fileName << " is empty.\n";
		outFile << "======= End Of Output File Contents =======\n";
		
		return 1;
	}
	outFile << fixed << left;
	
    // Output column headers and the dashed lines below the headers
    outFile << setw(3) << "#" << setw(12) << "Last" << setw(7) << "First"
    		<< setw(6) << "Quiz" << setw(6) << "HW" << setw(6) << "Exam"
    		<< setw(7) << "Total" << setw(9) << "Average" << endl;
    		
    outFile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----"
            << setw(6) << "----" << setw(6) << "---" << setw(6) << "----"
            << setw(7) << "-----" << setw(9) << "-------" << endl;
    
    // Key Key
    inFile >> lastName >> firstName;

    int i = 1;
    // Quiz
	for(i = 1; i <= numQuiz; i++)
	{
		inFile >> quiz;
		sumQuiz += quiz;
	}
	
	// Homework
	for(i = 1; i <= numHomework; i++)
	{
		inFile >> homework;
		sumHomework += homework;
	}
	
	// Exam
	for(i = 1; i <= numExam; i++)
	{
		inFile >> exam;
		sumExam += exam;
	}
    
    total = sumQuiz + sumHomework + sumExam;
    totalK = total;
    average = (float)total/totalK * 100.0;
    
    // Print out Key Key
    outFile << setw(3) << " " << setw(12) << lastName << setw(7) << firstName
    		<< setw(6) << sumQuiz << setw(6) << sumHomework << setw(6) << sumExam
    		<< setw(7) << total << setw(9) << setprecision(2) << average << endl;
    		
    outFile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----"
            << setw(6) << "----" << setw(6) << "---" << setw(6) << "----"
            << setw(7) << "-----" << setw(9) << "-------" << setprecision(0) << endl;
       
    inFile.ignore(INT_MAX, '\n');     
    sumQuiz = 0;
    sumHomework = 0;
    sumExam = 0;
// *****************************************************************************   		      
    // Students
    int student = 1;
    inFile >> lastName;
    while(!inFile.eof())
    {
    	inFile >> firstName;
    	
    	if(lastName.length() > 10)
    		lastName = lastName.substr(0, 10);
    	if(firstName.length() > 5)
    		firstName = firstName.substr(0, 5);
    	
    	sumQuiz = 0;
		sumHomework = 0;
		sumExam = 0;
		average = 0.0;
		
    	// Quiz
    	for(i = 1; i <= numQuiz; i++)
    	{
    		inFile >> quiz;
    		if(quiz < 0)
    			quiz = 0;
    		sumQuiz += quiz;
    	}
    	
    	// Homework
    	for(i = 1; i <= numHomework; i++)
    	{
    		inFile >> homework;
    		if(homework < 0)
    			homework = 0;
    		sumHomework += homework;
    	}
    	
    	// Exam
    	for(i = 1; i <= numExam; i++)
    	{
    		inFile >> exam;
    		if(exam < 0)
    			exam = 0;
    		sumExam += exam;
    	}
    	
    	total = sumQuiz + sumHomework + sumExam;		// total
    	
    	outFile << setw(3) << student << setw(12) << lastName << setw(7) << firstName
    		<< setw(6) << sumQuiz << setw(6) << sumHomework << setw(6) << sumExam
    		<< setw(7) << total << setw(9);
    	
    	average = (float)total/totalK * 100.0;   			// average
    	outFile << setprecision(2) << average << endl; 
    	classavg += average;
    	
    	inFile.ignore(INT_MAX, '\n');
    
    	student++;
    	inFile >> lastName;
    }
    	outFile << setw(3) << "-" << setw(12) << "----------" << setw(7) << "-----"
            << setw(6) << "----" << setw(6) << "---" << setw(6) << "----"
            << setw(7) << "-----" << setw(9) << "-------" << endl;
        
        classavg = classavg/(student-1);
        
        outFile << "Class Average = " << classavg << endl;
            
    return 0;
}

