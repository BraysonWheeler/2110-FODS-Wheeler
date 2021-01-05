#include "manager.h"

Manager::Manager() {
   managerName = "Unnamed";
   managerID = -1;
   managerPassword = "None";
}//end of default constructor


Manager::Manager(string name, int id, string password) {
   managerName = name;
   managerID = id;
   managerPassword = password;
}//end of parameterized constructor


void Manager::setName(string name) {
   managerName = name;
}//end of setName


string Manager::getName() {
   return managerName;
}//end of getName


void Manager::setID(int id) {
   managerID = id;
}//end of setID


int Manager::getID() {
   return managerID;
}//end of getID


void Manager::setPassword(string password) {
   managerPassword = password;
}//end of setPassword


string Manager::getPassword() {
   return managerPassword;
}//end of getPassword

