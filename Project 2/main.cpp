//includes
#include <iostream>
#include <string>
#include <fstream>
#include <regex>
#include "employee_hash.h"
#include "dept_hash.h"
#include "project_hash.h"

using namespace std;

int main() {
    //main variables
    string inputfile;
    string pair1; //first half of pair (file name + type)
    string pair2; //second half of pair
    string pair3; //first half of second line pair
    string pair4; //second half of pair
    string pair5; //first half of third line pair
    string pair6; //second half of pair

    string type; //employee, dept or project
    string filename; //.csv
    string key; //first line of .csv file
    string scheme; //second line of csv
    Employee_Hash employeeTable;
    Dept_Hash departmentTable;
    Project_Hash projectTable;

    ifstream ifile;

    //get input file
    cout << "Enter name of input file: ";
    getline(cin, inputfile);

    //open file and test
    ifile.open(inputfile);
    if (!ifile.is_open()) {
        cout << "File not opened or does not exist. Terminating program.\n";
        exit(0);
    }//end of if

 //read in first pair and save info
    string r = "\r";
    getline(ifile, pair1, ' '); //read until space
    getline(ifile, pair2, '\n'); //read until endline or carriage return
    getline(ifile, pair3, ' '); //read until space
    getline(ifile, pair4, '\n'); //read until endline or carriage return
    getline(ifile, pair5, ' '); //read until space
    getline(ifile, pair6, '\n'); //read until endline or carriage return
    ifile.close();

    if (pair1.find(r) != string::npos) { //then "\r" is in it.
        pair1.erase(pair1.size() - 1); //remove "\r"
    }//end of if
    if (pair2.find(r) != string::npos) {
        pair2.erase(pair2.size() - 1);
    }//end of if
    if (pair3.find(r) != string::npos) {
        pair3.erase(pair3.size() - 1);
    }//end of if
    if (pair4.find(r) != string::npos) {
        pair4.erase(pair4.size() - 1);
    }//end of if
    if (pair5.find(r) != string::npos) {
        pair5.erase(pair5.size() - 1);
    }//end of if
    if (pair6.find(r) != string::npos) {
        pair6.erase(pair6.size() - 1);
    }//end of if


 //determine which pair has .csv and open that one
    regex pattern1(".*\\.[a-zA-Z]{3}");

    if (regex_match(pair1, pattern1)) {
        filename = pair1;
        type = pair2;
    }//end of if
    else if (regex_match(pair2, pattern1)) {
        filename = pair2;
        type = pair1;
    }//end of else if

    //match employee/dept/project and read in info
    if (type.find("employee") != string::npos) {
        employeeTable.loadInfo(filename);
    }//end of if
    else if (type.find("department") != string::npos) {
        departmentTable.loadInfo(filename);
    }//end of else if
    else if (type.find("project") != string::npos) {
        projectTable.loadInfo(filename);
    }//end of else if
    else {
        "Type is not of one of the 3 built hash tables and the file cannot be opened.\n";
    }//end of else

    //repeated for 4/5
    if (regex_match(pair3, pattern1)) {
        filename = pair3;
        type = pair4;
    }//end of if
    else if (regex_match(pair4, pattern1)) {
        filename = pair4;
        type = pair3;
    }//end of else if

    //match employee/dept/project and read in info
    if (type.find("employee") != string::npos) {
        employeeTable.loadInfo(filename);
    }//end of if
    else if (type.find("department") != string::npos) {
        departmentTable.loadInfo(filename);
    }//end of else if
    else if (type.find("project") != string::npos) {
        projectTable.loadInfo(filename);
    }//end of else if
    else {
        "Type is not of one of the 3 built hash tables and the file cannot be opened.\n";
    }//end of else

    //repeated for 5/6
    if (regex_match(pair5, pattern1)) {
        filename = pair5;
        type = pair6;
    }//end of if
    else if (regex_match(pair6, pattern1)) {
        filename = pair6;
        type = pair5;
    }//end of else if

    //match employee/dept/project and read in info
    if (type.find("employee") != string::npos) {
        employeeTable.loadInfo(filename);
    }//end of if
    else if (type.find("department") != string::npos) {
        departmentTable.loadInfo(filename);
    }//end of else if
    else if (type.find("project") != string::npos) {
        projectTable.loadInfo(filename);
    }//end of else if
    else {
        "Type is not of one of the 3 built hash tables and the file cannot be opened.\n";
    }//end of elseinput.txt


 //open input.txt back up, and read in all the dummy lines
 //then process commands using regex.

    //Patterns to match lines
    regex patternDisplay("(DIS)(.*)"); //pattern for display
    regex patternInsertEmployee("^INSERT.*employee.$"); //pattern for Insert
    regex patternInsertDepartment("^INSERT.*department.$int");
    regex patternInsertProject("^INSERT.*project.$ ");
    regex patternUpdateDepartment("^UPDATE.*department.$");
    regex patternUpdateEmployee("^UPDATE.*employee.$");
    regex patternUpdateProject("^UPDATE.*project.$");
    regex patternSelectDepartment("^SELECT.*department.$");
    regex patternSelectEmployee("^SELECT.*employee.$");
    regex patternSelectProject("^SELECT.*project.$");

    regex patternDeleteeEmployee("^DELETE.*employee.$");
    regex patternDeleteeDepartment("^DELETE.*department.$");
    regex patternDeleteeProject("^SELECT.*project.$");
    regex writepattern("WRITE.+"); // (WRITE\(\)) Not working.
    string line, dummy;

    //Opening file again
    ifile.open(inputfile);
    if (!ifile.is_open()) {
        cout << "File not opened or does not exist. Terminating program.\n";
        exit(0);
    }//end of if

   //read in info from file
    getline(ifile, dummy);
    getline(ifile, dummy);
    getline(ifile, dummy);
    getline(ifile, dummy);
    //while not eof, do this for every line
    while (getline(ifile, line, '\n'))
    {
        if (line.find(r) != string::npos) {
            line.erase(line.size() - 1);
        }//end of if

        //if Display pattern matches
        if (regex_match(line, patternDisplay))
        {
            cout << "DISPLAY" << endl;
            cout << "-----------------------------------------------Employee------------------------------------------------" << endl;
            cout << "-------------------------------------------------------------------------------------------------------" << endl;
            employeeTable.display();
            cout << "-----------------------------------------------Department----------------------------------------------" << endl;
            cout << "-------------------------------------------------------------------------------------------------------" << endl;
            departmentTable.display();

            cout << "-----------------------------------------------Project-------------------------------------------------" << endl;
            cout << "-------------------------------------------------------------------------------------------------------" << endl;
            projectTable.display();
        }

        else if (regex_match(line, patternInsertEmployee))
        {
            //remove first part INSERT(( and last ),employee) to only leave the info seperated by comma
            line.erase(0, 8);
            line.erase((line.end()) - 11, line.end());

            employeeTable.insert(line);
        }

        else if (regex_match(line, patternInsertDepartment))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 13, line.end());

            departmentTable.insert(line);
        }
        else if (regex_match(line, patternInsertProject))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 10, line.end());
            projectTable.insert(line);
        }
        else if (regex_match(line, patternUpdateDepartment))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 13, line.end());

            departmentTable.update(line);
        }
        else if (regex_match(line, patternUpdateEmployee))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 11, line.end());

            employeeTable.update(line);
        }
        else if (regex_match(line, patternUpdateProject))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 10, line.end());

            projectTable.update(line);
        }
        else if (regex_match(line, patternSelectDepartment))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 13, line.end());

            departmentTable.select(line);
        }
        else if (regex_match(line, patternSelectEmployee))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 11, line.end());

            employeeTable.select(line);
        }
        else if (regex_match(line, patternSelectProject))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 10, line.end());

            projectTable.select(line);
        }
        else if (regex_match(line, patternDeleteeDepartment))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 13, line.end());
            departmentTable.Deletee(line);
        }
        else if (regex_match(line, patternDeleteeEmployee))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 11, line.end());
            employeeTable.Deletee(line);
        }
        else if (regex_match(line, patternDeleteeProject))
        {
            line.erase(0, 8);
            line.erase((line.end()) - 10, line.end());

            projectTable.select(line);
        }
        
        else if (regex_match(line, writepattern))
        {
            departmentTable.outfile();
            projectTable.outfile();
            employeeTable.outfile();
        }
    }
    ifile.close();

    //if insert, select, delete, etc

    return 0;
}//end of main
