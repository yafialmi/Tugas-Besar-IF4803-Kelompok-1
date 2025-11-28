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
    adrCustomer firstChild;
};

struct listParent {
    adrMenu first;
};


void createListParent(listParent &L);
adrMenu createElementParent(infotypeP x);
void insertFirstParent(listParent &L, adrMenu p);
void insertLastParent(listParent &L, adrMenu p);
void insertAfterParent(listParent &L, adrMenu p, adrMenu prec);
void deleteFirstParent(listParent &L, adrMenu &p);
void deleteLastParent(listParent &L, adrMenu &p);
void deleteAfterParent(listParent &L, adrMenu &p, adrMenu prec);
adrMenu findElementParent(listParent &L, infotypeP x);
void viewParent(listParent &L);


#endif // MENU_H_INCLUDED
