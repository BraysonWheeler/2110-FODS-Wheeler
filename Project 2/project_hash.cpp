#include "project_hash.h"
#include <sstream>
#include <fstream>
//project: base 2 hashing, chaining

int Project_Hash::HashFunction(int key) {
   int R = 4;
   int bucket;
   bucket = key * key;
   int lBits = (32 - R) / 2;
   int eBits = bucket >> lBits;
   eBits = eBits & (0xFFFFFFFF >> (32 - R));
   return eBits % tableSize;
}//end of hashfunction

void Project_Hash::loadInfo(string filename) {
   ifstream ifile;
   ifile.open(filename);

   if(!ifile.is_open()) {
      cout << filename << " not opened. Terminating program.\n";
      exit(0);
   }//end of if

   //variables
   Project temp;
   int bucket; //to determine where to put the new entry in the vector
   string dummy;
   string pIdStr;
   int pId;
   string eIdStr;
   int eId;
   string name;
   string start;
   string end;
   string eTimeStr;
   double eTime;


   //read in info from file
   getline(ifile, dummy); //first 2 lines
   getline(ifile, dummy);

   while(getline(ifile, dummy, ',')) { //eof
      pIdStr = dummy;
      pId = stoi(pIdStr);
      getline(ifile, eIdStr, ',');
      eId = stoi(eIdStr);
      getline(ifile, name, ',');
      getline(ifile, start, ',');
      getline(ifile, end, ',');
      getline(ifile, eTimeStr);
      eTime = stod(eTimeStr);

      //create Project and insert into hash table at the position called "bucket"
      temp = Project(pId, eId, name, start, end, eTime);
      bucket = HashFunction(pId); //pId is the key
      projects[bucket].push_back(temp);
   }//end of while loop for each line of input file

   ifile.close();
}//end of loadinfo


//display
  //should be able to display all at projects[i][j] in a nested for loop
void Project_Hash::display(){
	int bucket;
	for(int i=0;i<tableSize;i++)
	{
		bucket = HashFunction(i);
		//If not empty then print out info
		if(i == 0)
		{
			for(int j=0;j<projects[bucket].size();j++)
			{
				if (j==0)
				{
					cout << left << setw(17)<<"ProjId";
	               		        cout << left << setw(17)<<"EmpId";
       	              			cout << left << setw(17)<<"ProjName";
       	                		cout << left << setw(17)<<"StartDate";
       	               			cout << left << setw(17)<<"EndDate";
                        		cout << left << setw(17)<<"EmpTime"<<endl;

				}
				cout << left << setw(17)<<projects[bucket][j].getProjId();
				cout << left << setw(17)<<projects[bucket][j].getEmpId();
				cout << left << setw(17)<<projects[bucket][j].getProjName(); 
				cout << left << setw(17)<<projects[bucket][j].getStartDate();
				cout << left << setw(17)<<projects[bucket][j].getEndDate();
				cout << left << setw(17)<<projects[bucket][j].getEmpTime()<<endl;
			}

		}	
	}
}
//insert
void Project_Hash::insert(string originalLine)
{
   Project temp;
   int bucket; //to determine where to put the new entry in the vector
   string dummy;
   string pIdStr;
   int pId;
   string eIdStr;
   int eId;
   string name;
   string start;
   string end;
   string eTimeStr;
   double eTime;
   stringstream line;
   while(line.good())
   {
      getline(line, dummy, ',');
      pIdStr = dummy;
      pId = stoi(pIdStr);
      getline(line, eIdStr, ',');
      eId = stoi(eIdStr);
      getline(line, name, ',');
      getline(line, start, ',');
      getline(line, end, ',');
      getline(line, eTimeStr);
      eTime = stod(eTimeStr);
   }	   
    //create Project and insert into hash table at the position called "bucket"
      temp = Project(pId, eId, name, start, end, eTime);
      bucket = HashFunction(pId); //pId is the key
      projects[bucket].push_back(temp);
  

}
//update

void Project_Hash::update(string originalLine)
{
	regex projectULine("([0-9]+),([0-9]+),([a-z]+),([0-9]+),([0-9]+),([0-9]+)");
	smatch matcher;
	regex_search(originalLine,matcher,projectULine);


}

//select

void Project_Hash::select(string originalLine)
{

	regex projectSLine("([0-9]+),([0-9]+),([a-z]+),([0-9]+),([0-9]+),([0-9]+)");
	smatch matcher;
	regex_search(originalLine,matcher,projectSLine);

}


//delete
bool Project_Hash::findit(int x) {
    for (int i = 0; i < projects.size(); i++) {
        for (int j = 0; j < projects[i].size(); j++) {
            if (x == projects[i][j].getEmpId()) {
                projects[i].erase(projects[i].begin());
                return true;
            }
        }
    }
    return false;
}
void Project_Hash::Deletee(string originalLine) {
    regex pattern("([0-9]+),([0-9]+),([a-z]+),([0-9/]+),([0-9/]+),([a-z0-9.]+)");

    stringstream line(originalLine);
    int pjid;
    string pjidstr;
    int index;
    string dummy;
    if (regex_match(originalLine, pattern)) {
        getline(line, dummy, ',');  //eof
        string pjidstr = dummy;
        pjid = stoi(pjidstr);
        index = HashFunction(pjid);
        if (findit(index) == true) {
            cout << "Deletion of " << pjid << " successful \n";
        }
        else {
            cout << "Wrong project id \n";
        }
    }
    else {
        cout << "Not a match \n";
    }
}
//write
void Project_Hash::outfile() {
    ofstream outfile;
    outfile.open("project_out.csv");
    int bucket;
    for (int i = 0; i < tableSize; i++)
    {
        bucket = HashFunction(i);
        //If not empty then print out info
        if (i == 0)
        {
            for (int j = 0; j < projects[bucket].size(); j++)
            {
                if (j == 0)
                {
                    outfile << "projId" << endl;
                    outfile << "projId,empid,Projname,startDate,empTime" << endl;
                }
                outfile << projects[bucket][j].getProjId() << "," <<
                    projects[bucket][j].getEmpId() << "," << projects[bucket][j].getProjName() << "," << projects[bucket][j].getStartDate()
                    << "," << projects[bucket][j].getEndDate() << "," << projects[bucket][j].getEmpTime() << endl;
            }

        }
    }
}
