#include "employee_hash.h"

Employee_Hash::Employee::Employee() {
   emptysincestart = true;
   emptyafterremoval = false;
   empId = 0;
   firstName = "null";
   lastName = "null";
   phone = "0000000000";
   salary = 0;
   job = "null";
   email = "null";
   departId = 0;
}//end of default constructor

Employee_Hash::Employee::Employee(bool emptystart, bool emptyremoval, int id, string first, string last, string phonenumber, double pay, string jobname, string emailaddress, int deptId) {
   emptysincestart = emptystart;
   emptyafterremoval = emptyremoval;
   empId = id;
   firstName = first;
   lastName = last;
   phone = phonenumber;
   salary = pay;
   job = jobname;
   email = emailaddress;
   departId = deptId;
}//end of parameterized constructor

void Employee_Hash::Employee::setEmptySinceStart(bool empty) {
   emptysincestart = empty;
}//end of setemptysincestart

bool Employee_Hash::Employee::getEmptySinceStart() {
   return emptysincestart;
}//end of getemptysincestart

void Employee_Hash::Employee::setEmptyAfterRemoval(bool empty) {
   emptyafterremoval = empty;
}//end of setemptyafterremoval

bool Employee_Hash::Employee::getEmptyAfterRemoval() {
   return emptyafterremoval;
}//end of emptyafterremoval

void Employee_Hash::Employee::setEmpId(int id) {
   empId = id;
}//end of setempid

int Employee_Hash::Employee::getEmpId() {
   return empId;
}//end of getEmpId

void Employee_Hash::Employee::setFirstName(string first) {
   firstName = first;
}//end of setfirstname

string Employee_Hash::Employee::getFirstName() {
   return firstName;
}//end of getfirstname

void Employee_Hash::Employee::setLastName(string last) {
   lastName = last;
}//end of setlastname

string Employee_Hash::Employee::getLastName() {
   return lastName;
}//end of getlastname

void Employee_Hash::Employee::setPhone(string phonenumber) {
   phone = phonenumber;
}//end of setphone

string Employee_Hash::Employee::getPhone() {
   return phone;
}//end of getphone

void Employee_Hash::Employee::setSalary(double pay) {
   salary = pay;
}//end of setsalary

double Employee_Hash::Employee::getSalary() {
   return salary;
}//end of getsalary

void Employee_Hash::Employee::setJob(string jobname) {
   job = jobname;
}//end of setjob

string Employee_Hash::Employee::getJob() {
   return job;
}//end of getjob

void Employee_Hash::Employee::setEmail(string emailaddress) {
   email = emailaddress;
}//end of setemail

string Employee_Hash::Employee::getEmail() {
   return email;
}//end of getemail

void Employee_Hash::Employee::setDepartId(int deptId) {
   departId = deptId;
}//end of setdepartid

int Employee_Hash::Employee::getDepartId() {
   return departId;
}//end of get departid
