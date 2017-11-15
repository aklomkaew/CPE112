//******************************************************************
// Program: project 3 source code for modification
// Name: Atchima Klomkaew                                   
// CPE112, Lab Section 3                     
// Project due date: 9/4/15                      
// This program has two parts associated with it.  The students
// modify the source code to improve upon the existing code and 
// to learn some aspects of writing C++ code.
//******************************************************************
// Put all preprocessor directives here
// The following are the necessary header files
#include <iostream> // header file for standard input output 

#include <iomanip>

using namespace std;

/* This function calculates the pay in one of two ways */
/* depending on the hours worked			*/
void CalcPay( float, float, float& );

// Global constant declarations
const float MAX_HOURS = 40.0;   // Maximum normal work hours
const float OVERTIME = 1.5;     // Overtime pay rate factor

int main()
{
    // ################################################
    // variable Declarations for Part I of the program
    // ################################################
    float payRate;       // Employee's pay rate
	float hours;         // Hours worked
	float wages;         // Wages earned based on pay rate and hours worked.
	int   empNum;        // Employee ID number
	float overWages;	// Amount of the wages that is overtime
	float regWages;		// Amount of wages that is regular pay
	

	
	// ################################################
	// ####### Start of part 1 of the program  ########
	// ################################################
	// This part of the program is a wage calculation program
 
	
    cout << "\n----------------------------------\n";
	cout << "===> Start of Part I output <===\n";
    cout << "----------------------------------\n\n";

	// prompt for and read in the information for an employee
	// information read is the employee number, their pay rate 
	// and the number of hours they have worked for the week.
	cout << "Enter the employee number: "; 
    cin >> empNum; 
    cout << empNum << endl;                         
    cout << "Enter pay rate: ";            
    cin >> payRate; 
    cout << payRate << endl;                      
    cout << "Enter hours worked: ";      
    cin >> hours;
    cout << hours << endl;  
    cout << endl; // print out a blank line

	

	CalcPay(payRate, hours, wages);         // call the function that Compute wages

	// output the employee information and the results
	// note how the output statement is broken up into multiple lines so that
	// the cout statement is not too long.

	if (hours < MAX_HOURS)
	{
		regWages = wages;
		overWages = 0.0;
	}
	else
	{
		// calculate the amount of the wages that comes from
		// regular pay, and the amount that comes from overtime.
		regWages = payRate * 40.0;
		overWages = wages - regWages;
	}	// end of if then else statement

	cout << setprecision(2) << fixed;
	// break up long cout statement into three lines. Break at insertion op.
	cout << setw(20) << "Employee: " << empNum << endl
		 << setw(20) << "Pay Rate: " << payRate << endl
		 << setw(20) << "Hours: " << hours << endl;
	cout << setw(21) << "Regular Wages: $" << regWages << endl;
	cout << setw(21) << "Overtime Wages: $" << overWages << endl;
	cout << setw(21) << "Total Wages: $" << wages << endl;
	
    // keep the following cout statement
	cout << "\n===> End of part I output <===\n";
    cout << "----------------------------------\n\n";

	// ################################################################
	// ################################################################
	// ###########  END of the first part of the program ##############
	// ################################################################
	// ################################################################

	// ############################################################
	// ################### start of second part of the program ####
	// ############################################################
	// This part of the program calculates the total price of parts 
	// entered and itemizes the bill in the output

	// ################################################
    // variable Declarations for Part II of the program
   	int   partNumber;		// Unique part number
	int   quantity;		// Quantity of parts ordered
	float unitPrice;		// Price per part
	float partsPrice;		// Price of these particular parts
	float totalPrice;		// Total price of all ordered parts

	cout << "----------------------------------\n";
	cout << "===> Start of Part II output <===\n";
    cout << "----------------------------------\n";

	// Set up floating-point output format	
	
	cout << fixed << showpoint << setprecision(2);

	totalPrice = 0.0;		// Initialize summing variable to zero

	cout << "Enter the part number (or a negative number to quit): ";
	cin >> partNumber;     // Read in the first part number
	cout << partNumber << endl;

	while(partNumber >= 0 && cin)	// While part number and input stream valid
	{								// Start with the while loop
	
	cout << "Enter the quantity of this part ordered: "; // Prompt
	cin >> quantity;
	cout << quantity << endl;

	cout << "Enter the unit price for this part: ";      // Prompt
	cin >> unitPrice;
	cout << unitPrice << endl;

	partsPrice = quantity * unitPrice;
	cout << "Part " << partNumber                      // Echo print
		<< ", quantity " << quantity
		<< ", at $" << unitPrice << " each totals $"
		<< partsPrice << endl;

	totalPrice = totalPrice + partsPrice;
	
	cout << endl << "Enter the part number (or a negative number to quit): ";
	cin >> partNumber;	// read in the next part number
	cout << partNumber << endl;
	}	// End while(partNumber >= 0)

	cout << endl << "Total price of all parts ordered is: $";
	cout << totalPrice << endl << endl;
	
	cout << "\n===> End of part II output <===\n";
    cout << "----------------------------------\n\n";
	return 0;     // Indicate successful completion of the program
}                                           

//******************************************************************
//******************************************************************
//     All function definitions are placed below main
//******************************************************************
//******************************************************************

void CalcPay( /* in */  float  payRate,     // Employee's pay rate
		/* in */  float  hours,       // Hours worked
		/* out */ float& wages )      // Wages earned

// CalcPay computes wages from the employee's pay rate
// and the hours worked, taking overtime into account

{
	if (hours > MAX_HOURS)                     // Is there overtime?
		wages = (MAX_HOURS * payRate) +        // Yes
			(hours - MAX_HOURS) * payRate * OVERTIME;
	else
		wages = hours * payRate;               // No
}
