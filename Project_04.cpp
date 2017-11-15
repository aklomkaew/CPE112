// ****************************************
// Program Title: Sample header file
// Project File: Project_04.cpp
// Name: Atchima Klomkaew
// Course Section: CPE-112-02
// Lab Section: 3
// Due Date: 09/11/15
// program description: Description of
// What the program does.
// ****************************************
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double principal;           	 // principal or starting balance
    double finalBalance;        	// final balance
    double simpleIR;            	// simple interest rate
    double year;                	// number of years invested
    double effectiveIR;            // effective simple interest rate
    double balanceEff;            // final balance using effective simple interest rate
   
    // Asking for the user's inputs
    cout << "Input the starting balance: ";
    cin >> principal;
    cout << principal << endl;		// echo
    cout << "Input the interest rate (Ex: 5 for 5%): ";
    cin >> simpleIR;
    cout << simpleIR << endl;		// echo
    cout << "Input the number of years: ";
    cin >> year;
    cout << year << endl;
   
    // Setting precision
    cout << setprecision(2) << fixed;
    // Outputing the user's input
    cout << "For a principal of $" << principal;
    cout << "\nat an interest rate of " << simpleIR << "%";
    cout << "\nfor a period of " << year << " years,";
    cout << "\nthe final account balance would be:" << endl;
         
    // Calculate final balance for simple interest
    finalBalance = principal * (1.00 + (year * (simpleIR/100.00)));
   
    // Output the final balance for Simple Interest
    cout << "Simple Interest:" << endl;
    cout << "\tBalance = $" << finalBalance << endl << endl;
   
    // setting simple interest rate to be in a decimal form (/10)
    simpleIR = simpleIR/100.00;
   
/* *************************************************************************** */

    // Calculate Compounded Monthly
    // final balance
    finalBalance = principal * pow((1.00 + (simpleIR/12.00)), (12.00 * year));
   
    // Calculate the effective simple interest rate
    effectiveIR = (pow((1.00 + (simpleIR/12.00)), (12.00*year)) - 1.00)/year;
   
    // Calculate the balance using the effective simple interest rate
    balanceEff = principal * (1.00 + (year * effectiveIR));
   
    // setting effectiveIR to be in a percentage form
    effectiveIR = effectiveIR * 100.00;
   
    //Outputing information for Compounded Monthly
    cout << "Compounded Monthly:" << endl;
    cout << "\tBalance = $" << finalBalance << endl
         << "\tThe Effective Simple Interest Rate: " << effectiveIR << "%" << endl
         << "\tBalance using Simple Interest at the Effective Rate = $" << balanceEff << endl << endl;
         
/* *************************************************************************** */

    // Calculate Compounded Daily
    // final balance
    finalBalance = principal * pow((1.00 + (simpleIR/365.00)), (365.00 * year));
   
    // Calculate the effective simple interest rate
    effectiveIR = (pow((1.00 + (simpleIR/365.00)), (365.00*year)) - 1.00)/year;
   
    // Calculate the balance using the effective simple interest rate
    balanceEff = principal * (1.00 + (year * effectiveIR));
   
    // setting effectiveIR to be in a percentage form
    effectiveIR = effectiveIR * 100.00;
   
    //Outputing information for Compounded Daily
    cout << "Compounded Daily:" << endl;
    cout << "\tBalance = $" << finalBalance << endl
         << "\tThe Effective Simple Interest Rate: " << effectiveIR << "%" << endl
         << "\tBalance using Simple Interest at the Effective Rate = $" << balanceEff << endl << endl;
         
/* *************************************************************************** */

    // Calculate Compounded Continuously
    // final balance
    finalBalance = principal * exp(simpleIR * year);
   
    // Calculate the effective simple interest rate
    effectiveIR = (exp(simpleIR*year)-1.00)/year;
   
    // Calculate the balance using the effective simple interest rate
    balanceEff = principal * (1.00 + (year * effectiveIR));
   
    // setting effectiveIR to be in a percentage form
    effectiveIR = effectiveIR * 100.00;
   
    //Outputing information for Compounded Daily
    cout << "Compounded Continuously:" << endl;
    cout << "\tBalance = $" << finalBalance << endl
         << "\tThe Effective Simple Interest Rate: " << effectiveIR << "%" << endl
         << "\tBalance using Simple Interest at the Effective Rate = $" << balanceEff << endl;
   
    return 0;
}
