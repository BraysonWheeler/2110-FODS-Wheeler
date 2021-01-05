#include "user.h"
#include "users.h"

void Users::loadInfo(string file, User* temp) {
   ifstream ifile;
   ifile.open(file);
   if(!ifile.is_open()) {
      cout << "File not opened. Terminating program.\n";
      exit(0);
   }//end of if

   string thing;
   string name;
   string strid;
   int id;
   string pass;
   string make;
   string model;
   string year;
   string plate;

   while(getline(ifile, thing, ',')) { //eof
      name = thing;
      getline(ifile, strid, ',');
      id = stoi(strid);
      getline(ifile, pass, ',');
      getline(ifile, make, ',');
      getline(ifile, model, ',');
      getline(ifile, year, ',');
      getline(ifile, plate); //end row

      temp = new User(name, id, pass, make, model, year, plate);
      userList.push_back(temp);
   }//end of while

   ifile.close();
   if(ifile.is_open()) {
      cout << "User file not closed. Terminating program.\n";
   }//end of if
}//end of loadInfo


void Users::saveInfo(string file) {
     ofstream ofile;
     ofile.open(file);
     if(!ofile.is_open()) {
        cout << "Output file could not open. Terminating program.\n";
        exit(0);
     }//end of if

     //save user info to output file
     for(int i = 0; i< userList.size(); i++) {
        ofile << userList.at(i)->getName() << ",";
        ofile << userList.at(i)->getID() << ",";
        ofile << userList.at(i)->getPassword() << ",";
        ofile << userList.at(i)->getMake() << ",";
        ofile << userList.at(i)->getModel() << ",";
        ofile << userList.at(i)->getYear() << ",";
        ofile << userList.at(i)->getPlate() << endl;
     }//end of for loop
     ofile.close();

     if(ofile.is_open()) {
        cout << "User output file could not close. Terminating program.\n";
        exit(0);
     }//end of if

     //cleanup
     for (auto iterator = userList.begin(); iterator != userList.end(); ++iterator) {
        delete *iterator;
     }//end of for loop
     userList.clear();
}//end of saveInfo


void Users::RegisterUser(User* &temp) {
   string name;
   int id;
   string pass;
   string make;
   string model;
   string year;
   string plate;

   //last thing entered was a number, so:
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush input buffer

   cout << "Enter name: ";
   getline(cin, name);
   cout << "Enter id: ";
   cin >> id;
   while(cin.fail()) { //check id input
      cout << "Invalid input for ID. Enter a number: ";
      cin.clear();
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush input buffer
      cin >> id;
   }//end of while
   cin.ignore(numeric_limits<streamsize>::max(), '\n'); //flush input buffer
   cout << "Create password: ";
   getline(cin, pass);
   cout << "Now enter your vehicle information...\nEnter vehicle make: ";
   getline(cin, make);
   cout << "Enter vehicle model: ";
   getline(cin, model);
   cout << "Enter vehicle year: ";
   getline(cin, year);
   cout << "Enter vehicle plate number: ";
   getline(cin, plate);

   temp = new User(name, id, pass, make, model, year, plate);
   userList.push_back(temp);
   cout << "\nRegistration is complete.\n\n";
}//end of RegisterUser


void Users::printUser(int i) {
   cout << left << setw(37) << userList.at(i)->getName();
   cout << left << setw(8) << userList.at(i)->getID();
   cout << right << setw(20) << userList.at(i)->getMake();
   cout << right << setw(20) << userList.at(i)->getModel();
   cout << right << setw(20) << userList.at(i)->getYear();
   cout << right << setw(20) << userList.at(i)->getPlate() << endl;
}//end of printUser


void Users::printInfo() {
   for(int i = 0; i < userList.size(); i++) {
      printUser(i);
   }//end of for loop
}//end of printInfo


bool Users::userSearch(int id, string password) {
   bool found = false;
   for(int i = 0; i < userList.size(); i++) {
      if(userList.at(i)->getID() == id && userList.at(i)->getPassword().compare(password) == 0) {
         found = true;
         break;
      }//end of if
   }//end of for loop
   return found;
}//end of userSearch

void Users::removeUser(int id)
{
	int loc = -1;

	for(int i=0; i < userList.size(); i++)
	{
		if(userList.at(i)->getID() == id)
		{
			loc = i;
		}
	}

	if(loc == -1)
	{
		cout<<"User not found. Please try again with a valid ID."<<endl;
	}

	else
	{
		userList.erase(userList.begin() + loc);
		cout<<"The user has been removed."<<endl;
	}
}

void Users::changePassword(int id)
{
	int loc = -1;
	string userPassword;

	for(int i=0; i < userList.size(); i++)
	{
		if(userList.at(i)->getID() == id)
		{
			loc = i;
		}

		if(loc == -1)
		{
			cout<<"This user was not found. Please try again with a valid ID."<<endl;
		}

		else
		{
			cout<<"Enter the new password: "<<endl;
			getline(cin,userPassword);
			userList.at(loc)->setPassword(userPassword);
			cout<<"User password has sucessfully been changed."<<endl;
		}
	}
}

void Users::changeVehicleInfo(int id)
{
	int loc = -1;
	string vehicleMake;
	string vehicleModel;
	string vehicleYear;
	string vehiclePlate;

	for(int i=0; i < userList.size(); i++)
	{
		if(userList.at(i)->getID() == id)
		{
			loc = i;
		}

	}

	if(loc == -1)
	{
		cout<<"This user was not found. Please try againg with a valid ID."<<endl;
	}

	else
	{
		cout<<"Enter the new vehicle make: "<<endl;
		getline(cin,vehicleMake);
		userList.at(loc)->setMake(vehicleMake);

		cout<<"Enter the new vehicle model: "<<endl;
		getline(cin,vehicleModel);
		userList.at(loc)->setModel(vehicleModel);

		cout<<"Enter the new year of the vehicle: "<<endl;
		getline(cin,vehicleYear);
		userList.at(loc)->setYear(vehicleYear);
		
		cout<<"Enter the vehicle license plate: "<<endl;
		getline(cin,vehiclePlate);
		userList.at(loc)->setPlate(vehiclePlate);

		cout<<"New vehicle information has been sucessfully changed."<<endl;
	}
}


void Users::printVehicle(int i)
{
	cout<<"Vehicle Make: " << userList.at(i)->getMake() << endl;
	cout<<"Vehicle Model: " << userList.at(i)->getModel() << endl;
	cout<<"Vehicle Year: " << userList.at(i)->getYear() << endl;
	cout<<"Vehicle Plate Number: " << userList.at(i)->getPlate()<<endl;
}

void Users::printUserVehicle()
{
	for(int i=0; i < userList.size(); i++)
	{
		printVehicle(i);
	}
}

int Users::findLoc(int id)
{
	int loc = -1;
	
	for(int i=0; i < userList.size(); i++)
	{
		if(userList.at(i)->getID() == id)
		{
			loc = i;
		}
	}

		return loc;
}


