#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <limits>
#include <iterator>

class Managers {
   public:
      void loadInfo(string file, Manager* temp);
      void saveInfo(string file);

      void printManager(int i);
      void printInfo();
      bool managerSearch(int id, string password);
      void addManager(int id,string name, string password);
      void removeManager(int id);
      int findLoc(int id);
    void changePassword(int id);
   private:
      vector<Manager*> managerList;
};//end of Managers
