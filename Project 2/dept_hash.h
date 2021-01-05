#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <iomanip>
//dept: base 10 hashing, quadratic probing

using namespace std;

class Dept_Hash {
   public:
      int HashFunction(int key);
      int quadraticprobing(int key, int i);
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
      class Department {
         private:
            bool emptysincestart;
            bool emptyafterremoval;
            int departId;
            string name;
            string location;
            int mgrId;
            int admrDepartId;
         public:
            //constructors
            Department();
            Department(bool emptystart, bool emptyremoval, int deptId, string title, string place, int managerId, int admrDeptId);
            //get/set functions
            void setEmptySinceStart(bool empty);
            bool getEmptySinceStart();
            void setEmptyAfterRemoval(bool empty);
            bool getEmptyAfterRemoval();
            void setDepartId(int deptId);
            int getDepartId();
            void setName(string title);
            string getName();
            void setLocation(string place);
            string getLocation();
            void setMgrId(int managerId);
            int getMgrId();
            void setAdmrDepartId(int admrDeptId);
            int getAdmrDepartId();
         };//end of Department

      private:
         //this is the actual hash table
         int tableSize = 15;
         vector<Department> departments = vector<Department>(tableSize);
};//end of Dept_Hash
