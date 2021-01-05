#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iterator>
#include <limits>

using namespace std;

struct ticket {
private:
    
public:
    int tnum;
    int tamnt;
    int manid;
    string tstat = "unpaid";
    string tres;
    string voh;
    int vohid;
    string vm;
    string vma;
    string vmo;
    string vyr;
    string vpm;
    string appl = "none";
    string applstatus = "none";
};


class tickets {
private:
    
public:
    int userid;
    
    void insertticket();
    void printalltickets();
    void specificticket(int id);
    void viewyourticket();
    void payticket();
    void applticket();
    void viewyourappl();
    void Adminviewanappl(int id);
    void Adminrepsonse(int id);
    void removeticket(int id);
    
    vector<ticket> ticketlist;
};

