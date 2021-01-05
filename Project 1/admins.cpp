#include "admin.h"
#include "admins.h"

void Admins::loadInfo(string file, Admin* temp) {
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

   while(getline(ifile, thing, ',')) { //eof
      name = thing;
      getline(ifile, strid, ',');
      id = stoi(strid);
      getline(ifile, pass); //newline at the end of the row

      temp = new Admin(name, id, pass);
      adminList.push_back(temp);
   }//end of while

   ifile.close();
   if(ifile.is_open()) {
      cout << "Admin file not closed. Terminating program.\n";
   }//end of if

}//end of loadInfo


void Admins::saveInfo(string file) {
     ofstream ofile;
     ofile.open(file);
     if(!ofile.is_open()) {
        cout << "Output file could not open. Terminating program.\n";
        exit(0);
     }//end of if

     //save admin info to output file
     for(int i = 0; i< adminList.size(); i++) {
        ofile << adminList.at(i)->getName() << ",";
        ofile << adminList.at(i)->getID() << ",";
        ofile << adminList.at(i)->getPassword() << endl;
     }//end of for loop
     ofile.close();

     if(ofile.is_open()) {
        cout << "Admin output file could not close. Terminating program.\n";
        exit(0);
     }//end of if

     //cleanup
     for (auto iterator = adminList.begin(); iterator != adminList.end(); ++iterator) {
        delete *iterator;
     }//end of for loop
     adminList.clear();
}//end of saveInfo


void Admins::printAdmin(int i) {
   cout << left << setw(30) << adminList.at(i)->getName();
   cout << right << setw(4) << adminList.at(i)->getID() << endl;
}//end of printAdmin


void Admins::printInfo() {
   for(int i = 0; i < adminList.size(); i++) {
      printAdmin(i);
   }//end of for loop
}//end of printInfo


bool Admins::adminSearch(int id, string password) {
   bool found = false;
   for(int i = 0; i < adminList.size(); i++) {
      if(adminList.at(i)->getID() == id && adminList.at(i)->getPassword().compare(password) == 0) {
         found = true;
         break;
      }//end of if
   }//end of for loop
   return found;
}//end of search

void Admins::addAdmin(int id, string name, string password){
	Admin * temp = NULL;
	temp = new Admin(name,id,password);
	adminList.push_back(temp);
}

void Admins::removeAdmin(int id)
{
	int loc = -1;
	for(int i = 0; i < adminList.size(); i++)
	{	
		if (adminList.at(i)->getID() == id)
		{
			loc = i;
		}	
	}
	if(loc == -1)
	{
		cout<<"The admin was not found, please try again with valid id"<<endl;
	}
	else
	{
		adminList.erase(adminList.begin() + loc);
		cout<<"The admin was removed"<<endl;
	}
}

void Admins::changePassword(int id)
{
        int loc = -1;
	string newPass;
        for(int i = 0; i < adminList.size(); i++)
        {
                if (adminList.at(i)->getID() == id)
                {
                        loc = i;
                }
        }
        if(loc == -1)
        {
                cout<<"The admin was not found, please try again with valid id"<<endl;
        }
        else
        {
		cout<<"Enter the new password you wish for your account: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		getline(cin,newPass);
                adminList.at(loc)->setPassword(newPass);
                cout<<"Password successfully changed"<<endl;
        }
	
}
int Admins::findLoc(int id){
int loc = -1;
        for(int i = 0; i < adminList.size(); i++)
        {
                if (adminList.at(i)->getID() == id)
                {
                        loc = i;
                }
        }
	return loc;
}
