#include <string>
using namespace std;

class Manager {
   public:
      Manager();
      Manager(string name, int id, string password);

     void setName(string name);
     string getName();

     void setID(int id);
     int getID();

     void setPassword(string password);
     string getPassword();

   private:
      //name id password
      string managerName;
      int managerID;
      string managerPassword;
};//end of class
