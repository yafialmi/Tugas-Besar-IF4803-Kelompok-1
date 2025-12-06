#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include <iostream>
#include "customer.h"
using namespace std;

typedef struct elmMenu *adrMenu;
typedef struct menu infotypeP;

struct menu{
    string id;
    int stock;
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
void insertFirstMenu(listMenu &L, adrMenu &M);
void insertLastMenu(listMenu &L, adrMenu &M);
void insertAfterMenu(listMenu &L, adrMenu &M, adrMenu &Mrec);
void deleteFirstMenu(listMenu &L, adrMenu &p);
void deleteLastMenu(listMenu &L, adrMenu &p);
void deleteAfterMenu(listMenu &L, adrMenu &p, adrMenu &Mrec);
adrMenu findElementMenu(listMenu &L, infotypeP x);
void viewMenu(listMenu &L);


#endif // MENU_H_INCLUDED
