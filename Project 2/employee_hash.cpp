#include "employee_hash.h"
#include <iomanip>
#include <sstream>
#include<regex>

//employee: modulo hashing, linear probing

int Employee_Hash::HashFunction(int key) {
   return key % tableSize;
}//end of hashfunction

int Employee_Hash::linearprobing(int key, int size) {
   return (key + 1) % size;
}//end of linearprobing

void Employee_Hash::loadInfo(string filename) {
   ifstream ifile;
   ifile.open(filename);

   if(!ifile.is_open()) {
      cout << filename << " not opened. Terminating program.\n";
      exit(0);
   }//end of if

   //variables
   Employee temp;
   int bucket; //to determine where to put the new entry in the vector
   string dummy;
   bool emptystart = true;
   bool emptyremoval = false;
   string empIdStr;
   int empId;
   string firstName;
   string lastName;
   string phone;
   string salaryStr;
   double salary;
   string job;
   string email;
   string deptIdStr;
   int deptId;

   //initialize table
   for(int i = 0; i < tableSize; ++i) {
      temp = Employee();
      employees.push_back(temp);
   }//end of for loop

   //read in info from file
   getline(ifile, dummy); //first 2 lines
   getline(ifile, dummy);

   while(getline(ifile, dummy, ',')) { //eof
      empIdStr = dummy;
      empId = stoi(empIdStr);
      getline(ifile, firstName, ',');
      getline(ifile, lastName, ',');
      getline(ifile, phone, ',');
      getline(ifile, salaryStr, ',');
      salary = stod(salaryStr);
      getline(ifile, job, ',');
      getline(ifile, email, ',');
      getline(ifile, deptIdStr);
      deptId = stoi(deptIdStr);

      //create Employee and insert into hash table at the position called "bucket"
      temp = Employee(emptystart, emptyremoval, empId, firstName, lastName, phone, salary, job, email, deptId);
      bucket = HashFunction(empId); //empId is the key
      int i = 0;
      bool inserted = false;
      while(i < tableSize) {
         if(employees[bucket].getEmptySinceStart() || employees[bucket].getEmptyAfterRemoval()) {
            employees.insert(employees.begin() + bucket, temp); //insert into table at bucket pos
            employees[bucket].setEmptySinceStart(false); //not empty since start
            inserted = true;

            if(employees[bucket].getEmptyAfterRemoval()) { //if previously empty after removal, that is now false
               employees[bucket].setEmptyAfterRemoval(false);
            }//end of if
            break;
         }//end of if
         else {
            bucket = linearprobing(bucket, tableSize);
            i++;
         }//end of else
      }//end of while for probing
      if(!inserted) {
         cout << "Table full, could not insert " << temp.getFirstName() << endl;
      }//end of if
   }//end of while loop for each line of input file

   ifile.close();
}//end of loadinfo


//display
  //IMPORTANT NOTE: when you display, check the value of employees[bucket].getEmptySinceStart(). if it is false, then print. otherwise, do not print
void Employee_Hash::display(){
	int bucket;
	for(int i=0;i<tableSize;i++)
	{
		bucket = HashFunction(i);
		//If not empty then print out info
		if(i == 0)
		{
			cout << left << setw(11) << "empID";
                        cout << left << setw(11)<< "firstName";
                        cout << left << setw(11)<< "lastName";
                        cout << left << setw(13)<< "phone";
                        cout << left << setw(11)<< "salary";
                        cout << left << setw(11)<< "job";
                        cout << left << setw(20)<< "email";
                        cout << right << setw(11)<< "departId" << endl;
	
		}

		if (employees[bucket].getEmptySinceStart() == false)
		{
			cout << left <<setw(11)<< employees[bucket].getEmpId();
			cout << left << setw(11)<< employees[bucket].getFirstName();
			cout << left << setw(11)<< employees[bucket].getLastName();
			cout << left << setw(13)<< employees[bucket].getPhone(); 
			cout << left << setw(11)<< employees[bucket].getSalary();
			cout << left << setw(11)<< employees[bucket].getJob();
			cout << left << setw(20)<< employees[bucket].getEmail();
			cout << right << setw(11)<< employees[bucket].getDepartId() << endl;
		}
	}
}

//insert
void Employee_Hash::insert(string originalLine){
   //Variables
   Employee temp;
   int bucket; //to determine where to put the new entry in the vector
   string dummy;
   bool emptystart = true;
   bool emptyremoval = false;
   string empIdStr;
   int empId;
   string firstName;
   string lastName;
   string phone;
   string salaryStr;
   double salary;
   string job;
   string email;
   string deptIdStr;
   int deptId;
   stringstream line(originalLine);

   //get info from line
   while(line.good()){
   
   getline(line, dummy, ',');
   empIdStr = dummy;
   empId = stoi(empIdStr);
   getline(line, firstName, ',');
   getline(line, lastName, ',');
   getline(line, phone, ',');
   getline(line, salaryStr, ',');
   salary = stod(salaryStr);
   getline(line, job, ',');
   getline(line, email, ',');
   getline(line, deptIdStr);
   deptId = stoi(deptIdStr);
   }
   //temp employee to be added  
   temp = Employee(emptystart, emptyremoval, empId, firstName, lastName, phone, salary, job, email, deptId);
  //determine bucket location
   bucket = HashFunction(empId);
    int i = 0;
      bool inserted = false;
      while(i < tableSize) {
         if(employees[bucket].getEmptySinceStart() || employees[bucket].getEmptyAfterRemoval()) {
            employees.insert(employees.begin() + bucket, temp); //insert into table at bucket pos
            employees[bucket].setEmptySinceStart(false); //not empty since start
            inserted = true;

            if(employees[bucket].getEmptyAfterRemoval()) { //if previously empty after removal, that is now false
               employees[bucket].setEmptyAfterRemoval(false);
            }//end of if
            break;
         }//end of if
         else {
            bucket = linearprobing(bucket, tableSize);
            i++;
         }//end of else
      }//end of while for probing
      if(!inserted) {
         cout << "Table full, could not insert " << temp.getFirstName() << endl;
      }//end of if
   //end of while loop for each line of input file




}

//update

void Employee_Hash::update(string originalLine)
{
	regex employeeULine("([0-9]+),([a-z]+),([a-z]+),([0-9]+),([0-9]+),([a-z]+),([a-z]+),([0-9]+)");
	smatch matcher;
	regex_search(originalLine,matcher,employeeULine);

}

//select

void Employee_Hash::select(string originalLine)
{
	regex employeeULine("([0-9]+),([a-z]+),([a-z]+),([0-9]+),([0-9]+),([a-z]+),([a-z]+),([0-9]+)");
	smatch matcher;
	regex_search(originalLine,matcher,employeeULine);
}

//delete
bool Employee_Hash::findit(int x) {
    for (int i = 0; i < employees.size(); i++) {
        if (x == employees[i].getEmpId()) {
            return true;
        }
    }
    return false;
}

void Employee_Hash::Deletee(string originalLine) {
    regex pattern("([0-9]+),([a-z]+),([a-z]+),([0-9]+),([0-9.]+),([a-z]+),([a-z0-9.]+),([0-9]+)");

    stringstream line(originalLine);
    int empid;
    string empidstr;
    int index;
    string dummy;
    if (regex_match(originalLine, pattern)) {
        getline(line, dummy, ',');  //eof
        string empidstr = dummy;
        empid = stoi(empidstr);
        index = HashFunction(empid);
        if ( findit(index) == true) {
            employees.erase(employees.begin() + index);
            cout << "Deletion of " << empid << " successful \n";
        }
        else {
            cout << "Wrong employee id \n";
        }
    }
    else {
        cout << "Not a match \n";
    }
}
    
//write
void Employee_Hash::outfile() {
    ofstream outfile;
    outfile.open("employee_out.csv");
    int bucket;

    for (int i = 0; i < tableSize; i++)
    {
        bucket = HashFunction(i);
        //If not empty then print out info

        if (i == 0)
        {
            outfile << "empid" << endl;
            outfile << "empId,firstname,LastName,phone,salary,job,email,departId" << endl;

        }

        if (employees[bucket].getEmptySinceStart() == false)
        {
            outfile << employees[bucket].getEmpId() << "," <<
                employees[bucket].getFirstName() << "," << employees[bucket].getLastName() << "," << employees[bucket].getPhone() << "," << employees[bucket].getSalary() << ","
                << employees[bucket].getJob() << "," << employees[bucket].getEmail() << "," << employees[bucket].getDepartId() << endl;
        }
    }

}