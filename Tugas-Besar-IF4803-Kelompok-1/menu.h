#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "customer.h"
using namespace std;

typedef struct elmMenu *adrMenu;
typedef struct menu infotypeP;

struct menu{
    int id;
    int quantity;
    int price;
    string name;
};

struct elmMenu {
    infotypeP info;
    adrMenu next;
    listCustomer firstCustomer;
};

struct listMenu {
    adrMenu first;
};

bool checkEmptyMenu(listMenu L);
void createlistMenu(listMenu &L);
adrMenu createElementMenu(infotypeP x);
void insertFirstMenu(listMenu &L, adrMenu p);
void insertLastMenu(listMenu &L, adrMenu p);
void insertAfterMenu(listMenu &L, adrMenu p, adrMenu prec);
void deleteFirstMenu(listMenu &L, adrMenu &p);
void deleteLastMenu(listMenu &L, adrMenu &p);
void deleteAfterMenu(listMenu &L, adrMenu &p, adrMenu prec);
adrMenu findElementMenu(listMenu &L, infotypeP x);
void viewMenu(listMenu &L);


#endif // MENU_H_INCLUDED
