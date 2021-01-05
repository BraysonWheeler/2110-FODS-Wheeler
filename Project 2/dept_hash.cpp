#include "dept_hash.h"
#include <sstream>
#include<regex>
//dept: base 10 hash function, quadratic probing

int Dept_Hash::HashFunction(int key) {
   int R = 1; //had to make R = 1 in the event of 2-digit keys(ex. key = 10 for the first line), because 100 does not have 2+ middle bits to extract and causes a core dump.
   int bucket = key * key;
   string spos = to_string(bucket);
   int rDigits = (spos.size() - R)/2;
   spos.erase(spos.size() - rDigits, rDigits);
   int lDigits = spos.size() - R;
   spos.erase(0, lDigits);
   return stoi(spos) % tableSize;
}//end of hashfunction

int Dept_Hash::quadraticprobing(int key, int i) {
   //c1 = 2, c2 = 3
   return (HashFunction(key) + (2*i) + (3*(i*i))) % tableSize;
}//end of quadraticprobing

void Dept_Hash::loadInfo(string filename) {
   ifstream ifile;
   ifile.open(filename);

   if(!ifile.is_open()) {
      cout << filename << " not opened. Terminating program.\n";
      exit(0);
   }//end of if

   //variables
   Department temp;
   int bucket; //to determine where to put the new entry in the vector
   string dummy;
   bool emptystart = true;
   bool emptyremoval = false;
   string deptIdStr;
   int deptId;
   string title;
   string place;
   string mgrIdStr;
   int mgrId;
   string admrDeptIdStr;
   int admrDeptId;

   //initialize table
   for(int i = 0; i < tableSize; ++i) {
      temp = Department();
      departments.push_back(temp);
   }//end of for loop

   //read in info from file
   getline(ifile, dummy); //first 2 lines
   getline(ifile, dummy);

   while(getline(ifile, dummy, ',')) { //eof
      deptIdStr = dummy;
      deptId = stoi(deptIdStr);
      getline(ifile, title, ',');
      getline(ifile, place, ',');
      getline(ifile, mgrIdStr, ',');
      mgrId = stoi(mgrIdStr);
      getline(ifile, admrDeptIdStr);
      admrDeptId = stoi(admrDeptIdStr);

      //create Department and insert into hash table at the position called "bucket"
      temp = Department(emptystart, emptyremoval, deptId, title, place, mgrId, admrDeptId);
      bucket = HashFunction(deptId); //deptId is the key
      int i = 0;
      bool inserted = false;
      while(i < tableSize) {
         if(departments[bucket].getEmptySinceStart() || departments[bucket].getEmptyAfterRemoval()) {
            departments.insert(departments.begin() + bucket, temp); //insert into table at bucket pos
            departments[bucket].setEmptySinceStart(false); //not empty since start
            inserted = true;
            if(departments[bucket].getEmptyAfterRemoval()) { //if previously empty after removal, that is now false
               departments[bucket].setEmptyAfterRemoval(false);
            }//end of if
            break;
         }//end of if
         else {
            bucket = quadraticprobing(bucket, i);
            i++;
         }//end of else
      }//end of while for probing
      if(!inserted) {
         cout << "Table full, could not insert " << temp.getName() << endl;
      }//end of if
   }//end of while loop for each line of input file

   ifile.close();
}//end of loadinfo


//display
  //IMPORTANT NOTE: when you display, check the value of departments[bucket].getEmptySinceStart(). if it is false, then print. otherwise, do not print

void Dept_Hash::display(){
	int bucket;
	for(int i=0;i<tableSize;i++)
	{
		bucket = HashFunction(i);
		//If not empty then print out info
		
		if(i==0)
		{
			cout << left << setw(21)<<"DepartId";
                        cout << left << setw(21)<<"Name";
                        cout << left << setw(21)<<"Location";
                        cout << left << setw(21)<<"MgrId";
                        cout << left << setw(21)<<"AdmrId"<<endl;

		}
	
		if (departments[bucket].getEmptySinceStart() == false)
		{
			cout << left << setw(21)<< departments[bucket].getDepartId();
			cout << left << setw(21)<<departments[bucket].getName();
			cout << left << setw(21)<<departments[bucket].getLocation();
			cout << left << setw(21)<<departments[bucket].getMgrId();
			cout << left << setw(21)<<departments[bucket].getAdmrDepartId()<<endl;
		}
	}
}
//insert
void Dept_Hash::insert(string originalLine)
{
   Department temp;
   int bucket; //to determine where to put the new entry in the vector
   string dummy;
   bool emptystart = true;
   bool emptyremoval = false;
   string deptIdStr;
   int deptId;
   string title;
   string place;
   string mgrIdStr;
   int mgrId;
   string admrDeptIdStr;
   int admrDeptId;
   stringstream line(originalLine);

   //Reading from the origianl line
   while(line.good()){
      getline(line, dummy, ',');  //eof
      deptIdStr = dummy;
      deptId = stoi(deptIdStr);
      getline(line, title, ',');
      getline(line, place, ',');
      getline(line, mgrIdStr, ',');
      mgrId = stoi(mgrIdStr);
      getline(line, admrDeptIdStr);
      admrDeptId = stoi(admrDeptIdStr);
   }
      //create Department and insert into hash table at the position called "bucket"
      temp = Department(emptystart, emptyremoval, deptId, title, place, mgrId, admrDeptId);
      bucket = HashFunction(deptId); //deptId is the key
      int i = 0;
      bool inserted = false;
      while(i < tableSize) {
         if(departments[bucket].getEmptySinceStart() || departments[bucket].getEmptyAfterRemoval()) {
            departments.insert(departments.begin() + bucket, temp); //insert into table at bucket pos
            departments[bucket].setEmptySinceStart(false); //not empty since start
            inserted = true;
            if(departments[bucket].getEmptyAfterRemoval()) { //if previously empty after removal, that is now false
               departments[bucket].setEmptyAfterRemoval(false);
            }//end of if
            break;
         }//end of if
         else {
            bucket = quadraticprobing(bucket, i);
            i++;
         }//end of else
      }//end of while for probing
      if(!inserted) {
         cout << "Table full, could not insert " << temp.getName() << endl;
      }//end of if


}
//update

void Dept_Hash::update(string originalLine)
{

	regex departmentULine("([0-9]+),([a-z]+),(.*),([0-9]+),([0-9]+)");
	smatch matcher;
	regex_search(originalLine,matcher,departmentULine);


}

//select

void Dept_Hash::select(string originalLine)
{
	regex departmentSLine("([0-9]+),([a-z]+),(.*),([0-9]+),([0-9]+)");
	smatch matcher;
	regex_search(originalLine,matcher,departmentSLine);

}

//delete
bool Dept_Hash::findit(int x) {
    for (int i = 0; i < departments.size(); i++) {
        if (x == departments[i].getDepartId()) {
            return true;
        }
    }
    return false;
}
void Dept_Hash::Deletee(string originalLine) {
    regex pattern("([0-9]+),([a-z]+),(.*),([0-9]+),([0-9]+)");
    
    stringstream line(originalLine);
    int deptId;
    int index;
    string dummy;

    if (regex_match(originalLine, pattern)) {
;
        getline(line, dummy, ',');  //eof
        string deptIdStr = dummy;
        deptId = stoi(deptIdStr);
        index = HashFunction(deptId);
        if (findit(index) == true) {
            departments.erase(departments.begin() + index);
            cout << "Deletion of " << deptId << " successful \n";
        }
        else {
            cout << "Wrong Department id \n";
        }
    }
    else {
        cout << "Not a match \n";
    }

}
//write

void Dept_Hash::outfile() {
    ofstream outfile;
    outfile.open("department_out.csv");
    int bucket;

    for (int i = 0; i < tableSize; i++)
    {
        bucket = HashFunction(i);
        //If not empty then print out info

        if (i == 0)
        {
            outfile << "departid" << endl;
            outfile << "departId,name,location,mgrId,admrDepartId" << endl;

        }

        if (departments[bucket].getEmptySinceStart() == false)
        {
            outfile << departments[bucket].getDepartId() << ","<< 
                departments[bucket].getName()<< "," << departments[bucket].getLocation()<< "," << departments[bucket].getMgrId()<< "," << departments[bucket].getAdmrDepartId() << "," << endl;
        }
    }

}
