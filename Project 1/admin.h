#include <string>
using namespace std;

class Admin {
   public:
      Admin();
      Admin(string name, int id, string password);

     void setName(string name);
     string getName();

     void setID(int id);
     int getID();

     void setPassword(string password);
     string getPassword();

   private:
      //name id password
      string adminName;
      int adminID;
      string adminPassword;
};//end of class
