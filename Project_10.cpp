// ****************************************
// Program Title: Project_10
// Project File: Project_10.cpp
// Name: Atchima Klomkaew
// Course Section: CPE-112-02
// Lab Section: 3
// Due Date: 11/13/15
// program description: Description of
// What the program does.
// ****************************************
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <climits>

using namespace std;

// struct declaration
struct subscriberName
{
    string firstName, lastName;
    int customerID;
};

struct address
{
    string street, city, state;
    int zip;
};

struct Date
{
    string month;
    int day, year;
};

struct renewal_info
{
    int monthLeft;
    Date dt;
    address addr;
    subscriberName subs;
};

void openInFile(ifstream&, string&);
void openOutFile(ofstream&, string&);
void storeInfo(ifstream&, renewal_info&);
void writeSubRecord(ofstream&, renewal_info&);
void fileReadError(int&);
void fileEmpty(ofstream&);

int main()
{
    // struct
    renewal_info renew;
    
    // declare counters
    int subscribers = 0;
    int expsub = 0;
    ifstream inFile;
    ofstream outFile;
    string infileName, outfileName;
    bool cusFail = false;
    
    cout << endl;
    
    openInFile(inFile, infileName);
    openOutFile(outFile, outfileName);
    
    // Priming read
    inFile >> renew.subs.firstName
           >> renew.subs.lastName
           >> renew.subs.customerID;
    inFile.ignore(INT_MAX, '\n');
    subscribers++;
    
    if(inFile.fail() && inFile.eof())
        fileEmpty(outFile);    
    else if(inFile.fail() && !inFile.eof())
    {
        fileReadError(subscribers);
    	//cusFail = true;
    	exit(1);                // exit program?
    }
        
    // Start storing info
    while(inFile && !inFile.eof())
    {	
        // calling function to store information
        storeInfo(inFile, renew);
        
        // Check fail state
        if(inFile.fail() && !inFile.eof())
        {
            fileReadError(subscribers);
            cusFail = true;
         	break;
        }
    	
		if(renew.monthLeft == 0)
		{
   			expsub++;
   			writeSubRecord(outFile, renew);
   		}
   		
		subscribers++;
		
		// Read the next customer’s information
		inFile >> renew.subs.firstName
		   >> renew.subs.lastName
		   >> renew.subs.customerID;
		inFile.ignore(INT_MAX, '\n');
		
		// Check fail state
        if(inFile.fail() && !inFile.eof())
        {
            fileReadError(subscribers);
            cusFail = true;
         	break;
        }
    }
    
        cout << endl << string(47, '-') << endl
             << "Number of subscribers processed: " << subscribers-1 << endl;
        cout << "The number of expired subscriptions is: " << expsub << endl
             << string(47, '-') << endl << endl;
   
	// Close files
	inFile.close();
	outFile.close();
         
    return 0;
}

// **************************(Functions below)*********************************

void storeInfo(ifstream& inFile, renewal_info& renew)
{    
    cout << "====> Processing Customer ID: " << renew.subs.customerID << endl;

    // Read file
    // Address Struct
    getline(inFile, renew.addr.street, '\n');
    getline(inFile, renew.addr.city, '\n');
    getline(inFile, renew.addr.state, '\n');
    inFile >> renew.addr.zip;

    // renewal_info Struct
    inFile >> renew.monthLeft;
    inFile >> renew.dt.month >> renew.dt.day >> renew.dt.year;
    inFile.ignore(INT_MAX, '\n');     
}

void openInFile(ifstream& inFile, string& ifilename)
{
    // Priming read
    // Prompt user for input file
    cout << "Enter name of input file or Control-C to quit program: ";
    cin >> ifilename;
    cout << ifilename << endl << endl;                // Echo
    inFile.open(ifilename.c_str());
    
    while(inFile.fail())
    {
        cout << string(15, '*') << " File Open Error " << string(15, '*')
             << "\n==> Input file failed to open properly!!"
             << "\n==> Attempted to open file: " << ifilename
             << "\n==> Please try again..." << endl;
        cout << string(47, '*') << endl << endl;
        
        // Clear stream
        inFile.clear();
        
        // Prompt user for input file
        cout << "Enter name of input file or Control-C to quit program: ";
        cin >> ifilename;
        cout << ifilename << endl << endl;
        inFile.open(ifilename.c_str());
    }
}

void openOutFile(ofstream& outFile, string& ofilename)
{
    // Priming read
    // Prompt user for output file
    cout << "Enter name of output file or Control-C to quit program: ";
    cin >> ofilename;
    cout << ofilename << endl << endl;                // Echo
    outFile.open(ofilename.c_str());
    
    while(outFile.fail())
    {
        cout << string(15, '*') << " File Open Error " << string(15, '*')
             << "\n==> Output file failed to open properly!!"
             << "\n==> Attempted to open file: " << ofilename
             << "\n==> Please try again..." << endl;
        cout << string(47, '*') << endl << endl;
        
        // Clear stream
        outFile.clear();
        
        // Prompt user for output file
        cout << "Enter name of output file or Control-C to quit program: ";
        cin >> ofilename;
        cout << ofilename << endl << endl;
        outFile.open(ofilename.c_str());
    }
}

void writeSubRecord(ofstream& outFile, renewal_info& renew)
{
    // Print out each customer’s information to outFile
    outFile << string(55, '*') << endl
            << renew.subs.firstName << " " << renew.subs.lastName
            << "(" << renew.subs.customerID << ")" << endl
        	<< renew.addr.street << endl
        	<< renew.addr.city << ", " << renew.addr.state
        	<< " " << renew.addr.zip << endl
        	<< "The last renewal notice was sent on " << renew.dt.month
        	<< " " << renew.dt.day << ", " << renew.dt.year << endl
        	<< string(55, '*') << endl << endl;
}

void fileReadError(int& sub)
{
    cout << endl << string(15, '*') << " File Read Error " << string(15, '*') << endl;
    cout << "==> Error occurred reading file information\n"
         << "==> for subscriber record #" << sub << endl
         << "==> Processing of file terminated" << endl;
    cout << string(47, '*') << endl;
    
    //exit(1);                // exit program
}

void fileEmpty(ofstream& outFile)
{
    cout << "===> Input file is empty.  Program terminated" << endl << endl;
        outFile << string(52, '-') << endl
                << "==> The input file does not contain any information.\n"
                << string(52, '-') << endl;
    exit(1);
}
