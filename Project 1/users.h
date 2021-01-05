#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <limits>

class Users {
   public:
      void loadInfo(string file, User* temp);
      void saveInfo(string file);

      void RegisterUser(User* &temp);

      void printUser(int i);
      void printInfo();
      bool userSearch(int id, string password);
      void removeUser(int id);
      void changePassword(int id);
      void changeVehicleInfo(int id);
      void printUserVehicle();
      void printVehicle(int i);
      int findLoc(int id);

   private:
      vector<User*> userList;
};//end of users

