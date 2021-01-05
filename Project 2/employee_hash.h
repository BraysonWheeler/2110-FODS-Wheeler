#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>

//employee: modulo hashing, linear probing

using namespace std;

class Employee_Hash {
   public:
      int HashFunction(int key);
      int linearprobing(int key, int size);
      void loadInfo(string filename);
      void display();
      void insert(string line);
      void update(string line);
      void select(string line);
      void Deletee(string line);
      bool findit(int x);
      void outfile();
      //display, insert, update, select, delete, write

      //entries in the hash table
      class Employee {
         private:
            bool emptysincestart;
            bool emptyafterremoval;
            int empId;
            string firstName;
            string lastName;
            string phone;
            double salary;
            string job;
            string email;
            int departId;
         public:
            //constructors
            Employee();
            Employee(bool emptystart, bool emptyremoval, int id, string first, string last, string phonenumber, double pay, string jobname, string emailaddress, int deptId);
            //get/set functions
            void setEmptySinceStart(bool empty);
            bool getEmptySinceStart();
            void setEmptyAfterRemoval(bool empty);
            bool getEmptyAfterRemoval();
            void setEmpId(int id);
            int getEmpId();
            void setFirstName(string first);
            string getFirstName();
            void setLastName(string last);
            string getLastName();
            void setPhone(string phonenumber);
            string getPhone();
            void setSalary(double pay);
            double getSalary();
            void setJob(string jobname);
            string getJob();
            void setEmail(string emailaddress);
            string getEmail();
            void setDepartId(int deptId);
            int getDepartId();
         };//end of Employee

      private:
         //this is the actual hash table
         int tableSize = 15;
         vector<Employee> employees = vector<Employee>(tableSize);
};//end of Employee_Hash
