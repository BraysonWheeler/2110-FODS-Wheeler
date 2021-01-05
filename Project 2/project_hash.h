#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>

//project: base 2 hashing, chaining

using namespace std;

class Project_Hash {
   public:
      int HashFunction(int key);
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
      class Project {
         private:
            int projId;
            int empId;
            string projName;
            string startDate;
            string endDate;
            double empTime;
         public:
            //constructors
            Project();
            Project(int pId, int eId, string name, string start, string end, double eTime);
            //get/set functions
            void setProjId(int pId);
            int getProjId();
            void setEmpId(int eId);
            int getEmpId();
            void setProjName(string name);
            string getProjName();
            void setStartDate(string start);
            string getStartDate();
            void setEndDate(string end);
            string getEndDate();
            void setEmpTime(double eTime);
            double getEmpTime();
         };//end of Project

      private:
         //this is the actual hash table
         int tableSize = 15;
         vector<vector<Project>> projects = vector<vector<Project>>(tableSize);
};//end of Project_Hash
