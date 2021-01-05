#include "user.h"

User::User() {
   userName = "Unnamed";
   userID = -1;
   userPassword = "None";
   vehicleMake = "None";
   vehicleModel = "None";
   vehicleYear = "None";
   licensePlateNumber = "0000000";
}//end of default constructor


User::User(string name, int id, string password, string make, string model, string year, string plate) {
   userName = name;
   userID = id;
   userPassword = password;
   vehicleMake = make;
   vehicleModel = model;
   vehicleYear = year;
   licensePlateNumber = plate;
}//end of parameterized constructor


void User::setName(string name) {
   userName = name;
}//end of setName


string User::getName() {
   return userName;
}//end of getName


void User::setID(int id) {
   userID = id;
}//end of setID


int User::getID() {
   return userID;
}//end of getID


void User::setPassword(string password) {
   userPassword = password;
}//end of setPassword


string User::getPassword() {
   return userPassword;
}//end of getPassword


void User::setMake(string make) {
   vehicleMake = make;
}//end of setMake


string User::getMake() {
   return vehicleMake;
}//end of getMake


void User::setModel(string model) {
   vehicleModel = model;
}//end of setModel


string User::getModel() {
   return vehicleModel;
}//end of getModel


void User::setYear(string year) {
   vehicleYear = year;
}//send of setYear


string User::getYear() {
   return vehicleYear;
}//end of getYear


void User::setPlate(string plate) {
   licensePlateNumber = plate;
}//end of setPlate


string User::getPlate() {
   return licensePlateNumber;
}//end of getPlate

