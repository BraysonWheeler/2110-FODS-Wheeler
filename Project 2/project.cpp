#include "project_hash.h"

Project_Hash::Project::Project() {
   projId = 0;
   empId = 0;
   projName = "null";
   startDate = "null";
   endDate = "0000000000";
   empTime = 0;
}//end of default constructor

Project_Hash::Project::Project(int pId, int eId, string name, string start, string end, double eTime) {
   projId = pId;
   empId = eId;
   projName = name;
   startDate = start;
   endDate = end;
   empTime = eTime;
}//end of parameterized constructor

void Project_Hash::Project::setProjId(int pId) {
   projId = pId;
}//end of setprojid

int Project_Hash::Project::getProjId() {
   return projId;
}//end of getprojic

void Project_Hash::Project::setEmpId(int pId) {
   empId = pId;
}//end of setempid

int Project_Hash::Project::getEmpId() {
   return empId;
}//end of getEmpId

void Project_Hash::Project::setProjName(string name) {
   projName = name;
}//end of setprojname

string Project_Hash::Project::getProjName() {
   return projName;
}//end of getprojname

void Project_Hash::Project::setStartDate(string start) {
    startDate = start;
}//end of setstartdate

string Project_Hash::Project::getStartDate() {
   return startDate;
}//end of getstartdate

void Project_Hash::Project::setEndDate(string end) {
   endDate = end;
}//end of setenddate

string Project_Hash::Project::getEndDate() {
   return endDate;
}//end of getenddate

void Project_Hash::Project::setEmpTime(double eTime) {
   empTime = eTime;
}//end of setemptime

double Project_Hash::Project::getEmpTime() {
   return empTime;
}//end of getemptime

