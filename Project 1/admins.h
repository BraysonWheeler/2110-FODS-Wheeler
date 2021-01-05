#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <iterator>

class Admins {
   public:
      void loadInfo(string file, Admin* temp);
      void saveInfo(string file);

      void printAdmin(int i);
      void printInfo();
      bool adminSearch(int id, string password);
      void addAdmin(int id,string name, string password);
      void removeAdmin(int id);
      void changePassword(int id);
      int findLoc(int id);
   private:
      vector<Admin*> adminList;
};//end of admins
