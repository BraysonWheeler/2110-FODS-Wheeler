#include "dept_hash.h"

Dept_Hash::Department::Department() {
   emptysincestart = true;
   emptyafterremoval = false;
   departId = 0;
   name = "null";
   location = "null";
   mgrId = 0;
   admrDepartId = 0;
}//end of default constructor

Dept_Hash::Department::Department(bool emptystart, bool emptyremoval, int deptId, string title, string place, int managerId, int admrDeptId) {
   emptysincestart = emptystart;
   emptyafterremoval = emptyremoval;
   departId = deptId;
   name = title;
   location = place;
   mgrId = managerId;
   admrDepartId = admrDeptId;
}//end of parameterized constructor

void Dept_Hash::Department::setEmptySinceStart(bool empty) {
   emptysincestart = empty;
}//end of setemptysincestart

bool Dept_Hash::Department::getEmptySinceStart() {
   return emptysincestart;
}//end of getemptysincestart

void Dept_Hash::Department::setEmptyAfterRemoval(bool empty) {
   emptyafterremoval = empty;
}//end of setemptyafterremoval

bool Dept_Hash::Department::getEmptyAfterRemoval() {
   return emptyafterremoval;
}//end of emptyafterremoval

void Dept_Hash::Department::setDepartId(int deptId) {
   departId = deptId;
}//end of setdeptid

int Dept_Hash::Department::getDepartId() {
   return departId;
}//end of getdeptId

void Dept_Hash::Department::setName(string title) {
   name = title;
}//end of setname

string Dept_Hash::Department::getName() {
   return name;
}//end of getname

void Dept_Hash::Department::setLocation(string place) {
   location = place;
}//end of setlocation

string Dept_Hash::Department::getLocation() {
   return location;
}//end of getlocation

void Dept_Hash::Department::setMgrId(int managerId) {
   mgrId = managerId;
}//end of setmgrid

int Dept_Hash::Department::getMgrId() {
   return mgrId;
}//end of getmgrid

void Dept_Hash::Department::setAdmrDepartId(int admrDeptId) {
   admrDepartId = admrDeptId;
}//end of setadmrdepartid

int Dept_Hash::Department::getAdmrDepartId() {
   return admrDepartId;
}//end of getadmrdepartid

