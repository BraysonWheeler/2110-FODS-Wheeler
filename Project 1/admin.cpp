#include "admin.h"

Admin::Admin() {
   adminName = "Unnamed";
   adminID = -1;
   adminPassword = "None";
}//end of default constructor


Admin::Admin(string name, int id, string password) {
   adminName = name;
   adminID = id;
   adminPassword = password;
}//end of parameterized constructor


void Admin::setName(string name) {
   adminName = name;
}//end of setName


string Admin::getName() {
   return adminName;
}//end of getName


void Admin::setID(int id) {
   adminID = id;
}//end of setID


int Admin::getID() {
   return adminID;
}//end of getID


void Admin::setPassword(string password) {
   adminPassword = password;
}//end of setPassword


string Admin::getPassword() {
   return adminPassword;
}//end of getPassword

