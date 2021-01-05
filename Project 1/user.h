#include <string>
using namespace std;

class User {
   public:
      User();
      User(string name, int id, string password, string make, string model, string year, string plate);

     void setName(string name);
     string getName();

     void setID(int id);
     int getID();

     void setPassword(string password);
     string getPassword();

     void setMake(string make);
     string getMake();

     void setModel(string model);
     string getModel();

     void setYear(string year);
     string getYear();

     void setPlate(string plate);
     string getPlate();

   private:
      //name id password make model year plate #
      string userName;
      int userID;
      string userPassword;
      string vehicleMake;
      string vehicleModel;
      string vehicleYear;
      string licensePlateNumber;
};//end of class
