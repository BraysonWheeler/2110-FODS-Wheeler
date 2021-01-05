#include "manager.h"
#include "managers.h"

void Managers::loadInfo(string file, Manager* temp) {
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

      temp = new Manager(name, id, pass);
      managerList.push_back(temp);
   }//end of while

   ifile.close();
   if(ifile.is_open()) {
      cout << "Manager file not closed. Terminating program.\n";
   }//end of if

}//end of loadInfo


void Managers::saveInfo(string file) {
     ofstream ofile;
     ofile.open(file);
     if(!ofile.is_open()) {
        cout << "Output file could not open. Terminating program.\n";
        exit(0);
     }//end of if

     //save manager info to output file
     for(int i = 0; i< managerList.size(); i++) {
        ofile << managerList.at(i)->getName() << ",";
        ofile << managerList.at(i)->getID() << ",";
        ofile << managerList.at(i)->getPassword() << endl;
     }//end of for loop
     ofile.close();

     if(ofile.is_open()) {
        cout << "Manager output file could not close. Terminating program.\n";
        exit(0);
     }//end of if

     //cleanup
     for (auto iterator = managerList.begin(); iterator != managerList.end(); ++iterator) {
        delete *iterator;
     }//end of for loop
     managerList.clear();
}//end of saveInfo


void Managers::printManager(int i) {
   cout << left << setw(30) << managerList.at(i)->getName();
   cout << right << setw(4) << managerList.at(i)->getID() << endl;
}//end of printManager


void Managers::printInfo() {
   for(int i = 0; i < managerList.size(); i++) {
      printManager(i);
   }//end of for loop
}//end of printInfo


bool Managers::managerSearch(int id, string password) {
   bool found = false;
   for(int i = 0; i < managerList.size(); i++) {
      if(managerList.at(i)->getID() == id && managerList.at(i)->getPassword().compare(password) == 0) {
         found = true;
         break;
      }//end of if
   }//end of for loop
   return found;
}//end of managerSearch

void Managers::addManager(int id, string name, string password){

        Manager * temp = NULL;
        temp = new Manager(name,id,password);
        managerList.push_back(temp);

}


void Managers::removeManager(int id)
{
        int loc = -1;
        for(int i = 0; i < managerList.size(); i++)
        {
                if (managerList.at(i)->getID() == id)
                {
                        loc = i;
                }
        }
        if(loc == -1)
        {
                cout<<"The manager was not found, please try again with valid id"<<endl;
        }
        else
        {
                managerList.erase(managerList.begin() + loc);
                cout<<"The manager was removed"<<endl;
        }
}

int Managers::findLoc(int id){

	int loc = -1;
	for(int i = 0; i < managerList.size(); i++)
        {
                if (managerList.at(i)->getID() == id)
                {
                        loc = i;
                }
        }

	
	return loc;
}

void Managers::changePassword(int id)
{
        int loc = -1;
    string newPass;
        for(int i = 0; i < managerList.size(); i++)
        {
                if (managerList.at(i)->getID() == id)
                {
                        loc = i;
                }
        }
        if(loc == -1)
        {
                cout<<"The Manager was not found, please try again with valid id"<<endl;
        }
        else
        {
        cout<<"Enter the new password you wish for your account: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin,newPass);
                managerList.at(loc)->setPassword(newPass);
                cout<<"Password successfully changed"<<endl;
        }
    
}

