/*
Program by Katie Clarke, Andres Orozco, Isabel Chavez, and Logan Wheeler.
This is an implementation of the Project 1 instructions to create a parking lot management system.
*/

#include <iostream>
#include <string>
#include <fstream>
#include <limits>
#include "admin.h"
#include "admins.h"
#include "manager.h"
#include "managers.h"
#include "user.h"
#include "users.h"
#include "tickets.h"

using namespace std;

//function declarations
void testInput(ifstream& ifile, string filename);
void printLots(int i, int regSpots, int motorcycleSpots, int disabilitySpots, int firstRow, double rowsLeft, int finalRowCount);

int main() {

   //main variables
   string filename; //stores user-inputted file name (initial)
   string adminfile;
   string managementfile;
   string userfile;


   //for parking lot display
   int numLots;
   int regSpots;
   int motorcycleSpots;
   int disabilitySpots;
   int firstRow; //motorcycle + disability; gives a count guide for the subsequent rows
   double rowsLeft; //how many rows of R to print
   int finalRowCount = 0;

   //temps for adding new individuals to vectors
   Admins admins;
   Admin* temp;
   Managers managers;
   Manager* temp2;
   Users users;
   User* temp3;
    tickets tickets;

   //fstream variables
   ifstream ifile;
   ofstream ofile;

   //variables for login and user input
   int id;
   string password;
   string name;
   int input = 0;
   bool userFound = false; //to consolidate user menu
   //Used to store ser input without messing up orginal login variables ANDRES
   string tempName;
   string tempPass;
   int tempID;
   int tempLoc;


   //get input file
   cout << "Enter name of input file: ";
   getline(cin, filename);

   //open file and test
   ifile.open(filename);
   if(!ifile.is_open()) {
      cout << "File not opened or does not exist. Terminating program.\n";
      exit(0);
   }//end of if


   //read in info from input file, output lots
   ifile >> numLots;
   testInput(ifile, filename);
   for(int i = 0; i < numLots; i++) { //will read in and output numLots lots
      //get lot info
      ifile >> regSpots;
      testInput(ifile, filename);
      ifile >> motorcycleSpots;
      testInput(ifile, filename);
      ifile >> disabilitySpots;
      testInput(ifile, filename);
      if(motorcycleSpots == 0 && disabilitySpots == 0) {
         firstRow = regSpots;
      }//end of if
      else {
         firstRow = motorcycleSpots + disabilitySpots;
      }//end of else
      printLots(i, regSpots, motorcycleSpots, disabilitySpots, firstRow, rowsLeft, finalRowCount);
   }//end of for loop

   //clear the buffer from the ints
   ifile.ignore(numeric_limits<streamsize>::max(), '\n');

   getline(ifile, adminfile);
   getline(ifile, managementfile);
   getline(ifile, userfile);

   string str = "\r";
   //if adminfile, managamentfile, userfile contain "\r", get rid of it
   if(adminfile.find(str) != string::npos) { //then "\r" is in it.
      adminfile.erase(adminfile.size() - 1);
   }//end of if
   if(managementfile.find(str) != string::npos) {
      managementfile.erase(managementfile.size() - 1);
   }//end of if
   if(userfile.find(str) != string::npos) {
      userfile.erase(userfile.size() - 1);
   }//end of if


   ifile.close();
   if(ifile.is_open()) {
      cout << "Input file could not close. Terminating program.\n";
      exit(0);
   }//end of if

   admins.loadInfo(adminfile, temp);
   managers.loadInfo(managementfile, temp2);
   users.loadInfo(userfile, temp3);

   cout << "All Administrative Employee Information\n---------------------------------------\n";
   cout << "             Name                ID\n";
   cout << "-----------------------------------\n";
   admins.printInfo();
   cout << endl;

   cout << "------All Employee Information-----\n-----------------------------------\n";
   cout << "             Name                ID\n";
   cout << "-----------------------------------\n";
   managers.printInfo();
   cout << endl;

   cout << "-----------------------------------------------------All User Information-------------------------------------------------------\n--------------------------------------------------------------------------------------------------------------------------------\n";
   cout << "             Name                          ID               Make               Model                 Year           Plate Number\n";
   cout << "--------------------------------------------------------------------------------------------------------------------------------\n";
   users.printInfo();
   cout << endl << endl;

   while(input != 3) {
      cout << "Type in 1 to log into the system.\nType in 2 to register to the system.\nType in 3 to exit the system.\nOption: ";
      cin >> input;

      //test input
      while(cin.fail() || input < 0 || input > 3) { //until user enters a number 1-3
         cout << "Invalid input. Enter a number 1-3: ";
         cin.clear(); //clear fail
         cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush input buffer
         cin >> input; //user re-enters input
      }//end of while

      if(input == 1) {
         //enter login info
         cout << "Enter id: ";
         cin >> id;
         while(cin.fail()) {
            cout << "Invalid input. Enter id: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush input buffer
            cin >> id;
         }//end of while
         cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush input buffer
         cout << "Enter password: ";
         getline(cin, password);

         //while id and password are not in any of the lists
         while(!admins.adminSearch(id, password) && !managers.managerSearch(id,password) && !users.userSearch(id, password)) {
            cout << "ID or password is incorrect. Enter your credentials again.\n\n";
            cout << "Enter id: ";
            cin >> id;
            while(cin.fail()) {
               cout << "Invalid input. Enter id: ";
               cin.clear();
               cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush input buffer
               cin >> id;
            }//end of while
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush input buffer
            cout << "Enter password: ";
            getline(cin, password);
         }//end of while loop

         if(admins.adminSearch(id, password) || managers.managerSearch(id, password) || users.userSearch(id, password)) {
            //if present in admin or managament or user search functions then:
            cout << "\nLogin successful.\n";

            if(admins.adminSearch(id, password)) {
      		 //admin menu and functionality
               input = 0;
	    do{
		input = 0;
		cout<<"Select 1 to add new administrative employee"<<endl;
                cout<<"Select 2 to remove new administrative employee"<<endl;
                cout<<"Select 3 to view all administrative employee information (excluding password)"<<endl;
                cout<<"Select 4 to search information for a specific administrative employee"<<endl;
                cout<<"Select 5 to change password of the account that you are currently logged in"<<endl;
                cout<<"Select 6 to add new management employee"<<endl;
                cout<<"Select 7 to remove new management employee"<<endl;
                cout<<"Select 8 to view all management employee information (excluding password)"<<endl;
                cout<<"Select 9 to search information for a specific management employee"<<endl;
                cout<<"Select 10 to remove a user"<<endl;
                cout<<"Select 11 to view all user information (excluding password)"<<endl;
                cout<<"Select 12 to search information for a specific user"<<endl;
                cout<<"Select 13 to view appeal information"<<endl;
                cout<<"Select 14 to process an appeal"<<endl;
                cout<<"Select 15 to log out of account"<<endl;

		//cin.clear();
		//cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin >> input;
			switch(input)
			{
			case 1:
				cout<<"Enter new admin name: ";
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				getline(cin,tempName);
				cout<<"Enter new admin password: ";
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');
				getline(cin,tempPass);
				cout<<"Enter new admin ID: ";
				//cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> tempID;
				cout<<name<<" "<<id<<" "<<password<<endl;
				admins.addAdmin(tempID,tempName,tempPass);
				cout<<"Admin has been added"<<endl;
				break;
			case 2:
				cout<<"Enter id of admin to remove: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> tempID;
				admins.removeAdmin(tempID);
				break;
			case 3:
				admins.printInfo();
				break;
			case 4:
				cout<<"Enter the id of admin: ";
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> tempID;
				tempLoc = admins.findLoc(tempID);
				admins.printAdmin(tempLoc);
				break;
			case 5:
				//Assuming id and password have not changed elsewhere, should be ok
				admins.changePassword(id);
				break;
			case 6:
                                cout<<"Enter new manager name: ";
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                getline(cin,tempName);
                                cout<<"Enter new manager password: ";
                               // cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                getline(cin,tempPass);
                                cout<<"Enter new manager ID: ";
                                cin.clear();
                                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin >> tempID;
				managers.addManager(tempID,tempName,tempPass);
				cout<<"Manager has been added"<<endl;
				break;
			case 7:
				cout<<"Enter id of manager to remove: ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin >> tempID;
                                managers.removeManager(tempID);
				break;
			case 8:
				managers.printInfo();
				break;
			case 9:
				cout<<"Enter the id of manager: ";
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                cin >> tempID;
				tempLoc = managers.findLoc(tempID);
                                managers.printManager(tempLoc);
				break;
			case 10:
				cout<<"Enter the user's id: "<<endl;
				cin.clear();
				cin>>tempID;
				users.removeUser(tempID);
				break;

			case 11:
				users.printInfo();
				break;

			case 12:
				cout<<"Enter the user's id: "<<endl;
				cin.clear();
				cin>>tempID;												                                		     tempLoc = users.findLoc(tempID);
				users.printUser(tempLoc);
				break;
			case 13:
				//For BONUS
                    int apuid;
                    cout << "Enter user id to see appeal information \n";
                    cin.clear();
                    cin >> apuid;
                    tickets.Adminviewanappl(apuid);
				break;
			case 14:
				//For BONUS
                    cout << "Enter user id to respond to appl \n";
                    cin.clear();
                    cin >> apuid;
                    tickets.Adminrepsonse(apuid);
				break;
			case 15: //EXIT
				cout<<"Loging out"<<endl;
				break;
			default:
				cout<<"Enter valid input"<<endl;
				break;

			}
	    }while(input != 15);

	    }//end of if
            else if(managers.managerSearch(id, password)) {
	    do{
		 cout<<"Select the following option for a particular task."<<endl;
		 cout<<"Select 1 to remove a user."<<endl;
		 cout<<"Select 2 to view all user information."<<endl;
		 cout<<"Select 3 to search information for a specific user."<<endl;
		 cout<<"Select 4 to issue a ticket."<<endl;
		 cout<<"Select 5 to view all ticket information."<<endl;
		 cout<<"Select 6 to view a specific ticket information in detail."<<endl;
		 cout<<"Select 7 to remove a specific ticket information."<<endl;
		 cout<<"Select 8 to change password."<<endl;
		 cout<<"Select 9 to Log out."<<endl;
		 cout<<"Option: ";

		 cin>>input;

		 switch(input)
		{
			case 1: 
				cout<<"Enter the user's id: "<<endl;
				cin.clear();
				cin>>tempID;
				users.removeUser(tempID);
				break;

			case 2: 
				users.printInfo();
				break;

			case 3:
				cout<<"Enter the user's id: "<<endl;
				cin.clear();
				cin>>tempID;
				tempLoc = users.findLoc(tempID);
				users.printUser(tempLoc);
				break;

			case 4: 
				//Milestone 4
                tickets.insertticket();
                cout << "Inserted ticket! \n";
				break;
			
			case 5:
				//Milestone 4
                tickets.printalltickets();
				break;

			case 6:
                int tid;
				//Milestone 4
                cout << "enter ticket id \n";
                cin >> tid;
                tickets.specificticket(tid);
				break;

			case 7:
				//Milestone 4 Remove ticket
				cout<<"Enter ticket id to remove \n"<<endl;
                cin.clear();
                cin >> tid;
                tickets.removeticket(tid);
				break;

			case 8:
                managers.changePassword(id);
				break;

			default: 
				cout<<"Enter a valid option."<<endl;
				break;
			}
	   	}while(input != 9);

            }//end of else if
            else {
               userFound = true;
            }//end of else
         }//end of if

      }//end of if

      if(input == 2 || userFound) {
        if(input == 2) {
           users.RegisterUser(temp3);
        }//end of if
        userFound = false; //so if the user logs out and someone logs back in as another type, it will not display the user menu when they exit.
       //user menu and functionality

	do
	{
		cout<<"Select the following option for a particular task."<<endl;
		cout<<"Select 1 to change password."<<endl;
		cout<<"Select 2 to change vehicle information."<<endl;
		cout<<"Select 3 to view vehicle information."<<endl;
		cout<<"Select 4 to view all ticket information."<<endl;
		cout<<"Select 5 to pay a ticket amount."<<endl;
		cout<<"Select 6 to appeal against a ticket."<<endl;
		cout<<"Select 7 to view appeal information."<<endl;
		cout<<"Select 8 to log out."<<endl;
		cout<<"Option: ";

		cin>>input;

		switch(input)
		{
			case 1:
				users.changePassword(id);
				break;

			case 2: 
				users.changeVehicleInfo(id);
				break;

			case 3: 
				tempLoc = users.findLoc(id);
				users.printVehicle(tempLoc);
				break;

			case 4:
                //milestone 4
                tickets.userid=id;
                tickets.viewyourticket();
				break;

			case 5:
                //milestone 4
                tickets.userid=id;
                tickets.payticket();
				break;

			case 6: 
				//Milestone 4
                tickets.applticket();
				break;

			case 7:
				//Milestone 4
                tickets.viewyourappl();
				break;

			case 8:
                
				cout<<"Logging out."<<endl;
				break;

			default: 
				cout<<"Enter a valid option."<<endl;
				break;
			}
		}while(input != 8);
      }//end of if
   }//end of while

   cout << "\nExiting system.\n";

   //save info to files and cleanup (these functions will delete the temps created in main)
   admins.saveInfo(adminfile);
   managers.saveInfo(managementfile);
   users.saveInfo(userfile);
}//end of main



//MAIN.CPP FUNCTIONS
void testInput(ifstream& ifile, string filename) {
  while(ifile.fail()) {
     cout << "Invalid character in input file. Cannot read info. Closing file and terminating program.\n";
     ifile.clear();
     ifile.close();
     exit(0);
  }//end of while
}//end of testInput


void printLots(int i, int regSpots, int motorcycleSpots, int disabilitySpots, int firstRow, double rowsLeft, int finalRowCount) {
      //print lot info
      cout << "Parking lot #" << i + 1 << ":\n";
      cout << "Number of parking spaces: " << regSpots + firstRow << endl;
      cout << "Number of regular parking spaces: " << regSpots << endl;
      cout << "Number of motorcycle parking spaces: " << motorcycleSpots << endl;
      cout << "Number of disability parking spaces: " << disabilitySpots << endl;
      cout << "Parking space layout is shown below.\n";

      //print lot layout
      //FIRST ROW DASHES ABOVE
      cout << "-----"; //first space in each row will have 5 -'s above it, rest will have 4
      for(int i = 0; i < firstRow - 1; ++i) {
         cout << "----";
      }//end of for loop
      cout << endl;

      //FIRST ROW LETTERS
      for(int i = 0; i < motorcycleSpots; i++) {
         cout << "| M ";
      }//end of for loop
      if(disabilitySpots == 0) { //if no disability spots, end the row
         cout << "|\n";
      }//end of if
      else {
         for(int i = 0; i < disabilitySpots; i++) {
            cout << "| D ";
            if(i == (disabilitySpots - 1)) { //if on last disability spot, end the row
               cout << "|\n";
            }//end of if
         }//end of for loop
      }//end of else

      //FIRST ROW DASHES BELOW/SECOND ROW ABOVE
      cout << "-----"; // 5 -'s below first space, rest will have 4
      for(int i = 0; i < firstRow - 1; i++) {
         cout << "----";
      }//end of for loop
      cout << endl;

      //REGULAR ROW LETTERS
      if(firstRow != 0) {
         rowsLeft = static_cast<double>(regSpots) / firstRow;
      }//end of if
      else {
         rowsLeft = regSpots / 9.0; //max of 9 regular spots in first row
                                    //this is just arbitrary so there isn't a huge row of R's if there are 0 motor. and dis. spots
      }//end of else

      int count = 0;
      for(int i = 0; i < rowsLeft - 1; i++) { //for each row left, print R's
         if(count < firstRow) {
            while(count < firstRow) {
               cout << "| R ";
               count++;
               if(regSpots < firstRow) { //if the second row is not full, then it is the final row.
                  finalRowCount++;
               }//end of if
            }//end of while

            //print whole row of dashes
            cout << "|\n-----";
            for(int i = 0; i < firstRow - 1; i++) {
               cout << "----";
            }//end of for loop
            cout << endl;
         }//end of if

         if(count >= firstRow && count < regSpots) { //any rows that are entirely full, but are not the last row
            finalRowCount = 0; //resets each time so that the final row count will be correct to print correct # dashes
            while(count >= firstRow && count < regSpots) {
               cout << "| R ";
               count++;
               finalRowCount++;
            }//end of while
            if(count < regSpots) {
               cout << "|\n-----";
               for(int i = 0; i < firstRow - 1; i++) {
                  cout << "----";
               }//end of for loop
               cout << endl;
            }//end of if
         }//end of if

         if(count == regSpots) {
            cout << "|\n";
            cout << "-----";
            for(int i = 0; i < finalRowCount - 1; i++) {
               cout << "----";
            }//end of for loop
            cout << endl;
         }//end of if

      cout << endl;
      }//end of for loop
}//end of printLots
