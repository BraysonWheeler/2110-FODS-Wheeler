//
//  tickets.cpp
//  pj1_new
//
//  Created by Logan on 10/12/20.
//

#include "tickets.h"
#include <cmath>

void tickets::insertticket(){
    struct ticket aticket;
    aticket.tnum=rand() % 1001 + 39999;
    cout << "Ticket num is : " << aticket.tnum << endl;
    cout << "Enter your id Number \n";
    cin >> aticket.manid;
    cout << "Enter ticket amount \n";
    cin >> aticket.tamnt;
    aticket.tstat = "unpaid";
    cout << "Enter reason for ticket \n";
    cin >> aticket.tres;
    cout << "Enter veh owner \n";
    cin >> aticket.voh;
    cout << "Enter veh owner id \n";
    cin >> aticket.vohid;
    cout << "Enter veh maker \n";
    cin >> aticket.vma;
    cout << "Enter veh model \n";
    cin >> aticket.vmo;
    cout << "Enter veh year \n";
    cin >> aticket.vyr;
    cout << "Enter veh plate number \n";
    cin >> aticket.vpm;
    ticketlist.push_back(aticket);
    
}
//Prints all tickets
void tickets::printalltickets(){
    for(int i = 0 ; i < ticketlist.size(); ++i){
        cout << "Ticket id number : " << ticketlist[i].tnum << endl;
        cout << "Ticket amount : " <<ticketlist[i].tamnt << endl;
        cout << "Manager id : " << ticketlist[i].manid << endl;
        cout << "Ticket status : " << ticketlist[i].tstat << endl << endl;
    }
}

/*While  displaying  details  of  a  specific  ticket  information  your  system  should  display  ticket
number,  ticket  amount,  the  id  of  the  employee  who  issued  the  ticket,  ticket  status,  reason  for
the  ticket,  vehicle  owner  name,  vehicle  owner  id,  vehicle  make,  vehicle  model,  vehicle  year,
vehicle plate number.*/

void tickets::specificticket(int id){
    int fnd = 0;
    for(int i = 0 ; i < ticketlist.size(); ++i){
        if(ticketlist[i].tnum == id){
            fnd = 1;
            cout << "Ticket id number : " << ticketlist[i].tnum << endl;
            cout << "Ticket amount : " <<ticketlist[i].tamnt << endl;
            cout << "Manager id : " << ticketlist[i].manid << endl;
            cout << "Ticket status : " << ticketlist[i].tstat << endl;
            cout << "Ticket reason : " << ticketlist[i].tres << endl;
            cout << "Vehicle owner : " << ticketlist[i].voh << endl;
            cout << "Vehicle owner id : " << ticketlist[i].vohid << endl;
            cout << "Vehicle maker : " << ticketlist[i].vma << endl;
            cout << "Vehicle model : " << ticketlist[i].vmo << endl;
            cout << "Vehicle year: " << ticketlist[i].vyr << endl;
            cout << "Vehicle plate number : " << ticketlist[i].vpm << endl << endl;
        }
    }
    if(fnd == 1){
        return;
    }
    cout << "Ticket not found \n" << endl;
}

void tickets::viewyourticket(){
    int fnd = 0;
    for(int i = 0 ; i < ticketlist.size(); ++i){
        if(ticketlist[i].vohid == userid){
            fnd = 1;
            cout << "Ticket id number : " << ticketlist[i].tnum << endl;
            cout << "Ticket amount : " <<ticketlist[i].tamnt << endl;
            cout << "Manager id : " << ticketlist[i].manid << endl;
            cout << "Ticket status : " << ticketlist[i].tstat << endl << endl;
        }
    }
    if(fnd == 1){
        return;
    }
    cout << "No tickets found" << endl;
}

void tickets::payticket(){
    int pymnt;
    for(int i = 0 ; i < ticketlist.size(); ++i){
        if(ticketlist[i].vohid == userid){
            cout << "Ticket amount : " <<ticketlist[i].tamnt << endl;
            cout << "How much do you want to pay? \n";
            cin >> pymnt;
            ticketlist[i].tamnt = ticketlist[i].tamnt - pymnt;
            if(ticketlist[i].tamnt <= 0){
                cout << "Ticket Paid, Thank you! \n";
                return;
            }
            else{
                cout << "Thank you, amount left : " << ticketlist[i].tamnt << endl;
                return;
            }
        }
    }
    cout << "No tickets to pay" << endl;
}

void tickets::applticket(){
    int fnd = 0;
    for(int i = 0 ; i < ticketlist.size(); ++i){
        if(ticketlist[i].vohid == userid){
            fnd = 1;
            cout << "Ticket reason : " <<ticketlist[i].tres << endl;
            cout << "Please enter your appeal below \n";
            cin >> ticketlist[i].appl;
            cout << "Your appeal will be reviewed, Thank you! \n";
            ticketlist[i].applstatus = "pending";
        }
    }
    if(fnd == 1){
        return;
    }
    cout << "No tickets to appeal" << endl;
}

void tickets::viewyourappl(){
    int fnd = 0;
    for(int i = 0 ; i < ticketlist.size(); ++i){
        if(ticketlist[i].vohid == userid){
            fnd = 1;
            cout << "Your appeal status : " << ticketlist[i].applstatus << endl;
        }
    }
    if(fnd == 1){
        return;
    }
    cout << "No tickets to appeal" << endl;
}

void tickets::Adminviewanappl(int id){
    int fnd = 0;
    for(int i = 0 ; i < ticketlist.size(); ++i){
        if(ticketlist[i].vohid == id){
            fnd = 1;
            cout << endl << "Ticket id number : " << ticketlist[i].tnum << endl;
            cout << "User id : " << ticketlist[i].vohid << endl;
            cout << "Ticket amount : $" <<ticketlist[i].tamnt << endl;
            cout << "Manager id : " << ticketlist[i].manid << endl;
            cout << "Ticket status : " << ticketlist[i].tstat << endl;
            cout << "Ticket reason : " << ticketlist[i].tres << endl;
            cout << "--------------------------- \n";
            cout << "Appeal status : " << ticketlist[i].applstatus << endl;
            cout << "Appeal reasoning: " << ticketlist[i].appl << endl;
        }
    }
    if(fnd == 1){
        return;
    }
    cout << "No appeal found" << endl;
}

void tickets::Adminrepsonse(int id){
    int fnd = 0;
    int choice = 0;
    for(int i = 0 ; i < ticketlist.size(); ++i){
        if(ticketlist[i].vohid == id){
            fnd = 1;
            cout << "Current appeal status : " << ticketlist[i].applstatus << endl;
            cout << "Appeal response : 1 for Accepted 2 for rejected \n";
            cin >> choice;
            if (choice == 1){
                ticketlist[i].applstatus = "Accepted";
                ticketlist[i].tstat = "Resoleved";
                ticketlist[i].tamnt = 0;
            }
            else if (choice == 2){
                ticketlist[i].applstatus = "Rejected";
            }
            else{
                cout << "wrong input \n";
            }
            
            
        }
    }
    if(fnd == 1){
        return;
    }
    cout << "No tickets to appeal" << endl;
}

void tickets::removeticket(int id){
    int fnd = 0;
    for(int i = 0 ; i < ticketlist.size(); ++i){
        if(ticketlist[i].vohid == id){
            fnd = 1;
            ticketlist.erase(ticketlist.begin()+ i);
        }
    }
    if(fnd == 1){
        return;
    }
    cout << "No tickets found" << endl;
}
